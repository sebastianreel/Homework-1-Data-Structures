template<class ItemType>
Node<ItemType>* LinkedList<ItemType>::getNodeAt(int position) const{
	if((position >= 1) && (position <= itemCount)){
		Node<ItemType>* curPtr = headPtr;
		
        for (int skip = 1; skip < position; skip++){
			curPtr = curPtr->getNext();
		}
		return curPtr;
	}
	return nullptr;
} 

template<class ItemType>
LinkedList<ItemType>::LinkedList() : headPtr(nullptr), itemCount(0){}

template<class ItemType>
LinkedList<ItemType>::LinkedList(const LinkedList<ItemType>& aList){
	headPtr = aList.headPtr;
	itemCount = aList.itemCount;
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
	if (ableToInsert){
		Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);
		if (newPosition == 1){
			newNodePtr->setNext(headPtr);
			headPtr = newNodePtr;
		}else{
			Node<ItemType>* prevPtr = getNodeAt(newPosition - 1);
			newNodePtr->setNext(prevPtr->getNext());
			prevPtr->setNext(newNodePtr);
		}
		itemCount++;
	} 
	return ableToInsert;
}

template<class ItemType>
bool LinkedList<ItemType>::remove(int position){
	bool ableToRemove = (position >= 1) && (position <= itemCount);
	if (ableToRemove){
		Node<ItemType>* curPtr = nullptr;
		if (position == 1){
			curPtr = headPtr;
			headPtr = headPtr->getNext();
		}else{
			Node<ItemType>* prevPtr = getNodeAt(position - 1);
			curPtr = prevPtr->getNext();
			prevPtr->setNext(curPtr->getNext());
		}

		curPtr->setNext(nullptr);
		delete curPtr;
		curPtr = nullptr;
		itemCount--;
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
ItemType LinkedList<ItemType>::getEntry(int position) const {
	// enforce precondition
	bool ableToGet = (position >= 1) && (position <= itemCount);
	if (ableToGet){
		Node<ItemType>* nodePtr = getNodeAt(position);
		return nodePtr->getItem();		
	} 
	throw "Item not found";
} 

template<class ItemType>
ItemType LinkedList<ItemType>::replace(int position, const ItemType& newEntry){
	bool ableToGet = (position >= 1) && (position <= itemCount);
	if (ableToGet){
		Node<ItemType>* nodePtr = getNodeAt(position);
		ItemType oldEntry = nodePtr->getItem();
		nodePtr->setItem(newEntry);	
		return oldEntry;	
	} 
	throw "Item not found";
}

template<class ItemType>
LinkedList<ItemType>::~LinkedList(){
	clear();
} 