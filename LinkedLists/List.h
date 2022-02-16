#pragma once
#include "Iterator.h";
#include <iostream>

template <typename T>
class List
{
public:
	List();
	List(const List<T>& other);
	~List();

	/// <summary>
	/// deletes all nodes in the list
	/// </summary>
	void destroy();

	/// <summary>
	/// returns an iterator pointing to the first node in the list
	/// </summary>
	Iterator<T> begin() const;

	/// <summary>
	/// returns the next item after the last node in the list
	/// </summary>
	Iterator<T> end() const;

	/// <summary>
	/// set the default values for the first node pointer, the last node pointer, and the node count
	/// </summary>
	void initialize();

	/// <summary>
	/// sets the given iterator to point to a node at the given index
	/// </summary>
	bool getData(Iterator<T>& iter, int index);

	/// <summary>
	/// returns the amount of nodes in the list
	/// </summary>
	int getLength() const;
	const List<T>& operator =(const List<T>& otherlist);

	/// <summary>
	/// returns whether or not the list has any nodes in it
	/// </summary>
	bool isEmpty() const;

	/// <summary>
	/// checks to see if the given item is in the list
	/// </summary>
	/// <param name = "object"> the object type that is being checked for </param>
	bool contains(const T object);

	/// <summary>
	/// adds a new node to the beginning of the list
	/// </summary>
	/// <param name = "value"> the object type that is being added to the front of the list </param>
	void pushFront(const T& value);

	/// <summary>
	/// adds a new node to the end of the list
	/// </summary>
	/// <param name = "value"> the object type that is being added to the end of the list </param>
	void pushBack(const T& value);

	/// <summary>
	/// adds a new node at the given index
	/// </summary>
	/// <param name = "value"> the object type that is being added at the index specified </param>
	/// <param name = "index"> the index the value is being added into </param>
	bool insert(const T& value, int index);

	/// <summary>
	/// removes the first node with the given value
	/// </summary>
	/// <param name = "value"> the value of the nodes that are being removed </param>
	bool remove(const T& value);
	
	/// <summary>
	/// prints the values for all the nodes
	/// </summary>
	void print() const;


	void sort();


private:
	Node<T>* m_head;
	Node<T>* m_tail;
	int m_nodecount;
};


template<typename T>
inline List<T>::List()
{
	initialize();
}

template<typename T>
inline List<T>::List(const List<T>& other)
{
	m_head = other.m_head;
	m_tail = other.m_tail;
	m_nodecount = other.m_nodecount;
}

template<typename T>
inline List<T>::~List()
{
	destroy();
}

template<typename T>
inline void List<T>::destroy()
{
	while (!isEmpty())
	{
		remove(m_head->data);
	}
}

template<typename T>
inline Iterator<T> List<T>::begin() const
{
	Iterator<T> beginingIter = Iterator<T>(m_head);
	return beginingIter;
}

template<typename T>
inline Iterator<T> List<T>::end() const
{
	Iterator<T> endingIter = Iterator<T>(m_tail->next);
	return endingIter;
}

template<typename T>
inline void List<T>::initialize()
{
	m_nodecount = 0;
	m_head = nullptr;
	m_tail = nullptr;
}

template<typename T>
inline bool List<T>::getData(Iterator<T>& iter, int index)
{
	for (int i = 0; i < m_nodecount; i++)
	{
		iter.m_current = iter.m_current->next;

		if (i == index)
		{
			return true;
		}
	}

	return false;
}

template<typename T>
inline int List<T>::getLength() const
{
	return m_nodecount;
}

template<typename T>
inline const List<T>& List<T>::operator=(const List<T>& otherlist)
{
	this->m_head = otherlist.m_head;
	this->m_tail = otherlist.m_tail;
	this->m_nodecount = otherlist.m_nodecount;

	return this;
}

template<typename T>
inline bool List<T>::isEmpty() const
{
	if (m_nodecount == 0)
		return true;
	else
		return false;
}

template<typename T>
inline bool List<T>::contains(const T object)
{
	// Iterate through the list...
	for (Iterator<T> iter = begin(); iter != end(); ++iter)
	{
		//If the node the iterator is pointing to is the same type of object being passed in...
		if (*iter == object) 
			return true; //Return true
	}

	return false;
}

template<typename T>
inline void List<T>::pushFront(const T& value)
{
	/// Make a new node containing the value of the value passed in
	Node<T>* newNode = new Node<T>(value);

	if (m_head == nullptr && m_tail == nullptr)
	{
		m_head = newNode;
		m_tail = newNode;
	}
	else
	{
		m_head->previous = newNode;
		newNode->next = m_head;
		m_head = newNode;
	}

	m_nodecount++;

}

template<typename T>
inline void List<T>::pushBack(const T& value)
{
	/// Make a new node containing the value of the value passed in
	Node<T>* newNode = new Node<T>(value);

	if (m_head == nullptr && m_tail == nullptr)
	{
		m_head = newNode;
		m_tail = newNode;
	}
	else
	{
		m_tail->next = newNode;
		newNode->previous = m_tail;
		m_tail = newNode;
	}

	m_nodecount++;
}

template<typename T>
inline bool List<T>::insert(const T& value, int index)
{
	if (isEmpty())
	{
		pushFront(value);
		return true;
	}
	else
	{
		if (index == 0)
		{
			pushFront(value);
			return true;
		}
		else if (index == m_nodecount)
		{
			pushBack(value);
			return true;
		}

		Node<T>* currNode = m_head;
		Node<T>* newNode = new Node<T>(value);
		int i = 0;

		while (currNode != nullptr)
		{
			if (i == index)
			{
				newNode->next = currNode;
				newNode->previous = currNode->previous;
				currNode->previous->next = newNode;
				currNode->previous = newNode;
				i++;
				return true;
			}
			else
			{
				currNode = currNode->next;
				i++;
			}
		}
	}
	return false;
}

template<typename T>
inline bool List<T>::remove(const T& value)
{
	if (isEmpty())
	{
		return false;
	}
	else
	{
		Node<T>* currNode = m_head;

		while (currNode != nullptr)
		{
			if (currNode->data == value)
			{
				if (currNode->previous == nullptr)
				{
					m_head = currNode->next;
				}
				else
				{
					currNode->previous->next = currNode->next;
				}

				if (currNode->next == nullptr)
				{
					m_tail = currNode->previous;
				}
				else
				{
					currNode->next->previous = currNode->previous;
				}

				delete currNode;
				m_nodecount--;
				return true;
			}
			else
			{
				currNode = currNode->next;
			}
		}
	}
	return false;
}

template<typename T>
inline void List<T>::print() const
{
	for (Iterator<T> iter = begin(); iter != end(); ++iter)
	{
		std::cout << *iter << " ";
	}

	std::cout << "" << std::endl;
}

template<typename T>
inline void List<T>::sort()
{
	if (!isEmpty())
	{
		Node<T>* currNode = nullptr;
		Node<T>* tempNode = new Node<T>();

		for (int i = 0; i < getLength(); i++)
		{
			currNode = m_head;
			for (int j = 0; j < getLength(); j++)
			{
				if (currNode->data > currNode->next->data)
				{
					tempNode->data = currNode->data;
					currNode->data = currNode->next->data;
					currNode->next->data = tempNode->data;
				}

				currNode = currNode->next;
			}
		}
	}
}
