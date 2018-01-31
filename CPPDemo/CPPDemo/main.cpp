//
//  main.cpp
//  CPPDemo
//
//  Created by SongMenglong on 2017/12/29.
//  Copyright © 2017年 SongMenglong. All rights reserved.
//

#include <iostream>

#pragma mark 快速排序
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
        std::cout<<a[i]<<"";
    }
    std::cout<<std::endl;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    int a[] = {1,3,5,9,8,6,4,2,7};
    std::cout<<"before sort:";
    print_array(a,9);
    insert_sort(a,9);
    std::cout<<"after sort:";
    print_array(a,9);
    
    return 0;
}




