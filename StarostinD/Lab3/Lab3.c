#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	srand(time(NULL));
	int n;
	printf("Enter the length of the number (from 2 to 5): ");
	scanf_s("%d", &n);
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
		int t;
		while ((t = getchar()) != '\n' && t != EOF);
		char guess;
		int cb[2] = { 0 }; // cb[0] - cows cb[1] - bulls
		printf("Try to guess the number: ");
		for (int i = 0; i < n; ++i) {
			guess = getchar();
			guess -= '0';
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
		else {
			printf("cows: %d\nbulls: %d\n", cb[0], cb[1]);
			printf("-------------------------------\n");
		}
	}
	return 0;
}