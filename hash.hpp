//hash.hpp

#include "linkedList.hpp"

class HashTable
{
private:
    
    LinkedList * array;
    
    int hash( int itemKey );
    
public:
    
    HashTable(); // Constructor

    ~HashTable(); // Destructor
    
    bool insertItemLin(int toInsert);

    bool insertItemQuad(int toInsert);
    
    void printTable();
    
};

