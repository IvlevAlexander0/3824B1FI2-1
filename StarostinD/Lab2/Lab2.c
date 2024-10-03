#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void guess() {
	int x = 1 + rand() % 1000;
	int cnt = 0;
	int flag = 1;
	int try;
	while (flag) {
		printf("Try to guess the number(1-1000): ");
		scanf_s("%d", &try);
		++cnt;
		if (try == x) {
			printf("Congratulations, you guessed the number.\nNumber of attempts: %d", cnt);
			flag = 0;
		}
		else if (try < x) {
			printf("Wrong. The number guessed is greater.\n");
		}
		else if (try > x) {
			printf("Wrong. The number guessed is less.\n");
		}
	}

}
void set() {
	int x, cnt = 0;
	printf("Set the number(1-1000): ");
	scanf_s("%d", &x);
	printf("\nTrying to guess...\n");
	int l = 0, r = 1001, g = 0;
	char sign = ' ';
	while (sign != '=') {
		g = (r + l) / 2;
		++cnt;
		printf("%d\n", g);
		while ((sign = getchar()) != '\n' && sign != EOF);
		scanf_s("%c", &sign);
		if (sign == '=') {
			printf("I think you guessed %d\nNumber of attempts: %d\n", g, cnt);
		}
		else if (sign == '>') {
			l = g;
		}
		else if (sign == '<') {
			r = g;
		}
	}
}

int main() {
	srand(time(NULL));
	short choice;
	printf("Select mode:\n1.Guess the number \t 2.Set the number\n");
	scanf_s("%hd", &choice);
	printf("\n");
	choice == 1 ? guess() : set();
	return 0;
}