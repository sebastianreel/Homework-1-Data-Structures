#ifndef linked_list
#define linked_list
#include "list.h"
#include "node.h"

template<class ItemType>
class LinkedList : public ListInterface<ItemType>{
	Node<ItemType>* headPtr; 
	int itemCount; 
	Node<ItemType>* getNodeAt(int position) const; 
public:
	LinkedList();
	LinkedList(const LinkedList<ItemType>& aList);
	virtual ~LinkedList();
	bool isEmpty() const;
	int getLength() const;
	bool insert(int position, const ItemType& newEntry);
	bool remove(int position);
	void clear();
	ItemType getEntry(int position) const;
	ItemType replace(int position, const ItemType& newEntry);
};
#include "linkedlist.cpp"
#endif