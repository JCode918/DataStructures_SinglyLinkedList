#pragma once
#include <iostream>
class LinkedList
{
private:
	/*
	nodeCounter gives us an easy way to keep track of the number of loads in our linked list.
	*/
	int nodeCounter; 
	/*
	Our list is built with many different Nodes. Below you will find the basic structure of the building block of our list.
	*/
	struct Node
	{
		int data;
		Node* ptr;
		Node(const int & x, Node* next) : data(x), ptr(next) { }; // Constructor for a Node.
	};
	/*
	Pointer to the first node in our list.
	*/
	Node* head;

	/*
	Function will return true if the node was added.
	*/
bool addNodePrivate(int value, Node* t);
	

public:
	/*
	Constructor for Linked List
	*/
	LinkedList();
	
	/*
	Public Method of Adding a new Node to the list.
	*/
	void addNode(int val);

	/*
	Return the current count of for Items in the list.
	*/

	int getNodeCount() { return nodeCounter; };

	int getHeadValue() { return head->data; };

	std::string PrintList();

	~LinkedList();
};

