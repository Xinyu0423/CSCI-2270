//
//  Recitation5.hpp
//  CSCI-2270
//
//  Created by 蒋新宇 on 2018/2/13.
//  Copyright © 2018年 XInyu JIang. All rights reserved.
//

#ifndef Recitation5_h
#define Recitation5_h

#include <stdio.h>

//using namespace std;

struct Node {
    int id=-1;
    Node* prev = NULL;
    Node* next = NULL;
};

class doublyLL {
private:
    Node* createNode(int,Node*,Node*);
    Node* head = NULL;
    Node* tail = NULL;
public:
    bool insertNodeAtEnd(int);
    bool deleteNode(int);
    void printInfo();
    doublyLL();	//default constructor
    doublyLL(int);	//overloaded constructor
    ~doublyLL();	//destructor
};


#endif /* Recitation5_hpp */
