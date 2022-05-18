//
//  projectLL.hpp
//  CSCI-2270
//
//  Created by 蒋新宇 on 2018/5/6.
//  Copyright © 2018年 XInyu JIang. All rights reserved.
//

#ifndef projectLL_hpp
#define projectLL_hpp

#include <stdio.h>
#include <iostream>
using namespace std;
struct pLL{
    string name;
    int priority;
    int treatment;
    pLL* next;
};
class projectLL{
public:
    projectLL();
    ~projectLL();
    void addItem(string,int,int);
    void delteItem();
    void printLL();
    void deleteAll();
    pLL* head;
    int currIndex;
    
};

#endif /* projectLL_hpp */
