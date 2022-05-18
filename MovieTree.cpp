//
//  MovieTree.cpp
//  CSCI-2270
//
//  Created by 蒋新宇 on 2018/3/7.
//  Copyright © 2018年 XInyu JIang. All rights reserved.
//

#include "MovieTree.hpp"
#include <iostream>
using namespace std;
MovieTree::MovieTree(){
    root=NULL;
}
MovieTree::~MovieTree(){
    DeleteAll(root);
}
void MovieTree::DeleteAll(MovieNodeBST* myTree){
    MovieNodeLL* temp=new MovieNodeLL;
    MovieNodeLL* temp1=new MovieNodeLL;
    temp = myTree->head;
    if (temp == NULL) {
        return;
    }
    //cout << temp->title << endl;
    if(myTree->leftChild!=NULL){
        DeleteAll(myTree->leftChild);
    }
    if(myTree->rightChild!=NULL){
        DeleteAll(myTree->rightChild);
    }
    while(myTree->head!=NULL && temp!=NULL){
        cout<<"Deleting: "<<temp->title<<endl;
        temp1=temp->next;
        delete temp;
        temp = temp1;
        
    }
    delete myTree;
}
void MovieTree::addMovieNode(int tempRank, string tempTitle , int tempYear, int tempQuan){
    MovieNodeLL* tempLL=new MovieNodeLL(tempRank,tempTitle,tempYear,tempQuan);
    if(root==NULL){
        MovieNodeBST* tempRoot=new MovieNodeBST(tempTitle[0]);
        root=tempRoot;
        root->head=tempLL;
    }else{
        MovieNodeBST* tempRoot=root;
        MovieNodeBST* currentparent=NULL;
        while(tempRoot!=NULL){
            if(tempTitle[0]>tempRoot->letter){
                currentparent=tempRoot;
                tempRoot=tempRoot->rightChild;
            }else if(tempTitle[0]<tempRoot->letter){
                currentparent=tempRoot;
                tempRoot=tempRoot->leftChild;
            }else if(tempTitle[0]==tempRoot->letter){
                break;
            }
        }
        if(tempRoot==NULL){
            MovieNodeLL* myNode=new MovieNodeLL(tempRank,tempTitle,tempYear,tempQuan);
            MovieNodeBST* myRoot=new MovieNodeBST(tempTitle[0]);
            tempRoot=myRoot;
            if(currentparent->letter>tempRoot->letter){
                tempRoot->parent=currentparent;
                currentparent->leftChild=tempRoot;
            }else if(currentparent->letter<tempRoot->letter){
                tempRoot->parent=currentparent;
                currentparent->rightChild=tempRoot;
            }
            tempRoot->head=myNode;
        }else{
            MovieNodeLL* newNode=new MovieNodeLL(tempRank,tempTitle,tempYear,tempQuan);
            MovieNodeLL* tempAdd=tempRoot->head;
            MovieNodeLL*parent=NULL;
            while(tempAdd!=NULL && tempAdd->title<newNode->title){
                parent=tempAdd;
                tempAdd=tempAdd->next;
            }
            if(parent==NULL){
                newNode->next=tempAdd;
                tempRoot->head=newNode;
            }else{
                newNode->next=tempAdd;
                parent->next=newNode;
            }
        }
    }
}

void MovieTree::deleteMovieNode(string title){
    MovieNodeBST* treeNode=searchBST(root, title);
    if(treeNode==NULL){
        cout<<"Movie not found."<<endl;
        return;
    }
    MovieNodeLL* movieLL=searchLL(treeNode->head, title);
    if(movieLL==NULL){
        cout<<"Movie not found."<<endl;
        return;
    }
    if(movieLL==treeNode->head){
        if(movieLL->next!=NULL){
            //cout<<"first if"<<endl;
            MovieNodeLL* temp=treeNode->head;
            treeNode->head=treeNode->head->next;
            //cout<<temp->title<<endl;
            delete temp;
        }else if(movieLL->next==NULL){
            MovieNodeLL* temp=treeNode->head;
            treeNode->head=treeNode->head->next;
            //cout<<temp->title<<endl;
            delete temp;
            if(treeNode->leftChild==NULL && treeNode->rightChild==NULL){
                //cout<<"no children"<<endl;
                //delete treeNode;
                treeNode=NULL;
            }else if(treeNode->leftChild==NULL){
                cout<<"left"<<endl;
                MovieNodeBST* tempTree=treeNode;
                treeNode=treeNode->rightChild;
                delete tempTree;
            }else if(treeNode->rightChild==NULL){
                cout<<"right"<<endl;
                MovieNodeBST* tempTree=treeNode;
                treeNode=treeNode->leftChild;
                delete tempTree;
            }else{
                //cout<<"two children "<<endl;
                //cout<<"treeNode "<<treeNode<<endl;
                MovieNodeBST* tempTree=treeMinimum(treeNode->rightChild);
                treeNode->letter=tempTree->letter;
                treeNode->head=tempTree->head;
                //tempTree->rightChild=treeNode->rightChild;
                if(tempTree==treeNode->rightChild){
                    treeNode->rightChild=tempTree->rightChild;
                }else{
                    if(tempTree->rightChild==NULL){
                        tempTree->parent->rightChild=NULL;
                    }else{
                        tempTree->parent->leftChild=tempTree->rightChild;
                    }
                }
                delete tempTree;
            }
        }
    }else{
        //cout<<"fjbef"<<endl;
        MovieNodeLL* temp=treeNode->head;
        MovieNodeLL* previous=new MovieNodeLL;
        bool fl = false;
        while(temp!=NULL){
            if(temp->title==title){
                fl = true;
                break;
            }
            previous=temp;
            temp=temp->next;
        }
        if(fl==true){
            previous->next=temp->next;
            delete temp;
        }
    }
}
MovieNodeBST* MovieTree::treeMinimum(MovieNodeBST* node){
    if(node!=NULL){
        //cout << node << endl;
        while(node->leftChild!=NULL){
            node=node->leftChild;
            //cout<<node->head->title<<endl;
        }
        //cout << node << endl;
        return node;
    }else{
        return NULL;
    }
}

