#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    // 窗口可见
    w.show();

    return a.exec();
}


/*
[Qt界面开发（各种控件以及图表）](https://blog.csdn.net/zhangxiaoyu_sy/article/details/78925221)
*/
