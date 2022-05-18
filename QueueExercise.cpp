//
//  QueueExercise.cpp
//  CSCI-2270
//
//  Created by 蒋新宇 on 2018/2/28.
//  Copyright © 2018年 XInyu JIang. All rights reserved.
//

/*#include "QueueExercise.hpp"
#include <iostream>
using namespace std;
class Queue{
public:
    Queue();
    ~Queue();
    Queue(int);
    void enqueue(int);
    void dequeue();
    void printInfo();
    bool isFull();
    bool isEmpty();
private:
    int head;
    int tail;
    int size;
    int count;
    int* myArr;
};
Queue::Queue(){
    
}
Queue::Queue(int queueSize){
    head=0;
    tail=0;
    count=0;
    size=queueSize;
    myArr=new int[size];
}
Queue::~Queue(){
    delete[] myArr;
    myArr=NULL;
}
bool Queue::isFull(){
    if(size==count){
        cout<<"Array is full"<<endl;
        return true;
    }
    return false;
}
void Queue::enqueue(int value){
    if(isFull()==false){
        myArr[head]=value;
        head++;
        count++;
        if(head==tail){
            head=0;
        }
    }else{
        cout<<"Can not enqueue, array is full"<<endl;
    }
}
void Queue::printInfo(){
    for(int i=0;i<size;i++){
        cout<<"Index "<<i<<" = "<<myArr[i]<<endl;
    }
}
int main(){
    Queue myQueue(5);
    myQueue.enqueue(8);
    myQueue.enqueue(10);
    myQueue.enqueue(12);
    myQueue.enqueue(15);
    myQueue.enqueue(17);
    myQueue.enqueue(19);
    myQueue.printInfo();
}*/
