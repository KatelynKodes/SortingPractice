#pragma once

template <typename T>
class DynamicArray
{
public:
	DynamicArray();
	~DynamicArray();

	T getItem(int index);
	int getLength();

	void addItem(T item);
	void addItems(T items[], int itemsSize);
	bool removeItem(T item);
	void sortItems();
private:
	T* m_items;
	int m_length;
};

template<typename T>
inline DynamicArray<T>::DynamicArray()
{
	m_items = nullptr;
	m_length = 0;
}

template<typename T>
inline DynamicArray<T>::~DynamicArray()
{
}

template<typename T>
T DynamicArray<T>::getItem(int index)
{
	if (index < 0 || index >= getLength())
	{
		return T();
	}

	for (int i = 0; i < m_length; i++)
	{
		if (i == index)
		{
			return m_items[i];
		}
	}
}

template<typename T>
inline int DynamicArray<T>::getLength()
{
	return m_length;
}

template<typename T>
inline void DynamicArray<T>::addItem(T item)
{
	T* tempArray = new T  [getLength() + 1];

	for (int i = 0; i < getLength(); i++)
	{
		tempArray[i] = m_items[i];
	}

	tempArray[getLength()] = item;
	delete[] m_items;
	m_items = tempArray;
	m_length++;
}

template<typename T>
inline void DynamicArray<T>::addItems(T items[], int itemsSize)
{
	for (int i = 0; i < itemsSize; i++)
	{
		addItem(items[i]);
	}
}

template<typename T>
inline bool DynamicArray<T>::removeItem(T item)
{
	//Check if actor is null
	if (!item)
	{
		return false;
	}

	bool itemRemoved = false;

	T* tempArray = new T  [getLength() - 1];

	int j = 0;
	for (int i = 0; i < getLength(); i++)
	{
		if (item != m_items[i])
		{
			tempArray[j] = m_items[i];
			j++;
		}
		else
		{
			itemRemoved = true;
		}
	}

	if (itemRemoved)
	{
		delete[] m_items;
		m_items = tempArray;
		m_length--;
	}

	return itemRemoved;
}

template<typename T>
inline void DynamicArray<T>::sortItems()
{
	T key;
	int j = 0;

	for (int i = 0; i < getLength(); i++)
	{
		key = m_items[i];
		j = i - 1;
		while (j >= 0 && m_items[j] > key)
		{
			m_items[j + 1] = m_items[j];
			j--;
		}

		m_items[j + 1] = key;
	}
}
