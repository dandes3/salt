//hash.hpp

#include <iostream>
using namespace std;

//extern int table[10];

class HashTable
{

private:

	int table[10];
     
public:
    
    HashTable(); // Constructor
    
    bool insertItemLin(int toInsert);

    bool insertItemQuad(int toInsert);
    
    void printTable(bool chain);
    
};

