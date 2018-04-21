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
	std::cout << "The Current List count is " << MyList.getNodeCount() << std::endl;

	std::cout << MyList.PrintList();
	return 0;
}