#include <iostream>
#include "DynamicArray.h"

int numberArray[] = { 8,2,9,4,0 };
int numberArray2[] = { 4,6,7,3,9 };


template <typename T>
void PrintArray(T arrToPrint[], int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << arrToPrint[i];
		std::cout << " ";
	}

	std::cout << std::endl;
}

void PrintDynamicArray(DynamicArray<int> arr)
{
	for (int i = 0; i < arr.getLength(); i++)
	{
		std::cout << arr.getItem(i);
		std::cout << " ";
	}

	std::cout << std::endl;
}

template <typename T>
void BubbleSort(T ArrayToChange[], int size)
{
	T prevNum;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (numberArray[j] > numberArray[i])
			{
				prevNum = numberArray[j];

				numberArray[j] = numberArray[i];
				numberArray[i] = prevNum;
			}
		}
	}
}

void insertionSort(int arr[], int size)
{
	//set key to 0
	int key = 0;

	//set j to 0
	int j = 0;

	//for each item in collection...
	for (int i = 0; i < size; i++)
	{
		//Set key to be the value at the current index
		key = arr[i];

		//set j to be the previous index
		j = i - 1;

		//while j is greater than or equal to 0 
		//and the value of j ia greator than key
		while (j >= 0 && arr[j] > key)
		{
			//set value at the index of j+1 to br j
			arr[j + 1] = arr[j];

			//decrement
			j--;
		}

		//set avalue at the index of j+1 to be the key
		arr[j + 1] = key;
	}
}

int main()
{
	//BUBBLE SORT
	std::cout << "BUBBLE SORT:\nThe current array is: ";

	PrintArray(numberArray, 5);

	BubbleSort(numberArray, 5);

	std::cout << "The new array is: ";

	PrintArray(numberArray, 5);

	//INSERTION SORT
	std::cout << "\nINSERTION SORT:\nThe current array is ";
	PrintArray(numberArray2, 5);

	insertionSort(numberArray2, 5);

	std::cout << "The new array is: ";
	PrintArray(numberArray2, 5);

	//DYNAMIC ARRAY
	DynamicArray<int> arr = DynamicArray<int>();
	arr.addItems(new int[5] {5, 3, 2, 4, 1}, 5);

	std::cout << "\nDYNAMIC ARRAY LIST:\nThe current dynamic Array is: ";
	PrintDynamicArray(arr);

	arr.sortItems();
	std::cout << "array after sorting: ";
	PrintDynamicArray(arr);

	arr.removeItem(4);
	std::cout << "array after removing the number 4: ";
	PrintDynamicArray(arr);

}

