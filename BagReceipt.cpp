//
//  BagReceipt.cpp
//  Project2TrialLearningCplusplus
//
//  Created by Rudolf Musika on 2/1/18.
//  Copyright © 2018 Rudolf Musika. All rights reserved.
//

#include "BagReceipt.hpp"
#include <vector>

/** Default constructor */
template <typename ItemType>
BagReceipt<ItemType>::BagReceipt(){
    for(int i(0);i<maxItems;++i){
        inuse[i] =false;
    }
}

/** Gets the amount of items that are currently in the bag */
template <typename ItemType>
int BagReceipt<ItemType>::getCurrentSize() const {
    
    return itemCount;
}
/** Checks to see if the bag contains no items */
template <typename ItemType>
bool BagReceipt<ItemType>::isEmpty() const {
    
    for(int i(0);i<maxItems;++i){
        if(inuse[i])
            return false;
    }
    return true;
}

/** Makes sure that there is room to add an item in the bag and
 creates a receipt saying it is used if available */
template <typename ItemType>
int BagReceipt<ItemType>::add(const ItemType& newEntry) {
    int i(0);
    bool hasRoomToAdd(itemCount < maxItems);
    if(!hasRoomToAdd){
        ItemType* oldArray = items;
        bool* olduse = inuse;
        items = new ItemType[maxItems * 2];
        inuse = new bool[maxItems * 2];
        for(int p(0);p<maxItems;++p){
            items[p]=oldArray[p];
        }
        for(int d(0);d<maxItems;++d){
            inuse[d]=olduse[d];
        }
        delete [] oldArray;
        delete [] olduse;
        maxItems = 2*maxItems;
    }
    for(;i<maxItems;++i){
        if(inuse[i] == false){
            inuse[i] = true;
            items[i] = newEntry;
            break;
        }
    }
    ++itemCount;
    
    return i;
}

/** Checks to see if the location contains an item and if it does it
 * removes the item and sets receipt to false*/
template <typename ItemType>
ItemType BagReceipt<ItemType>::remove(const ItemType& anEntry) {
    
    int locatedIndex(getIndexOf(anEntry) );
    bool canRemoveItem(!isEmpty() && locatedIndex > -1);
    if (canRemoveItem) {
        --itemCount;
        inuse[locatedIndex] = false;
    }
    
    return items[locatedIndex];
}
/** Used to clear all the items out of the bag */
template <typename ItemType>
void BagReceipt<ItemType>::clear() {
    
    itemCount = 0;
    for(int i(0);i<maxItems;++i){
        inuse[i] = false;
        items[i] = "None";
    }
}
/** Checks to see if a specific type of item is in the bag */
template <typename ItemType>
bool BagReceipt<ItemType>::contains(const ItemType& anEntry) const {
    
    bool isFound(false);
    int curIndex(0);
    
    while (!isFound && curIndex < itemCount) {
        isFound = anEntry == items[curIndex];
        ++curIndex; // Does not matter if extra increment occurs
    }
    
    return isFound;
}
/** Counts the amount of times a specific item is in the bag */
template <typename ItemType>
int BagReceipt<ItemType>::getFrequencyOf(const ItemType& anEntry) const
{
    
    int frequency(0);
    int curIndex(0);
    
    while (curIndex < itemCount) {
        if (items[curIndex] == anEntry) {
            ++frequency;
        }
        ++curIndex;
    }
    
    return frequency;
}

template <typename ItemType>
std::vector<ItemType> BagReceipt<ItemType>::toVector() const {
    
    std::vector<ItemType> bagContents;
    
    for (int i(0); i < maxItems; ++i) {
        if(inuse[i] ==true)
            bagContents.push_back(items[i]);
    }
    
    return bagContents;
}
/** Checks to see if the location has an item in it */
template <typename ItemType>
int BagReceipt<ItemType>::getIndexOf(const ItemType& target) const {
    
    bool isFound(false);
    int targetIndex(-1);
    int searchIndex(0);
    
    while (!isFound && searchIndex < itemCount) {
        isFound = items[searchIndex] == target;
        
        if (isFound) {
            targetIndex = searchIndex;
        }
        ++searchIndex; // Does not matter if extra increment occurs
    }
    
    return targetIndex;
}

