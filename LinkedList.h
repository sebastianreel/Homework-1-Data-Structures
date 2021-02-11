#ifndef LINKED_LIST
#define LINKED_LIST

template<class ItemType>
class LinkedList: public ListInterface<ItemType>{
    Node<ItemType>* headPtr;
    int itemCount;
public:
    LinkedList();

    bool isEmpty() const;
    int getLength() const;
    bool insert(int newPosition, const ItemType& newEntry);
    bool remove(int position);
    void clear();
    ItemType replace(int position, const ItemType& newEntry);
    ItemType getEntry(const ItemType& newEntry) const;

    ~LinkedList() { }
};
#include "LinkedList.cpp"
#endif