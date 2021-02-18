#ifndef LINKED_LIST
#define LINKED_LIST

#include "Node.h"
#include "ListInterface.h"

template<class ItemType>
class LinkedList: public ListInterface<ItemType>{
    Node<ItemType>* headPtr;
    int itemCount;
    Node<ItemType>* getNodeAt(int position) const;

public:
    LinkedList();
    LinkedList(const LinkedList<ItemType>& aList);

    bool isEmpty() const;
    int getLength() const;
    bool insert(int newPosition, const ItemType& newEntry);
    bool remove(int position);
    void clear();
    ItemType replace(int position, const ItemType& newEntry);
    ItemType getEntry(int position) const;

    virtual ~LinkedList();
};
#endif