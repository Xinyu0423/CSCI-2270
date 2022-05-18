//
//  InClassExercise01-24.cpp
//  CSCI-2270
//
//  Created by 蒋新宇 on 2018/1/24.
//  Copyright © 2018年 XInyu JIang. All rights reserved.
//

#include "InClassExercise01_24.hpp"
#include <iostream>
using namespace std;
void passByVal(int a){
    a++;
}
void passByreference(int &a){
    a++;
}
/*int main(){
    int a=5;
    int *aPointer=&a;
    cout<<"a= "<<5<<endl;
    cout<<"a's refence is "<<&a<<endl;
    cout<<"aPointer is "<<aPointer<<endl;
    cout<<"stored at aPointer is "<<*aPointer<<endl;
    passByVal(a);
    cout<<"after pass by val "<<a<<endl;
    passByreference(a);
    cout<<"after pass by reference "<<a<<endl;
    //different between reference and pointer
    //pointer and be reassign, reference cannot
    
}*/

