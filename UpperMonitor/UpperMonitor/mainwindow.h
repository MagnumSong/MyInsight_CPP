#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
// 串口头文件
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
// 打印
#include <QDebug>

#include <QtWidgets>
// 获取文件信息
#include <QDialog>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    // 打开串口
    //void openSerialPort();


    // 信号槽
    void on_openSerialBtn_clicked();

    void on_openFileBtn_clicked();

    void readData();

    void timerTransDate();
    //
    void clearTextBtnClicked();

private:
    Ui::MainWindow *ui;
    // 串口变量
    QSerialPort *serial;
    // 文件名字
    QString fileName;
    // 定时器
    QTimer *timer;
    // bin文件大小
    int binSize;
    //
    QByteArray *tempByte;
    //
    int ulNum;

};

#endif // MAINWINDOW_H
