#include "Stack.h"

Node* initNode(char data) {
	Node* node = new Node;
	node->data = data;
	return node;
}

void deleteNode(Node* node) {
	delete node;
}

void connectNode(Node* nodeA, Node* nodeB) {
	if (nodeA == NULL) return;
	nodeA->next = nodeB;
}

void init(Stack& st) {
	st.top = NULL;
}

bool isEmpty(Stack& st) {
	return (st.top == NULL);
}

void clear(Stack& st) {
    char tmp;
    while (pop(st, tmp)) {};
}

void push(Stack& st, char data) {
    Node* node = initNode(data);
    connectNode(node, st.top);
    st.top = node;
}

bool peek(Stack& stList, char& res) {
    if (isEmpty(stList)) return false;
    res = stList.top->data;
    return true;
}

bool pop(Stack& stList, char& res) {
    if (!peek(stList, res)) return false;
    Node* newTopNode = stList.top->next;
    deleteNode(stList.top);
    stList.top = newTopNode;
    return true;
}