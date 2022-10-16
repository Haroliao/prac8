#include "LinkedList.h"
#include "Node.h"
#include <sstream>
#include <limits>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){

    //Executing main
    vector <string> input;
    string str;
    const char space=' ';
    vector <int> parameters;
    LinkedList list;

    //Getting input
    getline(cin,str); /*now oding string stream and breaking into words*/  stringstream stream (str);

    while (getline(stream,str,space)){
        //[pushing input words back
        input.push_back(str);
    }

    //size variable
    int size=input.size();

    //setting ints in a vector
    for (int i=0; i<size-3; i++){
        int temp=stoi(input[i]);
        parameters.push_back(temp);
    }


    for (auto &i:parameters){
        //adding to end first
        list.addEnd(i);
    }

    //Executing commands
    string temp0=input[size-3];
    string function=temp0;
    int temp1=stoi(input[size-2]);
    int parameter1=temp1;
    int temp2=stoi(input[size-1]);
    int parameter2=temp2;


    //vector addition of commands
    vector <string> commands;

    commands.push_back("AF");commands.push_back("AE");
    commands.push_back("AP");commands.push_back("S");
    commands.push_back("DF");commands.push_back("DE");
    commands.push_back("DP");commands.push_back("GI");



    //for the various commands

    if (function==commands[7]){
        list.getItem(parameter1);
    }
    if (function==commands[3]){
        list.search(parameter1);
    }
    if (function==commands[6]){
        list.deletePosition(parameter1);
    }
    if (function==commands[1]){
        list.addEnd(parameter1);
    }
    if (function==commands[4]){
        list.deleteFront();
    }

    if (function==commands[2]){
        list.addAtPosition(parameter1, parameter2);
    }
    if (function==commands[5]){
        list.deleteEnd();
    }

    if (function==commands[0]){
        list.addFront(parameter1);
    }



    //Printing and returning
    list.printItems();
    return 0;
}
//End of function