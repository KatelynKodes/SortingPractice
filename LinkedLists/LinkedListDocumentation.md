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

            - Name: operator=()
            - Description: Sets the current instance of the list's head, tail and node count to be equal to the other lists head, tail and nodecount. Then returns the instance of the list.
            - Visibility: public
            - Arguments: other (const List\<T>& otherlist)

            - Name: isEmpty()
            - Description: Returns a true or false value depending on if the node count is equal to 0. True if the nodecount is equal to 0, false otherwise.
            - Visibility: public
            - Arguments: none

            - Name: contains()
            - Description: Iterates through the list using an iterator and if the iterator is pointing to the value of the object passed into the method, returns true. Returns false if the whole list is iterated through
            - Visibility: public
            - Arguments: object (const T)

            - Name: pushFront()
            - Description: Adds a new node to the front of the list. After reating a new node with the value passed into the method if the head and tail are null, sets the head and tail to be pointing to the new node. Otherwise, the head node's previous is set to the new node, the new node's next points to the head node, and the head begins pointing to the new node. Then the node count increments by 1. 
            - Visibility: public
            - Arguments: value (const T&)

            - Name: pushBack()
            - Description: Adds a new node to the back of the list. After reating a new node with the value passed into the method if the head and tail are null, sets the head and tail to be pointing to the new node. Otherwise, the tail node's next is set to the new node, the new node's previous points to the tail node, and the tail begins pointing to the new node. Then the node count increments by 1. 
            - Visibility: public
            - Arguments: value (const T&)

            - Name: Insert()
            - Description: Inserts a node with a given value to a given index, if the list is empty the pushfront method is called using the value passed into the insert method. If not, the insert function checks if the index passed into it is equal to zero, if it is the pushfront method is called using the value passed into the insert method and returns true. It then checks if the index is equal to the node count, if so the pushBack method is called using the value passed into the insert method and returns true. If none of those conditions are met a new node is created with the value passed into the insert method and while the current node is not null pointer, the list keeps going to the next node until it reaches the index passed into the insert method. Here, it sets the new node's next to be the current node, the new node's previous to be the current node's previous, the new node's previous next to be the newNode and the current node's previous to be the new node. 
            - Visibility: public
            - Arguments: value (const T& value), index (int)

            - Name: remove()
            - Description: If the list is not empty, while the current node is not a null pointer, checks if the current node's data is equal to the value passed into the method. If true, there is a check to see if the current node is the head, if so the current node's next is set to be the head. If else, the current node's previous next is equal to the current node's next. Then, the current node is checked to see if it's the tail, if it's the tail the tail is set to be the current node's previous. Otherwise, the current node's next previous is equal to the current node's previous. The node is then deleted, the node count decrements by 1, and the method returns true. Failure to find the value will result in the method returning false.
            - Visibility: public
            - Arguments: value (const T&)

            - Name: print()
            - Description: Iterates through the list using an iterator and prints the value of the node the iterator is pointing at to the console.
            - Visibility: public
            - Arguments: none

            - Name: sort()
            - Description: If the list isn't empty, a new node is made called tempNode and the current node is set to be a null pointer. The loop is iterated through once to set the current node to equal the head, then a second time to check compare the values against each other and set the current node to the current node's next. If the current node's data is greater than the current node's next data, the temp node's data is set to the the current nodes data. Then the current node's data is set to the current node's next data, and then the current node's next data is set to the temp node data.
            - Visibility: public
            - Arguments: none

            - Name: m_head
            - Description: A pointer pointing to a node that is at the front of the list, the first node in the list
            - Visibility: private

            - Name: m_tail
            - Description: A pointer pointing to a node that is at the back of the list, the last node in the list
            - Visibility: private

            - Name: m_nodecount
            - Description: the amount of nodes inside of the list, represents the length of the list.
            - Visibility: private
            