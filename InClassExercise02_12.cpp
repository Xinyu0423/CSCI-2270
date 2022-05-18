//
//  InClassExercise02_12.cpp
//  CSCI-2270
//
//  Created by 蒋新宇 on 2018/2/12.
//  Copyright © 2018年 XInyu JIang. All rights reserved.
//

#include <iostream>
using namespace std;
const int maxSize=5;
class arrStack{
public:
    arrStack();
    ~arrStack();
    bool isEmpty();
    bool isFull();
    int peek();
    int pop();
    bool push(int);
private:
    int stackOints[maxSize];
    int currentSize=0;
};
arrStack::arrStack(){
    
}
arrStack::~arrStack(){
    
}
bool arrStack::isFull(){
    if(currentSize==maxSize){
        return true;
    }else{
        return false;
    }
}
bool arrStack::isEmpty(){
    if(currentSize==0){
        return true;
    }
    return false;
}
bool arrStack::push(int itemAdd){
    return true;
}
/*int main(){
    arrStack myStack;
    if(myStack.isEmpty()){
        cout<<"stack empty"<<endl;
    }
}*/
