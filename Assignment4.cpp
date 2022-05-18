//
//  Assignment4.cpp
//  CSCI-2270
//
//  Created by 蒋新宇 on 2018/2/16.
//  Copyright © 2018年 XInyu JIang. All rights reserved.
//

#include "CommunicationNetwork.h"
#include <iostream>
#include <sstream>
using namespace std;
/*int main(int c, char* const arg[]){
    CommunicationNetwork myCity;
    int choose=0;
    while(choose!=7){
        cin>>choose;
        cout << "======Main Menu======" << endl;
        cout << "1. Build Network" << endl;
        cout << "2. Print Network Path" << endl;
        cout << "3. Transmit Message Coast-To-Coast-To-Coast" << endl;
        cout << "4. Add City" << endl;
        cout << "5. Delete City" << endl;
        cout << "6. Clear Network" << endl;
        cout << "7. Quit" << endl;
        if(choose==1){
            myCity.buildNetwork();
            myCity.printNetwork();
        }else if(choose==2){
            myCity.printNetwork();
        }else if(choose==3){
            myCity.transmitMsg(arg[1]);
        }else if(choose==4){
            cin.ignore();
            string cityPreviousName;
            string cityNewName;
            cout << "Enter a city name: " << endl;
            getline(cin,cityNewName);
            cout << "Enter a previous city name: " << endl;
            getline(cin,cityPreviousName);
            myCity.addCity(cityNewName, cityPreviousName);
        }else if(choose==5){
            cin.ignore();
            string cityDelete;
            cout<<"Enter a city name"<<endl;
            getline(cin,cityDelete);
            myCity.deleteCity(cityDelete);
        }else if(choose==6){
            myCity.deleteNetwork();
        }else if(choose==7){
            cout<<"Goodbye!"<<endl;
        }
    }
    

}*/
