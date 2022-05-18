//
//  InClassExercise02_14.cpp
//  CSCI-2270
//
//  Created by 蒋新宇 on 2018/2/14.
//  Copyright © 2018年 XInyu JIang. All rights reserved.
//

#include "InClassExercise02_14.hpp"
#include <iostream>
using namespace std;
const int maxSize=5;
class arrcirQueue{
public:
    arrcirQueue();
    ~arrcirQueue();
    bool enQueue(int);
    bool deQueue(int&);
    bool peek(int&);
private:
    bool isFull();
    bool isEmpty();
    int head=-1;
    int tail=-1;
    int arrQueue[maxSize];
};
arrcirQueue::arrcirQueue(){
    
}
arrcirQueue::~arrcirQueue(){
    
}
bool arrcirQueue::isFull(){
    int tempHead=head;
    if(head==0){
        tempHead=maxSize;
    }
    if(tempHead-tail==1){
        return true;
    }else{
        return false;
    }
}
bool arrcirQueue::isEmpty(){
    if(head==-1&& tail==-1){
        return true;
    }else{
        return false;
    }
}
bool arrcirQueue::enQueue(int x){
    if(!isFull()){
        int tempTail=tail+1;
        if(tempTail==maxSize){
            tempTail=0;
        }
        tail=tempTail;
        arrQueue[tail]=x;
        if(head==-1){
            head=0;
        }
        cout<<"item "<<x<<" added"<<endl;
        return true;
    }
    return false;
}
bool arrcirQueue::deQueue(int& x){
    if(isEmpty()){
        cout<<"queue empty"<<endl;
    }else{
        x=arrQueue[head];
        if(head==tail){
            head=-1;
            tail=-1;
        }else{
            head++;
            if(head==maxSize){
                head=0;
            }
            return true;
    }
    }
    return false;
}