MovieNodeLL* MovieTree::searchLL(MovieNodeLL* head, string title){
    MovieNodeLL* temp=head;
    while(temp!=NULL){
        if(temp->title==title){
            break;
        }
        temp=temp->next;
    }
    return temp;
}
MovieNodeBST* MovieTree::searchBST(MovieNodeBST *node, string value) {
    // Your code here //
    while(node!=NULL){
        if(value[0]==node->letter){
            return node;
        }else if(value[0]>node->letter){
            node=node->rightChild;
        }else if(value[0]<node->letter){
            node=node->leftChild;
        }
    }
    return node;
}
void MovieTree::findMovie(string title){
    MovieNodeBST* tempRoot=searchBST(root, title);
    if(tempRoot==NULL){
        cout<<"Movie not found."<<endl;
        return;
    }
    MovieNodeLL* tempLL=tempRoot->head;
    while(tempLL!=NULL){
        if(tempLL->title==title){
            cout<<"Movie Info:"<<endl;
            cout<<"==========="<<endl;
            cout<<"Ranking:"<<tempLL->ranking<<endl;
            cout<<"Title:"<<tempLL->title<<endl;
            cout<<"Year:"<<tempLL->year<<endl;
            cout<<"Quantity:"<<tempLL->quantity<<endl;
            break;
        }
        tempLL=tempLL->next;
        if(tempLL==NULL){
            cout<<"Movie not found."<<endl;
        }else{
            
        }
    }
}
void MovieTree:: rentMovie(string title) {
    MovieNodeBST* tempRoot=searchBST(root, title);
    if(tempRoot==NULL){
        cout<<"Movie not found."<<endl;
        return;
    }
    MovieNodeLL* tempLL=tempRoot->head;
    while(tempLL!=NULL){
        if(tempLL->title==title){
            tempLL->quantity=tempLL->quantity-1;
            cout<<"Movie has been rented."<<endl;
            cout<<"Movie Info:"<<endl;
            cout<<"==========="<<endl;
            cout<<"Ranking:"<<tempLL->ranking<<endl;
            cout<<"Title:"<<tempLL->title<<endl;
            cout<<"Year:"<<tempLL->year<<endl;
            cout<<"Quantity:"<<tempLL->quantity<<endl;
            if(tempLL->quantity==0){
                //cout << "aaa" << endl;
                deleteMovieNode(tempLL->title);
                //cout << "bbb" << endl;
            }
            break;
        }
        tempLL=tempLL->next;
        if(tempLL==NULL){
            cout<<"Movie not found."<<endl;
        }
    }
}
int MovieTree::countMovieNodes(){
    int temp=0;
    countMovieNodes(root, &temp);
    return temp;
}
void MovieTree::countMovieNodes(MovieNodeBST *node, int *c) {
    if(node == NULL)
    {
        return;
    }
    MovieNodeLL* head=node->head;
    while(head!=NULL){
        (*c)++;
        head = head->next;
    }
    countMovieNodes(node->leftChild, c);
    countMovieNodes(node->rightChild, c);
}
void MovieTree::printMovieInventory(){
    printMovieInventory(root);
}
void MovieTree::printMovieInventory(MovieNodeBST* myTree){
    if(myTree->leftChild!=NULL){
        printMovieInventory(myTree->leftChild);
    }
    MovieNodeLL* temp=myTree->head;
    while(temp!=NULL){
        cout<<"Movie: "<<temp->title<<" "<<temp->quantity<<endl;
        temp=temp->next;
    }

    if(myTree->rightChild!=NULL){
        printMovieInventory(myTree->rightChild);
    }
}


