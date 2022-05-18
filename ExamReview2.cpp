//
//  ExamReview2.cpp
//  CSCI-2270
//
//  Created by 蒋新宇 on 2018/4/11.
//  Copyright © 2018年 XInyu JIang. All rights reserved.
//

#include "ExamReview2.hpp"
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
//question 1
/*
struct adjVertex;

struct vertex{
    std::string name;
    bool visited;
    vertex *prev;
    std::vector<adjVertex> adj;
};
struct adjVertex{
    vertex *v;
    int weight;
};
class Graph
{
public:
    Graph();
    ~Graph();
    void addEdge(std::string v1, std::string v2, int weight);
    void addVertex(std::string name);
    void shortestPath(string source, string destination, string intermediate);
protected:
private:
    std::vector<vertex> vertices;
};
void Graph::shortestPath(string source, string destination, string intermediate){
    vertex* startVert;
    vertex* endVert=NULL;
    for(unsigned int i=0;i<vertices.size();i++){
        if(vertices[i].name==source){
            startVert=&vertices[i];
        }
    }
    bool pathComplete=false;
    if(startVert!=NULL){
        startVert->visited=true;
        startVert->prev=NULL;
        queue<vertex*> vertexQ;
        vertexQ.push(startVert);
        while(vertexQ.size()!=0 && pathComplete==false){
            vertex* curV=vertexQ.front();
            vertexQ.pop();
            for(unsigned int i=0;i<curV->adj.size();i++){
                if(curV->adj[i].v->visited==false){
                    curV->adj[i].v->prev=curV;
                    if(curV->adj[i].v->name==destination){
                        //cout<<"Yes"<<endl;
                        endVert=curV->adj[i].v;
                        pathComplete=true;
                    }else{
                        curV->adj[i].v->visited=true;
                        vertexQ.push(curV->adj[i].v);
                    }
                }
            }
            if(pathComplete==true){
                break;
            }
        }
        pathComplete=false;
        bool flag=false;
        while(endVert!=NULL){
            if(endVert->name==intermediate){
                flag=true;
                break;
            }
            endVert=endVert->prev;
        }
        if(flag==true){
            cout<<"Yes"<<endl;
            return;
        }else{
            cout<<"No"<<endl;
            return;
        }
    }
}*/
//Question 2
/*struct adjVertex;
struct vertex{
    int value;
    int parentID;
    bool visited;
    std::vector<adjVertex> adj;
};
struct adjVertex{
    vertex *v;
};
class Graph
{
public:
    Graph();
    ~Graph();
    void addEdge(int v1, int v2);
    void addVertex(int name);
    void displayEdges();
    void printMislabeledParents(int startVertex);
private:
    std::vector<vertex> vertices;
};
void Graph::printMislabeledParents(int startVertex) {
    vertex *start;
    for (int i = 0; i < (int)vertices.size(); i++) {
        vertices[i].visited = false;
        if (vertices[i].value == startVertex) {
            start = &vertices[i];
        }
    }
    
    queue<vertex*> Q;
    Q.push(start);
    start->visited = true;
    cout << start->value << endl;
    while (!Q.empty()) {
        vertex *node = Q.front();
        Q.pop();
        for(unsigned int i=0;i<node->adj.size();i++){
            if(node->adj[i].v->visited==false){
                if(node->value!=node->adj[i].v->parentID){
                    cout<<node->adj[i].v->value<<endl;
                }else{
                    node->adj[i].v->visited=true;
                    Q.push(node->adj[i].v);
                }
            }
        }
        
    }
}*/
//Question 3
/*struct adjVertex;

struct vertex{
    int value;
    bool visited;
    std::vector<adjVertex> adj;
};
struct adjVertex{
    vertex *v;
};
class Graph
{
public:
    Graph();
    ~Graph();
    void addEdge(int v1, int v2);
    void addVertex(int name);
    void displayEdges();
    void findOddAdjacent(int startVertex);
private:
    std::vector<vertex> vertices;
};
void Graph::findOddAdjacent(int startVertex) {
    vertex *start;
    for (int i = 0; i < (int)vertices.size(); i++) {
        vertices[i].visited = false;
        if (vertices[i].value == startVertex) {
            start = &vertices[i];
        }
    }
    
    queue<vertex*> Q;
    Q.push(start);
    start->visited = true;
    cout << start->value << " ";
    while (!Q.empty()) {
        vertex *node = Q.front();
        Q.pop();
        for (int i = 0; i < (int)node->adj.size(); i++) {
            if(node->adj[i].v->visited==false){
                if((node->adj[i].v->value%2)==1){
                    cout<<node->adj[i].v->value<<" ";
                }
                    node->adj[i].v->visited=true;
                    Q.push(node->adj[i].v);
                
            }
            
        }
    }
}*/
//Question 4
/*struct adjVertex;

struct vertex{
    int value;
    bool visited;
    std::vector<adjVertex> adj;
};
struct adjVertex{
    vertex *v;
};
class Graph
{
public:
    Graph();
    ~Graph();
    void addEdge(int v1, int v2);
    void addVertex(int name);
    void displayEdges();
    void findNodeWithMaximumAdjacent(int startVertex);
private:
    std::vector<vertex> vertices;
};
void Graph::findNodeWithMaximumAdjacent(int startVertex) {
    vertex *start;
    for (int i = 0; i < (int)vertices.size(); i++) {
        vertices[i].visited = false;
        if (vertices[i].value == startVertex) {
            start = &vertices[i];
        }
    }
    
    queue<vertex*> Q;
    Q.push(start);
    start->visited = true;
    cout << start->value << " ";
    int count=0;
    int tempValue=0;
    //Students have to fill in this part
    while (!Q.empty()) {
        vertex *node = Q.front();
        Q.pop();
        for (int i = 0; i < (int)node->adj.size(); i++) {
            
            //Students have to fill in this part of the code and you can print the output within the loop as well as outside the loop
            if(int(node->adj.size())>count){
                count=node->adj.size();
                tempValue=node->value;
            }
            if(node->adj[i].v->visited==false){
                node->adj[i].v->visited=true;
                cout<<node->adj[i].v->value<<" ";
                Q.push(node->adj[i].v);
            }
        }
    }
    cout<<endl;
    cout<<tempValue<<endl;
}*/

