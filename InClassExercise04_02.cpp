//
//  InClassExercise04_02.cpp
//  CSCI-2270
//
//  Created by 蒋新宇 on 2018/4/2.
//  Copyright © 2018年 XInyu JIang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
//NEW
#include <stack>
#include <string>

using namespace std;

//CONTINUING LECTURE 27.CPP

//statically declared things go in the stack, dynamically go in heap

//if two vertices have an edge connecting them, they're adjacent
struct vertex;

struct adjVertex
{
    vertex* v; //allows us to store pointer to a vertex
    int weight;
};

struct vertex
{
    string key;
    vector<adjVertex> adjacent; //each thing in here is an adjacent vertex
    bool visited = false;
    int distance;
    vertex* parent;
    bool solved=false;
    //added for dijkstra
};

class Graph
{
private:
    //vertices
    vector<vertex> vertices;
    vertex* findVertex(string); //given a key, will return a pointer to the vertex
    //NEW
    void DFS(vertex*);
public:
    //methods for accessing graphs
    Graph();
    ~Graph();
    void insertVertex(string); //has identifier of the vertex (what string)
    void insertEdge(string, string, int); //start, end, weight
    void printGraph();
    void BFTraversal(string); //pass start node
    //NEW
    void DFSearch(string); //start node
    void DFSearchNR(string); //start node
    void resetGraph();
    int BSTDistanceBetween(string, string);
    void BSTPath(string,string);
    void dijkstra(string,string);
};

Graph::Graph()
{
    
}

Graph::~Graph()
{
    
}

//NEW
void Graph::resetGraph()
{
    //wanna reset flags in the graph if we wanted to do multiple searches
    for (int i = 0; i < vertices.size(); i++)
    {
        //these are statically declared
        //the pointers are pointing to the statically declared variables
        //so because the variable is statically declared, the pointer is already statically declared
        
        vertices[i].visited = false;
        vertices[i].parent=NULL;
        vertices[i].solved=false;
        vertices[i].distance=-1;
        
         //for (int j = 0; j < vertices[i].adjacent.size(); j++)
         //{
         //each pointer in the adjacency list, we set it to false twice
         //vertices[i].adjacent[j].v->visited = false;
         //}
         
    }
}

void Graph::insertVertex(string value)
{
    bool found = false;
    int i = 0;
    while (i < vertices.size() && !found)
    {
        if (vertices[i].key == value)
        {
            found = true;
        }
        i++;
    }
    if (!found)
    {
        vertex v;
        v.key = value;
        vertices.push_back(v);
    }
    else
    {
        cout << "There is already a vertex " << value << " in this graph" << endl;
    }
}

vertex* Graph::findVertex(string value)
{
    int i = 0;
    while (i < vertices.size())
    {
        if (vertices[i].key == value)
        {
            return & vertices[i];
        }
        i++;
    }
    return nullptr;
}


void Graph::insertEdge(string v1, string v2, int weight)
{
    //just does one edge, have to call twice for bidirectional edges8
    vertex* vStart = findVertex(v1);
    vertex* vEnd = findVertex(v2);
    if (vStart != nullptr && vEnd != nullptr)
    {
        //this code assumts that an edge doesn't exist
        //write some error checking to handle when it does
        adjVertex v1v2Edge;
        v1v2Edge.weight = weight;
        v1v2Edge.v = vEnd;
        vStart->adjacent.push_back(v1v2Edge);
    }
    else
    {
        if (vStart == nullptr)
        {
            cout << "No vertex with name " << v1 << " in this graph" << endl;
        }
        if (vEnd == nullptr)
        {
            cout << "No vertex with name " << v2 << " in this graph" << endl;
        }
    }
}

void Graph::BFTraversal(string vertName)
{
    queue<vertex*> vertexQ;
    vertex* currentVert = findVertex(vertName);
    if (currentVert != nullptr)
    {
        currentVert->visited = true;
        vertexQ.push(currentVert);
        while (vertexQ.size() != 0)
        {
            vertex* curV = vertexQ.front(); //like peek
            vertexQ.pop(); //like dequeue
            for (int i = 0; i < curV->adjacent.size(); i++)
            {
                //have or have not visited?
                if (!curV->adjacent[i].v->visited)
                {
                    curV->adjacent[i].v->visited = true;
                    cout << "Just visited " << curV->adjacent[i].v->key << endl;
                    //we push the thing from the adjacency list
                    vertexQ.push(curV->adjacent[i].v);
                }
            }
        }
    }
    else
    {
        cout << "Vertex " << vertName << " not in graph" << endl;
    }
}

