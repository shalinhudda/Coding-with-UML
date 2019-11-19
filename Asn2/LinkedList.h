#ifndef __LinkedList__
#define __LinkedList__
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>


using namespace std;

struct Data {
	int PartNumber = 0;
	int Quantity = 0;
	double Cost = 0;
	std::string Message;
};


class Node {

public:
	Node* next;
	Data data;
};


class LinkedList {
	Node* Temp;

public:
	Node* Head;

	LinkedList() : Head(NULL), Temp(NULL) {}
	~LinkedList() { std::cout << "Deleting LinkedList\n"; }

	void Insert(Data data) {
		if (Head == NULL) {
			Node* FirstNode = new Node;
			FirstNode->data = data;
			FirstNode->next = NULL;
			Head = FirstNode;
			Temp = FirstNode;
		}
		else {
			Node* NewNode = new Node;
			NewNode->data = data;
			NewNode->next = NULL;
			Temp->next = NewNode;
			Temp = NewNode;
		}
	}

	void Delete() {
		Node* CopyHead = Head;

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

	void Print() {
		Node* CopyHead = Head;
		while (CopyHead->next != NULL) {
			printf("%s", CopyHead->data);
			CopyHead = CopyHead->next;
			if (CopyHead->next == NULL) { printf("%s", CopyHead->data); }
		}
	}
	
};

#endif