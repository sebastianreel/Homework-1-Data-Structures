// Simple Linked List that displays a menu that lets you  add, remove, show number of, show all, or exit the program
// Sebastian Reel

#include <iostream>
#include "LinkedList.h"
#include <string>
using namespace std;

int getMenuChoice();

int main(){
    int menuC, position;
    string poop_name;
    menuC = getMenuChoice();
    LinkedList<string> poop;
    

    /*while(menuC != 0){
        switch(menuC){
        case 1:
            cout << "Please enter the position and name of the item.";
            cin >> Poop.insert(position, poop_name);
            cout << endl;
            break;
        case 2:
            cout << "Please enter the position of the item.";
            cin >> Poop.remove(position);
            cout << endl;
            break;
        case 3:
            cout << "The number of items in the list are: ";
            cout << Poop.getLength() << endl;
            break;
        case 4:
            // cout << "All of the items: ";
            
            break;
        case 0:
            break;
        default:
            cout << "Please enter a valid option." << endl;
        }
    }*/
    return 0;
}

int getMenuChoice(){
    int choice;
    
    cout << "***Menu of a Linked List***" << endl;
    cout << "1. Add a new item to the list" << endl;
    cout << "2. Delete an item in the list" << endl;
    cout << "3. Show the number of items" << endl;
    cout << "4. Show all of the items" << endl;
    cout << "0. EXIT" << endl;

    return choice;
}