//NEW
void Graph::DFS(vertex* curV)
{
    //goes all the way down one side before going down another side
    curV->visited = true;
    for (int i = 0; i < curV->adjacent.size(); i++)
    {
        if (!curV->adjacent[i].v->visited)
        {
            cout << "Just visited " << curV->adjacent[i].v->key << endl;
            //because it's recursive, we want to use nodes
            DFS(curV->adjacent[i].v);
        }
    }
}

//NEW
void Graph::DFSearch(string vertName)
{
    //this function is just a wrapper for our DFS recursive function
    vertex* currentVert = findVertex(vertName);
    if (currentVert != nullptr)
    {
        cout << "Starting depth first search at " << vertName << endl;
        DFS(currentVert);
    }
    else
    {
        //output error
    }
}

//NEW
void Graph::DFSearchNR(string vertName)
{
    vertex* currentVert = findVertex(vertName);
    if (currentVert != nullptr)
    {
        currentVert->visited = true;
        cout << "Starting non-recursive depth first search" << endl;
        stack<vertex*> vertStack;
        vertStack.push(currentVert);
        while (!vertStack.empty())
        {
            vertex* curV = vertStack.top(); //like peek //returns a thing
            vertStack.pop(); //doesn't return a thing, removes from the top
            cout << "Just visited " << curV->key << endl;
            for (int i = 0; i < curV->adjacent.size(); i++)
            {
                if (!curV->adjacent[i].v->visited)
                {
                    curV->adjacent[i].v->visited = true;
                    vertStack.push(curV->adjacent[i].v);
                }
            }
        }
    }
    else
    {
        //error
    }
}
int Graph::BSTDistanceBetween(string start, string end){
    vertex* startVert=findVertex(start);
    vertex* endVert=findVertex(end);
    if(startVert!=NULL && endVert!=NULL){
        startVert->visited=true;
        startVert->distance=0;
        queue<vertex*> vertexQ;
        vertexQ.push(startVert);
        while(vertexQ.size()!=0){
            vertex* curv=vertexQ.front();
            vertexQ.pop();
            for(int i=0;i<curv->adjacent.size();i++){
                if(curv->adjacent[i].v->visited==false){
                    curv->adjacent[i].v->distance=curv->distance+1;
                    if(curv->adjacent[i].v->key==end){
                        return curv->adjacent[i].v->distance;
                    }else{
                        curv->adjacent[i].v->visited=true;
                        vertexQ.push(curv->adjacent[i].v);
                    }
                }
            }
        }
    }else{
        if(startVert==NULL){
            cout<<"error"<<endl;
        }
        if(endVert==NULL){
            cout<<"error"<<endl;
        }
        return -1;
    }
    cout<<"no connection between two points"<<endl;
    return -1;
}
void Graph::BSTPath(string start, string end){
    vertex* startVert=findVertex(start);
    vertex* endVert=findVertex(end);
    bool pathComplete=false;
    if(startVert!=NULL && endVert!=NULL){
        startVert->visited=true;
        startVert->distance=0;
        startVert->parent=NULL;
        queue<vertex*> vertexQ;
        vertexQ.push(startVert);
        while(vertexQ.size()!=0 && pathComplete==false){
            vertex* curv=vertexQ.front();
            vertexQ.pop();
            for(int i=0;i<curv->adjacent.size();i++){
                if(curv->adjacent[i].v->visited==false){
                    curv->adjacent[i].v->distance=curv->distance+1;
                    curv->adjacent[i].v->parent=curv;
                    if(curv->adjacent[i].v->key==end){
                        pathComplete=true;
                    }else{
                        curv->adjacent[i].v->visited=true;
                        vertexQ.push(curv->adjacent[i].v);
                    }
                }
            }
        }
        if(pathComplete==true){
            int hotCount=0;
            cout<<"backward start at"<<end<<endl;
            vertex* curParent=endVert->parent;
            
            while(curParent!=NULL){
                hotCount++;
                cout<<"next hop"<<curParent->key<<endl;
                cout<<"hop count"<<hotCount<<endl;
                curParent=curParent->parent;
            }
            cout<<"done"<<endl;
        }else{
            cout<<"there is no path"<<endl;
        }
    }
}
//Note: this implementation assume there is a path between start to end;
void Graph::dijkstra(string startKey, string endKey){
    vertex* startVert=findVertex(startKey);
    vertex* endVert=findVertex(endKey);
    int curDist;
    int minDistance;
    vertex* solvedVertex;
    vertex* curV;
    vertex* curParent;
    if(startVert!=NULL && endVert!=NULL){
        startVert->solved=true;
        startVert->distance=0;
        vector<vertex*> solvedVertices;
        solvedVertices.push_back(startVert);
        while(endVert->solved==false){
            minDistance=INT_MAX;
            //Int_MAX is largest number in int
            solvedVertex=NULL;
            for(int i=0;i<solvedVertices.size();i++){
                curV=solvedVertices[i];
                for(int j=0;j<curV->adjacent.size();j++){
                    if(curV->adjacent[j].v->solved==false){
                        curDist=curV->distance+curV->adjacent[j].weight;
                        if(curDist<minDistance){
                            solvedVertex=curV->adjacent[j].v;
                            minDistance=curDist;
                            curParent=curV;
                            
                        }
                    }
                }
            }
            solvedVertex->distance=minDistance;
            solvedVertex->parent=curParent;
            solvedVertex->solved=true;
            solvedVertices.push_back(solvedVertex);
        }
        cout<<"short path from "<<startKey<<" to "<<endKey<<" "<<endVert->distance<<endl;
    }else{
        
    }
}
/*int main(){
    
     //vector<vertex> (vector of structs)
     //vector designed for queues/if the order doesn't matter, like with graphs
     //vector<int> vectorOfInts;
     //vectorOfInts.push_back(5); //puts something at the end of the vector
     //cout << "Size of vectorOfInts: " << vectorOfInts.size() << endl;
     //vectorOfInts.push_back(10);
     //vectorOfInts.push_back(15);
     
     //for (int i = 0; i < vectorOfInts.size(); i++){
     //cout << "Item " << i << " is " << vectorOfInts[i] << endl;
     //}
     //for loop will cout:
     //Item 0 is 5
     //Item 1 is 10
     //Item 2 is 15
     
    
    Graph grasshopper;
    grasshopper.insertVertex("South Boulder");
    grasshopper.insertVertex("Glacier Ice Cream");
    grasshopper.insertVertex("Golden");
    grasshopper.insertVertex("Superior");
    grasshopper.insertVertex("Superior Costco");
    grasshopper.insertVertex("Wildwood Guitars");
    grasshopper.insertVertex("Denver");
    grasshopper.insertVertex("Planet Fitness");
    grasshopper.insertVertex("IKEA");
    
    grasshopper.insertEdge("South Boulder", "Glacier Ice Cream", 1);
    grasshopper.insertEdge("Glacier Ice Cream", "South Boulder", 1);
    grasshopper.insertEdge("South Boulder", "Superior", 5);
    grasshopper.insertEdge("South Boulder", "Golden", 15);
    grasshopper.insertEdge("Golden", "South Boulder", 15);
    grasshopper.insertEdge("Superior", "Superior Costco", 1);
    grasshopper.insertEdge("Superior", "South Boulder", 5);
    grasshopper.insertEdge("Superior Costco", "Superior", 1);
    grasshopper.insertEdge("Superior", "Wildwood Guitars", 1);
    grasshopper.insertEdge("Superior", "Denver", 10);
    grasshopper.insertEdge("Denver", "Superior", 10);
    grasshopper.insertEdge("Denver", "Golden", 15);
    grasshopper.insertEdge("Denver", "Planet Fitness", 3);
    grasshopper.insertEdge("Denver", "IKEA", 20);
    
    //cout << "BFT starting at South Boulder" << endl;
    //grasshopper.BFTraversal("South Boulder");
    
    //cout << "BFT Starting at Denver" << endl;
    //grasshopper.BFTraversal("Denver");
    
    //efficiency difference between matrix and adjacency list
    //O(1) for matrix
    //for adjacency list, have to go through whole list for weight
    //for a matrix, we go right to it
    
    //depth vs. bret(?) search
    //bret(?) is horizontal
    //go to level, look at everything in the level
    //then go to next level, only going to do something when we visit the level
    //once you have seen a vertex, not recounting
    
    //depth is vertical
    //go all the way down in each row until you can't find anything, then go to next row
    
    //grasshopper.resetGraph();
    //grasshopper.DFSearch("South Boulder");
    
     //OUTPUT:
     //Starting depth first search at South Boulder
     //Just visited Glacier Ice Cream
     //Just visited Superior
     //Just visited Superior Costco
     //Just visited Wildwood Guitars
     //Just visited Denver
     //Just visited Golden
     //Just visited Planet Fitness
     //Just visited IKEA
     
    int numberHopes=grasshopper.BSTDistanceBetween("South Boulder", "IKEA");
    if(numberHopes!=-1){
        cout<<"hops are "<<numberHopes<<endl;
    }
    grasshopper.resetGraph();
    cout<<"hopes after reset graph is "<< numberHopes<<endl;
    
    grasshopper.resetGraph();
    grasshopper.dijkstra("Boulder", "IKEA");
    
    
}*/
