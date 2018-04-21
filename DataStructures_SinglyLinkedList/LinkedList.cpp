#include "LinkedList.h"
#include <iostream>
#include <sstream>	



LinkedList::LinkedList()
{
	head = nullptr;

}

void LinkedList::addNode(int val)
{
	bool statusAdd;
	statusAdd = addNodePrivate(val, head);
	if (statusAdd == true)
		std::cout << "Success: Node Successfully Added." << std::endl;
	else
		std::cerr << "Error: Node Wasn't Added." << std::endl;
}

bool LinkedList::addNodePrivate(int value, Node* t )
{
	/*
	If the current Node is not pointing to anything this situation could mean a few things.
	1. It is an empty list.
	2. You have recursively arrived at the last item and you are appending this new node to the end of the list.
	*/
	if (t == nullptr) 
	{
		Node* aNode = new Node(value, nullptr);
		head = aNode;
		++nodeCounter;
		return true;
	}	
	else if (t != nullptr)
	{
		if (t->ptr != nullptr)
		{
			addNodePrivate(value, t->ptr);
		}
		else
		{
			Node* aNode = new Node(value, nullptr);
			t->ptr = aNode;
			++nodeCounter;
			return true;
		}

	}


}


std::string LinkedList::PrintList()
{
	std::stringstream ss;
	Node* T = head;

	while (T != nullptr)
	{
		ss << T->data;

		if (T->ptr != nullptr)
		{
			ss << "-->";
		}
		T = T->ptr;
	}

	ss << std::endl;
	return ss.str();
}

LinkedList::~LinkedList()
{
}
