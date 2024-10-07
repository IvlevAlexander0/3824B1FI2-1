#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int main() {

	int n, mode, guess, scz;
	scz = 0;

	printf("Enter the program's mode (1 - you guess the program's number; 2 - program guesses your number)\n");
	scanf_s("%d", &mode);

	if (mode == 1)
	{
		srand(time(NULL));
		n = 1 + rand() % 1000;

		do {
			printf("Try to guess program's number entering the number from 1 to 1000\n");
			scanf_s("%d", &guess);
		} while (guess<1 || guess>1000);

		while (guess != n) {

			if (guess > n) {
				printf("Your number is too large. ");
			}

			else {
				printf("You number is too small. ");
			}

			do {
				printf("Try to guess program's number entering the number from 1 to 1000\n");
				scanf_s("%d", &guess);
			} while (guess < 1 || guess>1000);
			scz++;
		}
		printf("You've guessed! Program's number is %d\n", guess);
		printf("It have taken only %d attempts\n", scz + 1);
	}

	else if (mode == 2) {

		char odp[2], eq[] = "=", mo[] = ">", le[] = "<";
		int lim1, lim2;

		lim1 = 1;
		lim2 = 1000;

		guess = 0;

		do {
			printf("Enter your number(from 1 to 1000) and the program will try to guess it\n");
			scanf_s("%d", &n);
		} while (n < 1 || n>1000);

		while (1) {
			fgets(odp, sizeof(odp), stdin);
			if (strcmp(odp, mo) == 0) {
				lim1 = guess;
				continue;
			}

			else if (strcmp(odp, le) == 0) {
				lim2 = guess;
				continue;
			}

			else if (strcmp(odp, eq) == 0 && guess == n) {
				printf("The program has guessed\n");
				break;
			}

			scz++;
			guess = (lim2 - lim1) / 2 + lim1;

			printf("n = %d is it correct?(enter > or = or <)\n", guess);
		}

		printf("Your number is %d\n", guess);
		printf("It have taken only %d attempts for the program\n", scz);
	}
	return 0;
}