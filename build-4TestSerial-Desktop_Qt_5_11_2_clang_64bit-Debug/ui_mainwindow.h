/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label;
    QComboBox *comboBox_serialPort;
    QLabel *label_2;
    QComboBox *comboBox_baudRate;
    QLabel *label_3;
    QComboBox *comboBox_dataBits;
    QLabel *label_4;
    QComboBox *comboBox_parity;
    QLabel *label_5;
    QComboBox *comboBox_stopBit;
    QLabel *label_6;
    QComboBox *comboBox_flowBit;
    QSpacerItem *verticalSpacer;
    QPushButton *btn_openConsole;
    QGroupBox *groupBox_2;
    QLabel *label_7;
    QTextEdit *textEdit_recv;
    QLabel *label_8;
    QTextEdit *textEdit_send;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *btn_send;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_clearSend;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btn_clearRecv;
    QSpacerItem *horizontalSpacer_3;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(658, 460);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(0, 0, 171, 401));
        widget = new QWidget(groupBox);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 40, 147, 351));
        gridLayout = new QGridLayout(widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(54, 0));
        label->setMaximumSize(QSize(54, 16777215));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        comboBox_serialPort = new QComboBox(widget);
        comboBox_serialPort->setObjectName(QStringLiteral("comboBox_serialPort"));
        comboBox_serialPort->setMinimumSize(QSize(69, 0));
        comboBox_serialPort->setMaximumSize(QSize(69, 16777215));

        gridLayout->addWidget(comboBox_serialPort, 0, 1, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(54, 0));
        label_2->setMaximumSize(QSize(54, 16777215));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        comboBox_baudRate = new QComboBox(widget);
        comboBox_baudRate->setObjectName(QStringLiteral("comboBox_baudRate"));
        comboBox_baudRate->setMinimumSize(QSize(69, 0));
        comboBox_baudRate->setMaximumSize(QSize(69, 16777215));

        gridLayout->addWidget(comboBox_baudRate, 1, 1, 1, 1);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(54, 0));
        label_3->setMaximumSize(QSize(54, 16777215));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        comboBox_dataBits = new QComboBox(widget);
        comboBox_dataBits->setObjectName(QStringLiteral("comboBox_dataBits"));
        comboBox_dataBits->setMinimumSize(QSize(69, 0));
        comboBox_dataBits->setMaximumSize(QSize(69, 16777215));

        gridLayout->addWidget(comboBox_dataBits, 2, 1, 1, 1);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(54, 0));
        label_4->setMaximumSize(QSize(54, 16777215));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        comboBox_parity = new QComboBox(widget);
        comboBox_parity->setObjectName(QStringLiteral("comboBox_parity"));
        comboBox_parity->setMinimumSize(QSize(69, 0));
        comboBox_parity->setMaximumSize(QSize(69, 16777215));

        gridLayout->addWidget(comboBox_parity, 3, 1, 1, 1);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMinimumSize(QSize(54, 0));
        label_5->setMaximumSize(QSize(54, 16777215));

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        comboBox_stopBit = new QComboBox(widget);
        comboBox_stopBit->setObjectName(QStringLiteral("comboBox_stopBit"));
        comboBox_stopBit->setMinimumSize(QSize(69, 0));
        comboBox_stopBit->setMaximumSize(QSize(69, 16777215));

        gridLayout->addWidget(comboBox_stopBit, 4, 1, 1, 1);

        label_6 = new QLabel(widget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMinimumSize(QSize(54, 0));
        label_6->setMaximumSize(QSize(54, 16777215));

        gridLayout->addWidget(label_6, 5, 0, 1, 1);

        comboBox_flowBit = new QComboBox(widget);
        comboBox_flowBit->setObjectName(QStringLiteral("comboBox_flowBit"));
        comboBox_flowBit->setMinimumSize(QSize(69, 0));
        comboBox_flowBit->setMaximumSize(QSize(69, 16777215));

        gridLayout->addWidget(comboBox_flowBit, 5, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 145, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 6, 0, 1, 2);

        btn_openConsole = new QPushButton(widget);
        btn_openConsole->setObjectName(QStringLiteral("btn_openConsole"));

        gridLayout->addWidget(btn_openConsole, 7, 0, 1, 2);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(180, 0, 461, 401));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(20, 20, 54, 12));
        textEdit_recv = new QTextEdit(groupBox_2);
        textEdit_recv->setObjectName(QStringLiteral("textEdit_recv"));
        textEdit_recv->setGeometry(QRect(20, 40, 431, 131));
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(30, 180, 54, 12));
        textEdit_send = new QTextEdit(groupBox_2);
        textEdit_send->setObjectName(QStringLiteral("textEdit_send"));
        textEdit_send->setGeometry(QRect(20, 200, 431, 151));
        widget1 = new QWidget(groupBox_2);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(30, 370, 423, 25));
        horizontalLayout = new QHBoxLayout(widget1);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        btn_send = new QPushButton(widget1);
        btn_send->setObjectName(QStringLiteral("btn_send"));

        horizontalLayout->addWidget(btn_send);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btn_clearSend = new QPushButton(widget1);
        btn_clearSend->setObjectName(QStringLiteral("btn_clearSend"));

        horizontalLayout->addWidget(btn_clearSend);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        btn_clearRecv = new QPushButton(widget1);
        btn_clearRecv->setObjectName(QStringLiteral("btn_clearRecv"));

        horizontalLayout->addWidget(btn_clearRecv);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 658, 23));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "\344\270\262\345\217\243\345\217\202\346\225\260\351\205\215\347\275\256", nullptr));
        label->setText(QApplication::translate("MainWindow", "\347\253\257\345\217\243\345\217\267\357\274\232", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\346\263\242\347\211\271\347\216\207\357\274\232", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "\346\225\260\346\215\256\344\275\215\357\274\232", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "\346\240\241\351\252\214\344\275\215\357\274\232", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "\345\201\234\346\255\242\344\275\215\357\274\232", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "\346\265\201\346\216\247\344\275\215\357\274\232", nullptr));
        btn_openConsole->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\344\270\262\345\217\243", nullptr));
        groupBox_2->setTitle(QString());
        label_7->setText(QApplication::translate("MainWindow", "\346\216\245\346\224\266\346\225\260\346\215\256", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201\346\225\260\346\215\256", nullptr));
        btn_send->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201\346\225\260\346\215\256", nullptr));
        btn_clearSend->setText(QApplication::translate("MainWindow", "\346\270\205\347\251\272\345\217\221\351\200\201\345\214\272", nullptr));
        btn_clearRecv->setText(QApplication::translate("MainWindow", "\346\270\205\347\251\272\346\216\245\346\224\266\345\214\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
