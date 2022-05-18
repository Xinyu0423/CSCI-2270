//
//  Assignment2.cpp
//  CSCI-2270
//
//  Created by 蒋新宇 on 2018/2/1.
//  Copyright © 2018年 XInyu JIang. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

struct wordItem{
    string word;
    int count;
};
void getStopWords(char *ignoreWordFileName, string ignoreWords[]){
    ifstream inputFile(ignoreWordFileName);
    string temp;
    int i=0;
    while(getline(inputFile,temp)){
        stringstream ss(temp);
        ss>>ignoreWords[i];
        i++;
    }
}
bool isStopWord(string word, string ignoreWords[]){
    for(int i=0;i<50;i++){
        if(word==ignoreWords[i]){
            return true;
        }
    }
    return false;
}
int getTotalNumberNonStopWords(wordItem list[], int length){
    int countStop=0;
    for(int i=0;i<length;i++){
        countStop=countStop+list[i].count;
    }
    return countStop;
}
void doubleArr(wordItem* &oldArr,int* capy){
    int newCap=*capy*2;
    wordItem* newArr=new wordItem[newCap];
    for(int i=0;i<*capy;i++){
        newArr[i]=oldArr[i];
    }
    oldArr = NULL;
    delete[] oldArr;
    oldArr=newArr;
    *capy=newCap;
}
void arraySort(wordItem list[], int length){
    int index;
    for(int i=0;i<length;i++){
        index=i;
        for(int j=0;j<length;j++){
            if(list[index].count>list[j].count){
                index=j;
                wordItem temp;
                temp=list[i];
                list[i]=list[index];
                list[index]=temp;
            }
        }
    }
}
void printTopN(wordItem wordItemList[], int topN){
    for(int i=0;i<topN;i++){
        cout<<wordItemList[i].count<<" - "<<wordItemList[i].word<<endl;
    }
}
/*int main(int c,char* const arg[]){
    string ignoreWords[50];
    getStopWords(arg[3], ignoreWords);

    int size=100;
    int countDouble=0;
    wordItem* myItem=new wordItem[size];
    ifstream inputFile(arg[2]);
    int index=0;
    string line;
    string tempWord;
    bool wordFound;
    while(inputFile>>tempWord){
        wordFound=false;
        if(isStopWord(tempWord,ignoreWords)==false){
            for(int  i=0;i<size;i++){
                if(tempWord==myItem[i].word){
                    myItem[i].count=myItem[i].count+1;
                    wordFound=true;
                }
            }
            if(wordFound==false){
                myItem[index].word=tempWord;
                myItem[index].count=1;
                index++;
            }
            
            if(size ==index){
                doubleArr(myItem, &size);
                countDouble++;
            }
        }
    }
    arraySort(myItem, index);
    printTopN(myItem, 20);
    cout<<"#"<<endl;
    cout<<"Array doubled: "<<countDouble<<endl;
    cout<<"#"<<endl;
    cout<<"Unique non-common words: "<<index<<endl;
    cout<<"#"<<endl;
    cout<<"Total non-common words: "<<getTotalNumberNonStopWords(myItem, size)<<endl;

}*/
