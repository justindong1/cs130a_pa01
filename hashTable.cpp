// hashTable.cpp 

#include "hashTable.h"
#include <vector>
#include <string>
#include <list>
#include <cstdlib>

using namespace std; 

hashTable::hashTable(int size) {
    this->size = size; 
    table.resize(size); 
    a.resize(4); 
    maxCollisions.resize(2); 
    srand(time(NULL)); 
    for (int i=0; i<a.size(); i++) {
        a[i] = rand()%(size-1); 
    }
    for (int i=0; i<maxCollisions.size(); i++) {
        maxCollisions[i] = 0; 
    }
}

int hashTable::hash(std::vector<int> x) {
    int res = 0; 
    for (int i=0; i<x.size(); i++) {
        res+=x[i]*a[i];
    }
    res=res%size; 
    return res; 
}

void hashTable::insert(std::vector<int> x) {
    int index = hash(x); 
    for (list<vector<int> >::iterator i=table[index].begin(); i != table[index].end(); i++) {
        if (*i == x) {
            cerr << "The value " + printIP(x) + " is already in the table." << endl; 
        }
    }
    table[index].push_back(x); 
    numInserted++; 
    if (table[index].size() > maxCollisions[0]) {
        maxCollisions[0] = table[index].size();
        maxCollisions[1] = index; 
    }
}

std::string hashTable::printIP(std::vector<int> x) {
    std::string res; 
    for (int i=0; i<x.size(); i++) {
        res+=to_string(x[i]); 
        res+=".";
    }
    res.pop_back(); 
    return res; 
}

std::string hashTable::lookup(std::vector<int> x) {
    std::string res = printIP(x); 
    int index = hash(x); 
    for (list<vector<int> >::iterator i=table[index].begin(); i != table[index].end(); i++) {
        if (*i == x) {
            res+=": found.";
            return res; 
        }
    }
    res+=": not found.";
    return res; 
}

void hashTable::remove(std::vector<int> x) {
    int index = hash(x); 
    bool removed = false; 
    for (list<vector<int> >::iterator i=table[index].begin(); i != table[index].end(); i++) {
        if (*i == x) {
            table[index].erase(i); 
            removed = true; 
            numDeleted++; 
        }
    }
    if (removed == false) {
        cerr << "The value " + printIP(x) + " is not in the table." << endl; 
    }

}

void hashTable::printStats() {
    for (int i=a.size()-1; i>=0; i--) {
        cout << a[i] << " ";
    }
    cout << "\n";
    cout << getnumInserted() << endl; 
    cout << getnumDeleted() << endl; 
    cout << numOneItem() << endl; 
    cout << maxCollisions[0] << " " << maxCollisions[1] << endl; 
}

std::vector<int> hashTable::getmaxCollisions() {
    return maxCollisions;
}

int hashTable::getnumInserted() {
    return numInserted;
}

int hashTable::getnumDeleted() {
    return numDeleted; 
}

int hashTable::numOneItem() {
    int numOne = 0; 
    for (int i=0; i<size; i++) {
        if (table[i].size() == 1) {
            numOne++; 
        }
    }
    return numOne; 
}

