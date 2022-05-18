//
//  Assignment8.cpp
//  CSCI-2270
//
//  Created by 蒋新宇 on 2018/3/20.
//  Copyright © 2018年 XInyu JIang. All rights reserved.
//

/*#include "Graph.hpp"
#include <fstream>
#include <sstream>
using namespace std;
int main(int c, char* const arg[]){
    Graph myGraph;
    ifstream inputFile(arg[1]);
    string line;
    vector<string> city;
    string cityName;
    int i=0;
    vector<int> weight;
    string tempWeight;
    int index=0;
    while(getline(inputFile,line)){
        stringstream ss(line);
        if(i==0){
            getline(ss,cityName,',');
            while(getline(ss,cityName,',')){
                city.push_back(cityName);
            }
            for(int a=0;a<city.size();a++){
                myGraph.addVertex(city[a]);
            }
        }else{
            getline(ss,cityName,',');
            //cout<<"----------------------"<<endl;
            while(getline(ss,tempWeight,',')){
                weight.push_back(stoi(tempWeight));
            }
            
            for(int j=0;j<city.size();j++){
                if(weight[index]!=-1){
                    myGraph.addEdge(cityName,city[j],weight[index]);
                }
                index++;
                if(index>weight.size()){
                    index=0;
                }
            }
        }
        i++;
    }
    int choose=0;
    string firstCity;
    string secondCity;
    bool flag;
    while(choose!=3){
        cout << "======Main Menu======" << endl;
        cout << "1. Print vertices" << endl;
        cout << "2. Find districts" << endl;
        cout << "3. Find shortest path" <<endl;
        cout << "4. Find shortest weighted path" <<endl;
        cout << "5. Quit" << endl;
        cin>>choose;
        cin.ignore();
        cin.clear();
        if(choose==1){
            myGraph.displayEdges();
        }else if(choose==2){

            myGraph.assignDistricts();
        }else if(choose==3){
            cout << "Enter a starting city:" << endl;
            getline(cin,firstCity);
            cout << "Enter an ending city:" << endl;
            getline(cin,secondCity);
            myGraph.shortestPath(firstCity, secondCity);
            cin.ignore();
        }else if(choose==4){
            
            cout << "Enter a starting city:" << endl;
            getline(cin,firstCity);
            cout << "Enter an ending city:" << endl;
            getline(cin,secondCity);
            myGraph.shortestWeightedPath(firstCity, secondCity);
            cin.ignore();
        }else if(choose==5){
            cout<<"Goodbye!"<<endl;
            break;
        }
    }
}*/
