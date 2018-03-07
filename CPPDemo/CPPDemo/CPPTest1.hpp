//
//  CPPTest1.hpp
//  CPPDemo
//
//  Created by SongMenglong on 2018/3/7.
//  Copyright © 2018年 SongMenglong. All rights reserved.
//

#ifndef CPPTest1_hpp
#define CPPTest1_hpp

#include <stdio.h>

class CPPTest1 {
public:
    // 定义公共方法
   // void testPaiXu(); //排序方法
    
    void setDate(char);//设置日期

private:
    // 似有方法
    int year;
    int month;
    int day;
    bool pass;
    bool checkFormat(char);//验证日期输入格式
    void validate();//验证日期数值有效性
    bool leapYear(int);//闰年判断  
    
};


#endif /* CPPTest1_hpp */
