// main.cpp
// Justin Dong 6029318 CS130A

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "hashTable.h"

using namespace std; 

// returns IP address converted into a vector of four ints
std::vector<int> convertIP() {
    std::vector<int> ipConv; 
    std::string conv; 
    std::string ip; 
    cin >> ip; 
    for (int i=0; i<ip.size(); i++) {
        if (ip[i] != '.') {
            conv+= ip[i]; 
        }
        if (ip[i] == '.') {
            stringstream x(conv); 
            int ipAd = 0; 
            x >> ipAd; 
            conv = ""; 
            ipConv.push_back(ipAd); 
        }
    }
    stringstream x(conv); 
    int ipAd = 0; 
    x >> ipAd; 
    conv = ""; 
    ipConv.push_back(ipAd); 
    return ipConv; 
}

int main() {
    std::string size; 
    std::string com;
    cin >> size; 
    stringstream x(size); 
    int vecSize = 0; 
    x >> vecSize; 
    hashTable table1(vecSize); 
    while (cin) {
        cin >> com; 
        if (com == "insert") {
            std::vector<int> res = convertIP(); 
            table1.insert(res); 
        }
        if (com == "lookup") {
            std::vector<int> res = convertIP(); 
            cout << table1.lookup(res) << endl;
        }
        if (com == "delete") {
            std::vector<int> res = convertIP(); 
            table1.remove(res); 
        }
        if (com == "stat") {
            table1.printStats(); 
            break;
        }
    }
    return 0; 
}