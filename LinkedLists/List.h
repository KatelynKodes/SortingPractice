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
	Node<T>* currNode = m_head;
	Node<T>* TempNode = new Node<T>();

	for (int i = 0; i < m_nodecount; i++)
	{
		TempNode = currNode;
		delete currNode;
		currNode = TempNode->next;
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
	Iterator<T> endingIter = Iterator<T>(m_tail);
	return endingIter;
}

template<typename T>
inline void List<T>::initialize()
{
	m_nodecount = 0;
	m_head = new Node<T>();
	m_tail = new Node<T>();
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

	/// set the new node's previous to be null/nullptr
	newNode->previous = nullptr;

	/// set the head's node to have a previous equal to the new node
	m_head->previous = newNode;

	/// set the new node's next to be the head node
	newNode->next = m_head;

	/// set the new node to be the head node value
	m_head = newNode;

	//Increase the node count
	m_nodecount++;
}

template<typename T>
inline void List<T>::pushBack(const T& value)
{
	/// Make a new node containing the value of the value passed in
	Node<T>* newNode = new Node<T>(value);

	/// set the new node's next to be null/nullptr
	newNode->next = nullptr;

	/// set the new node's previous to be the tail node
	newNode->previous = m_tail;

	/// set the tail's node to have a next equal to the new node
	m_tail->next = nullptr;

	/// set the new node to be the tail node value
	m_tail = newNode;

	//Increase the node count
	m_nodecount++;
}

template<typename T>
inline bool List<T>::insert(const T& value, int index)
{
	Node<T>* newNode = new Node<T>(value);
	Node<T>* currNode = m_head;

	for (int i = 0; i < m_nodecount; i++)
	{
		//If i is equal to the number passed in...
		if (i == index)
		{
			//set the new nodes next to be the current node
			newNode->next = currNode;

			//set the new node's previous to be the current node's previous
			newNode->previous = currNode->previous;

			//set the current node's previous' next to be the new node
			currNode->previous->next = newNode;

			//set the current nodes previous to be the new node
			currNode->previous = newNode;

			//increase the node count
			m_nodecount++;

			return true;
		}

		// Set the iterators current to be the currents next
		currNode = currNode->next;
	}
	return false;
}

template<typename T>
inline bool List<T>::remove(const T& value)
{
	Node<T> currNode = m_head;

	for (int i = 0; i < m_nodecount; i++)
	{
		//If the current nodes data is equal to the value passed in...
		if (currNode.data == value)
		{
			//Set the current node's previous' next to be the current node's next
			currNode->previous->next = currNode->next;

			//set the current node's next previous to be the current node's previous
			currNode->next->previous = currNode->previous;

			//set the current current node's previous to be null
			currNode->previous = nullptr;

			//set the current node's next to be null
			currNode->next = nullptr;

			return true;
		}

		// Set the current node to be the current node's next
		currNode = currNode.next;
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

}
