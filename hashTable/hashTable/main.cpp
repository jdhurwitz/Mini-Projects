//
//  main.cpp
//  hashTable
//
//  Created by Jonathan Hurwitz on 12/17/15.
//  Copyright © 2015 Jonathan Hurwitz. All rights reserved.
//

#include <iostream>
#include "hashTable.hpp"

int main(int argc, const char * argv[]) {
    hashTable HT(20);
    HT.insert("Ricky", 21);
    HT.insert("Jonny", 20);
    HT.insert("Jeremy", 20);
    HT.insert("pizza", 1);
    HT.insert("Mike", 63);
    
    HT.printBuckets();
    
    return 0;
}
