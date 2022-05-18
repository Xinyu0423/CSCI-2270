//
//  InClassReview.cpp
//  CSCI-2270
//
//  Created by 蒋新宇 on 2018/1/19.
//  Copyright © 2018年 XInyu JIang. All rights reserved.
//

#include "InClassReview.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

struct student{
    int studentID=-1;
    string studentName="n/a";
    string studentMajor="n/a";
};
void swapTwo(int *x,int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}
//void swapByReference(int &)
/*int main(){
    int anInt=7;
    float aFloat=7.5;
    double aDouble=19.24249239;
    int anArray[10];
    string socks[10];
    socks[0]="blue";
    socks[1]="red";*/
    /*int a=4, b=5;
    cout<<"before swap"<<endl;
    cout<<"a= "<<a<<endl;
    cout<<"b= "<<b<<endl;
    cout<<"----------------------"<<endl;
    cout<<"after swap"<<endl;
    swapTwo(&a,&b);
    cout<<"a= "<<a<<endl;
    cout<<"b= "<<b<<endl;
     
    student studentArr[10];
    int numStudent=0;
    ifstream inputFile("students.txt");
    if(inputFile.fail()){
        cout<<"The file did not open"<<endl;
    }
    string tempStr;
    while(getline(inputFile,tempStr)){
        cout<<tempStr<<endl;
    }
    inputFile.clear();
    inputFile.seekg(0,ios::beg);
    cout<<"--------------------------------"<<endl;
    while(getline(inputFile,tempStr)){
        stringstream ss(tempStr);
        string tempID, tempName,tempMajor;
        getline(ss, tempID, ',');
        getline(ss, tempName, ',');
        getline(ss, tempMajor, ',');
        cout<<tempID<<endl;
        cout<<tempName<<endl;
        cout<<tempMajor<<endl;
        studentArr[numStudent].studentID=stoi(tempID);
        studentArr[numStudent].studentName=tempName;
        studentArr[numStudent].studentMajor=tempMajor;
        numStudent++;
    }
    inputFile.close();
    ofstream ouputFile("studentInfo");
    for(int i=0;i<numStudent;i++){
        
    }
    
    
    
}*/
