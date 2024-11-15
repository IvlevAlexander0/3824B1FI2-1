#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_SIZE 10000 // штрих код от 0000 до 9999
#define MAX_NAME 16

unsigned prices[MAX_SIZE];
unsigned counts[MAX_SIZE];
unsigned discounts[MAX_SIZE];
char products[MAX_SIZE][MAX_NAME];
char barcode_input[5];
unsigned receipt[5][256]; // 0 - barcode , 1 - price , 2 - discount , 3 - count , 4 - final price

int correct_barcode(){
	char ch;
	ch = getchar(); //чистка буфера от \n
	unsigned count = 0;
	while (count < 4) {
		ch = getchar();
		if (ch == '\n' && count < 4) {
			printf("Uncorrect data! Barcode must be from 0000 to 9999! Try again: ");
			count = 0; 
			continue;
		}
		if (ch < '0' || ch > '9') {
			printf("Uncorrect data! Barcode must be from 0000 to 9999! Try again: ");
			while ((ch = getchar()) != '\n' && ch != EOF) {}
			count = 0;
			continue;
		}
		barcode_input[count] = ch;
		count++;
	}
	ch = getchar(); //чистка буфера от \n
	int barcode = 0;
	for (size_t i = 0; i <= (count-1); i++) {
		barcode *= 10;
		barcode += barcode_input[i] - '0';
	}
	return (barcode);
}
void adding_product() {
	int barcode;
	printf("\nWrite the barcode (from 0000 to 9999) for new product: ");			 // ввод штрих кода
	barcode = correct_barcode();
	char ch;
	if (products[barcode][0] != '\0') {
		printf("Sorry, barcode %s is already used! Try another.\n", barcode_input);
		while ((ch = getchar()) != '\n' && ch != EOF) {}
		return adding_product();
	}
	else {
		printf("\nEnter the product's name (max length is 30 symbols) : ");			 // ввод названия продукта
		fgets(products[barcode], MAX_NAME, stdin);
		size_t len = strlen(products[barcode]);
		if (len > 0 && products[barcode][len - 1] == '\n') {
			products[barcode][len - 1] = '\0';
		}
		else while ((ch = getchar()) != '\n' && ch != EOF) {}
		printf("\nEnter the product's price : ");									 // ввод цены
		do {
			ch = getchar();
			if (ch == '\n') break;

			if (ch < '0' || ch > '9') {
				printf("Uncorrect data! Try again: ");
				while ((ch = getchar()) != '\n' && ch != EOF) {}
				prices[barcode] = 0;
				continue;
			}
			prices[barcode] = prices[barcode] * 10 + (ch - '0');
		} while (1);
		printf("\nEnter the product's discount (from 0 to 50) : ");					   //ввод скидки
		unsigned discount_input;
		while (1) {
			if ((scanf_s("%u", &discount_input) != 1) || discount_input > 50) {
				printf("Uncorrect discount! Try again: ");
				while ((ch = getchar()) != '\n' && ch != EOF) {};
			}
			else {
				discounts[barcode] = discount_input;
				break;
			}
		}
		while ((ch = getchar()) != '\n' && ch != EOF) {};
		system("cls");
		printf("* Product added to data successfully! *\n");
	}
}
void scanning_product() {
	int barcode;
	printf("\nWrite the product's barcode: ");			 
	barcode = correct_barcode();

	if (products[barcode][0] == '\0') {
		system("cls");
		printf("\nThere are no product with this barcode!\n");
	}
	else {
		system("cls");
		printf("\nName: %s | Price: %u$ | Discount: %u%% \n", products[barcode], prices[barcode], discounts[barcode]);
	}
}
void scan_and_add_product() {
	int barcode;
	printf("\nWrite the product's barcode: ");
	barcode = correct_barcode();
	if (products[barcode][0] == '\0') {
		system("cls");
		printf("\nThere are no product with this barcode!\n");
	}
	else {
		printf("Enter the count of product : ");
		unsigned count;
		char ch;
		while (1) {
			if ((scanf_s("%u", &count) != 1) || count > 99) {
				printf("Uncorrect discount! Try again: ");
				while ((ch = getchar()) != '\n' && ch != EOF) {};
			}
			else break;
		}
		while ((ch = getchar()) != '\n' && ch != EOF) {};
		char flag_repeat = 0;
		size_t i;
		for (i = 0; i <= 255; i++) {
			if (receipt[0][i] == 10000) break;  // 10000 - маркер свободной позиции
			if (barcode == receipt[0][i]) {
				flag_repeat = 1;   // товар уже в чеке
				break;
			}
		}
		if (flag_repeat) {
			receipt[3][i] += count;
			receipt[4][i] = (receipt[1][i] * (100 - receipt[2][i])) * receipt[3][i] / 100;
		}
		else {
			receipt[0][i] = barcode;
			receipt[1][i] = prices[barcode];
			receipt[2][i] = discounts[barcode];
			receipt[3][i] = count;
			receipt[4][i] = (receipt[1][i] * (100 - receipt[2][i])) * count / 100;
			}
		}
		system("cls");
		printf("* Product added to receipt successfully! *\n");
	}
