//
//  projectHeap.hpp
//  CSCI-2270
//
//  Created by 蒋新宇 on 2018/5/4.
//  Copyright © 2018年 XInyu JIang. All rights reserved.
//

#ifndef projectHeap_hpp
#define projectHeap_hpp

#include <stdio.h>
#include <iostream>
using namespace std;
struct heapItem{
    string name;
    int priority;
    int treatment;
};
class heap{
public:
    heap();
    ~heap();
    void addItem(string, int ,int);
    void deleteItem();
    void printHeap();
    void deleteAll();
    heapItem myHeap[880];
private:
    int currIndex;
    int maxSize;
    
    int getParentIndex(int);
    int getLeftIndex(int);
    int getRightIndex(int);
    heapItem getMinIndex(int);
    void minHeapify(int);
    //void swap(heapItem*,heapItem*);
    heapItem peek();
};
#endif /* projectHeap_hpp */
