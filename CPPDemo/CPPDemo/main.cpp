//
//  main.cpp
//  CPPDemo
//
//  Created by SongMenglong on 2017/12/29.
//  Copyright © 2017年 SongMenglong. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <climits>

// using编译指令
using namespace std;

// 定义一些方法
void springOut(int n); //
void diSanZhangCode(); // 第三章代码
void diSiZhangCode(); // 第四章代码

int main(int argc, const char * argv[]) {
    
    
    
    
    cout << "Hello World" << endl;
    cout << "Hello World" << endl;
    
    int carrots;
    carrots = 25;
    cout << "Hello " << carrots << " World" << endl;
    
    cout << pow(5.0, 8.0) << endl;
    
    springOut(9);
    
    return 0;
}

#pragma mark 第三章代码 处理数据
void diSanZhangCode()
{
    // 可以输出完整的浮点型数据
    cout.setf(ios_base::fixed, ios_base::floatfield); // fixed-point
    
    int num1 = 42;
    int num2 = 0X42;
    int num3 = 042;
    
    float num44 = 10e-2;
    
    cout << num1 << endl;
    cout << num2 << endl;
    cout << num3 << endl;
    
    cout << num44 << endl;
}

#pragma mark 第四章代码 复合类型
void diSiZhangCode()
{
    
}




/*
 CPPdemo
 打算用C++写个小玩意儿
 如：爬虫
 OpenGL
 
 */