//question 5
/*struct TreeNode
{
    char key;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
};
struct Node{
    char key;
    Node *next;
};

Node *head = NULL;
void RangeSearch(TreeNode *node, char m, char n){
    
}
*/
//question 6
/*struct Node{
    int key;
    Node *parent;
    Node *left;
    Node *right;
    Node(Node *p, Node *l, Node *r){
        parent = p;
        left = l;
        right = r;
    }
};
Node* insert(Node *root, int value){
    Node* tempNode=root;
    Node* curParent=NULL;
    while(tempNode!=NULL){
        curParent=tempNode;
        if(value<tempNode->key){
            tempNode=tempNode->left;
        }else if(value>tempNode->key){
            tempNode=tempNode->right;
        }
    }
    Node* instertNode=new Node(NULL,NULL,NULL);
    instertNode->key=value;
    if(curParent==NULL){
        root=instertNode;
    }else if(value<curParent->key){
        curParent->left=instertNode;
        cout << "inserted: " << instertNode->key << " left child of: " << curParent->key<<endl;
    }else if(value>curParent->key){
        cout << "inserted: " <<instertNode->key<< " right child of: " <<curParent->key<<endl;
    }
    return instertNode;
}*/

//question 7
/*struct adjVertex;
struct vertex{
    std::string name;
    bool visited;
    string color;
    std::vector<adjVertex> adj;
};
struct adjVertex{
    vertex *v;
    int weight;
};
class Graph
{
public:
    Graph();
    ~Graph();
    void addEdge(std::string v1, std::string v2, int weight);
    void addVertex(std::string name);
    void displayEdges();
    void colorVertices(string sourceVertex);
protected:
private:
    std::vector<vertex> vertices;
    
};
void Graph:: colorVertices(string sourceVertex){
    vertex* startVert;
    for(int i=0;i<vertices.size();i++){
        if(vertices[i].name==sourceVertex){
            startVert=&vertices[i];
        }
    }
    if(startVert!=NULL){
        startVert->visited=true;
        startVert->color="Red";
        queue<vertex*> vertexQ;
        vertexQ.push(startVert);
        while(vertexQ.size()!=0){
            vertex* curV=vertexQ.front();
            vertexQ.pop();
            for(int i=0;i<curV->adj.size();i++){
                if(curV->adj[i].v->visited==false){
                    if(curV->color=="Red"){
                        curV->adj[i].v->color="Black";
                    }else if(curV->color=="Black"){
                        curV->adj[i].v->color="Red";
                    }
                    curV->adj[i].v->visited=true;
                    vertexQ.push(curV->adj[i].v);
                }
            }
        }
    }
}*/
//Question 8
/*struct vertex;
struct adjVertex{
    vertex *v;
    int weight;
};
struct vertex{
    std::string name;
    bool visited;
    std::vector<adjVertex> adj;
};
class Graph
{
public:
    Graph();
    ~Graph();
    void addEdge(std::string v1, std::string v2, int weight);
    void addVertex(std::string name);
    void findVerticesWithNoAdjacentVertices();
protected:
private:
    std::vector<vertex> vertices;
};
void Graph::findVerticesWithNoAdjacentVertices(){
    vertex* startVert;
    bool found=false;
    for(int i=0;i<vertices.size();i++){
        startVert=&vertices[i];
        if(startVert!=NULL){
            startVert->visited=true;
            if(startVert->adj.size()==0){
                found=true;
                cout<<startVert->name<<" ";
            }
        }
    }
    if(found==false){
        cout<<"Not Found!"<<endl;
    }
}*/
