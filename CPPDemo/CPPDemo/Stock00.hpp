//
//  Stock00.hpp
//  CPPDemo
//
//  Created by SongMenglong on 2018/3/8.
//  Copyright © 2018年 SongMenglong. All rights reserved.
//

#ifndef Stock00_hpp
#define Stock00_hpp

#include <stdio.h>
#include <string>

class Stock {
private:
    std::string company;
    long shares;
    double share_val;
    double total_val;
    void set_tot() {
        total_val = shares *share_val;
    }
public:
//    void 
};




#endif /* Stock00_hpp */
