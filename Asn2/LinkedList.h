#ifndef __LinkedList__
#define __LinkedList__
#include <iostream>
#include "Node.h"

template <class T>
class LinkedList {
	Node<T>* Temp;

public:
	Node<T>* Head;

	LinkedList() : Head(NULL), Temp(NULL) {}
	~LinkedList() { std::cout << "Deleting LinkedList\n"; }

	void Insert(T data) {
		if (Head == NULL) {
			Node<T>* FirstNode = new Node<T>;
			FirstNode->data = data;
			FirstNode->next = NULL;
			Head = FirstNode;
			Temp = FirstNode;
		}
		else {
			Node<T>* NewNode = new Node<T>;
			NewNode->data = data;
			NewNode->next = NULL;
			Temp->next = NewNode;
			Temp = NewNode;
		}
	}

	void Delete() {
		Node<T>* CopyHead = Head;

		while (CopyHead->next != NULL) {
			Temp = CopyHead;
			CopyHead = CopyHead->next;
			if (CopyHead->next == NULL) {
				delete CopyHead;
				Temp->next = NULL;
				break;
			}
		}
	}
	
	T Get(int position) {
		int index = 1;
		Node<T>* CopyHead = Head;
		while (index < position) {
			CopyHead = CopyHead->next;
			index++;
		}
		return CopyHead->data;
	}

	void Print() {
		Node<T>* CopyHead = Head;
		while (CopyHead->next != NULL) {
			std::cout << CopyHead->data << "\n";
			CopyHead = CopyHead->next;
			if (CopyHead->next == NULL) { std::cout << CopyHead->data << "\n"; }
		}
	}
	
};

#endif