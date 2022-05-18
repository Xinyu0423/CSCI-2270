//
//  projectHeap.cpp
//  CSCI-2270
//
//  Created by 蒋新宇 on 2018/5/4.
//  Copyright © 2018年 XInyu JIang. All rights reserved.
//

#include "projectHeap.hpp"
#include <stdio.h>
#include <iostream>
#include <chrono>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
using namespace std;
heap::heap(){
    currIndex=0;
    maxSize=880;
}
heap::~heap(){
    
}
void heap::addItem(string pName, int pPriority, int pTreatment){
    if(currIndex==maxSize){
        cout<<"Can not add more"<<endl;
        return;
    }else{
        currIndex++;
        //cout<<"123"<<endl;
        int tempIndex=currIndex-1;
        myHeap[tempIndex].name=pName;
        myHeap[tempIndex].priority=pPriority;
        myHeap[tempIndex].treatment=pTreatment;
        
        while(tempIndex!=0 && myHeap[getParentIndex(tempIndex)].priority >= myHeap[tempIndex].priority){
            if(myHeap[getParentIndex(tempIndex)].priority == myHeap[tempIndex].priority){
                //cout<<"123"<<endl;
                if(myHeap[tempIndex].treatment < myHeap[getParentIndex(tempIndex)].treatment){
                    swap(myHeap[tempIndex],myHeap[getParentIndex(tempIndex)]);
                    tempIndex=getParentIndex(tempIndex);
                } else{
                    break;
                }
            } else{
                //cout<<"123"<<endl;
                swap(myHeap[tempIndex],myHeap[getParentIndex(tempIndex)]);
                //cout<<"123"<<endl;
                tempIndex=getParentIndex(tempIndex);
            }
        }
    }
}
void heap::deleteItem(){
    if(currIndex<=0){
        return;
    }else if(currIndex==1){
        currIndex=currIndex-1;
        return;
    }else{
        //heapItem temp=myHeap[0];
        swap(myHeap[0],myHeap[currIndex-1]);
        currIndex=currIndex-1;
        minHeapify(0);
    }
}
heapItem heap::peek(){
    return myHeap[0];
}

void heap::deleteAll(){
    for(int i=0;i<currIndex;i++){
        deleteItem();
    }
}
int heap::getParentIndex(int index){
    int temp=(index-1)/2;
    return temp;
}
int heap::getLeftIndex(int index){
    int temp=2*index+1;
    return temp;
}
int heap::getRightIndex(int index){
    int temp=2*index+2;
    return temp;
}
heapItem heap::getMinIndex(int index){
    return myHeap[0];
}
void heap::minHeapify(int index){
    int tempLeft=getLeftIndex(index);
    int tempRight=getRightIndex(index);
    int tempSmallest=index;
    if(tempLeft<currIndex && myHeap[tempLeft].priority <= myHeap[index].priority){
        if(myHeap[tempLeft].priority == myHeap[index].priority){
            if(myHeap[tempLeft].treatment < myHeap[index].treatment){
                tempSmallest=tempLeft;
            } else if(myHeap[tempLeft].treatment == myHeap[index].treatment && myHeap[tempLeft].name < myHeap[index].name){
                tempSmallest=tempLeft;
            }
        }else{
            tempSmallest=tempLeft;
        }
    }
    if(tempRight<currIndex &&myHeap[tempRight].priority<=myHeap[tempSmallest].priority){
        if(myHeap[tempRight].priority==myHeap[tempSmallest].priority){
            if(myHeap[tempRight].treatment<myHeap[tempSmallest].treatment){
                tempSmallest=tempRight;
            }else if(myHeap[tempRight].treatment == myHeap[tempSmallest].treatment && myHeap[tempRight].name < myHeap[tempSmallest].name){
                tempSmallest=tempLeft;
            }
        }
        else{
            tempSmallest=tempRight;
        }
    }
    if(tempSmallest!=index){
        swap(myHeap[index], myHeap[tempSmallest]);
        minHeapify(tempSmallest);
    }
}
// void heap::swap(heapItem* x, heapItem* y){
//     heapItem* temp=x;
//     *x=*y;
//     *y=*temp;
// }
void heap::printHeap(){
    //dequeue one element at a time
    //print one element
    //after all the priting is done, build heap again
    int tempIndex=currIndex;
    vector<heapItem> temp1;
    for(int i=0;i<tempIndex;i++){
        heapItem temp = peek();
        deleteItem();
        cout<<i+1<<": "<<temp.name<<" "<<temp.priority<<" "<<temp.treatment<<endl;
        temp1.push_back(temp);
        
    }
    for (int i=0;i<temp1.size();i++){
        addItem(temp1[i].name,temp1[i].priority, temp1[i].treatment);
    }
    
}
/*int main(){
    ifstream inputFile("patientData2270.csv");
    heap myPQ;
    int heapCount=1;
    string line;
    //while(){
    for(int i=0;i<881;i++){
        getline(inputFile,line,'\r');
        stringstream ss(line);
        string name;
        string firstPriority;
        string secondPriority;
        getline(ss,name,',');
        getline(ss,firstPriority,',');
        getline(ss,secondPriority,',');
        ///cout<<firstPriority<<endl;
        //cout<<name<<endl;
        if(heapCount!=1){
            myPQ.addItem(name, stoi(firstPriority), stoi(secondPriority));
        }
        heapCount++;
        //if(heapCount!=1){
         //myPQ.addItem(name, stoi(firstPriority), stoi(secondPriority));
         //}
    }
    
    //myPQ.deleteAll();
    
    myPQ.printHeap();
    
}*/
