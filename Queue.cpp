//
//  Queue.cpp
//  CSCI-2270
//
//  Created by 蒋新宇 on 2018/2/26.
//  Copyright © 2018年 XInyu JIang. All rights reserved.
//

/*#include "Queue.h"
#include <iostream>
#include <sstream>
using namespace std;
Queue::Queue(int qs) {
    queueSize = qs;
    arrayQueue = new string[queueSize];
    queueHead = 0;
    queueTail = 0;
    queueCount = 0;
}
Queue::~Queue() {
    delete [] arrayQueue;
    arrayQueue = NULL;
}
bool Queue::queueIsFull(){
    if(queueSize==queueCount){
        return true;
    }else{
        return false;
    }
    
}
void Queue::enqueue(string str){
    string word;
    if(queueIsFull()==false){
        arrayQueue[queueTail]=str;
        word=arrayQueue[queueTail];
        queueTail=(queueTail+1)%(queueSize);
        queueCount++;
    }else{
        cout<<"Queue full"<<endl;
    }
    cout<<"E: "<<word<<endl;
    cout<<"H: "<<queueHead<<endl;
    cout<<"T: "<<queueTail<<endl;
}


bool Queue::queueIsEmpty(){
    if(queueCount==0){
        return true;
    }else{
        return false;
    }
}
void Queue::dequeue(){
    if(queueIsEmpty()==true){
        cout<<"Queue is empty."<<endl;
    }else if(queueIsEmpty()==false){
        string word=arrayQueue[queueHead];
        queueHead=(queueHead+1)%queueSize;
        queueCount--;
        
        cout<<"H: "<<queueHead<<endl;
        cout<<"T: "<<queueTail<<endl;
        cout<<"word: "<<word<<endl;
    }
}

void Queue::printQueue(){
    if(queueIsEmpty()==true){
        cout<<"Empty"<<endl;
        return;
    }
    int index=queueHead;
    if(queueHead<queueCount){
        for(int i=0;i<queueCount;i++){
            if(index<queueCount){
                cout<<index<<": "<<arrayQueue[index]<<endl;
                index++;
            }if(index>=queueCount){
                index=0;
            }
        }
    }else if(queueHead==queueCount){
        cout<<queueHead<<": "<<arrayQueue[queueHead]<<endl;
    }
}
void Queue::enqueueSentence(string sent){
    stringstream ss(sent);
    int count=0;
    for(int i=0;i<sent.length();i++){
        if(sent[i]==' '){
            count++;
        }
    }
    string myArr[count+1];
    int i=0;
    while(getline(ss, myArr[i],' ')){
        enqueue(myArr[i]);
        i++;
    }
}*/



