#include <stdio.h>
#define Size 10000
#define Str_Size 20
#include <stdio.h>
int main() {
	int mode;
	char n = 0;
	char flag;
	float Values[Size] = { 40,70,80,400,35 }, Discounts[Size] = { 0,10,20,25,0 };
	char Names[Size][Str_Size] = { "bread\n","milk\n","sugar\n","meat\n","salt\n" };
	int flg = 1;
	Values[0] = 40;
	while (1) {
		int products_count = 0;
		int Cheque[Size] = { 0 };
		flg = 1;
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

			while ((flag = getchar()) != '\n' && flag != EOF) {}
			int Num = 0;
			for (int i = 0; i < 4; i++) {
				Num += List[i];
				Num *= 10;
			}
			Num /= 10;
			while (1) {
				printf("Choose the mode\n");
				scanf_s("%d", &mode);
				while ((flag = getchar()) != '\n' && flag != EOF) {}
				if (mode == 1) { // Скан товара
					if (Values[Num] != 0) { //   Замена/корректирование информации
						printf("This product has been already added, do you want to enter another barcode (print 0)\nor to edit the current one (print 1)? (in this case product will be deleted from your check if it exists)\n");
						scanf_s("%d", &mode);
						while ((flag = getchar()) != '\n' && flag != EOF) {};
						if (mode == 1) {
							for (int i = 0; i < Str_Size; i++) {
								Names[Num][i] = '0';
							}
							products_count -= Cheque[Num];
							Cheque[Num] = 0;
						}
						else if (mode == 0) {
							break;
						}
					}

					printf("Enter the product's name\n");
					int i = 0;
					do {
						n = getchar();
						Names[Num][i] = n;
						i++;
					} while (n != '\n' && n != EOF && i < Str_Size - 1);

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
					if (Values[Num] == 0) {
						printf("This product hasn't been scanned yet\n");
					}
					else {
						printf("%d Product's name: ", Num);
						for (int i = 0; i < Str_Size; i++) {
							if (Names[Num][i] == '0') {
								break;
							}
							printf("%c", Names[Num][i]);
						}
						printf("Price = %.2f\n", Values[Num]);
						if (Discounts[Num] > 0) {
							float New_Price = Values[Num] - Values[Num] * (Discounts[Num] / 100);
							printf("New price = %.2f\n", New_Price);
						}
					}
				}
				else if (mode == 3) { // добавить в чек
					if (Values[Num] != 0 && Names[Num][0] != '\n') {
						printf("How many products are you going to buy?\n");
						int Quantity = 0;
						scanf_s("%d", &Quantity);
						Cheque[Num] += Quantity;
						products_count += Quantity;
					}
					else {
						printf("You can't add this product, try to correct the data\n");
					}
				}
				else if (mode == 4) { // печать чека
					if (products_count) {
						flg = 0;
						break;
					}
					else {
						printf("There are hardly any products in your check\n");
					}
				}
				else if (mode == 5) { // Текущая сумма покупок
					if (products_count == 0) {
						printf("There are hardly any products in your check\n");
					}
					else {
						float Total_Cost = 0;
						for (int i = 0; i < Size; i++) {
							if (Cheque[i] > 0) {
								float Prix;
								if (Discounts[i] > 0) {
									Prix = Values[i] - Values[i] * (Discounts[i] / 100);
								}
								else {
									Prix = Values[i];
								}
								float cost = Cheque[i] * Prix;
								Total_Cost += cost;
							}
						}
						printf("Total cost is %.2f\n", Total_Cost);
					}
				}
				else if (mode == 6) { // Предпросмотр чека
					if (products_count == 0) {
						printf("There are hardly any products in your check\n");
					}
					else {
						float Total_Cost = 0, Total_Discount = 0;
						printf("Prototype of the check\n");
						for (int i = 0; i < Size; i++) { // Печать чека
							if (Cheque[i] > 0) {
								printf("Product's name: ");
								for (int j = 0; j < Str_Size; j++) {
									if (Names[i][j] == '0') {
										break;
									}
									printf("%c", Names[i][j]);
								}
								float Prix;
								if (Discounts[i] > 0) {
									Prix = Values[i] - Values[i] * (Discounts[i] / 100);
									Total_Discount += Cheque[i] * (Values[i] * (Discounts[i] / 100));
									printf("Price %.2f\n", Prix);
								}
								else {
									Prix = Values[i];
									printf("Price %.2f\n", Prix);
								}

								printf("Amount %d\n", Cheque[i]);
								float cost = Cheque[i] * Prix;
								//printf("Cost %.2f\n\n", cost);
								Total_Cost += cost;
							}
						}
						if (Total_Discount > 0) {
							printf("Total cost %.2f\n", Total_Cost + Total_Discount);
							printf("Total discount %.2f\n", Total_Discount);
							printf("Toatl cost with discount %.2f\n\n", Total_Cost);
						}
						else {
							printf("Total cost %.2f\n\n", Total_Cost);
						}
					}
				}
				else if (mode == 7) { // Переход к следующему товару
					break;
				}

			}
		}

		float Total_Cost = 0, Total_Discount = 0;
		printf("Check\n");
		for (int i = 0; i < Size; i++) { // Печать чека
			if (Cheque[i] > 0) {
				printf("Product's name: ");
				for (int j = 0; j < Str_Size; j++) {
					if (Names[i][j] == '0') {
						break;
					}
					printf("%c", Names[i][j]);
				}
				float Prix;
				if (Discounts[i] > 0) {
					Prix = Values[i] - Values[i] * (Discounts[i] / 100);
					Total_Discount += Cheque[i] * (Values[i] * (Discounts[i] / 100));
					printf("Price %.2f\n", Prix);
				}
				else {
					Prix = Values[i];
					printf("Price %.2f\n", Prix);
				}

				printf("Amount %d\n", Cheque[i]);
				float cost = Cheque[i] * Prix;
				//printf("Cost %.2f\n\n", cost);
				Total_Cost += cost;
			}
		}
		if (Total_Discount > 0) {
			printf("Total cost %.2f\n", Total_Cost + Total_Discount);
			printf("Total discount %.2f\n", Total_Discount);
			printf("Toatl cost with discount %.2f\n\n", Total_Cost);
		}
		else {
			printf("Total cost %.2f\n\n", Total_Cost);
		}
		printf("Do you want to finish(print 1 otherwise print 0)\n");
		scanf_s("%d", &mode);
		while ((flag = getchar()) != '\n' && flag != EOF) {}
		if (mode == 1) {
			break;
		}
		else {
			continue;

		}
	}
}