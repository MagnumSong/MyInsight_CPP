/****************************************************************************
 **
 ** Copyright (C) 2012 Denis Shienkov <denis.shienkov@gmail.com>
 ** Copyright (C) 2012 Laszlo Papp <lpapp@kde.org>
 ** Contact: https://www.qt.io/licensing/
 **
 ** This file is part of the QtSerialPort module of the Qt Toolkit.
 **
 ** $QT_BEGIN_LICENSE:BSD$
 ** Commercial License Usage
 ** Licensees holding valid commercial Qt licenses may use this file in
 ** accordance with the commercial license agreement provided with the
 ** Software or, alternatively, in accordance with the terms contained in
 ** a written agreement between you and The Qt Company. For licensing terms
 ** and conditions see https://www.qt.io/terms-conditions. For further
 ** information use the contact form at https://www.qt.io/contact-us.
 **
 ** BSD License Usage
 ** Alternatively, you may use this file under the terms of the BSD license
 ** as follows:
 **
 ** "Redistribution and use in source and binary forms, with or without
 ** modification, are permitted provided that the following conditions are
 ** met:
 **   * Redistributions of source code must retain the above copyright
 **     notice, this list of conditions and the following disclaimer.
 **   * Redistributions in binary form must reproduce the above copyright
 **     notice, this list of conditions and the following disclaimer in
 **     the documentation and/or other materials provided with the
 **     distribution.
 **   * Neither the name of The Qt Company Ltd nor the names of its
 **     contributors may be used to endorse or promote products derived
 **     from this software without specific prior written permission.
 **
 **
 ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
 **
 ** $QT_END_LICENSE$
 **
 ****************************************************************************/

#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "console.h"
#include "settingsdialog.h"

#include <QMessageBox>
#include <QLabel>
#include <QtSerialPort/QSerialPort>

#include <QFile>
#include <QFileDialog>
#include <QDir>
#include <QTextStream>
#include <QDataStream>
#include <QTimer>


#define APP_DISPLAY_SIZE 64

//! [0]
MainWindow::MainWindow(QWidget *parent) :
QMainWindow(parent),
ui(new Ui::MainWindow)
{
    //! [0]
    ui->setupUi(this);
    //    console = new Console;
    //    console->setEnabled(false);
    //    setCentralWidget(console);
    //! [1]
    serial = new QSerialPort(this);
    //! [1]
    settings = new SettingsDialog;
    
    ui->actionConnect->setEnabled(true);
    ui->actionDisconnect->setEnabled(false);
    ui->actionQuit->setEnabled(true);
    ui->actionConfigure->setEnabled(true);
    
    status = new QLabel;
    ui->statusBar->addWidget(status);
    
    initActionsConnections();
    
    connect(serial, static_cast<void (QSerialPort::*)(QSerialPort::SerialPortError)>(&QSerialPort::error),
            this, &MainWindow::handleError);
    
    //! [2]
    connect(serial, &QSerialPort::readyRead, this, &MainWindow::readData);
    //! [2]
    //    connect(console, &Console::getData, this, &MainWindow::writeData);
    //! [3]
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timerTransDate()));
    ulNum = 0;
    //timer->start(1000);
    //setCentralWidget(MainWindow);
}
//! [3]

MainWindow::~MainWindow()
{
    delete settings;
    delete ui;
}


//! [4] 打开串口
void MainWindow::openSerialPort()
{
    // 设置串口变量信息
    SettingsDialog::Settings p = settings->settings();
    serial->setPortName(p.name);
    serial->setBaudRate(p.baudRate);
    serial->setDataBits(p.dataBits);
    serial->setParity(p.parity);
    serial->setStopBits(p.stopBits);
    serial->setFlowControl(p.flowControl);
    if (serial->open(QIODevice::ReadWrite)) {
        //        console->setEnabled(true);
        //        console->setLocalEchoEnabled(p.localEchoEnabled);
        ui->actionConnect->setEnabled(false);
        ui->actionDisconnect->setEnabled(true);
        ui->actionConfigure->setEnabled(false);
        showStatusMessage(tr("Connected to %1 : %2, %3, %4, %5, %6")
                          .arg(p.name).arg(p.stringBaudRate).arg(p.stringDataBits)
                          .arg(p.stringParity).arg(p.stringStopBits).arg(p.stringFlowControl));
    } else {
        QMessageBox::critical(this, tr("Error"), serial->errorString());
        
        showStatusMessage(tr("Open error"));
    }
}
//! [4]

//! [5] 关闭串口
void MainWindow::closeSerialPort()
{
    if (serial->isOpen())
        serial->close();
    //    console->setEnabled(false);
    ui->actionConnect->setEnabled(true);
    ui->actionDisconnect->setEnabled(false);
    ui->actionConfigure->setEnabled(true);
    showStatusMessage(tr("Disconnected"));
}
//! [5]

void MainWindow::about()
{
    QMessageBox::about(this, tr("About Simple Terminal"),
                       tr("The <b>Simple Terminal</b> example demonstrates how to "
                          "use the Qt Serial Port module in modern GUI applications "
                          "using Qt, with a menu bar, toolbars, and a status bar."));
}

//! [6] 写数据
void MainWindow::writeData(const QByteArray &data)
{
    serial->write(data);
}
//! [6]

