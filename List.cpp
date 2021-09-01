#include "List.h"

void List_connectNode(INode*nodeA, INode*nodeB) {
	if (nodeA != NULL) nodeA->next = nodeB;
}

INode* List_initNode(int data) {
	INode* node = new INode;
	node->data = data;
	return node;
}

bool List_isEmpty(List& list) {
	return (list.head == NULL);
}

void List_deleteNode(INode* node) {
	delete node;
}

INode* List_getTail(List& list) {
	return List_getTail(list.head);
}

INode* List_getTail(INode* head) {
	INode* tail = NULL;
	for (INode* node = head; node != NULL; node = node->next) tail = node;
	return tail;
}

void List_addDataAtTail(List &list, int data) {
	INode* node = List_initNode(data);
	INode* tail = List_getTail(list);
	if (tail == NULL) list.head = node;
	else List_connectNode(tail, node);
}

void List_addArrayToList(List& list, int* data, int dataCount) {
	for (int i = 0; i < dataCount; i++) List_addDataAtTail(list, data[i]);
}

void List_printList(List& list) {
	for (INode* node = list.head; node != NULL; node = node->next) printf("%d\t", node->data);
}

void List_removeHead(List &list) {
	if (List_isEmpty(list)) return;

	INode* newHead = list.head->next;
	List_deleteNode(list.head);
	list.head = newHead;
}

INode* List_addDataAfterNode(INode* prevNode, int data) {
	INode* node = List_initNode(data);
	List_connectNode(prevNode, node);
	return node;
}

void List_removeTail(List& list) {
	if (List_isEmpty(list)) return;

	INode* prevTailNode = NULL;
	INode* tail;
	for (tail = list.head; tail != NULL; tail = tail->next) {
		if (tail->next == NULL) break;
		prevTailNode = tail;
	}

	List_deleteNode(tail);
	if (prevTailNode == NULL) list.head = NULL;
	else List_connectNode(prevTailNode, NULL);
}

void List_removeAfterNode(List &list, INode*targetNode) {
	if (List_isEmpty(list)) return;
	if (targetNode == NULL || targetNode->next == NULL) return;

	INode* newNodeAfter = targetNode->next->next;
	List_deleteNode(targetNode->next);
	List_connectNode(targetNode, newNodeAfter);
}

void List_clear(List &list) { //Xoa ca danh sach
	INode* tmpNextNode;
	INode* node = list.head;
	while (node != NULL) {
		tmpNextNode = node->next;
		List_deleteNode(node);
		node = tmpNextNode;
	}
	list.head = NULL;
}
