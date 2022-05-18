//
//  STLTree.cpp
//  CSCI-2270
//
//  Created by 蒋新宇 on 2018/5/2.
//  Copyright © 2018年 XInyu JIang. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
struct patient{
    string name;
    int priority;
    int treatment;
    patient(string pName="", int pri=1){
        name=pName;
        priority=pri;
    }
};
struct compare{
    bool operator()(const patient &a, const patient& b){
        if(a.priority<b.priority){
            return true;
        }else if(b.priority>b.priority){
            return false;
        }else{
            if(a.treatment>b.treatment){
                return false;
            }else if(a.treatment<b.treatment){
                return true;
            }else{
                return false;
            }
        }
    }
};