//! [7] 读数据
void MainWindow::readData()
{
    //    QByteArray data = serial->readAll();
    
    //    console->putData(data);
    QByteArray temp = serial->readAll();
    QString buf;
    
    if(!temp.isEmpty()){
        ui->textBrowser->setTextColor(Qt::black);
        //                if(chrReceive->isChecked()){
        //                    buf = temp;
        //                }else if(hexReceive->isChecked()){
        for(int i = 0; i < temp.count(); i++){
            QString s;
            s.sprintf("%02X ", (unsigned char)temp.at(i));
            buf += s;
        }
        //                }
        //ui->textBrowser->setText(ui->textBrowser->document()->toPlainText() + buf);
        ui->textBrowser->append(buf);
        
        QTextCursor cursor = ui->textBrowser->textCursor();
        cursor.movePosition(QTextCursor::End);
        ui->textBrowser->setTextCursor(cursor);
        
        ui->receivebyteLcdNumber->display(ui->receivebyteLcdNumber->value() + temp.size());
        //ui->statusBar->showMessage(tr("成功读取%1字节数据").arg(temp.size()));
    }
    
}
//! [7]

//! [8] 处理错误
void MainWindow::handleError(QSerialPort::SerialPortError error)
{
    if (error == QSerialPort::ResourceError) {
        QMessageBox::critical(this, tr("Critical Error"), serial->errorString());
        closeSerialPort();
    }
}
//! [8] 初始化槽信息

void MainWindow::initActionsConnections()
{
    // 打开串口槽函数
    connect(ui->actionConnect, &QAction::triggered, this, &MainWindow::openSerialPort);
    // 关闭串口槽函数
    connect(ui->actionDisconnect, &QAction::triggered, this, &MainWindow::closeSerialPort);
    connect(ui->actionQuit, &QAction::triggered, this, &MainWindow::close);
    connect(ui->actionConfigure, &QAction::triggered, settings, &SettingsDialog::show);
    connect(ui->actionClear, &QAction::triggered, this, &MainWindow::clearTextBrowser);
    connect(ui->actionAbout, &QAction::triggered, this, &MainWindow::about);
    connect(ui->actionAboutQt, &QAction::triggered, qApp, &QApplication::aboutQt);
}

// 显示状态信息
void MainWindow::showStatusMessage(const QString &message)
{
    status->setText(message);
}


void MainWindow::on_pushButton_clicked()
{
    // 开始定时器
    timer->start(500);
}

// 清理文本
void MainWindow::clearTextBrowser()
{
    ui->textBrowser->setText(NULL);
}

// 打开文件button
void MainWindow::on_openFileButton_clicked()
{
    //get file name
    fileName = QFileDialog::getOpenFileName(this,"Open File",QDir::currentPath());
    //    qDebug()<< "fileName is" << fileName;
    ui->filePathLineEdit->setText (fileName);
    if(fileName.isEmpty())
    {
        QMessageBox::information(this,"Error Message", "Please Select a Text File");
        return;
    }
    QFileInfo *pcsfileInfo = new QFileInfo(fileName);
    // 文件大小
    binSize = pcsfileInfo->size ();
    // 获取到文件
    QFile* file = new QFile;
    file->setFileName(fileName);
    bool ok = file->open(QIODevice::ReadOnly);
    if(ok)
    {
        //        QTextStream in(file);
        //        ui->textEdit->setText(in.readAll());//read all context from the file
    }
    else
    {
        QMessageBox::information(this,"Error Message", "File Open Error" + file->errorString());
        return;
    }
    QDataStream in(file);
    char * binByte = new char[binSize];
    in.setVersion (QDataStream::Qt_5_9);
    
    ui->statusBar->showMessage(tr("准备读取数据"));
    in.readRawData (binByte, binSize);      //读出文件到缓存
    ui->statusBar->showMessage(tr("读取数据完毕"));
    // 数据格式转换
    tempByte = new QByteArray(binByte, binSize);
    
    QString *tempStr = new QString(tempByte->toHex ().toUpper ());
    
    //显示文件内容
    qint8 cnt = 1;
    qint16 kcnt = 0;
    for(qint64 i = 2; i < tempStr->size ();)
    {
        tempStr->insert (i, ' ');//每个字节之间空一格
        i += 3;
        cnt++;
        if(cnt == 8)//每8个字节空2格
        {
            tempStr->insert (i, ' ');
            i += 1;
        }
        if(cnt == 16)//每16个字节空一格
        {
            cnt = 1;
            kcnt ++;
            if(kcnt == 64)//每64行，即1K数据，空一行
            {
                kcnt = 0;
                tempStr->insert (i, '\n');
                i++;
            }
            tempStr->insert (i, '\n');
            i += 3;         //避免换行后开头一个空格,换行相当于从新插入
        }
        
    }
    ui->statusBar->showMessage(tr("准备显示"));
    ui->fileViewPlainTextEdit->insertPlainText (*tempStr);
    ui->statusBar->showMessage(tr("显示完毕"));
    
    //timer->start(1000);
    //serial->write(binByte,25);
    delete tempByte;
    delete[] binByte;
    delete tempStr;
    
    // 文件关闭
    file->close ();
    delete file;
}

//
void MainWindow::timerTransDate()
{
    qint16 temp = 0;            //剩余待传数据
    qint16 FileSendEndFg;
    
    
    QFile *binFile = new QFile(fileName);
    binFile->open (QIODevice::ReadOnly);
    binFile->seek (ulNum * 1024);
    
    QDataStream in(binFile);
    //
    char * binByte = new char[binSize];
    in.setVersion (QDataStream::Qt_5_9);
    
    in.readRawData (binByte, binSize);      //读出文件到缓存
    
    char * binLitByte = new char[64];//bin缓存
    static int binfileseek = 0;
    
    if(binfileseek > binSize)
    {
        binfileseek = 0;
        timer->stop();
        return;
    }
    memcpy (binLitByte, binByte + binfileseek, 64);
    binfileseek += 64;
    
    temp = binSize - 1024*ulNum;
    
    serial->write(binLitByte,64);
    
    delete binByte;
    
}
