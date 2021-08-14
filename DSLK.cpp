#include <stdio.h>
#include "List.h"

void btDanhSachLK() {
	int data[] = {4,6,1,4};
	int dataCount = 4;

	List list;
	list.head = NULL;
	addArrayToList(list, data, dataCount);

	//makeOdd(list);

	printf("Danh sach sau ham makeOdd: \n");
	printList(list);
}
