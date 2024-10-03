#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
	int n, mode, guess, lim1, lim2, scz, flg = 1;
	char odp[2], eq[] = "=", mo[] = ">", le[] = "<";
	scz = 0;
	lim1 = 1;
	lim2 = 1000;

	printf("Enter the program's mode (1 - you guess the program's number; 2 - program guesses your number)\n");
	scanf_s("%d", &mode);

	if(mode == 1)
	{
		n = 1 + rand() % 1000;
		printf("Try to guess program's number\n");
		scanf_s("%d", &guess);

		while (guess != n) {

			if (guess > n) {
				printf("Your number is too large. Try again.\n");
			}

			else {
				printf("You number is too small. Try again.\n");
			}

			scanf_s("%d", &guess);
			scz++;
		}
		printf("You've guessed! n = %d\n", guess);
		printf("It have taken only %d attempts\n", scz+1);
	}

	else if (mode == 2) {

		guess = 0;
		printf("Enter your number and the program will try to guess it\n");
		scanf_s("%d",&n);

		while (flg) {
			fgets(odp, sizeof(odp), stdin);
			if (strcmp(odp,mo)==0) {
				lim1 = guess;
				continue;
			}

			else if (strcmp(odp,le)==0) {
				lim2 = guess;
				continue;
			}

			else if (strcmp(odp,eq)==0 && guess == n) {
				printf("The program have guessed\n");
				flg = 0;
				break;
			}

			scz++;
			guess = (lim2 - lim1) / 2 + lim1;
			
			printf("n = %d is it correct?(enter > or = or <)\n", guess);
			
		}

		printf("Your number is %d\n",guess);
		printf("It have taken only %d attempts for the program\n", scz);
	}
	return 0;
}