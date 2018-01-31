#include "mainwindow.h"
#include <QApplication>

#pragma mark 快速排序
using namespace std;

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


void print_array(int a[], int len)
{
    for(int i=0;i<len;i++)
    {
        //cout<<a[i]<<;
        //std::cout<<a[i]<<"";
    }
    //std::cout<<std::endl;
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    // insert code here...
    //std::cout << "Hello, World!\n";

    int a1[] = {1,3,5,9,8,6,4,2,7};
    //std::cout<<"before sort:";
    print_array(a1,9);
    insert_sort(a1,9);
    //std::cout<<"after sort:";
    print_array(a1,9);

    // 进程
    return a.exec();
}












