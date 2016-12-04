// Written by Don Andes, for the College of William & Mary, Fall 2016

//hashmain.cpp

#include "hash.hpp"

int main()
{
    int i; // Iterator
    int pullFrom; // Value to be taken in
    int buffAr[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}; // Initialize

    HashTable hash;

    cout << "\nHash Tables\n" << endl;
    cout << "Please enter up to 10 non-negative integers, followed by -1" << endl;

    // Pull from stdin until we hit 10 or a -1, put in array
    for(i = 0; i < 10; i++)
    {
        scanf("%d", &pullFrom);

        if(pullFrom == -1)
            break;

        buffAr[i] = pullFrom;
    }

    // Throw array back at console 
    for(i=0; i<10; i++)
    {
        printf("> %d\n", buffAr[i]);
        if(buffAr[i]==-1)
            break;
    }

    cout << "\nHash Table with Linear Probing" << endl;
    
    // Iterate through array and attempt to insert for each one
    for(i=0; i<10; i++)
    {
        if(!(hash.insertItemLin(buffAr[i])))
        {
            if(buffAr[i] != -1)
            {
                printf("\n  %d could not be inserted in the table\n", buffAr[i]);
            }
            else
                continue;
        }
    }

    hash.printTable(false);
    hash.purge();

    cout << "\nHash Table with Quadratic Probing" << endl;

    // Iterate through array and attempt to insert for each one (quadratic)
    for(i=0; i<10; i++)
    {
        if(!(hash.insertItemQuad(buffAr[i])))
        {
            if(buffAr[i] != -1)
            {
                printf("\n  %d could not be inserted in the table\n", buffAr[i]);
            }
            else
                continue;
        }
    }

    hash.printTable(false);
    hash.purge();

    cout << "\nExtra Credit: Hash Table with Double Hashing" << endl;

    // Iterate through array and attempt to insert for each one (dobule hashing)
    for(i=0; i<10; i++)
    {
        if(!(hash.insertItemDub(buffAr[i])))
        {
            if(buffAr[i] != -1)
            {
                printf("\n  %d could not be inserted in the table\n", buffAr[i]);
            }
            else
                continue;
        }
    }

    hash.printTable(false);
    hash.purge();

    cout << "\nExtra Credit: Hash Table with Seperate Chaining" << endl;

    // Iterate through array and attempt to insert for each one (chaining)
    for(i=0; i<10; i++)
    {
        if(!(hash.insertItemChain(buffAr[i])))
        {
            if(buffAr[i] != -1)
            {
                printf("\n  %d could not be inserted in the table\n", buffAr[i]);
            }
            else
                continue;
        }
    } 
    
    hash.printTable(true);
    hash.purge(); 
    
    return 0;
}
