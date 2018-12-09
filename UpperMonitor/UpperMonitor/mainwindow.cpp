#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore>
#include <QApplication>
//定时器
#include <QTimer>
#include <QDir>
#include <QString>

// 空白字符串
static const char blankString[] = QT_TRANSLATE_NOOP("SettingsDialog", "N/A");
// 默认发送字节大小
static const int sendByteSize = 1024;
// 延时毫秒数
static const int delayTimeMS = 50;

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
    ui->comboBox_serialPort->setCurrentIndex(1);

    // 设置波特率
    ui->comboBox_baudRate->addItem(QStringLiteral("1200"), QSerialPort::Baud1200);
    ui->comboBox_baudRate->addItem(QStringLiteral("2400"), QSerialPort::Baud2400);
    ui->comboBox_baudRate->addItem(QStringLiteral("4800"), QSerialPort::Baud4800);
    ui->comboBox_baudRate->addItem(QStringLiteral("9600"), QSerialPort::Baud9600);
    ui->comboBox_baudRate->addItem(QStringLiteral("19200"), QSerialPort::Baud19200);
    ui->comboBox_baudRate->addItem(QStringLiteral("38400"), QSerialPort::Baud38400);
    ui->comboBox_baudRate->addItem(QStringLiteral("57600"), QSerialPort::Baud57600);
    ui->comboBox_baudRate->addItem(QStringLiteral("115200"), QSerialPort::Baud115200);
    ui->comboBox_baudRate->setCurrentIndex(7);
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

    // 定时器
    timer = new QTimer(this);
    // 设置槽函数
    connect(timer,SIGNAL(timeout()),this,SLOT(timerTransDate()));
    //
    connect(ui->clearTextBtn,&QPushButton::clicked,this,&MainWindow::clearTextBtnClicked);

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
        //定时器停止
        timer->stop();
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
    // bin文件大小qint64转int类型
    binSize = QStringLiteral("%1").arg(fileInfo->size()).toInt();

    qDebug() << "选定文件的大小 : " << binSize;
    // 文件大小换算成16进制
    qDebug() << "选定文件的大小 16进制 : " << QString("%1").arg(binSize,4,16,QLatin1Char('0'));
    // 文件大小显示
    ui->labelFileSize->setText("文件大小:" + QString::number(binSize));

    // 获取到文件
    QFile *file = new QFile;
    // 设置文件信息
    file->setFileName(fileName);

    if (!file->open(QIODevice::ReadWrite)) {
        // 打开文件失败
        return;
    } else {
        qDebug() << "打开二进制文件 : " << "打开文件成功";
    }

    QDataStream stream(file);
    char *binByte = new char[binSize];

    // 读取文件到缓存
    stream.readRawData(binByte, binSize);
    // 数据格式转换
    tempByte = new QByteArray(binByte, binSize);

    QString *tempStr = new QString(tempByte->toHex().toUpper());

    // 显示文件内容
//    qint8 cnt = 1;
//    qint16 kcnt = 0;
    //
//    for(qint64 i = 2; i < tempStr->size ();)
//    {
//        tempStr->insert(i, ' ');//每个字节之间空一格
//        i += 3;
//        cnt++;
//    }

    ui->statusBar->showMessage(tr("准备显示"));
    //ui->textSendBrowser->insertPlainText (*tempStr);
    ui->statusBar->showMessage(tr("显示完毕"));

    //qDebug() << "打开二进制文件 内容 : " << *tempStr;

    delete tempByte;
    delete[] binByte;
    delete tempStr;

    // 文件关闭
    file->close ();
    delete file;
}


// Read Data 读到串口数据
void MainWindow::readData()
{
    // 检测文件是否为空
    if (fileName.isEmpty()) {
        // 检测到文件名为空时 停止下面的命令
        qDebug() << "readData: " << "发送文件为空";
        ui->textBrowser->append("发送文件为空");
        return;
    }

    // 读取串口数据
    QByteArray temp = serial->readAll();
    QString buf;

    qDebug() << "readData: " << temp;

    if (temp.isEmpty()) {
        // 当串口数据为空时
        qDebug() << "readData: " << "当串口数据为空";
        return;
    }

    QString tempStr = temp;
    if (tempStr.contains("Wait for Online Updata:4.....", Qt::CaseSensitive)) {
        // 发送串口命令  A474 -> 74A4
        qDebug() << "readData 准备发送命令: " << "55 50 46 57 74 A4 00 00 0D 0A";
        // 文件大小转十六进制
        QString fileSize = QString::number(binSize, 16).toUpper();
        QByteArray fileSizeArray = fileSize.toLatin1(); //.toHex();
        //
        //qDebug() << "readData 准备发送命令 大小端: " << qFromLittleEndian(binSize->toHex());
        QString charOne = QString("55504657") + fileSize +QString("00000D0A");


        qDebug() << "readData 准备发送命令: " << charOne.toLatin1().data();

        qint8 cnt = 1;
        qint16 kcnt = 0;

        QString tempFileSize;

        for(qint64 i = 2; i < fileSize.size();)
        {
            //tempStr->insert(i, ' ');//每个字节之间空一格
            qDebug() << "readData 准备发送命令: " << charOne.toLatin1().data();
            i += 3;
            cnt++;
        }


        //char *charOne = "55 50 46 57". //fileSizeArray.data();

        //serial->write("55 50 46 57" + fileSizeArray.data() + "00 00 0D 0A");
        serial->write("5550465774A400000D0A");
    }

    if (tempStr.contains("Bey-Bey Bootloader, Jump to App !!! ", Qt::CaseSensitive)) {
        // 发送文件
        qDebug() << "readData: " << "准备发送文件";
        ui->textBrowser->append("准备发送文件");
        // 定时器开启方法 延时毫秒数
        timer->start(delayTimeMS); //
    }
    // 设置文本颜色
    ui->textBrowser->setTextColor(Qt::black);
    // 显示字符串 拼接
    ui->textBrowser->append(temp);

    QTextCursor cursor = ui->textBrowser->textCursor();
    cursor.movePosition(QTextCursor::End);
    ui->textBrowser->setTextCursor(cursor);
    // 接收到数据的大小
    ui->statusBar->showMessage(tr("成功读取%1字节数据").arg(temp.size()));
}

// 定时器方法 定时器转换数据
void MainWindow::timerTransDate()
{
    qint16 temp = 0;
    // 文件名
    QFile *binFile = new QFile(fileName);

    binFile->open (QIODevice::ReadOnly);
    binFile->seek (ulNum * 1024);

    //初始化
    QDataStream stream(binFile);
    char * binByte = new char[binSize];
    //stream.setVersion (QDataStream::Qt_5_9);

    stream.readRawData (binByte, binSize);      //读出文件到缓存
    // 设置每次发送的大小
    char * binLitByte = new char[sendByteSize]; //bin缓存
    static int binfileseek = 0;

    if(binfileseek > binSize)
    {

        qDebug() << "File Size: " << binfileseek;
        binfileseek = 0;
        timer->stop();
        return;
    } else {
        qDebug() << "File Size: " << binfileseek;

    }

    memcpy (binLitByte, binByte + binfileseek, sendByteSize);

    binfileseek += sendByteSize;

    temp = binSize - 1024*ulNum;

    // 写入串口
    serial->write(binLitByte, sendByteSize);
    qDebug() << "写入文件长度: " << binByte + binfileseek;

    delete binByte;
}

void MainWindow::clearTextBtnClicked()
{
    ui->textBrowser->setText(NULL);
}
