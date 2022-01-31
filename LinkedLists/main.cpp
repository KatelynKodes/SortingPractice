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


}