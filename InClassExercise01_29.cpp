//
//  InClassExercise01_29.cpp
//  CSCI-2270
//
//  Created by 蒋新宇 on 2018/1/29.
//  Copyright © 2018年 XInyu JIang. All rights reserved.
//

#include "InClassExercise01_29.hpp"
#include <iostream>
using namespace std;

void doubleValue(double* n){
    double* temp=n;
    *n=(*n)*(*n);
}
/*int main(){
    int *iPointer=NULL;
    iPointer=new int;
    *iPointer=500;
    cout<<"iPointer= "<<*iPointer<<endl;
    (*iPointer)++;
    cout<<"iPointer value="<<*iPointer<<endl;
}*/
