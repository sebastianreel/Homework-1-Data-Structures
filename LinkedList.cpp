#include "LinkedList.h"

template<class ItemType>
LinkedList<ItemType>::LinkedList(){
    itemCount = 0;
    headPtr = nullptr;
}

template<class ItemType>
LinkedList<ItemType>::LinkedList(const LinkedList<ItemType>& aList){
    headPtr = aList.headPtr;
    itemCount = aList.itemCount;
}

template<class ItemType>
Node<ItemType>* LinkedList<ItemType>::getNodeAt(int position) const{
    //ENFORCE PRECONDITION
    if((position >= 1) && (position <= itemCount)){
        Node<ItemType>* currentPtr = headPtr;
        for(int skip = 1; skip < position; skip++){
            currentPtr = currentPtr->getNext();
        }
        return currentPtr;
    }
    return nullptr;
}

template<class ItemType>
bool LinkedList<ItemType>::isEmpty() const{
    return itemCount == 0;
}

template<class ItemType>
int LinkedList<ItemType>::getLength() const{
    return itemCount;
}

template<class ItemType>
bool LinkedList<ItemType>::insert(int newPosition, const ItemType& newEntry){
    bool ableToInsert = (newPosition >= 1) && (newPosition <= itemCount + 1);
                                                                                                        
    if(ableToInsert){
        // Createw noding ne containing new entry
        Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);
        //Attach the node to chain
        if(newPosition == 1){
            newNodePtr->setNext(headPtr);
            headPtr = newNodePtr;
        }else{
            Node<ItemType>* previousPtr = getNodeAt(newPosition - 1);
            newNodePtr->setNext(previousPtr->getNext());
            previousPtr->setNext(newNodePtr);
        }
        itemCount++;    // This will increase the number of entries
    }
    return ableToInsert;
}

template<class ItemType>
bool LinkedList<ItemType>::remove(int position){
    bool ableToRemove = (position >= 1) && (position <= itemCount);

    if(ableToRemove){
        Node<ItemType>* currentPtr = nullptr;
        if(position == 1){
            //This will remove the first node in the chain
            currentPtr = headPtr; 
            headPtr = headPtr->getNext();
        }else{
            //Find the node that is before the one to remove
            Node<ItemType>* previousPtr = getNodeAt(position - 1);
            //Point to node to remove
            currentPtr = previousPtr->getNext();
            //Disconnect indicated node from chain by connecting the prior node with the one after
            previousPtr->setNext(currentPtr->getNext());
        }

        currentPtr->setNext(nullptr);
        delete currentPtr;
        currentPtr = nullptr;
        itemCount--;    // Decrease the number/count of entries
    }
    return ableToRemove;
}

template<class ItemType>
void LinkedList<ItemType>::clear(){
    while(!isEmpty()){
        remove(1);
    }
}

template<class ItemType>
ItemType LinkedList<ItemType>::replace(int position, const ItemType& newEntry){
    //enforce precondition
    bool ableToGet = (position >= 1) && (position <= itemCount);

    if(ableToGet){
        Node<ItemType>* nodePtr = getNodeAt(position);
        ItemType oldEntry = nodePtr->getItem();
        nodePtr->setItem(newEntry);
        return oldEntry;
    }
}

template<class ItemType>
ItemType LinkedList<ItemType>::getEntry(int position) const{
    // enforce precondition
    bool ableToGet = (position >= 1) && (position <= itemCount);

    if(ableToGet){
        Node<ItemType>* nodePtr = getNodeAt(position);
        return nodePtr->getItem();
    }
}

template<class ItemType>
LinkedList<ItemType>::~LinkedList(){
    clear();
}