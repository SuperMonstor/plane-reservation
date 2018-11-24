//
//  main.cpp
//  random
//
//  Created by Satish Naik on 24/11/18.
//  Copyright © 2018 Satish Naik. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;


int main ()
{

    string password;
    string username;
    ofstream  writeFile("login.txt");
    ifstream  readFile("login.txt");
    if(writeFile.is_open())
    {
        
        writeFile<<"TanishaNaik"<<" "<< "project"<<endl;
        writeFile<<"sid"<<" " <<"proj1"<< endl;
        writeFile<<"sud"<<" " <<"proj2"<< endl;
    }
    
        cout<<"enter your username  and password"<< endl;
        cin >>username >> password;
        string checkpassword;
        string checkusername;
    while( readFile>>checkusername>>checkpassword)
    {
    if (checkusername==username && checkpassword==password)
        cout<<"access granted\n";
    }
}
    
    
       
        
        
    


    
    

