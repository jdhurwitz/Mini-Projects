//
//  hashTable.hpp
//  hashTable
//
//  Created by Jonathan Hurwitz on 12/17/15.
//  Copyright © 2015 Jonathan Hurwitz. All rights reserved.
//

#ifndef hashTable_hpp
#define hashTable_hpp

#include <stdio.h>
#include <vector>
#include <string>

class hashTable{
public:
    hashTable(int size);
    int hashFunc(std::string key);
    int numItemsInBucket(int index);
    
    void printBuckets();
    void insert(std::string name, int val);

private:
    int m_size;
    
    struct item{
        std::string name;
        int val;
        item* next;
    };

    std::vector<item*> table;
};

#endif /* hashTable_hpp */
