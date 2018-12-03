#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore>
#include <QApplication>
//定时器
#include <QTimer>
#include <QDir>

// 空白字符串
static const char blankString[] = QT_TRANSLATE_NOOP("SettingsDialog", "N/A");

/*
发送命令：55 50 46 57 74 A4 00 00 0D 0A
*/

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
    // 设置数据位
    ui->comboBox_dataBits->addItem(QStringLiteral("5"), QSerialPort::Data5);
    ui->comboBox_dataBits->addItem(QStringLiteral("6"), QSerialPort::Data6);
    ui->comboBox_dataBits->addItem(QStringLiteral("7"), QSerialPort::Data7);
    ui->comboBox_dataBits->addItem(QStringLiteral("8"), QSerialPort::Data8);
    ui->comboBox_dataBits->setCurrentIndex(3);

    // 设置奇偶校验位
    ui->comboBox_parity->addItem(tr("None"), QSerialPort::NoParity);
    ui->comboBox_parity->addItem(tr("Even"), QSerialPort::EvenParity);
    ui->comboBox_parity->addItem(tr("Odd"), QSerialPort::OddParity);
    ui->comboBox_parity->addItem(tr("Mark"), QSerialPort::MarkParity);
    ui->comboBox_parity->addItem(tr("Space"), QSerialPort::SpaceParity);

    // 设置停止位
    ui->comboBox_stopBit->addItem(QStringLiteral("1"), QSerialPort::OneStop);
    ui->comboBox_stopBit->addItem(QStringLiteral("2"), QSerialPort::TwoStop);

    // 添加流控
    ui->comboBox_flowBit->addItem(tr("None"), QSerialPort::NoFlowControl);
    ui->comboBox_flowBit->addItem(tr("RTS/CTS"), QSerialPort::HardwareControl);
    ui->comboBox_flowBit->addItem(tr("XON/XOFF"), QSerialPort::SoftwareControl);

    // 禁用发送按钮
    ui->sendButton->setEnabled(false);
    // 发送定时器
    timer = new QTimer(this);
    // 设置槽函数
    connect(timer,SIGNAL(timeout()),this,SLOT(timerTransDate()));
    // 发送命令 关联信号槽
    //connect(ui->sendCmdBtn, &QPushButton::clicked, this, &MainWindow::sendCmdButtonClicked);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_openSerialBtn_clicked()
{
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
            ui->comboBox_baudRate->setEnabled(false);
            ui->comboBox_dataBits->setEnabled(false);
            ui->comboBox_flowBit->setEnabled(false);
            ui->comboBox_parity->setEnabled(false);
            ui->comboBox_serialPort->setEnabled(false);
            ui->comboBox_stopBit->setEnabled(false);
            //发送按钮打开
            ui->sendButton->setEnabled(true);
            //打开串口变成关闭串口
            ui->openSerialBtn->setText(tr("关闭串口"));
            //
            //信号与槽函数关联
            connect(serial, &QSerialPort::readyRead, this, &MainWindow::readData);
        }

    } else {
        //关闭串口
        serial->clear();
        serial->close();
        serial->deleteLater();

        //恢复设置功能
        ui->comboBox_baudRate->setEnabled(true);
        ui->comboBox_dataBits->setEnabled(true);
        ui->comboBox_flowBit->setEnabled(true);
        ui->comboBox_parity->setEnabled(true);
        ui->comboBox_serialPort->setEnabled(true);
        ui->comboBox_stopBit->setEnabled(true);

        ui->openSerialBtn->setText(tr("打开串口"));
        ui->sendButton->setEnabled(false);
    }
}


