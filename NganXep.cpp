#include "NganXep.h"

// tra ve 0 neu ky tu loi, tra ve 1 neu ky tu mo ngoac
// tra ve 2 neu ky tu dong ngoac
int getType(char chr) {
	switch (chr) {
	case '(':
	case '[':
	case '{':
		return 1;

	case ')':
	case ']':
	case '}':
		return 2;
	}
	return 0;
}

//chr1 phai la mo ngoac, chr2 dong ngoac
bool isSameType(char chr1, char chr2) {
	if (chr1 == '(' && chr2 == ')') return true;
	if (chr1 == '{' && chr2 == '}') return true;
	if (chr1 == '[' && chr2 == ']') return true;
	return false;
}

bool checkBracketPairs(char* str) {
	Stack st;
	Stack_init(st);

	int len = strlen(str);
	int type;
	char tmpData;
	for (int i = 0; i < len; i++) {
		type = getType(str[i]);
		if (type == 0) return false;

		if (type == 1) {// mo ngoac
			Stack_push(st, str[i]);
		}
		else {//dong ngoac
			if (!Stack_pop(st, tmpData)) return false;
			if (!isSameType(tmpData, str[i])) return false;
		}
	}

	if (Stack_isEmpty(st)) return true;
	return false;
}

void btNganXep() {
	char str[200];

	printf("Nhap chuoi: ");
	gets_s(str, 200);

	bool isValid = checkBracketPairs(str);

	if (isValid) printf("Chuoi vua nhap hop le!");
	else printf("Chuoi vua nhap khong hop le!");
}
