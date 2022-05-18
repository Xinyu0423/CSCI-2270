//
//  projectLL.cpp
//  CSCI-2270
//
//  Created by 蒋新宇 on 2018/5/6.
//  Copyright © 2018年 XInyu JIang. All rights reserved.
//

#include "projectLL.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
projectLL::projectLL(){
    head=NULL;
}
projectLL::~projectLL(){
    
}
void projectLL::printLL(){
    pLL* temp=head;
    int tempIndex=1;
    if(head==NULL){
        cout<<"head is NULL, nothing to print"<<endl;
    }else{
        while(temp!=NULL){
            cout<<tempIndex<<": "<<temp->name<<" "<<temp->priority<<" "<<temp->treatment<<endl;
            temp=temp->next;
            tempIndex++;
        }
    }
}
void projectLL::addItem(string lName, int lPriority, int lTreatment){
    pLL* addLL=new pLL;
    addLL->name=lName;
    addLL->priority=lPriority;
    addLL->treatment=lTreatment;
    //cout<<"123"<<endl;
    if(head==NULL||lPriority<=head->priority){
        //cout<<"123"<<endl;
        /*pLL* temp=head;
        if(temp->next!=NULL && temp->next->priority<=lPriority){
            while(temp->next!=NULL && lPriority==head->priority){
                if(temp->next->treatment>=lTreatment){
                    break;
                }
                temp=temp->next;
            }
            addLL->next=temp->next;
            temp->next=addLL;
            return;
        }*/
        addLL->next=head;
        head=addLL;
    }else{
        pLL* temp=head;
        while(temp->next!=NULL && temp->next->priority<=lPriority){
            //cout<<temp->name<<endl;
            if(temp->next->priority==lPriority){
                if(temp->next->treatment>=lTreatment){
                    break;
                }
            }
            temp=temp->next;
        }
        addLL->next=temp->next;
        temp->next=addLL;
    }
    
}
void projectLL::delteItem(){
    if(head==NULL){
        cout<<"head is NULL, nothing to delete"<<endl;
    }else{
        pLL* temp=head;
        head=temp->next;
        delete temp;
    }
}
void projectLL::deleteAll(){
    for(int i=0;i<880;i++){
        delteItem();
    }
}
/*int main(){
    ifstream inputFile("patientData2270.csv");
    projectLL myLL;
    int LLCount=1;
    string line;
    
    for(int i=0;i<=880;i++){
        getline(inputFile,line,'\r');
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
            cout<<name<<endl;
            myLL.addItem(name, stoi(firstPriority), stoi(secondPriority));
        }
        LLCount++;
    }
    myLL.printLL();
    myLL.deleteAll();
    cout<<"---------after delete----------"<<endl;
    myLL.printLL();
}*/
