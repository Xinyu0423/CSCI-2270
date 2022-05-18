//
//  InClassExercise04_20.cpp
//  CSCI-2270
//
//  Created by 蒋新宇 on 2018/4/20.
//  Copyright © 2018年 XInyu JIang. All rights reserved.
//

#include "InClassExercise04_20.hpp"
#include <iostream>
#include <chrono>
using namespace std;
//max heap
//only prime priority
struct priorityItem{
    string itemName;
    int primePriority;
    int secondPriority;
};
long fib(int n){
    if(n<2){
        return n;
    }else{
        return (fib(n-1)+fib(n-2));
    }
}
class priorityQueue{
public:
    priorityQueue();
    ~priorityQueue();
    bool enqueue(string, int ,int );
    bool dequeue();
    string peek();
    void printPQ();
private:
    int lastIndex=0;
    int maxIndex=10;
    priorityItem* pQueue[10];
    
};
priorityQueue::priorityQueue(){
    for(int i=0;i<maxIndex;i++){
        pQueue[i]=NULL;
    }
}
priorityQueue::~priorityQueue(){
    for(int i=1;i<maxIndex;i++){
        delete pQueue[i];
    }
}
bool priorityQueue::enqueue(string name , int promP, int secP){
    if(lastIndex<maxIndex){
        priorityItem* itemToAdd=new priorityItem;
        itemToAdd->itemName=name;
        itemToAdd->primePriority=promP;
        itemToAdd->secondPriority=secP;
        pQueue[lastIndex]=itemToAdd;
        int currIndex=lastIndex;
        bool itemSwap=true;
        while(currIndex>1 && itemSwap==true){
            if(pQueue[lastIndex]->primePriority>pQueue[currIndex/2]->primePriority){
                priorityItem* temp=pQueue[currIndex/2];
                pQueue[currIndex/2]=pQueue[currIndex];
                pQueue[currIndex]=temp;
                currIndex=currIndex/2;
            }else{
                itemSwap=false;
            }
        }
        return true;
    }else{
        cout<<"queue is full"<<endl;
        return false;
    }
}
string priorityQueue::peek(){
    if(lastIndex!=0){
        return pQueue[1]->itemName;
    }else{
        cout<<"Priority Queue Empty"<<endl;
        return "N/A";
    }
}
bool priorityQueue::dequeue(){
    if(lastIndex>0){
        delete pQueue[1];
        if(lastIndex==1){
            lastIndex=0;
            pQueue[1]=NULL;
            pQueue[lastIndex]=NULL;
            lastIndex--;
            int currIndex=-1;
            int leftChild, rightChild, lagerChild;
            bool itemSwapped=true;
            while(currIndex<maxIndex && itemSwapped==true){
                leftChild=currIndex*2;
                rightChild=currIndex*2+1;
                if(leftChild>lastIndex){
                    itemSwapped=false;
                }else{
                    if(rightChild>lastIndex){
                        lagerChild=leftChild;
                    }else{
                        lagerChild=(pQueue[leftChild]->primePriority>pQueue[rightChild]->primePriority)? leftChild: rightChild;
                    }
                }
                if(pQueue[currIndex]->primePriority<pQueue[lagerChild]->primePriority){
                    priorityItem* temp=pQueue[lagerChild];
                    pQueue[lagerChild]=pQueue[currIndex];
                    pQueue[currIndex]=temp;
                    currIndex=lagerChild;
                }else{
                    itemSwapped=false;
                }
            }
        }
        return false;
    }else{
        cout<<"queue is empty, nothing to dequeue"<<endl;
        return false;
    }
}
void priorityQueue::printPQ(){
    if(lastIndex==0){
        cout<<"Nothing to print"<<endl;
    }else{
        for(int i=1;i<=lastIndex;i++){
            cout<<"item "<<i<<" : "<<pQueue[i]->itemName<<" priority "<<pQueue[i]->primePriority;
        }
    }
}

int main(){
    auto start=chrono::system_clock::now();
    
    priorityQueue myPQ;
    myPQ.enqueue("Dunkin Donuts", 2, 7);
    myPQ.enqueue("Cafeteria Sludge", 1, 0);
    myPQ.enqueue("Orgainic Fair Trade Generic Dark Roast", 5, 10);
    myPQ.enqueue("Breakfast Blend", 3, 10);
    myPQ.enqueue("Dunkin Donuts", 2, 7);
    cout<<"highest priority: "<<myPQ.peek()<<endl;
    myPQ.printPQ();
    auto end=chrono::system_clock::now();
    auto timeEkasoeed=chrono::duration<float>(end-start);
}
