#include "ConTro.h"

void btConTroNangCaoA() {
	int n;
	int* array = NULL;

	printf("Nhap n: ");
	scanf_s("%d", &n);

	array = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		printf("Nhap phan tu thu %d: ", i + 1);
		scanf_s("%d", &array[i]);
	}

	for (int i = 0; i < n; i++) {
		printf("%d\t", array[i]);
	}

	free(array);
}

void btConTroNangCaoB() {
	int** matrix = NULL;
	int m = 0, n = 0;

	printf("Nhap M, N: ");
	scanf_s("%d %d", &m, &n);

	matrix = (int**)malloc(sizeof(int*) * m);
	for (int r = 0; r < m; r++) matrix[r] = (int*)malloc(sizeof(int) * n);

	for (int r = 0; r < m; r++) {
		printf("Nhap hang thu %d\n", r + 1);
		for (int c = 0; c < n; c++) {
			printf("\tCot thu %d: ", c + 1);
			scanf_s("%d", &matrix[r][c]);
		}
	}

	for (int r = 0; r < m; r++) {
		printf("Hang thu %d: ", r + 1);
		for (int c = 0; c < n; c++) {
			printf("%d\t", matrix[r][c]);
		}
		printf("\n");
	}

	for (int r = 0; r < m; r++) free(matrix[r]);
	free(matrix);
}

void btConTroNangCaoC() {
	char** strArray = NULL;
	int n;
	int len;

	printf("Nhap N: ");
	scanf_s("%d", &n);

	strArray = (char**)malloc(sizeof(char*) * n);

	for (int i = 0; i < n; i++) {
		printf("Nhap do dai chuoi thu %d: ",i+1);
		scanf_s("%d", &len);
		strArray[i] = (char*)malloc(len + 1);
		printf("Nhap chuoi thu %d: ", i + 1);
		scanf_s("%*c");
		gets_s(strArray[i], len + 1);
	}

	for (int i = 0; i < n; i++) {
		printf("Chuoi thu %d: %s\n", i + 1, strArray[i]);
	}

	for (int i = 0; i < n; i++) {
		free(strArray[i]);
	}
	free(strArray);
}

void btConTroNangCao() {
	//btConTroNangCaoA();
	//btConTroNangCaoB();
	//btConTroNangCaoC();
}