#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
int main() {
	int length;
	printf("Enter the length: \n");
	while (scanf_s("%d", &length) != 1 || length < 2 || length > 5) { // �������� ����� �����
		printf_s("Number's length must be from 2 to 5.\n");
		char c;
		while ((c = getchar()) != '\n' && (c != EOF)) {}
	}
	int* digits = (int*)malloc(length * sizeof(int));
	char flag = 0;
	srand(time(NULL));
	digits[0] = rand() % 10;  // �������� n-�������� ����� � ���������������� �������
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
	int valid;
	int* digits_ask = (int*)malloc(length * sizeof(int));
	char ch;

	ch = getchar(); // ��� ���� ������ fgets ��� ������ ������� ����� ������� \n � ����� ������� ������ � ������������ ����� �����
	while (positions != length) {
		valid = 0;
		while (!valid) { // �������� �������� ����� � ������������ ���� ��������� �����
			printf_s("Enter the number: ");
			char* input = NULL;
			int count = 0;
			do {
				scanf_s("%c", &ch);
				if (ch == '\n')
					break;
				input = (char*)realloc(input, ++count * sizeof(char));
				input[count - 1] = ch;
			} while (1);
			if (count != length) {
				printf("Your number must be %d in length.\n\n", length);
				continue; 
			}

			int unique = 1; // �������� �� ����������� ���� ���� �����
			for (int i = 0; i < count; i++) {
				if (input[i] < '0' || input[i] > '9') { 
					unique = 0;
					break;
				}
				for (int j = i + 1; j < count; j++) {
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

			// ������� ��� ������� � ��� ������
			for (int i = 0; i < length; i++) {
				digits_ask[i] = input[i] - '0';
			}
			valid = 1;
			free(input);
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