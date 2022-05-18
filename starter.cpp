/*#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
using namespace std;

struct vertex;

struct adjVertex {
    vertex* v;
    int weight;
};

struct vertex {
    string key;
    vector<adjVertex> adjacent;
    bool visited = false;
    int distance;
    vertex* parent;
};

class Graph {
private:
    //vertices
    vector<vertex> vertices;
    vertex* findVertex(string);
public:
    //methods for accessing graphs
    Graph();
    ~Graph();
    void insertVertex(string);	//identifier of the vertex
    void insertEdge(string,string,int);	//start, end, weight
    void printGraph();
    void DFSpath(string, string);
    void findNodeWithMaximumAdjacent(string);
    
};

Graph::Graph() {}

Graph::~Graph() {}

void Graph::insertVertex(string value) {
    bool found = false;
    int i=0;
    while (i<vertices.size() && !found) {
        if (vertices[i].key == value) {
            found = true;
        }
        i++;
    }
    if (!found) {
        vertex v;
        v.key = value;
        vertices.push_back(v);
    }
    else {
        cout << "There is already a vertex " << value << " in this graph" << endl;
    }
}

vertex* Graph::findVertex(string value) {
    int i=0;
    while (i<vertices.size()) {
        if (vertices[i].key == value) {
            return &vertices[i];
        }
        i++;
    }
    return nullptr;
}



void Graph::insertEdge(string v1, string v2, int weight) {
    vertex *vStart = findVertex(v1);
    vertex *vEnd = findVertex(v2);
    if (vStart!=nullptr && vEnd!=nullptr) {
        //this code assumes that an edge doesn't exist
        //write some error checking to handle when it does
        adjVertex v1v2Edge;
        v1v2Edge.weight = weight;
        v1v2Edge.v = vEnd;
        vStart->adjacent.push_back(v1v2Edge);
    }
    else {
        if (vStart == nullptr) {
            cout << "no vertex with name " << v1 << " in this graph" << endl;
        }
        if (vEnd == nullptr) {
            cout << "no vertex with name " << v2 << " in this graph" << endl;
        }
    }
}

void Graph::findNodeWithMaximumAdjacent(string start) {
    queue<vertex*> vertexQ;
    vertex* curr=findVertex(start);
    string max;
    int count=0;
    if(curr!=NULL){
        cout<<"--------------";
        cout<<start<<" ";
        curr->visited=true;
        vertexQ.push(curr);
        while(vertexQ.size()!=0){
            vertex* tempV=vertexQ.front();
            tempV->distance=0;
            vertexQ.pop();
            for(int i=0;i<tempV->adjacent.size();i++){
                if(tempV->adjacent[i].v->visited==false){
                    tempV->adjacent[i].v->visited=true;
                    tempV->adjacent[i].v->distance=tempV->adjacent[i].v->distance+1;
                    if(count<tempV->adjacent[i].v->distance){
                        count=tempV->adjacent[i].v->distance;
                        max=tempV->adjacent[i].v->key;
                    }
                    cout<<tempV->adjacent[i].v->key<<" ";
                    vertexQ.push(tempV->adjacent[i].v);
                }
            }
        }
        cout<<"---------------"<<endl;
        cout<<"max is "<<max<<endl;
    }else{
        cout<<"can not find the vertex"<<endl;
    }
}

void Graph::DFSpath(string src, string dst) {
    vertex* start=findVertex(src);
    stack<vertex*> vStack;
    if(start!=NULL){
        start->visited=true;
        vStack.push(start);
        while(vStack.empty()==false){
            vertex* curr=vStack.top();
            vStack.pop();
            cout<<curr->key<<"-->";
            if(curr->key==dst){
                cout<<endl;
                return;
            }
            for(int i=0;i<curr->adjacent.size();i++){
                if(curr->adjacent[i].v->visited==false){
                    //cout<<curr->adjacent[i].v->key<<"-->";
                    curr->adjacent[i].v->visited=true;
                    vStack.push(curr->adjacent[i].v);
                }
            }
        }
    }
}

int main() {
    
    Graph myGraph;
    
    myGraph.insertVertex("A");
    myGraph.insertVertex("B");
    myGraph.insertVertex("C");
    myGraph.insertVertex("D");
    myGraph.insertVertex("E");
    myGraph.insertVertex("F");
    myGraph.insertVertex("G");
    
    myGraph.insertEdge("A", "B", 0); myGraph.insertEdge("B", "A", 0);
    myGraph.insertEdge("A", "C", 0); myGraph.insertEdge("C", "A", 0);
    myGraph.insertEdge("B", "D", 0); myGraph.insertEdge("D", "B", 0);
    myGraph.insertEdge("C", "D", 0); myGraph.insertEdge("D", "C", 0);
    myGraph.insertEdge("E", "D", 0); myGraph.insertEdge("D", "E", 0);
    myGraph.insertEdge("E", "B", 0); myGraph.insertEdge("B", "E", 0);
    myGraph.insertEdge("E", "G", 0); myGraph.insertEdge("G", "E", 0);
    myGraph.insertEdge("F", "G", 0); myGraph.insertEdge("G", "F", 0);
    //myGraph.findNodeWithMaximumAdjacent("A");
    //myGraph.findNodeWithMaximumAdjacent("B");
    //myGraph.findNodeWithMaximumAdjacent("C");
    myGraph.DFSpath("G", "A");
}*/
