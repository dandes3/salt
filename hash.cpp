//hash.cpp

#include "hash.hpp"

HashTable::HashTable()
{
    array = new LinkedList[10];
}

int HashTable::hash( string itemKey )
{
    int value = 0;
    for ( int i = 0; i < 10; i++ )
        value += itemKey[i];
    return (value * itemKey.length() ) % length;
}

// Adds an item to the Hash Table.
void HashTable::insertItem( Item * newItem )
{
    int index = hash( newItem -> key );
    array[ index ].insertItem( newItem );
}

// Deletes an Item by key from the Hash Table.
// Returns true if the operation is successful.
bool HashTable::removeItem( string itemKey )
{
    int index = hash( itemKey );
    return array[ index ].removeItem( itemKey );
}

// Returns an item from the Hash Table by key.
// If the item isn't found, a null pointer is returned.
Item * HashTable::getItemByKey( string itemKey )
{
    int index = hash( itemKey );
    return array[ index ].getItem( itemKey );
}

// Display the contents of the Hash Table to console window.
void HashTable::printTable()
{
    cout << "\n\nHash Table:\n";
    for ( int i = 0; i < length; i++ )
    {
        cout << "Bucket " << i + 1 << ": ";
        array[i].printList();
    }
}

// Prints a histogram illustrating the Item distribution.
void HashTable::printHistogram()
{
    cout << "\n\nHash Table Contains ";
    cout << getNumberOfItems() << " Items total\n";
    for ( int i = 0; i < length; i++ )
    {
        cout << i + 1 << ":\t";
        for ( int j = 0; j < array[i].getLength(); j++ )
            cout << " X";
        cout << "\n";
    }
}

// Returns the number of locations in the Hash Table.
int HashTable::getLength()
{
    return length;
}

// Returns the number of Items in the Hash Table.
int HashTable::getNumberOfItems()
{
    int itemCount = 0;
    for ( int i = 0; i < length; i++ )
    {
        itemCount += array[i].getLength();
    }
    return itemCount;
}

// De-allocates all memory used for the Hash Table.
HashTable::~HashTable()
{
    delete [] array;
}

//*****************************************************************
// End of File
//*****************************************************************