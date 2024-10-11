#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	printf("Please select the mode\n");
	printf("1 -  You're guessing, 2 - The computer guesses\n");
	int x;
	srand(time(NULL));
	while (1) {
		int r = scanf_s("%d", &x);
		if (r == 1 && (x == 1 || x == 2)) {
			break;
		}
		else {
			printf("Error. Please enter the correct values\n");
			while (getchar() != '\n');
		}
	}
	if (x == 1) {
		int r, range, n, count;
		count = 0;
		range = 1000;
		r = 1 + rand() % (range);
		printf("Please enter a value in the range [1;1000]\n");
		//printf("%d", r);
		while (1) {
			int m = scanf_s("%d", &n);
			if (m == 1 && (n <= 1000 && n >= 1)) {
				break;
			}
			else {
				printf("Error. Please enter the correct values\n");
				while (getchar() != '\n');
			}
		}
		count += 1;
		while (r != n) {
			if (r > n) {
				printf("The hidden number is bigger\n");
				printf("Please enter a value in the range [1;1000]\n");
				scanf_s("%d", &n);
				count += 1;
			}
			if (r < n) {
				printf("The hidden number is lessen\n");
				printf("Please enter a value in the range [1;1000]\n");
				scanf_s("%d", &n);
				count += 1;
			}
		}
		if (r == n) {
			printf("You guessed it!!!\n");
			printf("%d", count);
		}
	}
	if (x == 2) {
		int min = 1;
		int max = 1000;
		int b;
		int count = 0;
		char c;
		while (min <= max) {
			b = min + (max - min) / 2;
			count++;

			printf("%d\n", b);
			printf("Enter (>, <, =); > - the hidden number is bigger, < - the hidden number is lessen; = - the number are equal\n");
			while (1) {
				scanf_s(" %c", &c);// when using <getchar> two character inputs are required (example: 500: >>: new number 750)
				if (c == '>' || c == '<' || c == '=') {
					break;
				}
				else {
					printf("Error. Please enter the correct values\n");
					while (getchar() != '\n');
				}
			}

			if (c == '=') {
				printf("Win!!!\n");
				printf("%d %d\n", b, count);
				break;
			}
			else if (c == '>') {
				min = b + 1;
			}
			else if (c == '<') {
				max = b - 1;
			}
		}
		if (min > max) {
			printf("Error. The entered value is not in range [1 - 1000] \n");
		}
	}

	return 0;
}