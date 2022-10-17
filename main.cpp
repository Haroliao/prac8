#include <iostream>
#include <limits>
#include "LinkedList.h"
#include <vector>
#include <sstream>
#include "Node.h"
#include <string>



using namespace std;

int main(){

    vector <string> input;
    string letters;
    vector <int> numbers;
    const char space=' ';
    LinkedList L;
    int num;

    
    getline(cin,letters); 
    stringstream ss (letters); 
    
     while (getline(ss,letters,space)){
    
        input.push_back(letters);
    }

    int size=input.size();
 
    for (int i = 0; i<size-3; i++){
        num = stoi(input[i]);
        
        numbers.push_back(num);
    }
  
    int parameter = stoi(input[size-2]);
    int parameter2 = stoi(input[size-1]);
    string yo = input[size-3];
    
    if (yo == "AP"){
        cout << "";
        L.addFront(numbers[3]);
        L.addFront(numbers[2]);
        L.addFront(numbers[1]);
        L.addFront(numbers[0]);
        L.addAtPosition(parameter, parameter2);
        L.printItems();
    }
    if (yo == "DP"){
        cout << "";
        L.addFront(numbers[3]);
        L.addFront(numbers[2]);
        L.addFront(numbers[1]);
        L.addFront(numbers[0]);
        L.deletePosition(parameter);
        L.printItems();
    }
    if (yo == "GI"){
        cout << "";
        L.addFront(numbers[3]);
        L.addFront(numbers[2]);
        L.addFront(numbers[1]);
        L.addFront(numbers[0]);
        L.getItem(parameter);
        L.printItems();
    }
    if (yo == "AF"){
        cout << "";
        L.addFront(numbers[3]);
        L.addFront(numbers[2]);
        L.addFront(numbers[1]);
        L.addFront(numbers[0]);
        L.addFront(parameter);
        L.printItems();
    }
    if (yo == "AE"){
        cout << "";
        L.addFront(numbers[3]);
        L.addFront(numbers[2]);
        L.addFront(numbers[1]);
        L.addFront(numbers[0]);
        L.addEnd(parameter);
        L.printItems();
    }
    if (yo == "S"){
        cout << "";
        L.addFront(numbers[3]);
        L.addFront(numbers[2]);
        L.addFront(numbers[1]);
        L.addFront(numbers[0]);
        L.search(parameter);
        L.printItems();
    }
    if (yo == "DF"){
        cout << "";
        L.addFront(numbers[3]);
        L.addFront(numbers[2]);
        L.addFront(numbers[1]);
        L.addFront(numbers[0]);
        L.deleteFront();
        L.printItems();
    }
    if (yo == "DE"){
        cout << "";
        L.addFront(numbers[3]);
        L.addFront(numbers[2]);
        L.addFront(numbers[1]);
        L.addFront(numbers[0]);
        L.deleteEnd();
        L.printItems();
    }

    return 0;
}