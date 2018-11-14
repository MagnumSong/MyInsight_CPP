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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGroupBox *gbox3;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *ckHexSend;
    QCheckBox *ckHexReceive;
    QCheckBox *ckIsAutoSend;
    QComboBox *cboxSend;
    QCheckBox *ckIsAutoSave;
    QComboBox *cboxSave;
    QCheckBox *ckIsDebug;
    QCheckBox *ckIsAutoClear;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(653, 443);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gbox3 = new QGroupBox(centralWidget);
        gbox3->setObjectName(QStringLiteral("gbox3"));
        gbox3->setGeometry(QRect(20, 20, 167, 185));
        verticalLayout_2 = new QVBoxLayout(gbox3);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(3, 3, 3, 3);
        ckHexSend = new QCheckBox(gbox3);
        ckHexSend->setObjectName(QStringLiteral("ckHexSend"));
        ckHexSend->setChecked(true);

        verticalLayout_2->addWidget(ckHexSend);

        ckHexReceive = new QCheckBox(gbox3);
        ckHexReceive->setObjectName(QStringLiteral("ckHexReceive"));
        ckHexReceive->setChecked(true);

        verticalLayout_2->addWidget(ckHexReceive);

        ckIsAutoSend = new QCheckBox(gbox3);
        ckIsAutoSend->setObjectName(QStringLiteral("ckIsAutoSend"));

        verticalLayout_2->addWidget(ckIsAutoSend);

        cboxSend = new QComboBox(gbox3);
        cboxSend->setObjectName(QStringLiteral("cboxSend"));

        verticalLayout_2->addWidget(cboxSend);

        ckIsAutoSave = new QCheckBox(gbox3);
        ckIsAutoSave->setObjectName(QStringLiteral("ckIsAutoSave"));

        verticalLayout_2->addWidget(ckIsAutoSave);

        cboxSave = new QComboBox(gbox3);
        cboxSave->setObjectName(QStringLiteral("cboxSave"));

        verticalLayout_2->addWidget(cboxSave);

        ckIsDebug = new QCheckBox(gbox3);
        ckIsDebug->setObjectName(QStringLiteral("ckIsDebug"));

        verticalLayout_2->addWidget(ckIsDebug);

        ckIsAutoClear = new QCheckBox(gbox3);
        ckIsAutoClear->setObjectName(QStringLiteral("ckIsAutoClear"));

        verticalLayout_2->addWidget(ckIsAutoClear);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 653, 22));
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
        gbox3->setTitle(QApplication::translate("MainWindow", "\346\225\260\346\215\256\350\256\276\347\275\256", nullptr));
        ckHexSend->setText(QApplication::translate("MainWindow", "\345\215\201\345\205\255\350\277\233\345\210\266\346\225\260\346\215\256\345\217\221\351\200\201", nullptr));
        ckHexReceive->setText(QApplication::translate("MainWindow", "\345\215\201\345\205\255\350\277\233\345\210\266\346\225\260\346\215\256\346\216\245\346\224\266", nullptr));
        ckIsAutoSend->setText(QApplication::translate("MainWindow", "\345\220\257\347\224\250\350\207\252\345\212\250\345\217\221\351\200\201\346\225\260\346\215\256", nullptr));
        ckIsAutoSave->setText(QApplication::translate("MainWindow", "\345\220\257\347\224\250\350\207\252\345\212\250\344\277\235\345\255\230\346\225\260\346\215\256", nullptr));
        ckIsDebug->setText(QApplication::translate("MainWindow", "\346\250\241\346\213\237\350\256\276\345\244\207\345\233\236\345\244\215\346\225\260\346\215\256", nullptr));
        ckIsAutoClear->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201\346\225\260\346\215\256\350\207\252\345\212\250\346\270\205\347\251\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
