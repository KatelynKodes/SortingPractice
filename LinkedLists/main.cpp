#include "List.h"

int main()
{
	//Declare the list
	List<float> numberList = List<float>();

	//Insert numbers into the list
	numberList.pushFront(1);
	numberList.pushBack(2);
	numberList.pushBack(3);
	numberList.pushBack(5);
	numberList.pushBack(6);

	//print numbers
	std::cout << "LINKED LIST: ";
	numberList.print();

	//Inserting
	numberList.insert(4, 2);
	numberList.insert(0, 0);
	numberList.insert(7, 6);
	std::cout << "INSERTING INTO LINKED LIST:";
	numberList.print();

	//Sorting
	std::cout << "SORTED LINKED LIST:";
	numberList.print();

	//Removing
	std::cout << "REMOVING VALUE FROM LINKED LIST:";
	numberList.print();

}