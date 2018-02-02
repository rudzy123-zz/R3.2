//
//  main.cpp
//  Project2TrialLearningCplusplus
//
//  Created by Rudolf Musika on 2/1/18.
//  Copyright © 2018 Rudolf Musika. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;

#include "BagReceipt.hpp"

void displayBag(BagReceipt<std::string>& bag) {
    
    cout << "The bag contains "
    << bag.getCurrentSize()
    << " items:"
    << endl;
    
    std::vector<std::string> bagItems = bag.toVector();
    
    int numberOfEntries = (int)bagItems.size();
    
    for (int i(0); i < numberOfEntries; ++i) {
        cout << bagItems[i]
        << " ";
    }
    
    cout << endl
    << endl;
}

void bagTester(BagReceipt<std::string>& bag) {
    
    cout << "isEmpty: returns "
    << bag.isEmpty()
    << endl;
    
    displayBag(bag);
    
    std::string items[] = {"one", "two", "three", "four", "five",
        "six"};
    
    cout << "Add 6 items to the bag: "
    << endl;
    
    for (int i(0); i < 6; ++i) {
        cout<< "Adding "<<items[i]<< " at: "<< bag.add(items[i]) << endl;
    }
    
    displayBag(bag);
    
    cout << "isEmpty(): returns "
    << bag.isEmpty()
    << endl;
    
    cout << "getCurrentSize(): returns "
    << bag.getCurrentSize()
    << endl;
    
    cout << "Adding 'extra' at: "
    << bag.add("extra")
    << endl;
    
    cout << "contains(\"three\"): returns "
    << bag.contains("three")
    << endl;
    
    cout << "contains(\"ten\"): returns "
    << bag.contains("ten")
    << endl;
    
    cout << "getFrequencyOf(\"one\"): returns "
    << bag.getFrequencyOf("one")
    << endl;
    
    displayBag(bag);
    
    cout << "Removed "
    << bag.remove(items[0])
    << " from location 0."
    << endl;
    
    cout << "getFrequencyOf(\"one\"): returns "
    << bag.getFrequencyOf("one")
    << endl;
    
    cout << "Removed "
    << bag.remove(items[1])
    <<" from location 1."
    << endl;
    
    cout<<"Adding 'A' at: "
    <<bag.add("A")
    <<endl;
    
    cout<<"Adding 'B' at: "
    <<bag.add("B")
    <<endl;
    
    cout << "getFrequencyOf(\"one\"): returns "
    << bag.getFrequencyOf("one")
    << endl;
    
    cout << endl;
    
    displayBag(bag);
    
    cout << "After clearing the bag, ";
    
    bag.clear();
    
    cout << "isEmpty(): returns "
    << bag.isEmpty()
    << endl;
    
}

int main() {
    
    BagReceipt<std::string> bag;
    
    cout << "Testing the Array-Based Bag:"
    << endl
    << "The initial bag is empty."
    << endl;
    
    bagTester(bag);
    
    cout << "All done!"
    << endl;
    
    return EXIT_SUCCESS;
}
