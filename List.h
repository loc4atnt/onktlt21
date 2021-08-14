#ifndef _List_H_
#define _List_H_

#include <stdio.h>

struct Node {
	int data;
	Node* next = NULL;
};

struct List {
	Node* head = NULL;
};

void connectNode(Node *nodeA, Node *nodeB);
void deleteNode(Node* node);
Node* initNode(int data);
void addArrayToList(List &list, int *data, int dataCount);
void printList(List &list);
void addDataAtTail(List& list, int data);
Node* getTail(List& list);
void clear(List& list);
void removeAfterNode(List& list, Node* prevNode);
bool isEmpty(List& list);
void removeTail(List& list);
void removeHead(List& list);

#endif