#include "mainwindow.h"
#include <QApplication>
#include <QLabel>

#pragma mark 快速排序

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QLabel *label = new QLabel(&w);
    label->setText("滚滚长江东逝水");
    label->resize(200, 20);
    label->move(120, 120);

    w.show();

    // 进程
    return a.exec();
}












