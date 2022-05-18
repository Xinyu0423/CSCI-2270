//
//  InClassExerciseGraph.cpp
//  CSCI-2270
//
//  Created by 蒋新宇 on 2018/3/19.
//  Copyright © 2018年 XInyu JIang. All rights reserved.
//
/*#include "InClassExerciseGraph.hpp"
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct vertex;

struct adjVertex{
    vertex* v;
    int weight;
};
class Graph{
private:
    vector<vertex> vertices;
    vertex* findVertex(string);
public:
    Graph();
    ~Graph();
    void insertVertex(string);
    void insertEdge(string, string,int);
    void printGraph();
    void BSTTraversal(string);
};
struct vertex{
    string key;
    vector<adjVertex> adjacent;
    bool visted=false;
};
void Graph::insertVertex(string value){
    bool flag=false;
    int i=0;
    while(i<vertices.size() && flag==false){
        if(vertices[i].key==value){
            flag=true;
        }
        i++;
    }
    if(flag==false){
        vertex v;
        v.key=value;
        vertices.push_back(v);
    }else{
        cout<<value<<" has already in there"<<endl;
    }
}
vertex* Graph::findVertex(string value){
    int i=0;
    while(i<vertices.size()){
        if(vertices[i].key==value){
            return &vertices[i];
        }
        i++;
    }
    return NULL;
}
void Graph::insertEdge(string v1, string v2, int weight){
    vertex *vStart=findVertex(v1);
    vertex *vEnd=findVertex(v2);
    if(vStart!=NULL && vEnd!=NULL){
        adjVertex v1v2Edge;
        v1v2Edge.weight=weight;
        v1v2Edge.v=vEnd;
        vStart->adjacent.push_back(v1v2Edge);
    }else{
        if(vStart==NULL){
            cout<<"no vertext "                 <<v1<<" in the graph"<<endl;
        }
        if(vEnd==NULL){
            cout<<"no vertext "<<v2<<" in the graph"<<endl;
        }
    }
}
void Graph:: BSTTraversal(string vertName){
    queue<vertex*> vertexQ;
    vertex* currentVert=findVertex(vertName);
    if(currentVert!=NULL){
        currentVert->visted=true;
        vertexQ.push(currentVert);
        while(vertexQ.size()!=0){
            vertex* curV=vertexQ.front();
            //peek
            vertexQ.pop();
            //dequeue
            for(int i=0;i<curV->adjacent.size();i++){
                if(curV->adjacent[i].v->visted==false){
                    curV->adjacent[i].v->visted=true;
                    cout<<"visited "<<curV->adjacent[i].v->key<<endl;
                    vertexQ.push(curV->adjacent[i].v);
                }
            }
        }
    }else{
        cout<<vertName<<" not in the graph"<<endl;
    }
}
int main(){
    Graph myGraph;
    myGraph.insertVertex("South Boulder");
    myGraph.insertVertex("Glacier Ice Cream");
    myGraph.insertVertex("Golden");
    myGraph.insertVertex("Superior");
    myGraph.insertVertex("Superior Costco");
    myGraph.insertVertex("Wildwood Guitars");
    myGraph.insertVertex("Denver");
    myGraph.insertVertex("Rep Fitness");
    myGraph.insertVertex("IKEA");
    myGraph.insertEdge("South Boulder","Glacier Icer Cream", 1);
    myGraph.insertEdge("Glacier Ice Cream", "South Boulder", 1);
    myGraph.insertEdge("South Boulder","Superior", 5);
    myGraph.insertEdge("South Boulder", "Golden", 15);
    myGraph.insertEdge("Golden", "South Boulder",15);
    cout<<"start at South Boulder"<<endl;
    myGraph.BSTTraversal("South Boulder");
}*/
