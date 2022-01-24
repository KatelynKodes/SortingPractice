#include <iostream>

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

	std::cout << "\nThe new array is: ";

	PrintArray(numberArray, 5);

	//INSERTION SORT
	std::cout << "\n\nINSERTION SORT:\nThe current array is ";
	PrintArray(numberArray2, 5);

	insertionSort(numberArray2, 5);

	std::cout << "\nThe new array is: ";
	PrintArray(numberArray2, 5);
}

