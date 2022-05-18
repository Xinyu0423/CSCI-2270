//
//  Assignment3.cpp
//  CSCI-2270
//
//  Created by 蒋新宇 on 2018/2/7.
//  Copyright © 2018年 XInyu JIang. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
struct city{
    string cityName;
    string message;
    city* next;
    city(string name,city* initNext,string initMessage){
        cityName=name;
        next=initNext;
        message=initMessage;
    }
};
city *buildNetwork(){
    city* cityList=NULL;
    city* newCities[10];
    newCities[0]=new city("Los Angeles",NULL,"");
    newCities[1]=new city("Phoenix",NULL,"");
    newCities[2]=new city("Denver",NULL,"");
    newCities[3]=new city("Dallas",NULL,"");
    newCities[4]=new city("St. Louis",NULL,"");
    newCities[5]=new city("Chicago",NULL,"");
    newCities[6]=new city("Atlanta",NULL,"");
    newCities[7]=new city("Washington, D.C.",NULL,"");
    newCities[8]=new city("New York",NULL,"");
    newCities[9]=new city("Boston",NULL,"");
    cityList=newCities[0];
    city* currNode=cityList;
    int i=1;
    city* temp;
    while(i<10){
        while(currNode->next!=NULL){
            currNode=currNode->next;
        }
        temp=newCities[i];
        currNode->next=temp;
        i++;
    }
    
    return cityList;
}

city *addCity(city *head, city *previous, string cityName){
    
    //cout<<previous->cityName<<endl;
    city* cityAdd=new city(cityName,NULL,"");
    
    if(head==NULL){
        head=cityAdd;
        return head;
    }
    if(previous==NULL){
        cityAdd->next=head;
        head=cityAdd;
        return head;
    }
    city* tempCity=head;
    while(tempCity->next!=NULL){
        if(tempCity==previous){
            break;
        }
        tempCity=tempCity->next;
    }
    cityAdd->next=tempCity->next;
    tempCity->next=cityAdd;
    return head;
}
void transmitMsg(city *head){
    ifstream inputFile("messageIn.txt");
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
        //cout<<word[i]<<endl;
    }
    city* tempCity=head;
    for(int i=0;i<index;i++){
        tempCity=head;
        while(tempCity!=NULL){
            tempCity->message=word[i];
            cout<<tempCity->cityName<<" received "<<tempCity->message<<endl;
            tempCity=tempCity->next;
        }
    }
}
void printPath(city *head){
    city* tempCity=head;
    cout<<"===CURRENT PATH==="<<endl;
    while(tempCity!=NULL){
        cout<<tempCity->cityName<<" -> ";
        tempCity=tempCity->next;
    }
    cout<<" NULL"<<endl;
    cout<<"=================="<<endl;
}
/*int main(){
    city* cityList;
    cityList=buildNetwork();
    city* secondCity=NULL;
    city* tempCity2=cityList;
    city* previousCity=cityList->next->next->next;
    secondCity=addCity(cityList,NULL, "Seattle");
    transmitMsg(cityList);
    city* cityList=NULL;
    int input=0;
    while(input!=5){
        cin>>input;
        cout<<"======Main Menu======"<<endl;
        cout<<"1. Build Network"<<endl;
        cout<<"2. Print Network Path" <<endl;
        cout<<"3. Transmit Message Coast-To-Coast" <<endl;
        cout<<"4. Add City" <<endl;
        cout<<"5. Quit" <<endl;
        if(input==1){
            cityList=buildNetwork();
        }else if(input==2){
            printPath(cityList);
        }else if(input==3){
            transmitMsg(cityList);
        }else if(input==4){
            string cityName;
            cout<<"Enter a City name:"<<endl;
            cin>>cityName;
            string previousCityName;
            cout<<"Enter a previous City name:"<<endl;
            cin>>previousCityName;
            city* tempCity=cityList;
            while(tempCity->cityName!=previousCityName){
                tempCity=tempCity->next;
            }
            cityList=addCity(cityList,tempCity , cityName);
        }else if(input==5){
            cout<<"Goodbye!"<<endl;
        }

    }
}*/
