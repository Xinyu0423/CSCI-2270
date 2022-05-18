//
//  InClassExercise04_09.cpp
//  CSCI-2270
//
//  Created by 蒋新宇 on 2018/4/9.
//  Copyright © 2018年 XInyu JIang. All rights reserved.
//

/*#include "InClassExercise04_09.hpp"
#include<iostream>
using namespace std;
struct movieNode{
    string title;
    int inventory;
    float rating;
    movieNode* next;
};
class movieHashTable{
private:
    int hashTableSize=3;
    movieNode* hashTable[10];
    movieNode* createMove(string, float);
    int hashSum(string);
    int hashMult(string);
public:
    movieHashTable();
    ~movieHashTable();
    bool addMovie(string,float);
    int findMovie(string);
    void printMovieIntentory();
};
movieHashTable::movieHashTable(){
    for(int i=0;i<hashTableSize;i++){
        hashTable[i]=NULL;
    }
}
movieHashTable::~movieHashTable(){
    //delete every list
    //haven't do it yet
}
int movieHashTable:: hashSum(string key){
    int sum=0;
    for(int i=0;i<key.size();i++){
        sum+=key[i];
    }
    return sum%hashTableSize;
}
int movieHashTable::hashMult(string key){
    int m=hashTableSize;
    float A=13.0/32.0;
    int sum=0;
    for(int i=0;i<key.size();i++){
        sum+=key[i];
    }
    float kA=sum*A;
    float kAREM=kA-int(kA);
    return int(kAREM*m);
}
movieNode* movieHashTable::createMove(string movieName, float movieRating){
    movieNode* newMovie=new movieNode;
    newMovie->title=movieName;
    newMovie->rating=movieRating;
    newMovie->inventory=1;
    newMovie->next=NULL;
    return newMovie;
}
bool movieHashTable::addMovie(string movieName,float movieRanting){
    movieNode* newMovie=createMove(movieName,movieRanting);
    int tableLoc=hashSum(movieName);
    if(hashTable[tableLoc]==NULL){
        hashTable[tableLoc]=newMovie;
        return true;
    }else{
        movieNode* tempNode=hashTable[tableLoc];
        while(tempNode->next!=NULL){
            tempNode=tempNode->next;
        }
        tempNode->next=newMovie;
        return true;
    }
}
void movieHashTable::printMovieIntentory(){
    int listCount=1;
    int totalMovie=0;
    for(int i=0;i<hashTableSize;i++){
        cout<<"At index "<<i<<": "<<endl;
        if(hashTable[i]==NULL){
            cout<<"No movies at the index "<<endl;
        }else{
            movieNode* tempNode=hashTable[i];
            while(tempNode!=NULL){
                listCount++;
                cout<<"Movie "<<listCount<<": "<<tempNode->title<<endl;
                totalMovie++;
                tempNode=tempNode->next;
            }
            listCount=1;
        }
        cout<<"----------------------------------"<<endl;
    }
}
int main(){
    movieHashTable myMovie;
    myMovie.printMovieIntentory();
    cout<<"-------------adding movies----------------"<<endl;
    myMovie.addMovie("Total Recall", 5.0);
    myMovie.addMovie("The Running Man", 5.0);
    myMovie.addMovie("Predator", 5.0);
    myMovie.addMovie("Commando", 4.2);
    myMovie.addMovie("Kingergarten Cop", 4.1);
    myMovie.addMovie("Twins", 4.2);
    myMovie.addMovie("Terminator 2", 4.5);
    myMovie.printMovieIntentory();
}*/
