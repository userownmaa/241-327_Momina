#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "httpclient.h"

#include <QJsonDocument>  //для парсинга JSON-ответов сервера (представляет json-документ)
#include <QJsonArray>
#include <QLocale> //для преобразования строки цены в число
#include <algorithm>   //для сорировки
#include <QList>   //контейнер для временного хранения списка


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);           // создаёт все виджеты из .ui

    // Подключаем сигналы кнопок к слотам
    connect(ui->m_listBtn, &QPushButton::clicked, this, &MainWindow::onGetListClicked);
    connect(ui->m_getBtn, &QPushButton::clicked, this, &MainWindow::onGetByIdClicked);
    connect(ui->m_createBtn, &QPushButton::clicked, this, &MainWindow::onCreateClicked);
    connect(ui->m_updateBtn, &QPushButton::clicked, this, &MainWindow::onUpdateClicked);
    connect(ui->m_deleteBtn, &QPushButton::clicked, this, &MainWindow::onDeleteClicked);

    // Подключаем сигналы HttpClient
    connect(&HttpClient::instance(), &HttpClient::requestCompleted,
            this, &MainWindow::handleResponse);
    connect(&HttpClient::instance(), &HttpClient::requestError,
            this, &MainWindow::handleError);
}

MainWindow::~MainWindow()
{
    delete ui;
}

Medicine MainWindow::readMedicineFromForm()
{
    Medicine med;
    med.setName(ui->m_nameEdit->text());
    bool ok;
    double price = QLocale::c().toDouble(ui->m_priceEdit->text(), &ok);
    med.setPrice(ok ? price : 0.0);
    med.setQuantityInStock(ui->m_quantityEdit->text().toInt());
    med.setExpirationDate(QDate::fromString(ui->m_expirationEdit->text(), "yyyy-MM-dd"));
    med.setManufacturer(ui->m_manufacturerEdit->text());
    med.setRequiresPrescription(ui->m_prescriptionCheck->isChecked());
    med.setDescription(ui->m_descriptionEdit->toPlainText());
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
    ui->m_outputText->setText(text);
}

void MainWindow::handleResponse(const QByteArray& data)  //cлот, вызываемый при успешном получении ответа от сервера
{
//    qDebug() << "JSON:" << data;

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
        ui->m_outputText->setText(output);
    } else if (doc.isObject()) {
        Medicine med = Medicine::fromJson(doc.object());
        showMedicine(med);
    } else {
        ui->m_outputText->setText("Успешно.\nОтвет: " + QString(data));
    }

}

void MainWindow::handleError(const QString& error)    //cлот для отображения ошибок сети
{
    ui->m_outputText->setText("Ошибка: " + error);
}

void MainWindow::onGetListClicked() { HttpClient::instance().getMedicineList(); }
void MainWindow::onGetByIdClicked()
{
    int id = ui->m_idEdit->text().toInt();
    if (id <= 0) { ui->m_outputText->setText("Введите корректный ID"); return; }
    HttpClient::instance().getMedicineById(id);
}
void MainWindow::onCreateClicked() { HttpClient::instance().createMedicine(readMedicineFromForm()); }
void MainWindow::onUpdateClicked()
{
    int id = ui->m_idEdit->text().toInt();
    if (id <= 0) { ui->m_outputText->setText("Введите ID для обновления"); return; }
    Medicine med = readMedicineFromForm();
    med.setId(id);
    HttpClient::instance().updateMedicine(id, med);
}
void MainWindow::onDeleteClicked()
{
    int id = ui->m_idEdit->text().toInt();
    if (id <= 0) { ui->m_outputText->setText("Введите ID для удаления"); return; }
    HttpClient::instance().deleteMedicine(id);
}
