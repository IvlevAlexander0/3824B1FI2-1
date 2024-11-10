#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
int main() {
	int length;
	printf("Enter the length: \n");
	while (scanf_s("%d", &length) != 1 || length < 2 || length > 5) { // проверка ввода длины
		printf_s("Number's length must be from 2 to 5.\n");
		char c;
		while ((c = getchar()) != '\n' && (c != EOF)) {}
	}
	int* digits = (int*)malloc(length * sizeof(int));
	char flag = 0;
	srand(time(NULL));
	digits[0] = rand() % 10;  // создание n-значного числа с неповтор€ющимис€ цифрами
	for (int i = 1; i < length; i++) {
		while (flag == 0) {
			flag = 1;
			digits[i] = rand() % 10;
			for (int j = 0; j < i; j++) {
				if (digits[i] == digits[j]) {
					flag = 0; break;
				}
			}
		}
		flag = 0;
	}
	//for (int i = 0; i < length; i++) {
	//	printf_s("%d ", digits[i]);}
	int positions = 0, counter;
	char input[12];
	int valid;
	int* digits_ask = (int*)malloc(length * sizeof(int));
	char ch;
	ch = getchar(); // без этой строки fgets при первом запуске цикла считает \n и сразу напишет ошибку о неправильной длине числа
	while (positions != length) {
		valid = 0;
		while (!valid) { // алгоритм проверки длины и уникальности цифр вводимого числа
			printf_s("Enter the number: ");
			fgets(input, sizeof(input), stdin); 
			int num_digits = strlen(input) - 1; // т.к. последний символ это переход на новую строку
			if (num_digits != length) {
				printf("Your number must be %d in length.\n\n", length);
				continue; 
			}

			int unique = 1; // проверка на различность всех цифр числа
			for (int i = 0; i < num_digits; i++) {
				if (input[i] < '0' || input[i] > '9') { 
					unique = 0;
					break;
				}
				for (int j = i + 1; j < num_digits; j++) {
					if (input[i] == input[j]) {
						unique = 0;
						break;
					}
				}
				if (!unique) break;
			}

			if (!unique) {
				printf("All digits in number must be different!.\n");
				continue; 
			}

			// перевод чар массива в инт массив
			for (int i = 0; i < length; i++) {
				digits_ask[i] = input[i] - '0';
			}
			valid = 1;
		}
		positions = 0;
		counter = 0;
		for (int i = 0; i < length; i++) {
			for (int j = 0; j < length; j++) {
				if (digits_ask[i] == digits[j]) {
					if (i == j) {
						positions++;
					}
					counter++;
					break;
				}
			}
		}
		counter -= positions;
		if (positions == length) {
			printf_s("\n  * You damn right! *\n");
		}
		else {
			printf_s("Cows: %d. Bulls: %d\n\n", counter, positions);
		}
	}
	free(digits);
	free(digits_ask);
	return 0;
}