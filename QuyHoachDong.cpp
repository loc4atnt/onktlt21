#include "QuyHoachDong.h"

int sumOfRow(int n, int** T, int m) {
	int sum = 0;
	for (int i = 0; i < m; i++) sum += T[n - 1][i];
	return sum;
}

void topDown(int n, int** T, int *a, int m) {
	int sum = sumOfRow(n, T, m);
	if (sum >= 0) return;

	// truong hop co ban
	for (int i = 0; i < m; i++) {
		if (a[i] == n) {
			for (int j = 0; j < m; j++) T[n - 1][j] = 0;
			T[n - 1][i] = 1;
			return;// return truong hop co ban.
		}
	}

	// truong hop khong co ban
	int minSum = n + 1;
	int toiUu = -1;
	for (int i = 0; i < m; i++) {
		if (n < a[i]) break;
		topDown(n - a[i], T, a, m);
		sum = sumOfRow(n - a[i], T, m);
		if (sum > 0 && sum < minSum) {
			minSum = sum;
			toiUu = i;
		}
	}

	for (int i = 0; i < m; i++) T[n - 1][i] = 0;
	if (toiUu > -1) {
		T[n - 1][toiUu] += 1;
		for (int i = 0; i < m; i++) T[n - 1][i] += T[n - a[toiUu] - 1][i];
	}
}

void btQuyHoachDong() {
	int a[] = {2,3,5};
	int m = 3;
	int n = 11;

	int** T = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++) {
		T[i] = (int*)malloc(sizeof(int) * m);
		for (int j = 0; j < m; j++) T[i][j] = -1;//-1 chua giai
	}

	topDown(n, T, a, m);

	// lay ket qua tu bang tra T roi in ra man hinh
	if (sumOfRow(n, T, m) == 0) {
		printf("Khong co dap an cho n = %d\n", n);
	}
	else {
		printf("Dap an cho n = %d\n", n);
		printf("Loai xu: ");
		for (int i = 0; i < m; i++) {
			printf("%d\t", a[i]);
		}
		printf("\n");
		printf("So xu  : ");
		for (int i = 0; i < m; i++) {
			printf("%d\t", T[n - 1][i]);
		}
	}
}
