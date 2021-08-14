#ifndef _Stack_H_
#define _Stack_H_

#include <stdio.h>

struct Node {
	Node* next = NULL;
	char data;
};

struct Stack {
	Node* top = NULL;
};

Node* initNode(char data);
void deleteNode(Node* node);
void connectNode(Node* nodeA, Node* nodeB);
void init(Stack& St);
bool isEmpty(Stack& St);
void clear(Stack& St);
void push(Stack& st, char data);
bool peek(Stack& stList, char& res);
bool pop(Stack& stList, char& res);

#endif