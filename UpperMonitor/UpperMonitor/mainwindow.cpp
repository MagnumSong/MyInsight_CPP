#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include <QtCore>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // 初始化串口变量
    serial = new QSerialPort;

}

MainWindow::~MainWindow()
{
    delete ui;




}




/*
打开串口-〉设置串口
打开文件-〉选定文件-〉读取文件大小-〉发送文件
*/


// 打开串口button的动作方法
void MainWindow::on_openSerialBtn_clicked()
{
    qDebug("打开串口");

}

// 打开文件 读取文件大小
void MainWindow::on_openFileBtn_clicked()
{
    QString filter = "所有文件 (*.*)";
    // 打开文件
    QString fileName = QFileDialog::getOpenFileName(0, "选择文件", QCoreApplication::applicationDirPath(), filter);


}



