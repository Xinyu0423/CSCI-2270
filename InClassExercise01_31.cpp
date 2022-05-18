//
//  InClassExercise01_31.cpp
//  CSCI-2270
//
//  Created by 蒋新宇 on 2018/1/31.
//  Copyright © 2018年 XInyu JIang. All rights reserved.
//


#include <iostream>
using namespace std;
struct Node{
    int id;
    Node* next=nullptr;
    
};
Node* creatNode(int id, Node *nextNode){
    Node* newNode=new Node;
    newNode->id=id;
    newNode->next=nextNode;
    return newNode;
}
void printList(Node* head){
    if(head==NULL){
        cout<<"empty list"<<endl;
    }else{
        Node* currtentNode=head;
        while(currtentNode!=NULL){
            cout<<"NodeID "<<currtentNode->id<<endl;
            currtentNode=currtentNode->next;
        }
    }
}
Node* insertNode(Node* head,int nextID){
    if(head==NULL){
        Node* newNode=creatNode(nextID, NULL);
        head=newNode;
    }else{
        Node* currentNode=head;
        while(currentNode->next!=NULL){
            currentNode=currentNode->next;
        }
        Node* newNode=creatNode(nextID, NULL);
        currentNode->next=newNode;
    }
    return head;
}
Node* deleteNode(Node* head,int nodeID){
    bool flag=false;
    if(head==NULL){
        cout<<"nothing to delete"<<endl;
        return NULL;
    }else{
        if(head->id==nodeID){
            Node* nextNode=head->next;
            delete head;
            head=nextNode;
            flag=true;
            cout<<"node "<<nodeID<<" deleted"<<endl;
        }else if(head->next!=NULL && head->next->id==nodeID){
            Node* newNextNode=head->next->next;
            delete head->next;
            head->next=newNextNode;
            flag=true;
            cout<<"node "<<nodeID<<" deleted"<<endl;
        }else{
            Node* currNode=head->next;
            while(currNode->next!=NULL &&currNode->next!=NULL && !flag){
                if(currNode->next->id==nodeID){
                    Node* newNextNode=currNode->next->next;
                    delete currNode->next;
                    currNode->next=newNextNode;
                    flag=true;
                    cout<<"node "<<nodeID<<" deleted"<<endl;
                }else{
                    currNode=currNode->next;
                }
            }
        }
    }
    return head;
}
/*int main(){
    Node* head=NULL;
    cout<<"------------before delete---------------"<<endl;
    head=insertNode(head, 30);
    head=insertNode(head, 10);
    head=insertNode(head, 20);
    head=insertNode(head, 15);
    head=insertNode(head, 18);
    head=insertNode(head, 40);
    printList(head);
    cout<<"-----------after delede--------------"<<endl;
    cout<<"delete head"<<endl;
    head=deleteNode(head,30);
    printList(head);
    cout<<"delete middle"<<endl;
    head=deleteNode(head,20);
    head=deleteNode(head,18);
    printList(head);
    cout<<"delete tail"<<endl;
    head=deleteNode(head,40);
    printList(head);
    
}*/
