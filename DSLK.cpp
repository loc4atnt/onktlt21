#include "DSLK.h"

void makeOdd(List& list) {
    // tach so chan
    int newData1;
    int newData2;
    INode* newNode1;
    INode* newNode2;
    INode* prevNode = NULL;
    INode* nextNode;
    INode* node = list.head;
    while (node != NULL) {
        nextNode = node->next;
        if (node->data % 2 == 0) {
            newData1 = node->data / 2;

            if (prevNode != NULL) List_removeAfterNode(list, prevNode);
            else List_removeHead(list);

            if (newData1 % 2 != 0)
            {
                newData2 = newData1;
            }
            else {
                newData1 = newData1-1;
                newData2 = newData1+2;
            }

            newNode1 = List_initNode(newData1);
            newNode2 = List_initNode(newData2);
            List_connectNode(newNode2, nextNode);
            List_connectNode(newNode1, newNode2);
            if (prevNode != NULL) List_connectNode(prevNode, newNode1);
            else list.head = newNode1;

            prevNode = newNode2;
            node = nextNode;
        }
        else {
            prevNode = node;
            node = nextNode;
        }
    }

    // loai node trung nhau lien tiep
    int lastData = -1;
    prevNode = NULL;
    nextNode;
    node = list.head;
    while (node != NULL) {
        nextNode = node->next;
        if (node->data == lastData) {
            List_removeAfterNode(list, prevNode);
            node = nextNode;
        }
        else {
            lastData = node->data;
            prevNode = node;
            node = nextNode;
        }
    }
}

void btDanhSachLK() {
	int data[] = {1,4,6,1,4,3};
	int dataCount = 6;

	List list;
	list.head = NULL;
	List_addArrayToList(list, data, dataCount);

	makeOdd(list);

	printf("Danh sach sau ham makeOdd:\n");
	List_printList(list);

    List_clear(list);
}
