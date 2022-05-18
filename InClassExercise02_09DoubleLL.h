//
//  InClassExercise02_09DoubleLL.hpp
//  CSCI-2270
//
//  Created by 蒋新宇 on 2018/2/9.
//  Copyright © 2018年 XInyu JIang. All rights reserved.
//

/*#ifndef InClassExercise02_09DoubleLL_h
#define InClassExercise02_09DoubleLL_h

#include <stdio.h>
using namespace std;
struct Node{
    int id=1;
    Node* prev=NULL;
    Node* next=NULL;
};
class DoubleLL{
private:
    Node* createNode(int,Node*,Node*);
    void deleteList();
    Node* head=NULL;
    Node* tail=NULL;
public:
    bool insertNodeAtEnd(int);
    void printLL();
    DoubleLL();
    DoubleLL(int);
    ~DoubleLL();
    
};
#endif /* InClassExercise02_09DoubleLL_hpp */
