//hash.cpp


#include "hash.hpp"

// Initialize all to -1.
HashTable::HashTable()
{    
    for(int i=0; i<10;i++)
        table[i] = -1;
}

// Adds an item to the Hash Table with Linear Probing.
bool HashTable::insertItemLin(int toInsert)
{
    if (toInsert == -1)
        return false;

    int lastDig = (toInsert % 10);

    if(table[lastDig] == -1)
    {
        table[lastDig] = toInsert;
        return true;
    }
    else
    {
        for(int i=(lastDig+1); i<10; i++)
        {
            if(table[i] == -1)
            {
                table[i] = toInsert;
                return true;
            }
        }

        for(int i=0; i<lastDig; i++)
        {
            if(table[i] == -1)
            {
                table[i] = toInsert;
                return true;
            }
        }  
    }
    return false;
}

// Adds an item to the Hash Table with Quadratic Probing. 
bool HashTable::insertItemQuad(int toInsert)
{
    cout<<"This no worky yet"<<endl;
}

// Display the contents of the Hash Table to console window.
void HashTable::printTable(bool chain)
{
    if(!chain)
    {
        printf("\n");
        for(int i=0; i<10; i++)
        {
            if(table[i] == -1)
                printf("   %d\n", i);
            else
                printf("   %d  %d\n", i, table[i]);
        }
    }
    else
    {
        cout<<"This no worky yet"<<endl;
    }
}






