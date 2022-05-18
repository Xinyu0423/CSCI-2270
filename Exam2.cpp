//
//  Exam2.cpp
//  CSCI-2270
//
//  Created by 蒋新宇 on 2018/4/13.
//  Copyright © 2018年 XInyu JIang. All rights reserved.
//

#include "Exam2.hpp"
/*#include <iostream>
using namespace std;
struct TreeNode{
    int key;
    TreeNode *leftChild;
    TreeNode *rightChild;
    TreeNode *parent;
};
TreeNode* minNode(TreeNode* root){
    TreeNode* tempNode=root;
    while(tempNode->leftChild!=NULL){
        tempNode=tempNode->leftChild;
    }
    return tempNode;
}
TreeNode* maxNode(TreeNode* root){
    TreeNode* tempNode=root;
    while(tempNode->rightChild!=NULL){
        tempNode=tempNode->rightChild;
    }
    return tempNode;
}
void replaceMaxWithMin(TreeNode *root){
    if(root==NULL){
        return;
    }
    TreeNode* smallest=minNode(root);
    if(smallest->rightChild!=NULL){
        smallest->rightChild->parent=smallest->parent;
        smallest->parent->leftChild=smallest->rightChild;
    }else{
       smallest->parent->leftChild=NULL;
    }
    TreeNode* biggest=maxNode(root);
    biggest->key=smallest->key;
    delete smallest;
    
}*/

/*#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct vertex;
struct adjVertex{
vertex *v;
};
struct vertex{
    std::string name;
    bool visited;
    int distance;
    std::vector<adjVertex> adj;
};
          
class Graph
{
public:
    Graph();
    ~Graph();
    void addEdge(std::string v1, std::string v2);
    void addVertex(std::string name);
    bool ifPathExistsLessThanDist(string vertex1, string vertex2, int dist);
protected:
private:
    std::vector<vertex> vertices;
};
          
Graph::Graph()
{
}
          
Graph::~Graph()
{
    //dtor
}
void Graph::addEdge(string v1, string v2){
    for(int i = 0; i < (int)vertices.size(); i++){
        if(vertices[i].name == v1){
            for(int j = 0; j < (int)vertices.size(); j++){
                if(vertices[j].name == v2 && i != j){
                    adjVertex av;
                    av.v = &vertices[j];
                    vertices[i].adj.push_back(av);
                    //another vertex for edge in other direction
                    adjVertex av2;
                    av2.v = &vertices[i];
                    vertices[j].adj.push_back(av2);
                }
            }
        }
    }
}
void Graph::addVertex(string n){
    bool found = false;
    for(int i = 0; i < (int)vertices.size(); i++){
        if(vertices[i].name == n){
            found = true;
            //cout<<vertices[i].name<<" found."<<endl;
        }
    }
    if(found == false){
        vertex v;
        v.name = n;
        v.visited = false;
        vertices.push_back(v);
    }
}

bool Graph::ifPathExistsLessThanDist(string vertex1, string vertex2, int dest){
    vertex* startVert;
    //vertex* endVert=NULL;
    bool pathComplete=false;
    bool found=false;
    for(unsigned int i=0;i<vertices.size();i++){
        if(vertices[i].name==vertex1){
            startVert=&vertices[i];
        }
    }
    if(startVert!=NULL){
        startVert->visited=true;
        startVert->distance=0;
        queue<vertex*> vertexQ;
        vertexQ.push(startVert);
        while(vertexQ.size()!=0 && pathComplete==false){
            vertex* curV=vertexQ.front();
            vertexQ.pop();
            for(unsigned int i=0;i<curV->adj.size();i++){
                int count=0;
                if(curV->adj[i].v->visited==false){
                    curV->adj[i].v->visited=true;
                    curV->adj[i].v->distance=curV->distance+1;
                    if(curV->adj[i].v->name==vertex2){
                        pathComplete=true;
                        found=true;
                    }
                    if(curV->adj[i].v->distance>=dest){
                        return false;
                    }
                    count++;
                    curV->adj[i].v->visited=true;
                    vertexQ.push(curV->adj[i].v);
                }
            }
            
        }
    }
    if(found==true){
        return true;
    }else{
        return false;
    }
}
          
int main() {
    Graph g;
              
    g.addVertex("a");
    g.addVertex("b");
    g.addVertex("c");
    g.addVertex("d");
    g.addVertex("e");
              
    g.addEdge("a", "b");
    g.addEdge("a", "d");
    g.addEdge("c", "d");
    g.addEdge("b", "c");
    g.addEdge("d", "e");
    g.addEdge("c", "e");
              
    //cout << g.ifPathExistsLessThanDist("c", "b", 1) << endl;;
    //cout << g.ifPathExistsLessThanDist("a", "e", 1) << endl;;
    cout << g.ifPathExistsLessThanDist("a", "e", 3) << endl;;
    //cout << g.ifPathExistsLessThanDist("c", "b", 1) << endl;;
    //cout << g.ifPathExistsLessThanDist("c", "b", 2) << endl;;
    //cout << g.ifPathExistsLessThanDist("c", "d", 2) << endl;;
    //cout << g.ifPathExistsLessThanDist("c", "f", 99) << endl;;
    //cout << g.ifPathExistsLessThanDist("a", "g", 3) << endl;;
    return 0;
}*/
