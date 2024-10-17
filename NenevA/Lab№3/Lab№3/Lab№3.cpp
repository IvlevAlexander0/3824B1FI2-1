#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
	int List[5] = { -1,-1,-1,-1,-1 };
	int i = 0, n, num, j, flg;
	srand(time(NULL));
	List[0] = 1 + rand() % 9;
	do {
		printf("Enter the number's length(from 2 to 5)\n");
		scanf_s("%d", &n);
	} while (n < 2 || n>5);
	printf("Please wait a little bit while the number is being generated\n");
	while (i < n) {
		srand(time(NULL));
		num = rand() % 10;
		flg = 1;
		for (j = 0; j < n; j++) {
			if (num == List[j]) {
				flg = 0;
			}
		}
		if (flg) {
			List[i] = num;
			i++;
		}
	}

	int guess, save;
	printf("Try to guess the number\n");
	while (1) {
		int ListTry[5] = { 0,-1,-2,-3,-4 }, flag = 0;
		do {
			for (i = 0; i < 5; i++) {
				ListTry[i] = -i;
			}
			flag = 0;
			printf("Enter the number with all different figures which length = %d\n", n);
			scanf_s("%d", &guess);
			save = guess;
			i = 0;
			while (save > 0) {
				ListTry[i] = save % 10;
				save /= 10;
				i++;
			}

			for (i = 0; i < n - 1; i++) {
				for (j = i + 1; j < n; j++) {
					if (ListTry[i] == ListTry[j]) {
						flag = 1;
					}
				}
			}

		} while (guess / pow(10, n - 1) < 1 || guess / pow(10, n - 1) > 10 || flag == 1);

		int bull = 0, cow = 0;
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				if (List[i] == ListTry[j]) {
					if (i == j) {
						bull++;
					}
					else {
						cow++;
					}
				}
			}
		}
		if (bull == n) {
			printf("You've guessed");
			break;
		}
		printf("bulls %d, cows %d\n", bull, cow);
	}
}