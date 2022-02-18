#include "List.h"

int main()
{
	//Declare the list
	List<float> numberList = List<float>();


	//Insert numbers into the list
	numberList.pushFront(6);
	numberList.pushBack(9);
	numberList.pushBack(3);
	numberList.pushBack(2);
	numberList.pushBack(7);

	//print numbers
	std::cout << "LINKED LIST: ";
	numberList.print();

	//Inserting
	std::cout << "INSERTING INTO LINKED LIST:";
	numberList.insert(1, 3);
	numberList.insert(5, 0);
	numberList.insert(4, numberList.getLength());
	numberList.print();

	//Sorting
	std::cout << "SORTED LINKED LIST:";
	numberList.sort();
	numberList.print();

	//Removing
	numberList.remove(3);
	std::cout << "REMOVING VALUE FROM LINKED LIST:";
	numberList.print();

	system("pause");
}