#pragma once
#include "Iterator.h";

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
	void initialize();

	bool getData(Iterator<T>& iter, int index);
	int getLength() const;
	const List<T>& operator =(const List<T>& otherlist);

	/// <summary>
	/// checks to see if the given item is in the list
	/// </summary>
	/// <param name = "object"> the object type that is being checked for </param>
	bool contains(const T object);

	void pushFront(const T& value);
	void pushBack(const T& value);

	bool insert(const T& value, int index);
	bool remove(const T& value);

	void print() const;
	bool isEmpty() const;
	void sort();


private:
	Node<T>* m_head;
	Node<T>* m_tail;
	int m_nodecount;
};


template<typename T>
inline List<T>::List()
{
}

template<typename T>
inline List<T>::List(const List<T>& other)
{
}

template<typename T>
inline List<T>::~List()
{
}

template<typename T>
inline void List<T>::destroy()
{
}

template<typename T>
inline Iterator<T> List<T>::begin() const
{
	return Iterator<T>();
}

template<typename T>
inline Iterator<T> List<T>::end() const
{
	return Iterator<T>();
}

template<typename T>
inline void List<T>::initialize()
{
}

template<typename T>
inline bool List<T>::getData(Iterator<T>& iter, int index)
{
	return false;
}

template<typename T>
inline int List<T>::getLength() const
{
	return m_nodecount;
}
