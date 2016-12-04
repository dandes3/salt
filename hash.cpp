//hash.cpp

#include "hash.hpp"

// Initialize all to -1.
HashTable::HashTable()
{    
    for(int i=0; i<10;i++)
        table[i] = -1;
}

// Purge values, re-write arrays to all -1
void HashTable::purge()
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
        for(int i=1; i<6; i++) // After 5^2, keys start to loop
        {
            int newMod = (lastDig + pow(i, 2));

            if(newMod>10)
                newMod = newMod % 10;

            if(newMod==10) 
                newMod = 0;

            if(table[newMod] == -1)
            {
                table[newMod] = toInsert;
                return true;
            }
        }
    }
    return false;
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






