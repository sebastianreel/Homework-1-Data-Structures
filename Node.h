// Node header file used for Linked List files 

#ifndef NODE
#define NODE
#include <iostream>
using namespace std;

template<class ItemType>
class Node{
    ItemType item;
    Node<ItemType>* next;
public:
    Node();
    Node(const ItemType& anItem);
    Node(const ItemType& anItem, Node<ItemType>& nextNodePtr);
    
    void setItem(const ItemType& anItem);
    void setNext(Node<ItemType>* nextNodePtr);
    ItemType getItem() const;
    Node<ItemType>* getNext() const;

};
#endif