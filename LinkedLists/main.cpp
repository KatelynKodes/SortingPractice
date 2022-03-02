#include "List.h"

int main()
{
	//Declare the list
	List<float> numberList = List<float>();
	List<float> numberList2 = List<float>();


	//Insert numbers into the list
	numberList.pushFront(6);
	numberList.pushBack(9);
	numberList.pushBack(3);
	numberList.pushBack(2);
	numberList.pushBack(7);

	numberList2.pushFront(6);
	numberList2.pushFront(9);
	numberList2.pushFront(3);
	numberList2.pushBack(2);
	numberList2.pushBack(7);
	numberList2.pushBack(9);

	//print numbers
	std::cout << "LINKED LIST: ";
	numberList.print();

	Iterator<float> SearchIterator = Iterator<float>();

	if (numberList.getData(SearchIterator, 3))
	{
		std::cout << "Data found, item at index of 3 is: " << SearchIterator.operator*() << std::endl;
	}

	numberList.sort();
	std::cout << "LINKED LIST: ";
	numberList.print();

	numberList = numberList2;
	std::cout << "LINKED LIST: ";
	numberList.print();

	system("pause");
}