#ifndef _List_H_
#define _List_H_

#include <stdio.h>

struct INode {
	int data;
	INode* next = NULL;
};

struct List {
	INode* head = NULL;
};

void List_connectNode(INode*nodeA, INode*nodeB);
void List_deleteNode(INode* node);
INode* List_initNode(int data);
void List_addArrayToList(List &list, int *data, int dataCount);
void List_printList(List &list);
void List_addDataAtTail(List& list, int data);
INode* List_getTail(List& list);
INode* List_getTail(INode*head);
void List_clear(List& list);
void List_removeAfterNode(List& list, INode* prevNode);
bool List_isEmpty(List& list);
void List_removeTail(List& list);
void List_removeHead(List& list);
INode* List_addDataAfterNode(INode* prevNode, int data);

#endif