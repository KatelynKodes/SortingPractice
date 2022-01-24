#pragma once

template <typename T>
class DynamicArray
{
public:
	DynamicArray();
	~DynamicArray();

	T* getItem(int index);
	int getLength();

	void addItem(T item);
	bool removeItem(T item);
	void sortItems();
private:
	T** m_items;
	int m_length
};

template<typename T>
inline DynamicArray<T>::DynamicArray()
{
	m_items = new T* {};
	m_length = 0;
}

template<typename T>
inline DynamicArray<T>::~DynamicArray()
{
	delete m_items;
}

template<typename T>
T* DynamicArray<T>::getItem(int index)
{
	for (int i = 0; i < m_length; i++)
	{
		if (i == index)
		{
			return m_items[i];
		}
	}

	return nullptr;
}

template<typename T>
inline int DynamicArray<T>::getLength()
{
	return m_length;
}

template<typename T>
inline void DynamicArray<T>::addItem(T item)
{
	T** tempArray = new T * [m_length + 1];

	for (int i = 0; i < m_length; i++)
	{
		tempArray[i] = m_items[i];
	}

	tempArray[m_length] = item;

	m_items = tempArray;
	m_length++;
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

	T** tempArray = new T * [m_length - 1];

	j = 0;
	for (int i = 0; i < m_length)
	{
		if (item != m_items[i])
		{
			tempArray[j] = m_items[i];
			j++
		}
		else
		{
			itemRemoved = true;
		}
	}

	if (itemRemoved)
	{
		m_items = tempArray;
		m_length--;
	}

	return itemRemoved;
}

template<typename T>
inline void DynamicArray<T>::sortItems()
{
	T* key;
	int j = 0;

	for (int i = 0; i < m_length, i++)
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
