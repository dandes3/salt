//linkedList.h

#include <iostream>
#include <string>

using namespace std;

struct Item
{
    int key;
    Item * next;
};

class LinkedList
{
private:
    Item * head;
    
    int length;
    
public:
    // Constructs the empty linked list object.
    // Creates the head node and sets length to zero.
    LinkedList();
    
    // Inserts an item at the end of the list.
    void insertItem( Item * newItem );
    
    // Removes an item from the list by item key.
    // Returns true if the operation is successful.
    bool removeItem( string itemKey );
    
    // Searches for an item by its key.
    // Returns a reference to first match.
    // Returns a NULL pointer if no match is found.
    Item * getItem( string itemKey );
    
    // Displays list contents to the console window.
    void printList();
    
    // Returns the length of the list.
    int getLength();
    
    // De-allocates list memory when the program terminates.
    ~LinkedList();
};

#endif

//*****************************************************************
// End of File
//*****************************************************************