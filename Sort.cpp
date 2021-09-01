#include "Sort.h"

INode* selectionSort(INode* head) {
	if (head==NULL || head->next == NULL) return head;

	INode* prevMinNode = NULL;
	INode* minNode = head;
	INode* prevNode = minNode;
	INode* node = minNode->next;
	while (node != NULL) {
		if (node->data < minNode->data) {
			minNode = node;
			prevMinNode = prevNode;
		}
		prevNode = node;
		node = node->next;
	}

	if (prevMinNode != NULL) {
		INode* tail = List_getTail(head);
		prevMinNode->next = NULL;
		tail->next = head;
	}

	minNode->next = selectionSort(minNode->next);
	return minNode;
}

void btSelectionSort() {
	int data[] = { 100,4,6,1,4,-12 };
	int dataCount = 6;

	List list;
	list.head = NULL;
	List_addArrayToList(list, data, dataCount);

	list.head = selectionSort(list.head);

	printf("Danh sach sau khi sap xep: \n");
	List_printList(list);
}
