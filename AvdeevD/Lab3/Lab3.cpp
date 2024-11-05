#include <stdio.h>
#include <time.h>
#include <stdlib.h>
enum BOOLEAN {
	False,
	True
};

int countofn() {
	int n;
	printf("Choose the length of a number from 2 to 5:");
	scanf_s("%d", &n);
	return n;
}

void main()
{
	srand(time(NULL));
	int n1, n2 = 1;
	enum BOOLEAN rep = False;
	int fullnum[5] = {-1, -1, -1, -1, -1};
	fullnum[0] = rand() % 9 + 1;
	int n = countofn();
	do {
		rep = False;
		n1 = rand() % 10;
		for (int i = 0; i < 5; i++) {
			if (n1 == fullnum[i]) {
				rep = True;
			}
		}
		if (not(rep)) {
			fullnum[n2] = n1;
			n2++;
		}
	} while (n2 < n);

	/*for (int i = 0; i < n2; i++) { //для проверки числа и тестов
		printf("%d", fullnum[i]);
	}
	printf("\n");*/

	int bulls, cows, ci, count = 0;
	char c;
	printf("You're playing a game called 'bulls and cows'. The number is already made.\n");
	printf("Try to guess it (all digits are different).");
	while (1) {
		count = 0;
		bulls = 0;
		cows = 0;
		printf("Take a guess: ");
		while ((c = getchar()) != '\n') {
			ci = int(c) - 48;
			for (int i = 0; i < n2; i++) {
				if (ci == fullnum[i]) {
					if (count == i) {
						bulls++;
					}
					else {
						cows++;
					}
				}
			}
			count++;
		}
		if (bulls == n2) {
			printf("Congratulations! You won!");
			break;
		}
		else {
			printf("Number of cows: %d, number of bulls: %d.\n", cows, bulls);
		}
	}
}