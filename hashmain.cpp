//hashmain.cpp

#include "hash.hpp"

int main()
{
    int pullFrom; 
    int buffAr[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};

    HashTable hash;

    cout << "" << endl;
    cout << "Hash Tables" << endl;
    cout << "" << endl;
    cout << "Please enter up to 10 non-negative integers, followed by -1" << endl;

    for(int i = 0; i < 10; i++)
    {
        scanf("%d", &pullFrom);

        if(pullFrom == -1)
            break;

        buffAr[i] = pullFrom;
    }

    for(int i=0; i<10; i++)
    {
        printf("> %d\n", buffAr[i]);
        if(buffAr[i]==-1)
            break;
    }

    cout << "" << endl;
    cout << "Hash Table with Linear Probing" << endl;
    
    for(int i=0; i<10; i++)
    {
        if(!(hash.insertItemLin(buffAr[i])))
        {
            if(buffAr[i] != -1)
            {
                printf("\n");
                printf("  %d could not be inserted in the table\n", buffAr[i]);
            }
            else
                continue;
        }
    }
    hash.printTable(false);
    cout << "" << endl;

    hash.purge();

    cout << "" << endl;
    cout << "Hash Table with Quadratic Probing" << endl;

    for(int i=0; i<10; i++)
    {
        if(!(hash.insertItemQuad(buffAr[i])))
        {
            if(buffAr[i] != -1)
            {
                printf("\n");
                printf("  %d could not be inserted in the table\n", buffAr[i]);
            }
            else
                continue;
        }
    }

    hash.printTable(false);
    cout << "" << endl;

    hash.purge();

    cout << "" << endl;
    cout << "Extra Credit: Hash Table with Double Hashing" << endl;

    for(int i=0; i<10; i++)
    {
        if(!(hash.insertItemDub(buffAr[i])))
        {
            if(buffAr[i] != -1)
            {
                printf("\n");
                printf("  %d could not be inserted in the table\n", buffAr[i]);
            }
            else
                continue;
        }
    }

    hash.printTable(false);
    cout << "" << endl;

    hash.purge();

    cout << "" << endl;
    cout << "Extra Credit: Hash Table with Seperate Chaining" << endl;

    
    for(int i=0; i<10; i++)
    {
        if(!(hash.insertItemChain(buffAr[i])))
        {
            if(buffAr[i] != -1)
            {
                printf("\n");
                printf("  %d could not be inserted in the table\n", buffAr[i]);
            }
            else
                continue;
        }
    }  
    
    return 0;
}
