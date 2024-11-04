#include <stdio.h>
int main() {
	const int Size = 10000, Str_Size = 20;
	int mode;
	float Values[Size] = { 0 }, Discounts[Size] = { 0 };
	int Cheque[Size] = { 0 };
	char Names[Size][Str_Size] = { 0 };
	int flg = 1;
	int Instruction = 1;

	while (flg) {
		int List[4] = { 0 };
		printf("Enter the barcode(four digits from 0 to 9)\n");
		int j = 0;
		do {
			char k;
			k = getchar();
			List[j] = k - '0';
			j++;
		} while (j < 4);
		char flag;
		while ((flag = getchar()) != '\n' && flag != EOF) {}

		int Num = 0;
		for (int i = 0; i < 4; i++) {
			Num += List[i];
			Num *= 10;
		}
		Num /= 10;

		if (Instruction) { // список команд
			printf("Instruction:\n");
			printf("0 - next product\n");
			printf("1 - enter the product's name\n");
			printf("2 - enter the product's price\n");
			printf("3 - enter the discount\n");
			printf("4 - add to check\n");
			printf("5 - get all information about product\n");
			printf("6 - prints the check\n");
			printf("7 - get list of commands again\n");
		}
		Instruction = 0;
		while (1) {
			printf("Choose the mode\n");
			scanf_s("%d", &mode);
			while ((flag = getchar()) != '\n' && flag != EOF) {};
			if (mode == 0) { // -перейти к другому штирхкоду
				break;
			}
			else if (mode == 1) { // 1 - добавить/изменить наименование
				printf("Enter the product's name(Up to %d symbols)\n",Str_Size);
				for (int i = 0; i < 20; i++) {
					Names[Num][i] = '0'; // В случае если надо будет заменить
				}
				for (int i = 0; i < Str_Size; i++) {
					char n;
					n = getchar();
					if (n == '\n') {
						break;
					}
					Names[Num][i] = n;
				}
			}
			else if (mode == 2) { // 2 -добавить цену
				do {
					printf("Enter the product's price\n");
					scanf_s("%f", &Values[Num]);
				} while (0 > Values[Num]);
			}
			else if (mode == 3) { // 3 - добавить скидку
				do {
					printf("Enter the product's discount(from 1 to 50 per cent)\n");
					scanf_s("%f", &Discounts[Num]);
				} while (Discounts[Num] < 0 || Discounts[Num] > 50);
			}
			else if (mode == 4) { // добавить в чек
				if (Names[Num][0] == 0) {
					printf("The product's name is empty");
				}
				else {
					Cheque[Num]++;
					printf("Added to your check\n");
				}
			}
			else if (mode == 5) { // Вся информация
				printf("%d ", Num);
				for (int i = 0; i < Str_Size; i++) {
					if (Names[Num][i] == '0') {
						break;
					}
					printf("%c", Names[Num][i]);
				}
				printf("\n");
				printf("Price = %.2f\n", Values[Num]);
				if (Discounts[Num] > 0) {
					float New_Price = Values[Num] - Values[Num] * (Discounts[Num] / 100);
					printf("New price = %.2f\n", New_Price);
				}
			}
			else if (mode == 6) { // Выход из цикла и переход к отображению чека
				flg = 0;
				printf("\n");
				break;
			}
			else if (mode == 7) { // 7 - вывести команды
				printf("Instruction:\n");
				printf("0 - next product\n");
				printf("1 - enter the product's name\n");
				printf("2 - enter the product's price\n");
				printf("3 - enter the discount\n");
				printf("4 - add to check\n");
				printf("5 - get all information about product\n");
				printf("6 - prints the check\n");
				printf("7 - get list of commands again\n");
			}
			else {
				printf("Incorrect mode has been chosen\n");
			}
		}
	}

	float Total_Cost = 0;
	printf("Check\n");
	for (int i = 0; i < Size; i++) { // Печать чека
		if (Cheque[i] > 0) {
			for (int j = 0; j < Str_Size; j++) {
				if (Names[i][j] == '0') {
					break;
				}
				printf("%c", Names[i][j]);
			}
			printf("\n");

			float Prix;
			if (Discounts[i] > 0) {
				Prix = Values[i] - Values[i] * (Discounts[i] / 100);
				printf("Price %.2f\n", Prix);
			}
			else {
				Prix = Values[i];
				printf("Price %.2f\n", Prix);
			}

			printf("Amount %d\n", Cheque[i]);
			float cost = Cheque[i] * Prix;
			printf("Cost %.2f\n\n", cost);
			Total_Cost += cost;
		}
	}
	printf("Total cost %.2f", Total_Cost);
}