void print_receipt() {
	unsigned i = 0;
	char ch;
	while ((ch = getchar()) != '\n' && ch != EOF) {}
	system("cls");
	while (receipt[0][i] != 10000) {
		printf_s("Name: %16s | Price: %5u | Discount: %2u%% | Count: %2u | Final price: %5u$\n", products[receipt[0][i]], receipt[1][i], receipt[2][i], receipt[3][i], receipt[4][i]);
		i++;
	}
	i = 0;
	unsigned total_discount = 0;
	unsigned total_price = 0;
	while (receipt[0][i] != 10000) {
		total_price += receipt[4][i];
		total_discount += receipt[1][i] * receipt[2][i] * receipt[3][i] / 100;
		i++;
	}
	for (i = 0; i != 23; i++) {
		printf("-");
	}
	printf("|");
	for (i = 0; i != 14; i++) {
		printf("-");
	}
	printf("|");
	for (i = 0; i != 15; i++) {
		printf("-");
	}
	printf("|");
	for (i = 0; i != 11; i++) {
		printf("-");
	}
	printf("|");
	for (i = 0; i != 19; i++) {
		printf("-");
	}
	printf("\n");
	for (i = 0; i != 38; i++) {
		printf(" ");
	}
	printf("|");
	printf(" Total discount: %9u$", total_discount);
	printf("|");
	printf(" Total price: %5u$", total_price);
}
unsigned correct_answer(unsigned max) {
	unsigned a;
	while (scanf_s("%d", &a) != 1 || a < 1 || a > max) {
		printf_s("Uncorrect answer! number must be from 1 to %u\n", max);
		char c;
		while ((c = getchar()) != '\n' && (c != EOF)) {}
	}
	return (a);

}

void main() {
	for (size_t i = 0; i < MAX_SIZE; i++) {
		products[i][0] = '\0';
		prices[i] = 0;
		counts[i] = 0;
	}
	for (size_t i = 0; i < 256; i++) {
		receipt[0][i] = 10000;         // 10000 - маркер свободной позиции
	}
	strcpy_s(products[0], "bread");		prices[0] = 20;	discounts[0] = 0;
	strcpy_s(products[1], "milk");		prices[1] = 80;	discounts[1] = 10;
	strcpy_s(products[2], "chocolad");	prices[2] = 99;	discounts[2] = 30;
	strcpy_s(products[3], "apple");		prices[3] = 15;	discounts[3] = 0;
	strcpy_s(products[4], "ice cream");	prices[4] = 49;	discounts[4] = 15;
	unsigned working = 1;
	while (working) {
		printf("\nChoose the operation:\n\
1. Adding a product description to the program\n\
2. Scanning the product and displaying its description\n\
3. Scan the product and add it to the receipt\n\
4. Print the receipt\n\
5. Generate a final receipt\n\n");
		char action;
		action = correct_answer(5);
		switch (action) {
		case 1: adding_product(); break;
		case 2: scanning_product(); break;
		case 3: scan_and_add_product(); break;
		case 4: print_receipt(); break;
		case 5: print_receipt();
			printf("\n 1 - Create new receipt.\n\
 2 - Exit.\n ");
			unsigned ask;
			ask = correct_answer(2);
			if (ask == 2) {
				working = 0; break;
			}
			system("cls");
			for (size_t i = 0; i < 256; i++) {
				receipt[0][i] = 10000;         // 10000 - маркер свободной позиции
			}
			break;
		defualt: break;
		}
	}
}