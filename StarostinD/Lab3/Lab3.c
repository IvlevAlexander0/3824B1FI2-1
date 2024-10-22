#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	srand(time(NULL));
	int n;
	printf("Enter the length of the number (from 2 to 5): ");
	while(1) {
		char c = 0;
		c = scanf_s("%d", &n);
		if (c != 1 || n < 2 || n > 5) {
			while ((c = getchar()) != '\n');
			printf("Error! Try again.\n");
		}
		else {
			break;
		}
	}
	char c;
	while ((c = getchar()) != '\n');
	printf("________________________________________________\n");
	int num[5] = { -1, -1, -1, -1, -1 };
	int was[10] = { 0 };
	for (int i = 0; i < n; ++i) {
		while (num[i] == -1 || num[0] == 0) {
			int digit = rand() % 10;
			if (!was[digit]) {
				num[i] = digit;
				++was[digit];
			}
		}
	}
	while (1) {
		int flag = 1;
		char guess, asd;
		int check[10] = { 0 };
		int cb[2] = { 0 }; // cb[0] - cows cb[1] - bulls
		printf("Try to guess the number: ");
		for (int i = 0; i < n; ++i) {
			guess = getchar();
			if (check[guess - '0'] || guess < '0' || guess > '9') {
				while ((asd = getchar()) != '\n');
				printf("Incorrect number, try again.\n");
				for (size_t j = 0; j < 10; ++j) {
					check[j] = 0;
				}
				flag = 0;
				break;
			}
			guess -= '0';
			++check[guess];
			if (was[guess]) {
				if (guess == num[i]) {
					++cb[1];
				}
				else {
					++cb[0];
				}
			}
		}
		if (cb[1] == n) {
			printf("You win!\n");
			printf("________________________________");
			break;
		}
		else  if (flag){
			while ((asd = getchar()) != '\n') {
				if (asd - '0' >= 0 && asd - '0' <= 9) {
					printf("Incorrect number, try again.\n");
					flag = 0;
				}
			}
			if(flag) {
				printf("cows: %d\nbulls: %d\n", cb[0], cb[1]);
				printf("-------------------------------\n");
			}
		}
	}
	return 0;
}