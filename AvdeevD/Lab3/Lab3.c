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
	while (n > 5 || n < 2) {
		printf("\nYou've input incorrect number. Try again: ");
		scanf_s("%d", &n);
	}
	return n;
}

void main()
{
	srand(time(NULL));
	int n1, n2 = 1;
	enum BOOLEAN rep = False, povt = False;
	int count1 = 1;
	int fullnum[5] = { -1, -1, -1, -1, -1 };
	fullnum[0] = rand() % 9 + 1;
	int n = countofn();
	do{
		do {
			rep = False;
			n1 = rand() % 10;
			for (int i = 0; i < n; i++) {
				if (n1 == fullnum[i]) {
					rep = True;
				}
			}
			if (rep == False) {
				fullnum[n2] = n1;
				n2++;
			}
		} while (n2 < n);





		/*for (int i = 0; i < n2; i++) { //для проверки числа и тестов
			printf("%d", fullnum[i]);
		}
		printf("\n");*/
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				if (fullnum[i] == fullnum[j]) {
					printf("Digits repeat.");
					povt = True;//проверка на повторение цифр
					break;
				}
			}
			count1++;
		}
		if (count1 == n) {
			printf("Number of digits is right.\n"); //проверка на количество цифр
		}
	} while (count1 != n && povt == True);
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
			ci = (int)(c)-48;
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
			printf("Congratulations! You won!\n");
			break;
		}
		else {
			printf("Number of cows: %d, number of bulls: %d.\n", cows, bulls);
		}
	}
}