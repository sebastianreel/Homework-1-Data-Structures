// Sebastian Reel
// Basic Project: Linked List (using strings in this case)

#include <iostream>
#include <string>
#include "linkedlist.h"
using namespace std;

int getMenuChoice();
void display(LinkedList<string>&);
void deleteString(LinkedList<string>&);
void addString(LinkedList<string>&);
void replace(LinkedList<string>&);

using namespace std;

int main(){
    int choice;
    LinkedList<string> stringList;

    while(choice != 0){
        choice = getMenuChoice();

        switch(choice){
            case 1:
                addString(stringList);
                break;
            case 2:
                deleteString(stringList);
                break;
            case 3:
                replace(stringList);
                break;
            case 4:
                display(stringList);
                break;
            case 0:
                break;
            default:
                cout << endl << "Invalid choice." << endl;
                break;
        }
    }
    return 0;
}

int getMenuChoice(){
    int x;

    cout << endl << "LINKED LIST: STRINGS" << endl;
    cout << "1 -> Add Strings" << endl;
    cout << "2 -> Remove Strings" << endl;
    cout << "3 -> Replace Strings" << endl;
    cout << "4 -> Display Strings" << endl;
    cout << "0 -> Exit" << endl;

    cin >> x;
    return x;
}

void display(LinkedList<string>& list){
    if(list.isEmpty()){
        cout << "Empty List." << endl;
        return;
    }

    for(int pos = 1; pos <= list.getLength(); pos++){
        cout << pos << ": " << list.getEntry(pos) << endl;
    }
}

void deleteString(LinkedList<string>& list){
    if(list.isEmpty()){
        cout << "Empty List." << endl;
        return;
    }

    int pos;
    string temp;
    display(list);

    cout << endl << "Please select which string you'd like to remove? ";
    cin >> pos;

    temp = list.getEntry(pos);
    if(list.remove(pos)){
        cout << endl << "Removed: " << temp << endl;
    }else{
        cout << endl << "Could not remove " << temp << endl;
    }
}

void addString(LinkedList<string>& list){
    int add;
    string newS;

    cout << endl << "How many strings would you like to add? ";
    cin >> add;

    for(int pos = 1; pos <= add; pos++){
        cout << endl << "Please enter string: " << endl;
        cin >> newS;
        list.insert(pos, newS);
    }
}

void replace(LinkedList<string>& list){
    if(list.isEmpty()){
        cout << "Empty List." << endl;
        return;
    }

    int pos;
    string newS, oldS;
    display(list);

    cout << endl << "Please select which string you'd like to replace: " << endl;
    cin >> pos;
    cout << endl << "Please enter new string: " << endl;
    cin >> newS;

    try{
        oldS = list.replace(pos, newS);
        cout << oldS << " was replaced with " << newS << endl;
    }catch(const char* msg){
        cout << msg << endl;
    }
}