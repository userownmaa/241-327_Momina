#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "medicine.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

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
    Ui::MainWindow *ui;
    Medicine readMedicineFromForm();
    void showMedicine(const Medicine& med);
};

#endif
