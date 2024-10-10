#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	printf("Please select the mode\n");
	printf("1 -  You're guessing, 2 - The computer guesses\n");
	int x, flag, c;
	do {
		flag = 0;
		int r = scanf("%d", &x);
		if ((r != 1) || (x < 1) || (x > 2)) {
			flag = 1;
			printf("Error. Please enter the correct values\n");
		}
		while ((c = getchar()) != '\n' && c != EOF) 
		{}
	} while (flag != 0);

	if (x == 1) {
		srand(time(NULL));
		int r, range, n, count;
		count = 0;
		range = 1001;
		r = rand() % range;
		//printf("%d", r);
		scanf_s("%d", &n);
		count += 1;
		while (r != n) {
			if (r > n) {
				printf("The hidden number is bigger\n");
				scanf_s("%d", &n);
				count += 1;
			}
			if (r < n) {
				printf("The hidden number is lessen\n");
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
		srand(time(NULL));
		int a, b, k, range;
		int count2;
		count2 = 0;
		char m = '0';
		range = 1001;
		printf(" > - the hidden number is bigger; < - the hidden number is lessen; = -  the number are equal\n");
		scanf_s("%d", &a);
		b = rand() % range;
		printf("%d", b);
		k = abs(a - b);

		scanf_s("\n%c", &m);
		count2 += 1;
		while (m != '=') {
			if (m == '<' && k > a) {
				k = abs(b - a);
				b = rand() % k;
				printf("%d", b);
				scanf_s("\n%c", &m);
				count2 += 1;

			}
			if (m == '<' && k < a) {
				k = abs(b - a);
				b = k + rand() % (a - k + 1);
				printf("%d", b);
				scanf_s("\n%c", &m);
				count2 += 1;


			}
			if (m == '>') {
				k = b;
				b = k + rand() % (a - k + 1);
				printf("%d", b);
				scanf_s("\n%c", &m);
				count2 += 1;

			}
		}
		if (m == '=') {
			printf("WIN!!!\n");
			printf("%d", count2);
		}

	}

	return 0;
}