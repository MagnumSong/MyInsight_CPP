#include "mainwindow.h"
#include "ui_mainwindow.h"

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
    qDebug("打开文件，读取文件大小");

    //connect(ui->actionopenfilephoto,SIGNAL(triggered()),this,SLOT(OpenFilePhoto()));

    /*
    QString filter = "所有文件 (*.*)";
    ui->txtSendFile->setText(myHelper::GetFileName(filter));

    ui->pbarSendData->setRange(0, 100);
    ui->pbarSendData->setValue(0);
    ui->pbarReceiveData->setRange(0, 100);
    ui->pbarReceiveData->setValue(0);
    */

}



