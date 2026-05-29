#include "mainwindow.h"
#include "httpclient.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QLabel>
#include <QJsonDocument>
#include <QJsonArray>
#include <QLocale>
#include <algorithm>
#include <QList>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    setupUI();
    connect(&HttpClient::instance(), &HttpClient::requestCompleted,  //connect из Qt: соединяет сигнал requestCompleted объекта HttpClient (синглтон) со слотом handleResponse текущего окна (this). Когда HTTP-запрос успешно завершится, будет вызван handleResponse с полученными данными. Это обеспечивает асинхронную связь между сетевым менеджером и интерфейсом.
            this, &MainWindow::handleResponse);
    connect(&HttpClient::instance(), &HttpClient::requestError,
            this, &MainWindow::handleError);
}

MainWindow::~MainWindow() {}

void MainWindow::setupUI()
{
    QWidget *central = new QWidget(this);
    QVBoxLayout *mainLayout = new QVBoxLayout(central);

    QHBoxLayout *idLayout = new QHBoxLayout;
    idLayout->addWidget(new QLabel("ID:"));
    m_idEdit = new QLineEdit;
    idLayout->addWidget(m_idEdit);
    mainLayout->addLayout(idLayout);

    QFormLayout *form = new QFormLayout;
    m_nameEdit = new QLineEdit;
    m_priceEdit = new QLineEdit;
    m_quantityEdit = new QLineEdit;
    m_expirationEdit = new QLineEdit;
    m_expirationEdit->setPlaceholderText("ГГГГ-ММ-ДД");
    m_manufacturerEdit = new QLineEdit;
    m_prescriptionCheck = new QCheckBox;
    m_descriptionEdit = new QTextEdit;
    m_descriptionEdit->setMaximumHeight(60);

    form->addRow("Название:", m_nameEdit);
    form->addRow("Цена:", m_priceEdit);
    form->addRow("Кол-во:", m_quantityEdit);
    form->addRow("Срок годности:", m_expirationEdit);
    form->addRow("Производитель:", m_manufacturerEdit);
    form->addRow("По рецепту:", m_prescriptionCheck);
    form->addRow("Описание:", m_descriptionEdit);
    mainLayout->addLayout(form);

    QHBoxLayout *btnLayout = new QHBoxLayout;
    m_listBtn = new QPushButton("GET List");
    m_getBtn = new QPushButton("GET by ID");
    m_createBtn = new QPushButton("POST Create");
    m_updateBtn = new QPushButton("PUT Update");
    m_deleteBtn = new QPushButton("DELETE");
    btnLayout->addWidget(m_listBtn);
    btnLayout->addWidget(m_getBtn);
    btnLayout->addWidget(m_createBtn);
    btnLayout->addWidget(m_updateBtn);
    btnLayout->addWidget(m_deleteBtn);
    mainLayout->addLayout(btnLayout);

    mainLayout->addWidget(new QLabel("Ответ сервера:"));
    m_outputText = new QTextEdit;
    m_outputText->setReadOnly(true);
    mainLayout->addWidget(m_outputText);

    setCentralWidget(central);
    setWindowTitle("REST Client - Лекарства");
    resize(650, 550);

    connect(m_listBtn, &QPushButton::clicked, this, &MainWindow::onGetListClicked);  //соединение слотов с сигналами нажатия кнопок
    connect(m_getBtn, &QPushButton::clicked, this, &MainWindow::onGetByIdClicked);
    connect(m_createBtn, &QPushButton::clicked, this, &MainWindow::onCreateClicked);
    connect(m_updateBtn, &QPushButton::clicked, this, &MainWindow::onUpdateClicked);
    connect(m_deleteBtn, &QPushButton::clicked, this, &MainWindow::onDeleteClicked);
}

Medicine MainWindow::readMedicineFromForm()
{
    Medicine med;
    med.setName(m_nameEdit->text());
    bool ok;
    double price = QLocale::c().toDouble(m_priceEdit->text(), &ok);
    med.setPrice(ok ? price : 0.0);
    med.setQuantityInStock(m_quantityEdit->text().toInt());
    med.setExpirationDate(QDate::fromString(m_expirationEdit->text(), "yyyy-MM-dd"));
    med.setManufacturer(m_manufacturerEdit->text());
    med.setRequiresPrescription(m_prescriptionCheck->isChecked());
    med.setDescription(m_descriptionEdit->toPlainText());
    return med;
}

void MainWindow::showMedicine(const Medicine& med)
{
    QString text = QString("ID: %1\nНазвание: %2\nЦена: %3\nКол-во: %4\n"
                           "Срок годности: %5\nПроизводитель: %6\nРецепт: %7\nОписание: %8")
                       .arg(med.id()).arg(med.name()).arg(med.price())
                       .arg(med.quantityInStock()).arg(med.expirationDate().toString("yyyy-MM-dd"))
                       .arg(med.manufacturer()).arg(med.requiresPrescription() ? "Да" : "Нет")
                       .arg(med.description());
    m_outputText->setText(text);
}

void MainWindow::handleResponse(const QByteArray& data)  //cлот, вызываемый при успешном получении ответа от сервера
{
//    qDebug() << "Raw JSON:" << data;

    QJsonDocument doc = QJsonDocument::fromJson(data);   //парсинг JSON-данных в документ

    if (doc.isArray()) {
        QJsonArray arr = doc.array();
        QList<Medicine> medicines;
        for (const QJsonValue& val : arr) {
            medicines.append(Medicine::fromJson(val.toObject()));  //преобразование каждого элемента массива в объект Medicine и сохранение в список
        }
        // cортировка по ID
        std::sort(medicines.begin(), medicines.end(),
                  [](const Medicine& a, const Medicine& b) {
                      return a.id() < b.id();
                  });

        QString output = "Список лекарств:\n\n";
        for (const Medicine& med : medicines) {
            output += QString("%1) %2 (цена %3, в наличии %4)\n")
                          .arg(med.id()).arg(med.name()).arg(med.price()).arg(med.quantityInStock());
        }
        m_outputText->setText(output);
    } else if (doc.isObject()) {
        Medicine med = Medicine::fromJson(doc.object());
        showMedicine(med);
    } else {
        m_outputText->setText("Успешно.\nОтвет: " + QString(data));
    }

}

void MainWindow::handleError(const QString& error)    //cлот для отображения ошибок сети
{
    m_outputText->setText("Ошибка: " + error);
}

void MainWindow::onGetListClicked() { HttpClient::instance().getMedicineList(); }
void MainWindow::onGetByIdClicked()
{
    int id = m_idEdit->text().toInt();
    if (id <= 0) { m_outputText->setText("Введите корректный ID"); return; }
    HttpClient::instance().getMedicineById(id);
}
void MainWindow::onCreateClicked() { HttpClient::instance().createMedicine(readMedicineFromForm()); }
void MainWindow::onUpdateClicked()
{
    int id = m_idEdit->text().toInt();
    if (id <= 0) { m_outputText->setText("Введите ID для обновления"); return; }
    Medicine med = readMedicineFromForm();
    med.setId(id);
    HttpClient::instance().updateMedicine(id, med);
}
void MainWindow::onDeleteClicked()
{
    int id = m_idEdit->text().toInt();
    if (id <= 0) { m_outputText->setText("Введите ID для удаления"); return; }
    HttpClient::instance().deleteMedicine(id);
}
