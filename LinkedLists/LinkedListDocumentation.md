|Katelyn West|
| :---          	|
| S218002   |
|Code Design and Data Structures|
|   Linked Lists Test Application|

## I. Requirements

1. **Description of problem**

    - **Name**: Implement a Double-Linked List 
    - **Problem Statement**: Successful creation of a project which implements and demonstrates a double-
linked list 
    - **Problem specifications**:
        - The program must demonstrate a custom sorting algorithm

2. **Input Information**
3. **Output Information**
4. **User-Interface Information**

## II. Design

1. _System Architecture_

2. _Object Information_
    - **Filename**: Node.h
        - **Class Name**: Node
            - Name: Node()
            - Description: The base constructor of a node, sets the data inside the node to be an empty type
            - Visibility: public
            - Arguments: none

            - Name: Node()
            - Description: Override constructor for the node class, set the value of the node to be the value passed into the constructor
            - Visibility: public
            - Arguments: value (T)

            - Name: next
            - Description: A pointer pointing to a node that is next to this node, the next node in the list.
            - Visibility: public

            - Name: previous
            - Description: A pointer pointing to a node that is behind this node, the previous node in the list
            - Visibility: public

            - Name: data
            - Description: The value holding the current data of the node.
            - Visibility: public
    - **Filename**: Iterator.h
        - **Class Name**: Iterator
            - Name: Iterator()
            - Description: Base constructor for the iterator, sets the current node to be equal to an empty node.
            - Visibility: public
            - Arguments: none

            - Name: Iterator 
            - Description: Constructor override for the base constructor, sets the current to be equal to the node passed into the constructor
            - Visibility: public
            - Arguments: node (Node\<T>*)

            - Name: operator++()
            - Description: sets the current node to be the current node's next and returns the current node.
            - Visibility: public
            - Arguments: none

            - Name: operator--()
            - Description: sets the current node to the current node's previous, returns the current node.
            - Visibility: public
            - Arguments: none

            - Name: operator*()
            - Description: Returns the current node's data.
            - Visibility: public
            - Arguments: none

            - Name: operator==()
            - Description: Returns a true or false boolean if the current node of this iterator is equal to the current node of the iterator refrence passed into the operator.
            - Visibility: public
            - Arguments: iter (const Iterator\<T>&)

            - Name: operator!=()
            - Description: Returns a true or false boolean if the current node of this iterator is not equal to the current node of the iterator refrence passed into the operator.
            - Visibility: public
            - Arguments: iter (const Iterator\<T>&)

            - Name: m_current
            - Description: The current node this iterator is pointing to.
            - Visibility: private
    - **Filename**: List.h
        - **Class Name**: List
            - Name: List()
            - Description: Base constructor of the list class, calls the initialize method
            - Visibility: public
            - Arguments: List(const List\<T>& other)

            - Name: ~List()
            - Description: The destructor for the List class, calls the destroy method.
            - Visibility: public
            - Arguments: none

            - Name: destroy()
            - Description: While the list is not empty, call the remove function while passing the heads data into the remove method, continously removes the head until the list is empty.
            - Visibility: public
            - Arguments: none

            - Name: begin()
            - Description: Returns an iterator that is pointing to the head node of the list.
            - Visibility: public
            - Arguments: none

            - Name: end()
            - Description: Returns an iterator that is pointing to the tail node of the list.
            - Visibility: public
            - Arguments: none

            - Name: Initialize()
            - Description: Sets the node count to zero and sets the head and tail node in the list to be a null pointer.
            - Visibility: public
            - Arguments: none

            - Name: getData
            - Description: Sets the iterator passed into the method to be pointing to a node at the index of the integer passed into the method
            - Visibility: public
            - Arguments: iter (const Iterator\<T>&), index (int)

            - Name: getLength
            - Description: returns the node count of the list
            - Visibility: public
            - Arguments: none

            - Name: 
            - Description: 
            - Visibility: 
            - Arguments:

            - Name: 
            - Description: 
            - Visibility: 
            - Arguments:

            - Name: 
            - Description: 
            - Visibility: 
            - Arguments:
            