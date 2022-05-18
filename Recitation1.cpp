//
//  Recitation1.cpp
//  CSCI-2270
//
//  Created by 蒋新宇 on 2018/1/23.
//  Copyright © 2018年 XInyu JIang. All rights reserved.
//

#include "Recitation1.hpp"
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;
struct car{
    string make;
    string model;
    int year;
};
void readFile(car carArr[],string size,string x,string y){
    ifstream inputFile(x);
    ofstream outputFile(y);
    string temp;
    int index=0;
    if(inputFile.fail()){
        cout<<"open document fail"<<endl;
    }else{
        while(getline(inputFile,temp)){
            stringstream ss(temp);
            string tempMake;
            string tempModel;
            string tempYear;
            getline(ss,tempMake , ' ');
            getline(ss,tempModel , ' ');
            getline(ss,tempYear,',');
            cout<<tempYear<<endl;
            carArr[index].make=tempMake;
            carArr[index].model=tempModel;
            carArr[index].year=stoi(tempYear);
            outputFile<<carArr[index].make<<" ";
            outputFile<<carArr[index].model<<" ";
            outputFile<<carArr[index].year<<endl;
            index++;
        }
    }
    inputFile.close();
    outputFile.close();
    
}
/*int main(int c, char *arg[]){
    car myArr[100];
    string inputFileName=arg[1];
    string line=arg[2];
    string outputFileName=arg[3];
    readFile(myArr,line,inputFileName,outputFileName);
    for(int i=0;i<100;i++){
        cout<<"car's make is "<<myArr[i].make<<endl;
        cout<<"car's model is "<<myArr[i].model<<endl;
        cout<<"car's year is "<<myArr[i].year<<endl;
    }
    
}*/

