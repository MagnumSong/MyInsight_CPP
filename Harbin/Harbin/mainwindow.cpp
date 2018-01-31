#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //BubbleSort();
}

MainWindow::~MainWindow()
{
    delete ui;
}

// 直接插入排序
void insert_sort(int a[],int len)
{
    int i=0,j=0,temp=0;
    for(i=1;i<len;i++)
    {
        temp =a[i];
        for(j=i-1;j>=0&&temp<a[j];j--)
        {
            a[j+1]=a[j];
        }
        a[j+1]=temp;
    }
}



