
#include <iostream>
#include "Recitation6.h"
using namespace std;
//Create a node with key as data
 
/*
 node* BST:: createNode(int data)
{
    node* nn = new node;
    nn->key = data;
    nn->left = NULL;
    nn->right = NULL;
    nn->parent = NULL;
    return nn;
}

BST::BST()
{
    
}

// parameterized constructor. It will create the root and put the data in the root.
 
BST::BST(int data)
{
    root = createNode(data);
}

// Destructor
 
BST::~BST(){
    
    destroyNode(root);
    
}
 
 //This function will destroy the subtree rooted at curNode.
 //Think about in what order should you destroy.
 
void BST:: destroyNode(node *curNode){
    if(curNode)
    {
        destroyNode(curNode->left);
        destroyNode(curNode->right);
        delete curNode;
        curNode = NULL;
    }
}

 //This function will search the data in a tree rooted at root
 //We will call this function from searchKey.
 //NOTE: As root is a private member of BST class, main function can not access root.
 //So we need this helper function.
 
bool BST::searchKeyHelper(node* root, int data){
    //TODO: Implement your searching function here.
    // Function will return true if the data is there. Else it will return false.
    if(root!=NULL){
        if(data<root->key && root->left!=NULL){
            return searchKeyHelper(root->left, data);
        }else if(data>root->key && root->right!=NULL){
            return searchKeyHelper(root->right, data);
        }else if(data==root->key){
            cout<<data<<" found"<<endl;
            return true;
        }else{
            cout<<"can not find the data"<<data<<endl;
            return false;
        }
    }else{
        return false;
    }
}

 //This function will search the data in the tree
 
bool BST::searchKey(int data){
    return searchKeyHelper(root, data);
}

 
 //This function will add the data in the tree rooted at curNode.
 //We will call this function from insertNode.
 //NOTE: root is a private member of BST. As root is a private member of BST class, main
 //function can not access root.
 //So we need this helper function. Implement your code for inserting a node in this function.
 
node* BST:: insertNodeHelper(node* curNode, int data){
    //TODO: Implement the code for insert a node at the tree rooted at curNode.
    node* tempNode=root;
    node* currParent=NULL;
    while(tempNode!=NULL){
        currParent=tempNode;
        if(data==tempNode->key){
            cout<<"can not add "<<data<<", "<<data<<" has already in the tree"<<endl;
            break;
        }else{
            if(data<tempNode->key){
                tempNode=tempNode->left;
            }else if(data>tempNode->key){
                tempNode=tempNode->right;
            }
        }
    }
    if(data<currParent->key){
        currParent->left=createNode(data);
    }else if(data>currParent->key){
        currParent->right=createNode(data);
    }
    return currParent;
}


 This function will insert the data in the tree. As this function can not access the root
 it will call the insertNodeHelper function.
 
void BST:: insertNode( int data){
    if(root == NULL) // if the BST is empty create the root
        root = createNode(data);
    else // insert the data in the tree rooted at root
        insertNodeHelper(root, data);
}

 This function will traverse the tree in-order and print out the node elements.
 printTree() function will call this function.
 NOTE: As root is a private member of BST class, main function can not access root. So printTree will
 call this helper function.
 
void BST:: printTreeHelper(node* curNode){
    if(curNode)
    {
        printTreeHelper( curNode->left);
        cout << curNode->key<<endl;
        printTreeHelper( curNode->right);
    }
}

void BST:: printTree(){
    printTreeHelper(root);
}
int main(){
    BST* myTree=new BST(22);
    myTree->insertNode(5);
    myTree->insertNode(6);
    myTree->insertNode(10);
    myTree->insertNode(10);
    myTree->printTree();
    myTree->searchKey(10);
    myTree->searchKey(99);
    
}*/
