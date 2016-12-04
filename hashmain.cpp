
#include "hash.hpp"

int main()
{
    int pullFrom; 
    int buffAr[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};

    HashTable hash;

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
                printf("  %d could not be inserted in the table\n", buffAr[i]);
            else
                continue;
        }
    }
    hash.printTable(false);
    return 0;
}
