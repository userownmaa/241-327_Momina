#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QCheckBox>
#include "medicine.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT    //Макрос Q_OBJECT делает возможным использование сигналов/слотов

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onGetListClicked();
    void onGetByIdClicked();
    void onCreateClicked();
    void onUpdateClicked();
    void onDeleteClicked();
    void handleResponse(const QByteArray& data);
    void handleError(const QString& error);

private:
    void setupUI();
    Medicine readMedicineFromForm();
    void showMedicine(const Medicine& med);

    QLineEdit *m_idEdit;  //виджеты, хранятся как указатели, потому что создаются динамически в setupUI() и должны существовать всё время жизни окна.
    QLineEdit *m_nameEdit;
    QLineEdit *m_priceEdit;
    QLineEdit *m_quantityEdit;
    QLineEdit *m_expirationEdit;
    QLineEdit *m_manufacturerEdit;
    QCheckBox *m_prescriptionCheck;
    QTextEdit *m_descriptionEdit;
    QTextEdit *m_outputText;
    QPushButton *m_listBtn, *m_getBtn, *m_createBtn, *m_updateBtn, *m_deleteBtn;
};

#endif
