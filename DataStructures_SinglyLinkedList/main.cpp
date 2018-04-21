#include <iostream>
#include <sstream>
#include "LinkedList.h"

int main()
{
	LinkedList MyList;
	MyList.addNode(3);
	MyList.addNode(4);
	MyList.addNode(5);
	MyList.addNode(6);
	MyList.addNode(7);

	/*
	std::cout << "The Current List count is " << MyList.getNodeCount() << std::endl;
	std::cout << "The Current Head is " << MyList.getHeadValue() << std::endl;
	MyList.deleteNode(3);
	std::cout << "The Current List count is " << MyList.getNodeCount() << std::endl;
	std::cout << "The Current Head is " << MyList.getHeadValue() << std::endl;
	std::cout << MyList.PrintList() << std::endl;
	MyList.deleteNode(6);
	std::cout << "The Current List count is " << MyList.getNodeCount() << std::endl;
	std::cout << "The Current Head is " << MyList.getHeadValue() << std::endl;
	std::cout << MyList.PrintList();
	MyList.deleteNode(7);
	std::cout << "The Current List count is " << MyList.getNodeCount() << std::endl;
	std::cout << "The Current Head is " << MyList.getHeadValue() << std::endl;
	*/

	std::cout << MyList.PrintList();

	return 0;
}