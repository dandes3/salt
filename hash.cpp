// Written by Don Andes, for the College of William & Mary, Fall 2016

//hash.cpp

#include "hash.hpp"


// Initialize all to -1 for int array, NULL for ptr array
HashTable::HashTable()
{    
    int i; // Iterator

    for(i=0; i<10;i++)
        table[i] = -1;

    for(i=0; i<10;i++)
        nTable[i] = NULL;
}

// Purge values, re-write arrays to all -1, NULL for ptr array
void HashTable::purge()
{
    int i; // Iterator

    for(i=0; i<10;i++)
        table[i] = -1;

    for(i=0; i<10;i++)
        nTable[i] = NULL;
}

// Adds an item to the Hash Table with Linear Probing.
bool HashTable::insertItemLin(int toInsert)
{
    int i; // Iterator
    int lastDig; // Modulo value, treated as index in Linear Probing

    // Passed a dead location, fail out
    if (toInsert == -1) 
        return false;

    // Pull last digit for index
    lastDig = (toInsert % 10); 

    // Found empty slot, insert value
    if(table[lastDig] == -1) 
    {
        table[lastDig] = toInsert;
        return true;
    }

    // Else, we probe one by one until we find an open spot
    // attack right side of array first, then loop back and attack left
    else
    {
        for(i=(lastDig+1); i<10; i++)
        {
            if(table[i] == -1)
            {
                table[i] = toInsert;
                return true;
            }
        }

        for(i=0; i<lastDig; i++)
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
    int i; // Iterator
    int newMod; // New index after remod
    int lastDig; // Modulo value

    // Passed a dead location, fail out
    if (toInsert == -1) 
        return false;

    // Pull last digit for index
    lastDig = (toInsert % 10);

    // Found empty slot, insert value
    if(table[lastDig] == -1)
    {
        table[lastDig] = toInsert;
        return true;
    }

    // Else, remod the index quadratically and try again
    else
    {
        for(i=1; i<6; i++) // After 5^2, keys start to loop
        {
            newMod = (lastDig + pow(i, 2)); // Reason for math include

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

bool HashTable::insertItemDub(int toInsert)
{
    int j; // Alternative location variable
    int lastDig; // Modulo value
    int wrap = 0; // Used for determining times we have wrapped around array
    int count = 0; // Counter
    int jumpVal = 0; // New bucket jump-by number

    // Passed a dead location, fail out
    if (toInsert == -1) 
        return false;

    // Pull last digit for index
    lastDig = (toInsert % 10);

    // Found empty slot, insert value
    if(table[lastDig] == -1)
    {
        table[lastDig] = toInsert;
        return true;
    }

    // Else we re-hash, and begin jumping through list by the new bucket
    // jump value. After we wrap twice, we've covered the whole list
    else
    {
        jumpVal = (7-(toInsert % 7));

        while(wrap<3)
        {
            count++;
            j = lastDig + (jumpVal * count);

            if(j==10)
                j = 0;

            if(j>10)
            {
                j = j%10;
                wrap++;
            }

            if(table[j] == -1)
            {
                table[j] = toInsert;
                return true;
            }  
        }
    }
    return false;
}

bool HashTable::insertItemChain(int toInsert)
{
    int lastDig; // Modulo value

    // Passed a dead location, fail out
    if (toInsert == -1) 
        return false;

    // Pull last digit for index
    lastDig = (toInsert % 10);

    // If the table index is empty, we fill it with a new node, with a
    // payload of the passed value
    if(nTable[lastDig] == NULL)
    {
        Node *newNode = new Node;
        newNode->next = NULL;
        newNode->data = toInsert;
        nTable[lastDig] = newNode;
    }

    // Else we make a new node, fill it's payload, and make it the new head. 
    // The old node gets appended to the end
    else
    {
        Node *aNode = new Node;
        aNode->data = toInsert;
        Node* tmp = nTable[lastDig];
        nTable[lastDig] = aNode;
        nTable[lastDig]->next = tmp;
    }
    return true;
}

// Display the contents of the Hash Table to console window.
void HashTable::printTable(bool chain)
{
    int i; // Iterator

    // Normal printout, no chaining. Iterate through list and pretty print
    if(!chain)
    {
        printf("\n");
        for(i=0; i<10; i++)
        {
            if(table[i] == -1)
                printf("   %d\n", i);
            else
                printf("   %d  %d\n", i, table[i]);
        }
    }

    // Chaining list, check each node and push throught the head to the end
    // of each linked list. Pretty print payloads along the way
    else
    {
        printf("\n");
        for(i=0; i<10; i++)
        {
            if(nTable[i] == NULL)
                printf("   %d  ->_\n", i);
            else
            {
                Node* tmp = nTable[i];
                printf("   %d ", i);

                while(tmp->next)
                {
                    printf(" -> %d", tmp->data);
                    tmp = tmp->next;
                }
                printf(" -> %d", tmp->data);
                printf(" ->_\n");
            }
        }
    }
    // Formatting line
    cout << "" << endl;
}






