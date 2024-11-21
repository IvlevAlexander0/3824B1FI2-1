#include <stdio.h>
#define Size 10000
#define Str_Size 20
#include <stdio.h>
int main() {
	int mode;
	float Values[Size] = { 40,70,80,400,35 }, Discounts[Size] = { 0,10,20,25,0 };
	int Cheque[Size] = { 0 };
	char Names[Size][Str_Size] = { "bread","milk","sugar","meat","salt" };
	int flg = 1;
	Values[0] = 40;
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
		printf("Instruction\n 1.Scanning\n2.Description\n3.Addition to check\n4.Print the check\n5.Next product\n");
		while (1) {
			printf("Choose the mode\n");
			scanf_s("%d", &mode);
			while ((flag = getchar()) != '\n' && flag != EOF) {};
			if (mode == 1) { // Скан товара
				printf("Enter the product's name\n");
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
				do {
					printf("Enter the product's price\n");
					scanf_s("%f", &Values[Num]);
				} while (0 > Values[Num]);
				do {
					printf("Enter the product's discount(from 1 to 50 per cent or 0 if ther's no discount)\n");
					scanf_s("%f", &Discounts[Num]);
				} while (Discounts[Num] < 0 || Discounts[Num] > 50);
			}
			else if (mode == 2) { // Описание
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
			else if (mode == 3) { // добавить в чек
				printf("How many products are you going to buy?\n");
				int Quantity = 0;
				scanf_s("%d", &Quantity);
				Cheque[Num] += Quantity;
			}
			else if (mode == 4) { // печать чека
				flg = 0;
				break;
			}
			else if (mode == 5) {
				break;
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