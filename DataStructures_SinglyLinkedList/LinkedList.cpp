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
	else if (t != nullptr &&  t->data != value)
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
	else // This should cover the situation of the value already being entered into the linked list. This will be removed and replaced with a find function
		return false;


}

void LinkedList::find(int value)
{
	findPrivate(value, head);
	if (findPrivate(value, head) == true)
	{
		std::cout << "The Value entered is within the list." << std::endl;
	}
	else
		std::cout << "The Value entered can not be found." << std::endl;
}

bool LinkedList::findPrivate(int value, Node * t)
{
	if (t == nullptr)
	{
		return false;
	}
	else
	{
		if (t->data == value)
		{
			return true;
		}
		else if (t->data != value && t->ptr != nullptr)
		{
			return findPrivate(value, t->ptr);
		}
		else if (t->data != value && t->ptr == nullptr)
		{
			return false;
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

void LinkedList::deleteNode(int value)
{
	deleteNodePrivate(value, head);
}

bool LinkedList::deleteNodePrivate(int value, Node * t)
{
	/*
	The Value doesn't exist in the linked list.
	*/
	if (findPrivate(value, head) == false && head == nullptr)
	{
		if (head == nullptr)
		{
			std::cerr << "This is an empty list" << std::endl;
		}

		return false;
	}
	else
	{
		/*
		The Case where the value to be deleted is the head node.
		*/
		if (t->data == value && t == head)
		{
			Node* oldHead = t;
			head = oldHead->ptr;
			delete oldHead;
			--nodeCounter; // Remember to update the counter.
			return true;
		}
		if (t->data != value && t->ptr != nullptr)
		{
			if (t->ptr->data == value)
			{
				//Case where the Node to be deleted is between two nodes.
				if (t->ptr->data == value && t->ptr->ptr != nullptr)
				{
					Node* aNode = t; // The Node Directly before the one to be deleted.
					Node* bNode = t->ptr; // *** This is the Node to that will be deleted. ***
					Node* cNode = t->ptr->ptr; // Node Directly after the one to be deleted.
					aNode->ptr = cNode; // This step connects the aNode to the cNode.
					delete bNode; // returns the memory used to create the node back.
					--nodeCounter; 
					return true;
				}
				// Case Where the Node to be deleted is already the last node.
				else if (t->ptr->data == value && t->ptr->ptr == nullptr)
				{
					Node* aNode = t;
					Node* bNode = aNode->ptr;
					aNode->ptr = nullptr;
					delete bNode;
					--nodeCounter;
					return true;
				}

			}
			else if (t->ptr->data != value)
			{
				return deleteNodePrivate(value, t->ptr);
			}
		}

	}
	
}

void LinkedList::destroyAllNode(Node * aNode)
{
	if (aNode == nullptr)
	{
		return;
	}
	else if (aNode != nullptr && aNode->ptr != nullptr)
	{
		std::cout << aNode->data << " memory is being returned to the system." << std::endl;
		return destroyAllNode(aNode->ptr);		
		delete aNode;
	}
	else if (aNode != nullptr && aNode->ptr == nullptr)
	{
		std::cout << aNode->data << " memory is being returned to the system this is also the last Node." << std::endl;

		delete aNode;
	}
}


LinkedList::~LinkedList()
{
	destroyAllNode(head);
}
