//
//  assignment1.cpp
//  CSCI-2270
//
//  Created by 蒋新宇 on 2017/12/29.
//  Copyright © 2017年 XInyu JIang. All rights reserved.
//

#include "assignment1.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

/*
 *Algorithm description
 *  structure
 */
struct shop{
    string name="n/a";
    string status="n/a";
    int price;
    //structure
};
/*Algorithm description
 *  use the size and array that passed in to print the information that needed
 */
void printInfo(shop itemArr[],int size){
    for(int i=0;i<size;i++){
        cout<<itemArr[i].name<< "," <<itemArr[i].status<<", "<<itemArr[i].price<<endl;
        //use the array and size to print the information that needed
    }
}
/*
 *Algorithm description
 *  start from the index that need to delete
 *  shift the element by put the next one fronter
 */
void delteArr(shop shopArr[],int size,int indexDelete){
    for(int i=indexDelete;i<size;i++){
        shopArr[i]=shopArr[i+1];
        //start from the index that matches
        //if name is the same, status is differt and want price is higher than sale price
        //shift the array by shift the next one fronter
    }
}
/*
 *Algorithm description
 *  open the file and if the file can not opened
 *  print to show it can not be opened
 *  use string stream to split and get the name, status and the price
 *  use a flag to check to show the element get matched
 *  use if statement to check if the name is the same
 *  and the status is different and the wanted price is heigher than for sale price
 *  if it is, save it to shopArr, and shift one element front by call delteArr function
 *  if it did not get matched, save it to itemArr
 */
int readFile(shop shopArr[],shop itemArr[], int size,string fileName){
    ifstream inputFile(fileName);
    //open the documents
    int index=0;
    int itemIndex=0;
    if(inputFile.fail()){
        cout<<"open document failed"<<endl;
        //if the file can not be opened, print this
    }else{
        string tempStr;
        while(getline(inputFile,tempStr)){
            //get each line from a file
            bool isFound=false;
            //initailze a flage and set it as false
            stringstream ss(tempStr);
            string tempName;
            string tempStatus;
            string tempPrice;
            getline(ss, tempName, ',');
            getline(ss, tempStatus, ',');
            getline(ss, tempPrice);
            //use stringstream to split it
            for(int i=0;i<itemIndex;i++){
                if(itemArr[i].name ==tempName && itemArr[i].status!=tempStatus){
                    //check if the name is the same and the status is different
                    if(tempStatus==" for sale" && itemArr[i].status==" wanted" && stoi(tempPrice) <= itemArr[i].price){
                        //if one is "for sale" and another one is "wanted"
                        //and the wanted price is bigger than the for sale price
                        shopArr[index].name=tempName;
                        shopArr[index].status=tempStatus;
                        shopArr[index].price=stoi(tempPrice);
                        //save it to the shop array
                        cout<<shopArr[index].name<<" "<<shopArr[index].price<<endl;
                        //print out the one get matched
                        isFound=true;
                        //change the flag to frue
                        delteArr(itemArr, itemIndex, i);
                        //call the delteArray function to delete the element
                        index++;
                        itemIndex=itemIndex-1;
                        //change the index of both
                        break;
                        //use break to stop the
                    }else if(tempStatus==" wanted" && itemArr[i].status ==" for sale" && stoi(tempPrice) >= itemArr[i].price){
                        //if one is "wanted" and another one is "for sale"
                        //and the wanted price is bigger than the for sale price
                        shopArr[index].name=itemArr[i].name;
                        shopArr[index].status=itemArr[i].status;
                        shopArr[index].price=itemArr[i].price;
                        cout<<shopArr[index].name<<" "<<shopArr[index].price<<endl;
                        isFound=true;
                        delteArr(itemArr, itemIndex, i);
                        index++;
                        itemIndex=itemIndex-1;
                        break;
                    }
                }
            }
            if(isFound==false){
                //if it did not get matched
                itemArr[itemIndex].name=tempName;
                itemArr[itemIndex].status=tempStatus;
                itemArr[itemIndex].price=stoi(tempPrice);
                //save it to itemArr
                itemIndex++;
            }
        }
    }
    inputFile.close();
    //close the file
    return itemIndex;
}
/*
 *Algorithm description
 *  main function
 */
/*int main(int c, char const* arg[]){
    shop myArr[100];
    shop itemArr[100];
    string filename = arg[1];
    int line=readFile(myArr,itemArr,100,filename);
    cout<<"#"<<endl;
    printInfo(itemArr, line);
    cout<<"#"<<endl;

}*/


