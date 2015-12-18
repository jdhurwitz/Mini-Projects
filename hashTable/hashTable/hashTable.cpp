//
//  hashTable.cpp
//  hashTable
//
//  Created by Jonathan Hurwitz on 12/17/15.
//  Copyright © 2015 Jonathan Hurwitz. All rights reserved.
//

#include "hashTable.hpp"
#include <string>
#include <iostream>

using namespace std;
hashTable::hashTable(int size){
    m_size = size;
    table.resize(size);

    vector<item*>::iterator it;
    for(it = table.begin(); it < table.end(); ++it){
        *it = NULL;
    }
}

int hashTable::numItemsInBucket(int index){
    item* cur = table[index];
    int count = 0;
    
    //Empty bucket
    if(cur == NULL)
        return 0;
    
    //Case for single item
    count++;
    while(cur->next != NULL){
        count++;
        cur=cur->next;
    }
    
    return count;
}

void hashTable::printBuckets(){
    vector<item*>::iterator it;
    int index = 0;
    for(it = table.begin(); it< table.end(); it++){
        cout<<"-----------------------"<<endl;
        cout<<"index = "<<index<<endl;
        if(table[index] != NULL){
            cout<<table[index]->name<<endl;
            cout<<table[index]->val<<endl;
        }else{
            cout<<"NULL"<<endl;
        }
        cout<<"# items in bucket: "<<numItemsInBucket(index)<<endl;
        cout<<"-----------------------"<<endl;
        
        index++;
        
    }
}

void hashTable::insert(string name, int val){
    item* to_add = new item;
    to_add->name = name;
    to_add->val = val;
    to_add->next = NULL;
    
    int hashed_index = hashFunc(name);
    
    //Empty bucket
    if(table[hashed_index] == NULL )
        table[hashed_index] = to_add;
    
    //Not empty
    else{
        //Find last node in LL
        item* cur_node = table[hashed_index];
        while(cur_node->next != NULL){
            cur_node = cur_node->next;
        }
        
        //Found last one. Add new node at end.
        cur_node->next = to_add;
    }
}

int hashTable::hashFunc(string key){
    int total = 0;
    for(int i = 0; i < key.length(); i++){
        total += (i+1)*key[i];
    }
    return total% m_size;
}