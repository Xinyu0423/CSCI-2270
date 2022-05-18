//
//  InClassExercise02_05.cpp
//  CSCI-2270
//
//  Created by 蒋新宇 on 2018/2/5.
//  Copyright © 2018年 XInyu JIang. All rights reserved.
//

#include "InClassExercise02_05.hpp"
#include <iostream>
using namespace std;
struct Node{
    int id=-1;
    Node* next=NULL;
};
class singleLinkedList{
private:
    Node* createNode(int, Node*);
    Node* head=NULL;
    void deleteList();
public:
    singleLinkedList();
    singleLinkedList(int);
    ~singleLinkedList();
    bool insertNodeAtEnd(int);
    bool deleteNode(int);
    void printList();
};
singleLinkedList::singleLinkedList(){
    
}
singleLinkedList::singleLinkedList(int id){
    head=createNode(id, nullptr);
}
singleLinkedList::~singleLinkedList(){
    delete head;
}
Node* singleLinkedList::createNode(int id, Node* nextNode){
    Node* newNode=new Node;
    newNode->id=id;
    newNode->next=nextNode;
    return newNode;
}
bool singleLinkedList::insertNodeAtEnd(int id){
    Node* newNode=createNode(id, nullptr);
    if(head==nullptr){
        head=newNode;
    }else{
        Node* currentNode=head;
        while(currentNode->next!=nullptr){
            currentNode=currentNode->next;
        }

        currentNode->next=newNode;
    }
    return true;
}
void singleLinkedList::printList(){
    if(head==nullptr){
        cout<<"empty list"<<endl;
    }else{
        Node* currtentNode=head;
        while(currtentNode!=nullptr){
            cout<<"NodeID "<<currtentNode->id<<endl;
            currtentNode=currtentNode->next;
        }
    }

}
void singleLinkedList::deleteList(){
    Node* currNode=head;
    Node* tempNode;
    while(currNode!=nullptr){
        tempNode=currNode->next;
        cout<<"delete nnode"<<currNode->id<<endl;
        delete currNode;
        currNode=tempNode;
    }
}
/*int main(){
    singleLinkedList myList(10);
    myList.insertNodeAtEnd(15);
    myList.insertNodeAtEnd(30);
    myList.insertNodeAtEnd(5);
    
    singleLinkedList secondList(22);
    secondList.insertNodeAtEnd(57);
    cout<<"print first list"<<endl;
    myList.printList();
    cout<<"print second list"<<endl;
    secondList.printList();
    
    singleLinkedList* thirdList=new singleLinkedList(35);
    thirdList->printList();
    delete thirdList;
    
}*/
