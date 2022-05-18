//
//  InClassExercise02_19.cpp
//  CSCI-2270
//
//  Created by 蒋新宇 on 2018/2/19.
//  Copyright © 2018年 XInyu JIang. All rights reserved.
//

#include <iostream>
using namespace std;
struct Node{
    int id=-1;
    Node* left=NULL;
    Node* right=NULL;
    Node* parent=NULL;
};
class BST{
private:
    Node* root=NULL;
    Node* createNode(int, Node*, Node*, Node*);
    int getSize(int *);
    bool addNodePri(Node*,int);
    Node* search(Node*, int);
public:
    BST();
    ~BST();
    bool addNode(int);
    bool deleteNode(int);
    bool addNodeRec(int);
    int findSmallest();
    int findLargest();
    int getSizeOfTree();
};
BST::BST(){
    
}
BST::~BST(){
    
}
Node* BST::createNode(int id, Node* parentN, Node* rightC, Node* leftC){
    Node* newNode=new Node;
    newNode->id=id;
    newNode->parent=parentN;
    newNode->right=rightC;
    newNode->left=leftC;
    return newNode;
}
int BST::findLargest(){
    if(root!=NULL){
        Node* tempNode=root;
        while(tempNode->right!=NULL){
            tempNode=tempNode->right;
        }
        return tempNode->id;
    }else{
        return -1;
    }
}
/*int BST::getSizeOfTree(){
    return getSize(root);
}
int BST::getSize(Node* startNode){
    int size=0;
    if(startNode!=NULL){
        size++;
        size=size+getSize(startNode->left);
        size=size+getSize(startNode->right);
    }
    return size;
}
bool BST::addNode(int item){
    Node* tempNode=root;
    Node* currParent=NULL;
    while(tempNode!=NULL){
        currParent=tempNode;
        if(item==tempNode->id){
            cout<<"can not add"<<endl;
            return false;
        }else {
            if（item<tempNode->id){
                tempNode=tempNode->left;
            }else {
                tempNode=tempNode->right;
            }
        }
    }
    if(currParent==NULL){
        root=createNode(item, NULL, NULL, NULL);
    }else if(item<currParent->id){
        currParent->left=tempNode(item, currParent,NULL,NULL);
    }else{
        currParent->right=createNode(item, currParent, NULL, NULL);
        
    }
 
}*/
bool BST::addNodeRec(int item){
    if(root==NULL){
        Node* newNode=createNode(item, NULL, NULL, NULL);
        root=newNode;
        cout<<"item "<<item<<" added as root"<<endl;
        return true;
    }else{
        return addNodePri(root, item);
    }
}
bool BST::addNodePri(Node* currNode,int item){
    if(item<currNode->id){
        if(currNode->left!=NULL){
            return(addNodePri(currNode->left, item));
        }else{
            currNode->left=createNode(item, currNode, NULL, NULL);
            return true;
        }
    }else if(item>currNode->id){
        if(currNode->right!=NULL){
            return(addNodePri(currNode->right, item));
        }else{
            currNode->right=createNode(item, currNode, NULL, NULL);
            return true;
        }
    }else{
        cout<<"item "<<item<<" is already in the tree";
        return false;
    }
    return false;
}
Node* search(Node* startNode,int item){
    if(startNode!=NULL){
        if(item<startNode->id && startNode->left!=NULL){
            return search(startNode->left,item);
        }else if(item<startNode->id && startNode->right!=NULL){
            return search(startNode->right,item);
        }else if(item==startNode->id){
            return startNode;
        }
    }else{
        cout<<"value not there"<<endl;
    }
    return startNode;
}
/*int mian(){
    BST myTree;
    myTree.addNodeRec(18);
    
    
}*/
