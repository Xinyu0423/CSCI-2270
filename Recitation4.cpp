//
//  Recitation4.cpp
//  CSCI-2270
//
//  Created by 蒋新宇 on 2018/2/6.
//  Copyright © 2018年 XInyu JIang. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

struct Node{
    int id;
    Node* next;
};
class myLinkedList{
private:
    Node* head;
    Node* createNode(int,Node*);
public:
    myLinkedList();
    ~myLinkedList();
    myLinkedList(int);
    bool insertNode(int);
    void printLinkedList();
    int instertEvenNode(int,int[]);
};
myLinkedList::myLinkedList(){
    
}
myLinkedList::~myLinkedList(){
    delete head;
}
myLinkedList::myLinkedList(int x){
    head=createNode(x, nullptr);
}
Node* myLinkedList::createNode(int id,Node* next){
    Node* myNode=new Node;
    myNode->id=id;
    myNode->next=next;
    return myNode;
}

bool myLinkedList::insertNode(int insertID){
        Node* tempNode=createNode(insertID, nullptr);
        if(head==nullptr){
            head=tempNode;
        }
        Node* anotherNode=head;
        //cout<<anotherNode->next<<endl;
        while(anotherNode->next!=nullptr){
            anotherNode=anotherNode->next;
        }
        anotherNode->next=tempNode;
        return true;
}
void myLinkedList::printLinkedList(){
    if(head==nullptr) {
        cout<<"empty linked list"<<endl;
    }
    Node* tempNode=head;
    while(tempNode->next!=NULL){
        cout<<"head id is "<<tempNode->id<<endl;
        tempNode=tempNode->next;
    }
    cout<<"head id is "<<tempNode->id<<endl;
}
int myLinkedList::instertEvenNode(int insertID,int ignorePoints[]){
    Node* currNode=createNode(insertID, nullptr);
    if(head==nullptr){
        currNode->next=head;
        head=currNode;
    }
    Node* tempNode=head;
    while(tempNode->id%2!=0){
        tempNode=tempNode->next;
        for(int i=0;i<3;i++){
            if(tempNode->id==ignorePoints[i]){
                tempNode=tempNode->next;
            }
        }
    }
    currNode->next=tempNode->next;
    tempNode->next=currNode;
    return tempNode->id;
}
/*int main(){
    myLinkedList myLL(3);
    myLL.insertNode(4);
    myLL.insertNode(5);
    //myLL.insertNode(6);
    //myLL.insertNode(7);
    //myLL.insertNode(8);
    myLL.printLinkedList();
    if(0x0==NULL){
        cout<<"2131"<<endl;
    }
    cout<<"---------------after insert-------------"<<endl;
    int myArr[100];
    int x=myLL.instertEvenNode(23,myArr);
    myArr[0]=x;
    x=myLL.instertEvenNode(25,myArr);
    myArr[1]=x;
    x=myLL.instertEvenNode(29, myArr);
    myArr[2]=x;
    myLL.printLinkedList();
}*/
