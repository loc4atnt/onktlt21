#include <stdio.h>
#include "List.h"

void btSelectionSort() {
	int data[] = { 4,6,1,4 };
	int dataCount = 4;

	List list;
	list.head = NULL;
	addArrayToList(list, data, dataCount);

	//selectionSort(....);

	printf("Danh sach sau khi sap xep: \n");
	printList(list);
}
