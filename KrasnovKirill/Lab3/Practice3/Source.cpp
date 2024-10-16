#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int stp(int k) {
	int num = 1;
	for (int i = 0; i < k; i++) {
		num = num * 10;
	}
	return num;
}

int main() {
	srand(time(NULL));
	int n, p, bull = 0, cow = 0, flag = 0;
	int a[5] = { 0, 0, 0, 0, 0 }, b[5] = { 0, 0, 0, 0, 0 };
	int A;

	do {
		printf("Input the lenght of the number (2...5): ");
		scanf_s("%d", &n);
		if (n >= 2 && n <= 5) {
			break;
		}
		else {
			printf("Uncorrect data\n");
		}
	} while (1);

	do {
		flag = 0;
		int A = rand() % stp(n);

		for (int i = 0; i < n; i++) {
			a[i] = A / stp(n - i - 1);
			A = A % stp(n - i - 1);
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i] == a[j] && i != j) {
					flag = 1;
				}
			}
		}
	} while (flag == 1);

	do {
		do {
			printf("\nInput the number (%d digits): ", n);
			scanf_s("%d", &p);
			if (stp(n - 1) < p && p < stp(n + 1)) {
				break;
			}
			else {
				printf("Uncorrect data\n");
			}
		} while (1);

		for (int i = 0; i < n; i++) {
			b[i] = p / stp(n - i - 1);
			p = p % stp(n - i - 1);
		}
		cow = 0; bull = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] == b[i]) {
				bull++;
			}
			for (int j = 0; j < n; j++) {
				if (a[i] == b[j] && a[i] != b[i]) {
					cow++;
				}
			}
		}
		if (bull == n) {
			printf("\nU guessed!\n");
			break;
		}
		printf("%d cows, %d bulls\n", cow, bull);
	} while (1);
	return 0;
}