// 打开文件 读取文件大小
void MainWindow::on_openFileBtn_clicked()
{
    QString filter = "所有文件 (*.*)";
    // 打开文件
    //QString fileName = QFileDialog::getOpenFileName(0, "选择文件", QCoreApplication::applicationDirPath(), filter);
    fileName = QFileDialog::getOpenFileName(this, "Open File", QDir::currentPath());
    // 显示选定的文件
    ui->txtSendFile->setText(fileName);
    // 读取文件大小
    QFileInfo *fileInfo = new QFileInfo(fileName);
    //int fileSize = fileInfo->size(); // qint64
    // bin文件大小qint64转int类型
    binSize = QStringLiteral("%1").arg(fileInfo->size()).toInt();

    qDebug() << "选定文件的大小 : " << binSize;
    // 文件大小换算成16进制
    qDebug() << "选定文件的大小 16进制 : " << QString("%1").arg(binSize,4,16,QLatin1Char('0'));

    ui->labelFileSize->setText(QString("%1").arg(binSize,4,16,QLatin1Char('0')));

    // 获取到文件
    QFile *file = new QFile;
    // 设置文件信息
    file->setFileName(fileName);
    bool ok = file->open(QIODevice::ReadOnly);
    if (ok) {
        //
    } else {
        //
    }

    //
    QDataStream stream(file);
    char *binByte = new char[binSize];
    // 文件状态更新

    // 读取文件到缓存
    stream.readRawData(binByte, binSize);

    // 数据格式转换
    tempByte = new QByteArray(binByte, binSize);

    QString *tempStr = new QString(tempByte->toHex().toUpper());

    // 显示文件内容
    qint8 cnt = 1;
    qint16 kcnt = 0;
    //
    for(qint64 i = 2; i < tempStr->size ();)
    {
        tempStr->insert(i, ' ');//每个字节之间空一格
        i += 3;
        cnt++;
        if(cnt == 8)//每8个字节空2格
        {
            tempStr->insert(i, ' ');
            i += 1;
        }
        if(cnt == 16)//每16个字节空一格
        {
            cnt = 1;
            kcnt ++;
            if(kcnt == 64)//每64行，即1K数据，空一行
            {
                kcnt = 0;
                tempStr->insert(i, '\n');
                i++;
            }
            tempStr->insert(i, '\n');
            i += 3;         //避免换行后开头一个空格,换行相当于从新插入
        }
    }

    ui->statusBar->showMessage(tr("准备显示"));
    //ui->fileViewPlainTextEdit->insertPlainText (*tempStr);
    ui->statusBar->showMessage(tr("显示完毕"));

    delete tempByte;
    delete[] binByte;
    delete tempStr;

    // 文件关闭
    file->close ();
    delete file;
}


// Read Data
void MainWindow::readData()
{
    QByteArray temp = serial->readAll();
    QString buf;

    qDebug() << "readData: " << temp;


    if (!temp.isEmpty()) {
        // 读取信息不为空
        ui->textBrowser->setTextColor(Qt::black);

        for(int i = 0; i < temp.count(); i++) {
            QString s;
            s.sprintf("%02X ", (unsigned char)temp.at(i));
            buf += s;
        }

        // 文本显示
        ui->textBrowser->append(buf);

        QTextCursor cursor = ui->textBrowser->textCursor();
        cursor.movePosition(QTextCursor::End);
        ui->textBrowser->setTextCursor(cursor);
        // 接收到数据的大小
        ui->statusBar->showMessage(tr("成功读取%1字节数据").arg(temp.size()));
    }
}


void MainWindow::on_sendButton_clicked()
{
    // 先发送命令给串口
    //serial->write(ui->textEdit_send->toPlainText().toLatin1());

    // 55 50 46 57 74 A4 00 00 0D 0A
    QString cmdStr = "55 50 46 57 74 A4 00 00 0D 0A";

    serial->write("cmdStr");

    // 开始定时器
    //timer->start(500);



}


// 定时器方法
void MainWindow::timerTransDate()
{
    //qDebug("定时器阿");
    qDebug() << "定时器阿 " << 11;

    qint16 temp = 0;
    qint16 FileSendEndFg;

    QFile *binFile = new QFile(fileName);
    binFile->open (QIODevice::ReadOnly);
    binFile->seek (ulNum * 1024);

    QDataStream in(binFile);
    //
    char * binByte = new char[binSize];
    in.setVersion (QDataStream::Qt_5_9);

    in.readRawData (binByte, binSize);      //读出文件到缓存

    char * binLitByte = new char[64]; //bin缓存
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
