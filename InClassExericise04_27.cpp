//
//  InClassExericise04_27.cpp
//  CSCI-2270
//
//  Created by 蒋新宇 on 2018/4/27.
//  Copyright © 2018年 XInyu JIang. All rights reserved.
//

#include "InClassExericise04_27.hpp"
#include<iostream>
#include <queue>
using namespace std;
struct patient{
    string name;
    int priority;
    patient(string pName="",int pri=0){
        name=pName;
        priority=pri;
    }
};
struct compare{
    bool operator()(const patient &a, const patient &b){
        return a.priority< b.priority;
    }
};
int main(){
    priority_queue<int> pqInts;
    pqInts.push(4);
    pqInts.push(14);
    pqInts.push(24);
    pqInts.push(34);
    while(!pqInts.empty()==false){
        cout<<pqInts.top()<<endl;
        pqInts.pop();
    }
    priority_queue<patient, vector<patient>, compare> pq;
    patient p1("quaid", 50);
    patient p2("t800", 15);
    patient p3("dutch", 30);
    patient p4("kimble", 75);
    patient p5("rishard", 55);
}
