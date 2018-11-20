#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
// 串口头文件
#include <QtSerialPort/QSerialPort>
// 打印
#include <QDebug>

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
    // 信号槽
    void on_openSerialBtn_clicked();

    void on_openFileBtn_clicked();

private:
    Ui::MainWindow *ui;
    // 串口变量
    QSerialPort *serial;

};

#endif // MAINWINDOW_H
