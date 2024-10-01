#include <stdio.h>>
#include <stdlib.h>
#include <time.h>

int main() {
	srand(time(NULL));
	int mod, num, count = 0, a, dlim = 1, ulim = 1000, flag = 1, flag_flag = 1;
	char ans;
	// _mod
	do { 
		printf("Choose the game mod (1 - you guess the number, 2 - the computer guesses the number): ");
		scanf_s("%d", &mod);
		flag = (mod != 1) && (mod != 2) && (mod != 3);
		if (flag) {
			printf("Uncorrect data\n");
		}
	} while (flag); // mod_

	switch (mod)
	{
	case 1:
		num = rand() % 1000;

		do {
			flag = 1; // _a
			do {
				printf("Guess the number (1 ... 1000): ");
				scanf_s("%d", &a);
				flag = a < 1 || a > 1000;
				if (flag) {
					printf("Uncorrect data\n");
				}
			} while (flag); // a_

			if (flag_flag) {
				printf("Wrong, ");
				if (num > a) { printf("Over\n"); }
				if (num < a) { printf("Less\n"); }
				count++;
			}
		} while (flag_flag);
		
		count++;
		printf("Congratilations! You finally guessed\n");
		printf("Amount of tries = %d", count);
		return 0;
		break;
	case 2:
		flag = 1; // _num
		do {
			printf("Input your number (1 ... 1000)\n");
			scanf_s("%d", &num);
			flag = (num < 1) || (num > 1000);
			if (flag) {
				printf("Uncorrect data\n");
			}
		} while (flag); // num_

		do {
			a = rand() % 1000;
			printf("The number is %d?\n", a);
			
			flag = 1; // _ans
			do {
				printf("Input the your answer (<, >, =): ");
				scanf_s("%c", &ans);
				flag = (ans != '>' || ans != '<' || ans != '=');
				if (flag) {
					printf("Uncorrect data\n");
				}
			} while (flag); // ans_

			if (ans == '>') {
				dlim = a + 1;
				a = dlim + rand() % (ulim - dlim + 1);
				count++;
				printf("The number is %d?\n", a);
			}
			if(ans == '<') {
				ulim = a - 1;
				a = dlim + rand() % (ulim - dlim + 1);
				count++;
				printf("The number is %d?\n", a);
			}
		} while (ans != '=');

		printf("The computer guessed your number\n");
		printf("Amount of tries = %d\n", count);
		return 0;
		break;
	case 3:
		flag = 1; // _num
		do {
			printf("Input your number (1 ... 1000)\n");
			scanf_s("%d", &num);
			flag = (num < 1) || (num > 1000);
			if (flag) {
				printf("Uncorrect data\n");
			}
		} while (flag); // num_

		a = rand() % 1000;
		printf("The number is %d? (<, >, =): \n", a);

		do {
			scanf_s("%c", &ans);
			if (ans == '>') {
				dlim = a + 1;
				a = dlim + rand() % (ulim - dlim + 1);
				count++;
				printf("The number is %d? (<, >, =): \n", a);
			}
			if (ans == '<') {
				ulim = a - 1;
				a = dlim + rand() % (ulim - dlim + 1);
				count++;
				printf("The number is %d? (<, >, =): \n", a);
			}
		} while (a != num);

		count++;
		printf("The computer guessed your number\n");
		printf("Amount of tries = %d\n", count);
		return 0;
		break;
	}
}