// Written by Don Andes, for the College of William & Mary, Fall 2016

//hash.hpp

#include <iostream> 
#include <stdio.h>
#include <math.h> // Needed for power operations

using namespace std; // Less std::etc everywhere


// Barebones linked list. Really just linked nodes
struct Node
{
    int data;
	Node* next;
};


// Overall HashTable class 
class HashTable
{

private:
	int table[10]; // Internal array to track hash placement

	Node* nTable[10]; // Internal pointer array to handle chaining
     
public:
    HashTable(); // Constructor

    void purge(); // Psuedo destructor, resets all values to -1 or NULL
    
    bool insertItemLin(int toInsert); // Inserts item into hash table using linear probing

    bool insertItemQuad(int toInsert); // Inserts item into hash table using quadratic probing

    bool insertItemDub(int toInsert); // Inserts item into hash table with second hash function

    bool insertItemChain(int toInsert); // Inserts item into hash table using seperate chaining
    
    void printTable(bool chain); // Prints hash table, special function for chain printing  
};

