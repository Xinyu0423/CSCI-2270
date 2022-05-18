//
//  projectMain.cpp
//  CSCI-2270
//
//  Created by 蒋新宇 on 2018/5/3.
//  Copyright © 2018年 XInyu JIang. All rights reserved.
//

#include "projectHeap.hpp"
#include "projectLL.hpp"
#include <iostream>
#include <fstream>
#include <queue>
#include <sstream>
#include <time.h>
using namespace std;
struct patient{
    string name;
    int priority;
    int treatment;
    patient(string pName="", int pri=1){
        name=pName;
        priority=pri;
    }
};
struct compare{
    bool operator()(const patient &a, const patient& b){
        if(a.priority>b.priority){
            return true;
        }else if(a.priority<b.priority){
            return false;
        }else{
            if(a.treatment>b.treatment){
                return true;
            }else if(a.treatment<b.treatment){
                return false;
            }else{
                return false;
            }
        }
        return false;
    }
};
int main(int c, char const* argv[]){
    for(int i=0;i<500;i++){
        clock_t t1,t2;
        t1=clock();
        int testSize=880;
        int countLine=1;
        string filename=argv[1];
        ifstream inputFile(filename);
        string line;
        priority_queue<patient, vector<patient>,compare> pQueue;
        while(getline(inputFile, line,'\r')){
            stringstream ss(line);
            string name;
            string firstPriority;
            string secondPriority;
            getline(ss,name,',');
            getline(ss,firstPriority,',');
            getline(ss,secondPriority,',');
            if(countLine-1==testSize){
                break;
            }
            if(countLine!=1){
                patient* myPatient=new patient;
                myPatient->name=name;
                myPatient->priority=stoi(firstPriority);
                myPatient->treatment=stoi(secondPriority);
                pQueue.push(*myPatient);
                
            }
            countLine++;
        }
        //cout<<"Rank\tpatient,  Priority,  Treatment"<<endl;
        int rank=1;
        //-----------------STL print ------------------------
        while(!pQueue.empty()){
            patient pTemp=pQueue.top();
            //cout<<rank<<":\t"<<pTemp.name<<",  "<<pTemp.priority<<",  "<<pTemp.treatment<<endl;
            rank++;
            pQueue.pop();
        }
        inputFile.close();
        t2=clock();
        cout<<"STL is "<<float(t2)-float(t1)/CLOCKS_PER_SEC<<endl;
        //----------------heap-----------------
        clock_t t3, t4;
        t3=clock();
        inputFile.open(filename);
        heap myHeap;
        int heapCount=1;
        while(getline(inputFile,line,'\r')){
            stringstream ss(line);
            string name;
            string firstPriority;
            string secondPriority;
            getline(ss,name,',');
            getline(ss,firstPriority,',');
            getline(ss,secondPriority,',');
            //cout<<firstPriority<<endl;
            //cout<<name<<endl;
            if(heapCount!=1){
                myHeap.addItem(name, stoi(firstPriority), stoi(secondPriority));
            }
            heapCount++;
        }
        //--------------------heap print---------------------
        //myHeap.printHeap();
        inputFile.close();
        t4=clock();
        cout<<"Heap is "<<float(t4)-float(t3)/CLOCKS_PER_SEC<<endl;
        //----------------------------Linked List----------------------
        clock_t t5, t6;
        t5=clock();
        inputFile.open(filename);
        projectLL myLL;
        int LLCount=1;
        while(getline(inputFile,line,'\r')){
            //getline(inputFile,line,'\r');
            stringstream ss(line);
            string name;
            string firstPriority;
            string secondPriority;
            getline(ss,name,',');
            getline(ss,firstPriority,',');
            getline(ss,secondPriority,',');
            ///cout<<firstPriority<<endl;
            //cout<<name<<endl;
            if(LLCount!=1){
                //cout<<"123"<<endl;
                //cout<<name<<endl;
                myLL.addItem(name, stoi(firstPriority), stoi(secondPriority));
            }
            LLCount++;
        }
        //---------------------linked list print-------------------------
        //myLL.printLL();
        myLL.deleteAll();
        //cout<<"---------after delete----------"<<endl;
        //myLL.printLL();
        inputFile.close();
        t6=clock();
         cout<<"run time for Linked List is "<<float(t6)-float(t5)/CLOCKS_PER_SEC<<endl;
    }
}

