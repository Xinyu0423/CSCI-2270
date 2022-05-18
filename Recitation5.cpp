//
//  Recitation5.cpp
//  CSCI-2270
//
//  Created by 蒋新宇 on 2018/2/13.
//  Copyright © 2018年 XInyu JIang. All rights reserved.
//

#include "Recitation5.h"
#include <iostream>
using namespace std;

doublyLL::doublyLL() {
    
}

doublyLL::doublyLL(int nodeID) {
    //create head node
    head = createNode(nodeID, NULL, NULL);
    tail = head;
}

doublyLL::~doublyLL() {
    
}


Node* doublyLL::createNode(int nodeID, Node* nodePrev, Node* nodeNext) {
    Node* newNode = new Node;
    newNode->id = nodeID;
    newNode->next = nodeNext;
    newNode->prev = nodePrev;
    
    return newNode;
}

bool doublyLL::insertNodeAtEnd(int nodeID) {
    if (head == NULL) {
        //nothing in the list
        head = createNode(nodeID,NULL, NULL);
        tail = head;
    }
    else {
        Node* newNode = createNode(nodeID, tail, NULL);
        tail->next = newNode;
        tail = newNode;
    }
    return true;
}

bool doublyLL::deleteNode(int nodeID){
    Node* currNode=head;
    while(currNode!=NULL){
        if(currNode->id==nodeID){
            if(currNode->prev==NULL){
                currNode->next->prev=NULL;
                delete head;
                head=currNode->next;
            }else if(currNode->next==NULL){
                currNode->prev->next=NULL;
                delete head;
            }else{
                currNode->next->prev=currNode->prev;
                currNode->prev->next=currNode->next;
                delete head;
            }
        }
        currNode=currNode->next;
    }
    return false;
}
void doublyLL::printInfo(){
    Node* tempNode=head;
    while(tempNode!=NULL){
        cout<<tempNode->id<<endl;
        tempNode=tempNode->next;
    }
}
/*int main(){
    doublyLL MyLL;
    cout<<"----------before delete------------"<<endl;
    MyLL.insertNodeAtEnd(13);
    MyLL.insertNodeAtEnd(15);
    MyLL.insertNodeAtEnd(15);
    MyLL.insertNodeAtEnd(19);
    MyLL.insertNodeAtEnd(14);
    MyLL.printInfo();
    cout<<"-------------after delete----------"<<endl;
    cout<<"delete head"<<endl;
    MyLL.deleteNode(13);
    MyLL.printInfo();
    cout<<"delete middle"<<endl;
    MyLL.deleteNode(15);
    MyLL.deleteNode(15);
    MyLL.printInfo();
    cout<<"delete tail"<<endl;
    MyLL.deleteNode(14);
    MyLL.printInfo();
    
}*/


