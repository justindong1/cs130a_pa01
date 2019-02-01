// hashTable.h
// Justin Dong 6029318 CMPSC130A

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <string>
#include <utility>

class hashTable {
    public:
        hashTable(int size);
        void insert(std::vector<int> x); 
        std::string lookup(std::vector<int> x); 
        void remove(std::vector<int> x); 
        void printStats(); 
        int hash(std::vector<int> x); 
        std::string printIP(std::vector<int> x); 
        // int numEmptySlots(); 
        int numOneItem(); 
        int getnumInserted(); 
        int getnumDeleted(); 
        // int getmaxIndex(); 
        std::vector<int> getmaxCollisions();
        // int getSize(); 
    private:
        std::vector<std::list<std::vector<int> >> table; 
        std::vector<int> a; 
        int numInserted;
        int numDeleted; 
        std::vector<int> maxCollisions; 
        int size; 
};

#endif // HASHTABLE_H