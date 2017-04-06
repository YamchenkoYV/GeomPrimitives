#ifndef MYLISTS_HPP
#define MYLISTS_HPP

/*The lists classes*/

#include "GeomBody.hpp"
#include <iostream>

//The node of MyList
class Node {
public:
	Node(GeomBody* e) : _element(e) {}
	~Node() { delete _element; }

	Node* _prev = NULL;
	Node* _next = NULL;
	GeomBody* _element;
};

class MyList {
public:
	MyList() {
		head = NULL;
		size = 0;
	}

	~MyList()
	{
		Node* temp;
		while (head != NULL) {
			temp = head;
			head = head->_next;
			delete temp;
		}
	}

	//Add the geometric primitive to the end of my list
	void push_back(GeomBody* elem) {
		Node* curNode = head;
		Node* newNode = new Node(elem);
		
		if (head == NULL)
		{
			head = newNode;
			size++;
			return;
		}

		while (curNode->_next != NULL)
			curNode = curNode->_next;

		newNode->_prev = curNode;
		curNode->_next = newNode;
		size++;
	}

	//Print the information about every primitive in the list
	void PrintGBodiesStates() {
		int counter = 1;
		Node* temp = head;
		
		std::cout << "List contains " << size << " primitives." << std::endl;
		while (temp != NULL) {
			std::cout << counter++ << ". ";
			temp->_element->PrintState();
			temp = temp->_next;
		}
	}

	//Get the list size
	unsigned int GetSize() { return size; }

protected:
	Node* head;
	unsigned int size;
};

//The list derived of myList
class MyDerivedList : public MyList {
public:
	//Add the copies of the geometric primitive after every m elements
	bool addMultiCopies(GeomBody* newGB, int m) {
		if (m < 1) {
			std::cout << "Error while adding multiple copies: parameter value should be more than 1" << std::endl;
			return false;
		}else if (size == 0) {
			std::cout << "Error while adding multiple copies: list is empty." << std::endl;
			return false;
		}
		else if (m > size) {
			std::cout << "Error while adding multiple copies: parameter value is bigger than list size(" << size << ")." << std::endl;
			return false;
		}

		int i = 1;
		for (Node* node = head; node != NULL ; i++) {
			if ((i % m) == 0)
				node = addNodeAfter(node, new Node(newGB->MakeCopy()));
			else
				node = node->_next;
		}
		delete newGB;
		return true;
	}

private:
	//The method to insert newNode after curNode to the list 
	//Returns the next node
	Node* addNodeAfter(Node* curNode, Node* newNode) {
		newNode->_prev = curNode;
		newNode->_next = curNode->_next;
		curNode->_next = newNode;
		size++;
		return newNode->_next;
	}
};

#endif// MYLISTS_HPP