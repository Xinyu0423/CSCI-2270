//
//  Graph.cpp
//  CSCI-2270
//
//  Created by 蒋新宇 on 2018/3/20.
//  Copyright © 2018年 XInyu JIang. All rights reserved.
//

#include "Graph.hpp"
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <climits>

using namespace std;
Graph::Graph(){
    
}
Graph::~Graph(){
    
}
void Graph::addVertex(string name){
    bool flag=false;
    int i=0;
    while(i<vertices.size() && flag==false){
        if(vertices[i].name==name){
            flag=true;
        }
        i++;
    }
    if(flag==false){
        vertex v;
        v.name=name;
        v.districtID=-1;
        v.visited=false;
        vertices.push_back(v);
    }else{
        cout<<name<<" already in the graph."<<endl;
    }
}
void Graph::addEdge(string v1, string v2, int weight){
    vertex* vStart=NULL;
    vertex* vEnd=NULL;
    int i=0;
    while(i<vertices.size()){
        if(vertices[i].name==v1){
            vStart=&vertices[i];
        }else if(vertices[i].name==v2){
            vEnd=&vertices[i];
        }
        i++;
    }
    if(vStart!=NULL && vEnd!=NULL){
        adjVertex v1v2Edge;
        v1v2Edge.weight=weight;
        v1v2Edge.v=vEnd;
        vStart->adj.push_back(v1v2Edge);
    }
}
void Graph::displayEdges(){
    //loop through all vertices and adjacent vertices
    for(int i = 0; i < vertices.size(); i++){
        cout<<vertices[i].districtID<<":";
        cout<<vertices[i].name<<"-->";
        for(int j = 0; j < vertices[i].adj.size(); j++){
            cout<<vertices[i].adj[j].v->name;
            if(j!=vertices[i].adj.size()-1){
                cout<<"***";
            }
        }
        cout<<endl;
    }
    
}
void Graph::assignDistricts(){
    int districts=1;
    int count=1;
    for(int i=0;i<vertices.size();i++){
        vertices[i].districtID=-1;
    }
    for(int i=0;i<vertices.size();i++){
        if(vertices[i].districtID==-1){
            //cout<<"runs "<<count<<" times"<<endl;
            count++;
            DFSLabel(vertices[i].name, districts);
            districts++;
        }
    }
}
void Graph::DFSLabel(string startingCity, int distID){
    vertex* currVertex=findVertex(startingCity);
    //cout<<currVertex->name<<endl;
    currVertex->districtID=distID;
    if(currVertex!=NULL){
        currVertex->visited=true;
        stack<vertex*> vertexStack;
        vertexStack.push(currVertex);
        while(vertexStack.empty()==false){
            vertex* curr=vertexStack.top();
            vertexStack.pop();
            for(int i=0;i<curr->adj.size();i++){
                if(curr->adj[i].v->visited==false){
                    curr->adj[i].v->visited=true;
                    if(curr->adj[i].v->districtID==-1){
                        curr->adj[i].v->districtID=distID;
                    }
                    
                    vertexStack.push(curr->adj[i].v);
                }
            }
        }
    }
}
void Graph::shortestPath(string startCity, string endCity){
    vertex* startVert=findVertex(startCity);
    vertex* endVert=findVertex(endCity);
    bool pathComplete=false;
    if(startVert==NULL || endVert==NULL){
        cout<<"One or more cities doesn't exist"<<endl;
        return;
    }
    if(startVert->districtID!=endVert->districtID){
        cout<<"No safe path between cities"<<endl;
        return;
    }
    if(startVert!=NULL && endVert!=NULL){
        for(int i=0;i<vertices.size();i++){
            vertices[i].visited=false;
        }
        startVert->visited=true;
        startVert->unweightedDistance=0;
        startVert->parent=NULL;
        queue<vertex*> vertexQ;
        vertexQ.push(startVert);
        while(vertexQ.size()!=0 && pathComplete==false){
            vertex* curV=vertexQ.front();
            vertexQ.pop();
            for(int i=0;i<curV->adj.size();i++){
                if(curV->adj[i].v->visited==false){
                    curV->adj[i].v->unweightedDistance=curV->unweightedDistance+1;
                    curV->adj[i].v->parent=curV;
                    if(curV->adj[i].v->name==endCity){
                        pathComplete=true;
                    }
                    curV->adj[i].v->visited=true;
                    vertexQ.push(curV->adj[i].v);
                }
            }
        }
        if(pathComplete==true){
            vector<vertex*> myVector;
            cout<<endVert->unweightedDistance;
            vertex* curParent=endVert;
            while(curParent!=NULL){
                myVector.push_back(curParent);
                curParent=curParent->parent;
            }
            //cout<<"size== "<<myVector.size()<<endl;
            //cout<<"testing on index 2"<<myVector[2]->name<<endl;
            for(int i=myVector.size()-1;i>=0;i--){
                cout<<", "<<myVector[i]->name;
            }
            cout<<endl;
        }
    }
}
vertex* Graph::findVertex(string cityName){
    for(int i=0;i<vertices.size();i++){
        if(vertices[i].name==cityName){
            return & vertices[i];
        }
    }
    return NULL;
}
void Graph::shortestWeightedPath(string startCity, string endCity){
    vertex* startVert=findVertex(startCity);
    vertex* endVert=findVertex(endCity);
    int curDistance;
    int minDistance;
    vertex* solvedVert;
    vertex* curV;
    vertex* curParent;
    vertex* tempNode;
    if(startVert==NULL || endVert==NULL){
        cout<<"No safe path between cities"<<endl;
        return;
    }
    if(startVert->districtID!=endVert->districtID){
        cout<<"No safe path between cities"<<endl;
        return;
    }
    if(startVert->districtID==-1 || endVert->districtID==-1){
        cout<<"Please identify the districts before checking distances"<<endl;
        return;
    }
    if(startVert!=NULL && endVert!=NULL){
        for(int i=0;i<vertices.size();i++){
            vertices[i].visited=false;
            vertices[i].weightedDistance=INT_MAX;
        }
        startVert->visited=true;
        startVert->weightedDistance=0;
        vector<vertex*> solvedVertices;
        solvedVertices.push_back(startVert);
        while(endVert->visited==false){
            minDistance=INT_MAX;
            solvedVert=NULL;
            for(int i=0;i<solvedVertices.size();i++){
                curV=solvedVertices[i];
                for(int j=0;j<curV->adj.size();j++){
                    if(curV->adj[j].v->visited==false){
                        curDistance=curV->weightedDistance+curV->adj[j].weight;
                        if(curDistance<minDistance){
                            solvedVert=curV->adj[j].v;
                            minDistance=curDistance;
                            curParent=curV;
                        }
                    }
                }
            }
            solvedVert->weightedDistance=minDistance;
            solvedVert->parent=curParent;
            solvedVert->visited=true;
            solvedVertices.push_back(solvedVert);
            
        }
        cout<<endVert->weightedDistance;
        vector<vertex*> myVector;
        vertex* tempParent=endVert;
        while(tempParent!=NULL){
            myVector.push_back(tempParent);
            tempParent=tempParent->parent;
            if(tempParent->name==startCity){
                break;
            }

        }
        //cout<<"size== "<<myVector.size()<<endl;
        //cout<<"testing on index 2"<<myVector[2]->name<<endl;
        cout<<", "<<startCity;
        for(int i=myVector.size()-1;i>=0;i--){
            cout<<", "<<myVector[i]->name;
        }
        cout<<endl;

    }
}

