//
//  Recitation3.cpp
//  CSCI-2270
//
//  Created by 蒋新宇 on 2018/1/30.
//  Copyright © 2018年 XInyu JIang. All rights reserved.
//

/*#include "Recitation3.hpp"
#include <iostream>
#include <fstream>
using namespace std;
int main(){
    
}
struct Distance{
    int feet;
    int inch;
};
int main(){
    Distance d;
    Distance* ptr;
    d.feet=8;
    d.inch=10;
    ptr=&d;
    //cout<<"Distance "<<ptr->feet<<" ft "<<ptr->inch<<endl;
    int* a=new int(25);
    for (int i=0;i<25;i++){
        //a[i]=i;
        cout<<a[i]<<endl;
    }
void resize(int *oldArr,int* capy){
    int newCap=*capy*2;
    int* newArr=new int[newCap];
    for(int i=0;i<*capy;i++){
        newArr[i]=oldArr[i];
    }
    oldArr = NULL;
    delete[] oldArr;
    oldArr=newArr;
    *capy=newCap;
}
/*int main(int c,char* const arg[]){
    ifstream inputFile(arg[1]);
    if(c!=2){
        cout<<"incorrect output"<<endl;
        return 0;
    }
    int capacity=10;
    int* myArr=new int[capacity];
    string temp;
    int numElement=0;
    
    if(inputFile.fail()){
        cout<<"open document fail"<<endl;
    }else{
        while(getline(inputFile,temp)){
            //cout<<temp<<"-----"<<endl;
            //cout<<"temp value "<<temp<<endl;
            int tempInt=stoi(temp);
            //cout<<"tempInt value "<<tempInt<<endl;
            myArr[numElement]=tempInt;
            if(numElement==capacity){
                resize(myArr, &capacity);
            }
            numElement++;
        }
    }
    cout<<"twenty element="<<myArr[20]<<endl;
    cout<<"capacity= "<<capacity<<endl;
    cout<<"num elements= "<<numElement<<endl;
    cout<<"the size of array "<<sizeof(myArr)<<endl;
    for(int i=0;i<numElement;i++){
        cout<<myArr[i]<<endl;
    }
}*/ 
