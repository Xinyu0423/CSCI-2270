//
//  starter.hpp
//  CSCI-2270
//
//  Created by 蒋新宇 on 2018/4/3.
//  Copyright © 2018年 XInyu JIang. All rights reserved.
//

#ifndef starter_hpp
#define starter_hpp

#include <stdio.h>

#endif /* starter_hpp */
/*void Graph::DFSpath(string src , string dst){
 stack<vertex*> vertStack;
 map<vertex*, vertex*> parent;
 vertex* curr=findVertex(src);
 if(curr==NULL){
 return;
 }
 if(curr!=NULL){
 vertStack.push(curr);
 while(vertStack.size()!=0){
 vertex* curV=vertStack.top();
 vertStack.pop();
 if(curV->visited==false){
 curV->visited=true;
 if(curV->key==dst){
 stack<vertex*> path;
 vertex* tempV=curV;
 cout<<"Track back: "<<endl;
 cout<<dst;
 path.push(curV);
 while(parent[tempV]->key!=src){
 cout<<"-->"<<parent[tempV]->key;
 path.push(parent[tempV]);
 tempV=parent[tempV];
 }
 cout<<"---"<<src<<endl;
 path.push(curr);
 cout<<"the path: "<<endl;
 while(path.empty()==false){
 cout<<path.top()->key<<"-->";
 path.pop();
 }
 cout<<endl;
 return;
 }
 for(int i=0;i<curV->adjacent.size();i++){
 vertStack.push(curV->adjacent[i].v);
 parent.insert(make_pair(curV->adjacent[i].v, curV));
 }
 }
 }
 }
 }*/
