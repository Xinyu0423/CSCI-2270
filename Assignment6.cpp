
//
//  Assignment6.cpp
//  CSCI-2270
//
//  Created by 蒋新宇 on 2018/3/11.
//  Copyright © 2018年 XInyu JIang. All rights reserved.
//

#include "MovieTree.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
int main(int arg, char* const argv[]){
    MovieTree myTree;
    ifstream inputFile(argv[1]);
    string line;
    while(getline(inputFile,line)){
        string ranking;
        string movieName;
        string year;
        string quanity;
        stringstream ss(line);
        getline(ss,ranking,',');
        getline(ss,movieName,',');
        getline(ss,year,',');
        getline(ss,quanity,',');
        myTree.addMovieNode(stoi(ranking), movieName, stoi(year), stoi(quanity));
    }
    int choose=0;
    string title="";
    int countMovie;
    while(choose!=6){
        cout << "======Main Menu======" << endl;
        cout << "1. Find a movie" << endl;
        cout << "2. Rent a movie" << endl;
        cout << "3. Print the inventory" << endl;
        cout << "4. Delete a movie" << endl;
        cout << "5. Count the movies" << endl;
        cout << "6. Quit" << endl;
        cin>>choose;
        cin.ignore();
        cin.clear();
        if(choose==1){
            cout << "Enter title:" << endl;
            getline(cin,title);
            myTree.findMovie(title);
        }else if(choose==2){
            cout << "Enter title:" << endl;
            getline(cin,title);
            myTree.rentMovie(title);
        }else if(choose==3){
            myTree.printMovieInventory();
        }else if(choose==4){
            cout << "Enter title:" << endl;
            getline(cin,title);
            myTree.deleteMovieNode(title);
        }else if(choose==5){
            countMovie=myTree.countMovieNodes();
            cout<<"Tree contains: "<<countMovie<<" movies."<<endl;
        }else if(choose==6){
            cout<<"Goodbye!"<<endl;
        }
    }
}


