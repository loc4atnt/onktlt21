#include "List.h"

void connectNode(Node *nodeA, Node *nodeB) {
	if (nodeA != NULL) nodeA->next = nodeB;
}

Node* initNode(int data) {
	Node* node = new Node;
	node->data = data;
	return node;
}

bool isEmpty(List& list) {
	return (list.head == NULL);
}

void deleteNode(Node* node) {
	delete node;
}

Node* getTail(List& list) {
	Node* tail = NULL;
	for (Node* node = list.head; node != NULL; node = node->next) tail = node;
	return tail;
}

void addDataAtTail(List &list, int data) {
	Node* node = initNode(data);
	connectNode(getTail(list), node);
}

void addArrayToList(List& list, int* data, int dataCount) {
	for (int i = 0; i < dataCount; i++) addDataAtTail(list, data[i]);
}

void printList(List& list) {
	for (Node* node = list.head; node != NULL; node = node->next) printf("%d\t", node->data);
}

void removeHead(List &list) {
	if (isEmpty(list)) return;

	Node* newHead = list.head->next;
	deleteNode(list.head);
	list.head = newHead;
}

void removeTail(List& list) {
	if (isEmpty(list)) return;

	Node* prevTailNode = NULL;
	Node* tail;
	for (tail = list.head; tail != NULL; tail = tail->next) {
		if (tail->next == NULL) break;
		prevTailNode = tail;
	}

	deleteNode(tail);
	if (prevTailNode == NULL) list.head = NULL;
	else connectNode(prevTailNode, NULL);
}

void removeAfterNode(List &list, Node *targetNode) {
	if (isEmpty(list)) return;
	if (targetNode == NULL || targetNode->next == NULL) return;

	Node* newNodeAfter = targetNode->next->next;
	deleteNode(targetNode->next);
	connectNode(targetNode, newNodeAfter);
}

void clear(List &list) { //Xoa ca danh sach
	Node* tmpNextNode;
	Node* node = list.head;
	while (node != NULL) {
		tmpNextNode = node->next;
		deleteNode(node);
		node = tmpNextNode;
	}
	list.head = NULL;
}
