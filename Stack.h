#ifndef _Stack_H_
#define _Stack_H_

#include <stdio.h>

struct CNode {
	CNode* next = NULL;
	char data;
};

struct Stack {
	CNode* top = NULL;
};

CNode* Stack_initNode(char data);//khoi tao node
void Stack_deleteNode(CNode* node);
void Stack_connectNode(CNode* nodeA, CNode* nodeB);
void Stack_init(Stack& St);
bool Stack_isEmpty(Stack& St);
void Stack_clear(Stack& St);
void Stack_push(Stack& st, char data);//lay du lieu ra
bool Stack_peek(Stack& stList, char& res);
bool Stack_pop(Stack& stList, char& res);

#endif