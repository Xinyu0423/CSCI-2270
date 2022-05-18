//
//  CommunicationNetwork.cpp
//  CSCI-2270
//
//  Created by 蒋新宇 on 2018/2/16.
//  Copyright © 2018年 XInyu JIang. All rights reserved.
//

/*#include "CommunicationNetwork.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
CommunicationNetwork::CommunicationNetwork(){
    head=NULL;
    tail=NULL;
}
CommunicationNetwork::~CommunicationNetwork(){
    head=NULL;
    tail=NULL;
}
void CommunicationNetwork::addCity(string newCityName, string previousCityName){
    City* newCity=new City(newCityName,NULL,NULL,"");
    if(head==NULL){
        head=newCity;
        tail=newCity;
    }else if(previousCityName==""|| previousCityName==tail->cityName){
        tail->next=newCity;
        newCity->previous=tail;
        tail=newCity;
    }else if(previousCityName=="First"){
        head->previous=newCity;
        newCity->next=head;
        head=newCity;
    }else{
        City* currCity=head;
        while(currCity!=NULL){
            if(currCity->cityName==previousCityName){
                City* tempCity=currCity->next;
                currCity->next->previous=newCity;
                currCity->next=newCity;
                currCity->next->next=tempCity;
                newCity->previous=currCity;
            }
            currCity=currCity->next;
        }
    }
    //cout <<
}
void CommunicationNetwork::transmitMsg(char * filename){
    ifstream inputFile(filename);
    string line;
    getline(inputFile,line);
    int index=1;
    int i=0;
    while(i<line.length()-1){
        if(line[i]==' '){
            index++;
        }
        i++;
    }
    string word[index];
    stringstream ss(line);
    for(int i=0;i<index;i++){
        ss>>word[i];
    }
    City* tempCity;
    for(int i=0;i<index;i++){
        tempCity=head;
        while(tempCity!=NULL){
            tempCity->message=word[i];
            cout<<tempCity->cityName<<" received "<<tempCity->message<<endl;
            //cout<<tempCity->next->cityName<<endl;
            cout<<word[i]<<endl;
            tempCity=tempCity->next;
        }
        City* previousTemp=tail->previous;
        while(previousTemp!=NULL){
            previousTemp->message=word[i];
            cout<<previousTemp->cityName<<" received "<<previousTemp->message<<endl;
            previousTemp=previousTemp->previous;
        }
    }
}
void CommunicationNetwork::printNetwork(){
    cout<<"===CURRENT PATH==="<<endl;
    City* tempCity=head;
    cout<<"NULL <- ";
    while(tempCity->next!=NULL){
        cout<<tempCity->cityName<<" <-> ";
        tempCity=tempCity->next;
    }
    cout<<tempCity->cityName<<" ";
    cout<<"-> NULL"<<endl;
    cout<<"==================";
}
void CommunicationNetwork::buildNetwork(){
    
    City* newCities[10];
    newCities[0]=new City("Los Angeles",NULL,NULL,"");
    newCities[1]=new City("Phoenix",NULL,NULL,"");
    newCities[2]=new City("Denver",NULL,NULL,"");
    newCities[3]=new City("Dallas",NULL,NULL,"");
    newCities[4]=new City("St. Louis",NULL,NULL,"");
    newCities[5]=new City("Chicago",NULL,NULL,"");
    newCities[6]=new City("Atlanta",NULL,NULL,"");
    newCities[7]=new City("Washington, D.C.",NULL,NULL,"");
    newCities[8]=new City("New York",NULL,NULL,"");
    newCities[9]=new City("Boston",NULL,NULL,"");
    head=newCities[0];
    City* tempCity=head;
    int i=1;
    while(i<10){
        while(tempCity->next!=NULL){
            tempCity=tempCity->next;
        }
        tempCity->next=newCities[i];
        i++;
    }
    int j=8;
    tail=newCities[9];
    City* prevTemp=tail;
    while(j>=0){
        while(prevTemp->previous!=NULL){
            prevTemp=prevTemp->previous;
        }
        prevTemp->previous=newCities[j];
        //cout<<prevTemp->cityName<<endl;
        j--;
    }
    prevTemp=prevTemp->previous;
    prevTemp->previous=newCities[0];
    //cout<<prevTemp->cityName<<endl;
    
}
void CommunicationNetwork::deleteCity(string removeCity){
    City* currCity=head;
    bool flag=true;
    while(currCity!=NULL){
        if(currCity->cityName==removeCity){
            if(currCity->previous==NULL){
                currCity->next->previous=NULL;
                flag=false;
                //delete head;
                head=currCity->next;
            }else if(currCity->next==NULL){
                currCity->previous->next=NULL;
                flag=false;
                //delete head;
            }else{
                currCity->next->previous=currCity->previous;
                currCity->previous->next=currCity->next;
                //delete head;
                flag=false;
            }
        }
        currCity=currCity->next;
    }
    if(flag==true){
        cout<<removeCity<<" not found"<<endl;
    }
}
void CommunicationNetwork::deleteNetwork(){
    City* currCity=head;
    string deleteName="";
    while(currCity!=NULL){
        deleteName=currCity->cityName;
        cout<<"deleting "<<deleteName<<endl;
        deleteCity(deleteName);
        currCity=currCity->next;
    }
}
/*addCity("Los Angeles", "First");
 addCity("Phoenix", "Los Angeles");
 addCity("Denver", "Phoenix");
 addCity("Dallas", "Denver");
 addCity("St. Louis", "Dallas");
 addCity("Chicago", "St. Louis");
 addCity("Atlanta", "Chicago");
 addCity("Washington, D.C.", "Atlanta");
 addCity("New York", "Washington, D.C.");
 addCity("Boston", "");*/
