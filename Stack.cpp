#include "Stack.h"

CNode* Stack_initNode(char data) {
    CNode* node = new CNode;
	node->data = data;
	return node;
}

void Stack_deleteNode(CNode* node) {
	delete node;
}

void Stack_connectNode(CNode* nodeA, CNode* nodeB) {
	if (nodeA == NULL) return;
	nodeA->next = nodeB;
}

void Stack_init(Stack& st) {
	st.top = NULL;
}

bool Stack_isEmpty(Stack& st) {
	return (st.top == NULL);
}

void Stack_clear(Stack& st) {
    char tmp;
    while (Stack_pop(st, tmp)) {};
}

void Stack_push(Stack& st, char data) {
    CNode* node = Stack_initNode(data);
    Stack_connectNode(node, st.top);
    st.top = node;
}

bool Stack_peek(Stack& stList, char& res) {
    if (Stack_isEmpty(stList)) return false;
    res = stList.top->data;
    return true;
}

bool Stack_pop(Stack& stList, char& res) {
    if (!Stack_peek(stList, res)) return false;
    CNode* newTopNode = stList.top->next;
    Stack_deleteNode(stList.top);
    stList.top = newTopNode;
    return true;
}