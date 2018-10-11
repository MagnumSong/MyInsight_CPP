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
    
    // 第三章代码
    //diSanZhangCode();
    
    diSiZhangCode();
    
    
    
    return 0;
}

#pragma mark 第三章代码 处理数据
void diSanZhangCode()
{
    cout << "Hello World" << endl;
    
    int carrots;
    carrots = 25;
    cout << "Hello " << carrots << " World" << endl;
    
    cout << pow(5.0, 8.0) << endl;
    
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
    cout << 9.11e-31 << endl;
}

#pragma mark 第四章代码 复合类型
void diSiZhangCode()
{
    using namespace std;
    
    // 1.数组
    int yams[3];
    yams[0] = 7;
    yams[1] = 8;
    yams[2] = 6;
    
    int yamcosts[3] = {20, 30, 5};
    cout << "Total yams = ";
    cout << yams[0] + yams[1] + yams[2] << endl;
    cout << "The package with " << yams[1] << " yams costs";
    cout << yamcosts[1] << " cents per yam" << endl;
    
    // 2.字符串
    const int ArSize = 20;
    char name[ArSize];
    char dessert[ArSize];
    
    cout << "Enter your name:" << endl;
    cin.getline(name, ArSize);
    cout << "Enter your faviorite dessert:" << endl;
    cin.getline(dessert, ArSize);
    cout << "I have some delicious " << dessert;
    cout << " for you, " << name << endl;
    
    // 3.string类简介
    
    // 4.结构简介
    
}

/*
 CPPdemo
 打算用C++写个小玩意儿
 如：爬虫
 OpenGL
 
 */
