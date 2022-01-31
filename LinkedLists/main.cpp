#include "List.h"

int main()
{
	//Declare the list
	List<float> numberList = List<float>();

	//Insert numbers into the list
	numberList.pushFront(1);
	numberList.pushFront(2);

	//print numbers
	std::cout << "LINKED LIST: ";
	numberList.print();


}