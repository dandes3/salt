//hash.hpp

#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;



class Node
{
private:
	int data;
	Node* next;

public:
	Node() {};
	void SetData(int aData) { data = aData; };
    void SetNext(Node* aNext) { next = aNext; };
    int Data() { return data; };
    Node* Next() { return next; };
};

class List
{
private:
	Node *head;

public:
	List() {head = NULL};

	void Append(int data);

	int head();

	void Print();

};


class HashTable
{

private:
	int table[10]; // Internal array to track hash placement
     
public:
    HashTable(); // Constructor

    void purge(); // Psuedo destructor, resets all values to -1
    
    bool insertItemLin(int toInsert); // Inserts item into hash table using linear probing

    bool insertItemQuad(int toInsert); // Inserts item into hash table using quadratic probing

    bool insertItemDub(int toInsert); // Inserts item into hash table with second hash function
    
    void printTable(bool chain); // Prints hash table 
     
};

