/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout_2;
    QLabel *label;
    QLineEdit *m_idEdit;
    QLabel *label_2;
    QLineEdit *m_nameEdit;
    QLabel *label_3;
    QLineEdit *m_priceEdit;
    QLabel *label_4;
    QLineEdit *m_quantityEdit;
    QLabel *label_5;
    QLineEdit *m_expirationEdit;
    QLabel *label_6;
    QLineEdit *m_manufacturerEdit;
    QLabel *label_7;
    QCheckBox *m_prescriptionCheck;
    QLabel *label_8;
    QTextEdit *m_descriptionEdit;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *m_listBtn;
    QPushButton *m_getBtn;
    QPushButton *m_createBtn;
    QPushButton *m_updateBtn;
    QPushButton *m_deleteBtn;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_9;
    QTextEdit *m_outputText;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 641);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        formLayoutWidget = new QWidget(centralwidget);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(9, 9, 781, 281));
        formLayout_2 = new QFormLayout(formLayoutWidget);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label);

        m_idEdit = new QLineEdit(formLayoutWidget);
        m_idEdit->setObjectName(QString::fromUtf8("m_idEdit"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, m_idEdit);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_2);

        m_nameEdit = new QLineEdit(formLayoutWidget);
        m_nameEdit->setObjectName(QString::fromUtf8("m_nameEdit"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, m_nameEdit);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_3);

        m_priceEdit = new QLineEdit(formLayoutWidget);
        m_priceEdit->setObjectName(QString::fromUtf8("m_priceEdit"));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, m_priceEdit);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout_2->setWidget(3, QFormLayout::LabelRole, label_4);

        m_quantityEdit = new QLineEdit(formLayoutWidget);
        m_quantityEdit->setObjectName(QString::fromUtf8("m_quantityEdit"));

        formLayout_2->setWidget(3, QFormLayout::FieldRole, m_quantityEdit);

        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout_2->setWidget(4, QFormLayout::LabelRole, label_5);

        m_expirationEdit = new QLineEdit(formLayoutWidget);
        m_expirationEdit->setObjectName(QString::fromUtf8("m_expirationEdit"));

        formLayout_2->setWidget(4, QFormLayout::FieldRole, m_expirationEdit);

        label_6 = new QLabel(formLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout_2->setWidget(5, QFormLayout::LabelRole, label_6);

        m_manufacturerEdit = new QLineEdit(formLayoutWidget);
        m_manufacturerEdit->setObjectName(QString::fromUtf8("m_manufacturerEdit"));

        formLayout_2->setWidget(5, QFormLayout::FieldRole, m_manufacturerEdit);

        label_7 = new QLabel(formLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout_2->setWidget(6, QFormLayout::LabelRole, label_7);

        m_prescriptionCheck = new QCheckBox(formLayoutWidget);
        m_prescriptionCheck->setObjectName(QString::fromUtf8("m_prescriptionCheck"));

        formLayout_2->setWidget(6, QFormLayout::FieldRole, m_prescriptionCheck);

        label_8 = new QLabel(formLayoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        formLayout_2->setWidget(7, QFormLayout::LabelRole, label_8);

        m_descriptionEdit = new QTextEdit(formLayoutWidget);
        m_descriptionEdit->setObjectName(QString::fromUtf8("m_descriptionEdit"));

        formLayout_2->setWidget(7, QFormLayout::FieldRole, m_descriptionEdit);

        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(9, 299, 781, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        m_listBtn = new QPushButton(horizontalLayoutWidget);
        m_listBtn->setObjectName(QString::fromUtf8("m_listBtn"));

        horizontalLayout->addWidget(m_listBtn);

        m_getBtn = new QPushButton(horizontalLayoutWidget);
        m_getBtn->setObjectName(QString::fromUtf8("m_getBtn"));

        horizontalLayout->addWidget(m_getBtn);

        m_createBtn = new QPushButton(horizontalLayoutWidget);
        m_createBtn->setObjectName(QString::fromUtf8("m_createBtn"));

        horizontalLayout->addWidget(m_createBtn);

        m_updateBtn = new QPushButton(horizontalLayoutWidget);
        m_updateBtn->setObjectName(QString::fromUtf8("m_updateBtn"));

        horizontalLayout->addWidget(m_updateBtn);

        m_deleteBtn = new QPushButton(horizontalLayoutWidget);
        m_deleteBtn->setObjectName(QString::fromUtf8("m_deleteBtn"));

        horizontalLayout->addWidget(m_deleteBtn);

        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(9, 349, 781, 241));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(verticalLayoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        verticalLayout->addWidget(label_9);

        m_outputText = new QTextEdit(verticalLayoutWidget);
        m_outputText->setObjectName(QString::fromUtf8("m_outputText"));

        verticalLayout->addWidget(m_outputText);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "ID:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\246\320\265\320\275\320\260:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276:", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\320\241\321\200\320\276\320\272 \320\263\320\276\320\264\320\275\320\276\321\201\321\202\320\270:", nullptr));
        m_expirationEdit->setText(QString());
        m_expirationEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\223\320\223\320\223\320\223-\320\234\320\234-\320\224\320\224", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\320\270\320\267\320\262\320\276\320\264\320\270\321\202\320\265\320\273\321\214:", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276 \321\200\320\265\321\206\320\265\320\277\321\202\321\203:", nullptr));
        m_prescriptionCheck->setText(QString());
        label_8->setText(QCoreApplication::translate("MainWindow", "\320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265:", nullptr));
        m_listBtn->setText(QCoreApplication::translate("MainWindow", "GET List", nullptr));
        m_getBtn->setText(QCoreApplication::translate("MainWindow", "GET by ID", nullptr));
        m_createBtn->setText(QCoreApplication::translate("MainWindow", "POST Create", nullptr));
        m_updateBtn->setText(QCoreApplication::translate("MainWindow", "PUT Update", nullptr));
        m_deleteBtn->setText(QCoreApplication::translate("MainWindow", "DELETE", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\262\320\265\321\202 \321\201\320\265\321\200\320\262\320\265\321\200\320\260:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
