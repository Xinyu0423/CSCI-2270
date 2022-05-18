//
//  InClassExercise01_26.cpp
//  CSCI-2270
//
//  Created by 蒋新宇 on 2018/1/26.
//  Copyright © 2018年 XInyu JIang. All rights reserved.
//

#include "InClassExercise01_26.hpp"
#include <iostream>
void passByPointer(int *pte){
    *pte=*pte+1;
}
using namespace std;
int *mutiplyArraySize(int p[],int length,int m){
    int *newArr=new int[length*m];
    for(int i=0;i<length;i++){
        newArr[i]=p[i];
    }
    delete[] p;
    return newArr;
}
/*int main(){
    int x=10;
    while(x-->0){
        cout<<"x: "<<x<<endl;
    }
    int *ptr=new int;
    delete ptr;
    cout<<ptr<<endl;
    *ptr=0;
    passByPointer(ptr);
    cout<<"ptr value is "<<*ptr<<endl;
    int *myArr=new int[200];
    for (int i=0;i<200;i++){
        myArr[i]=i+1;
    }
    cout<<"reference: "<<myArr<<endl;
    cout<<"after dereference "<<*myArr<<endl;
    int *newArr=mutiplyArraySize(myArr, 200, 3);
    for(int i=0;i<600;i++){
        cout<<"index "<<i<<endl;
    }
    
}*/
