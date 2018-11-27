#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore>
#include <QApplication>

// 空白字符串
static const char blankString[] = QT_TRANSLATE_NOOP("SettingsDialog", "N/A");

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // 初始化串口变量
    serial = new QSerialPort;

    QString description;
    QString manufacturer;
    QString serialNumber;

    ui->txtSendFile->setText("fileName");
    // 获取可以用的串口
    QList<QSerialPortInfo> serialPortInfos = QSerialPortInfo::availablePorts();


    // 输出当前系统可以使用的串口个数
    qDebug() << "Total numbers of ports 可用的串口数量: " << serialPortInfos.count();
    // 设置端口选择器文字
    ui->comboBox_serialPort->addItem(tr("端口"));
    // 将所有可以使用的串口设备添加到ComboBox中
    for (const QSerialPortInfo &serialPortInfo : serialPortInfos)
    {
        QStringList list;
        description = serialPortInfo.description();
        manufacturer = serialPortInfo.manufacturer();
        serialNumber = serialPortInfo.serialNumber();

        list << serialPortInfo.portName()
             << (!description.isEmpty() ? description : blankString)
             << (!manufacturer.isEmpty() ? manufacturer : blankString)
             << (!serialNumber.isEmpty() ? serialNumber : blankString)
             << serialPortInfo.systemLocation()
             << (serialPortInfo.vendorIdentifier() ? QString::number(serialPortInfo.vendorIdentifier(), 16) : blankString)
             << (serialPortInfo.productIdentifier() ? QString::number(serialPortInfo.productIdentifier(), 16) : blankString);

        ui->comboBox_serialPort->addItem(list.first(), list);
    }

    // 设置波特率
    ui->comboBox_baudRate->addItem(tr("波特率"));

    ui->comboBox_baudRate->addItem(QStringLiteral("1200"), QSerialPort::Baud1200);
    ui->comboBox_baudRate->addItem(QStringLiteral("2400"), QSerialPort::Baud2400);
    ui->comboBox_baudRate->addItem(QStringLiteral("4800"), QSerialPort::Baud4800);
    ui->comboBox_baudRate->addItem(QStringLiteral("9600"), QSerialPort::Baud9600);
    ui->comboBox_baudRate->addItem(QStringLiteral("19200"), QSerialPort::Baud19200);
    ui->comboBox_baudRate->addItem(QStringLiteral("38400"), QSerialPort::Baud38400);
    ui->comboBox_baudRate->addItem(QStringLiteral("57600"), QSerialPort::Baud57600);
    ui->comboBox_baudRate->addItem(QStringLiteral("115200"), QSerialPort::Baud115200);

}

MainWindow::~MainWindow()
{
    delete ui;
}


// 打开串口
void MainWindow::on_openSerialBtn_clicked()
{
    qDebug("打开串口");

    if (ui->openSerialBtn->text() == tr("打开串口")) {

        //设置串口名字
        serial->setPortName(ui->comboBox_serialPort->currentText());
        //设置波特率
        serial->setBaudRate(ui->comboBox_baudRate->currentText().toInt());
        //设置数据位
        serial->setDataBits(QSerialPort::Data8);
        //设置奇偶校验位
        serial->setParity(QSerialPort::NoParity);
        //设置停止位
        serial->setStopBits(QSerialPort::OneStop);
        //设置流控
        serial->setFlowControl(QSerialPort::NoFlowControl);
        //
        if(serial->open(QIODevice::ReadWrite)) {
            //关闭可选按钮
    //        ui->comboBox_baudRate->setEnabled(false);
    //        ui->comboBox_dataBits->setEnabled(false);
    //        ui->comboBox_flowBit->setEnabled(false);
    //        ui->comboBox_parity->setEnabled(false);
    //        ui->comboBox_serialPort->setEnabled(false);
    //        ui->comboBox_stopBit->setEnabled(false);
            //发送按钮打开
    //        ui->btn_send->setEnabled(true);
            //打开串口变成关闭串口
    //        ui->btn_openConsole->setText(tr("关闭串口"));
            //
            //信号与槽函数关联
            connect(serial, &QSerialPort::readyRead, this, &MainWindow::readData);
        }

    } else {
        //关闭串口
        //serial->clear();
        serial->close();
        //serial->deleteLater();

        //恢复设置功能
//        ui->comboBox_baudRate->setEnabled(true);
//        ui->comboBox_dataBits->setEnabled(true);
//        ui->comboBox_flowBit->setEnabled(true);
//        ui->comboBox_parity->setEnabled(true);
//        ui->comboBox_serialPort->setEnabled(true);
//        ui->comboBox_stopBit->setEnabled(true);

//        ui->btn_openConsole->setText(tr("打开串口"));
//        ui->btn_send->setEnabled(false);

    }




}

// 打开文件 读取文件大小
void MainWindow::on_openFileBtn_clicked()
{
    QString filter = "所有文件 (*.*)";
    // 打开文件
    QString fileName = QFileDialog::getOpenFileName(0, "选择文件", QCoreApplication::applicationDirPath(), filter);
    // 显示选定的文件
    ui->txtSendFile->setText(fileName);
    // 读取文件大小
    QFileInfo info(fileName);
    qDebug() << "选定文件的大小 : " << info.size();
    // 文件大小换算成16进制

    // 文件的大小
    QString fileSize = QString("%1").arg(info.size(),4,16,QLatin1Char('0'));
    qDebug() << "选定文件的大小 16进制 : " << fileSize;

    ui->labelFileSize->setText(fileSize);
}

//void MainWindow::writeData(const QByteArray &data)
//{
//    serial->write(data);
//}


// Read Data
void MainWindow::readData()
{
    // https://blog.csdn.net/zn2857/article/details/79001122

    QByteArray temp = serial->readAll();
    QString buf;

    if (!temp.isEmpty()) {
        // 读取信息不为空
        //ui->textBrowser->setTextColor(Qt::black);

        for(int i = 0; i < temp.count(); i++) {
            QString s;
            s.sprintf("%02X ", (unsigned char)temp.at(i));
            buf += s;
        }

//        ui->textBrowser->append(buf);

//        QTextCursor cursor = ui->textBrowser->textCursor();
//        cursor.movePosition(QTextCursor::End);
//        ui->textBrowser->setTextCursor(cursor);

//        ui->receivebyteLcdNumber->display(ui->receivebyteLcdNumber->value() + temp.size());


       //ui->statusBar->showMessage(tr("成功读取%1字节数据").arg(temp.size()));






    }
}
