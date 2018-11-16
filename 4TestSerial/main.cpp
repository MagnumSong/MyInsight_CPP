#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}

/*
[Qt5.8中串口类QSerialPort](https://blog.csdn.net/dengjin20104042056/article/details/82151545)
*/
