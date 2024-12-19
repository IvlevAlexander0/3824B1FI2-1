#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#define MAX_PROD_COUNT 1000
void flush() {
	char s;
	while (getchar() != '\n' );
}

void barcode(int* code) {
	int flag = 0;
	int n = 0;
	char c;
	int c1;
	int dopcode[MAX_PROD_COUNT] = { 0 };
	do {
		printf("Enter the barcode: ");
		int count = 0;
		flag = 0;
		n = 0;
		while ((c = getchar())!='\n') {
			if (n > 3) {
				printf("You've entered more than four digits. For barcode is neccesary to input only four digits.\n");
				flag = 1;
				flush();
				break;
			}
			c1 = (int)c - (int)'0';
			dopcode[n] = c1;
			n++;
		}
		if (n < 4) {
			flag = 1;
			printf("You've entered less than four digits. For barcode is neccesary to input only four digits.\n");
		}
	} while (flag != 0);
	for (size_t i = 0; i < 4; i++) {
		code[i] = dopcode[i];
	}
}

int main() {
	int products[MAX_PROD_COUNT][4] = { {0,0,0,1}, {0,0,0,2}, {0,0,0,3}, {0,0,0,4}, {0,0,0,5} };
	char descrip[MAX_PROD_COUNT][20] = {"Cookies", "Milk", "Bread", "Tea", "Water"};
	int index = 5;
	int price[MAX_PROD_COUNT] = { 100, 60, 30, 50, 40 };
	int discount[MAX_PROD_COUNT] = {25, 10, 0, 0, 15};
	int code[4] = { 0 };
	int mode = 0;
	int cart[MAX_PROD_COUNT] = { 0 };
	int countcart = 0;
	double res;
	int flag1 = 1;
	double summa = 0;
	int flagall = 1;
	printf("Welcome to the shop!\nPlease, choose what do you want to do.\n");
	do {
		printf("\n1 - To add a new product.\n2 - To scan a product and see info about it.\n3 - to scan a product and add it to the cart.\n");
		printf("4 - To see your current receipt.\n5 - To finish current receipt and either continue shopping or exit the shop.\n");
		printf("Enter the number of an option you'd like to choose: ");
		int flag = 0;
		int r;
		do {
			flag = 0;
			r = scanf_s("%d", &mode);
			if (r != 1 || mode < 1 || mode > 5) {
				printf("Enter valid option, please! Try again:");
				flag = 1;
			}
		} while (flag != 0);
		switch (mode)
		{	
		case 1: 
			printf("\nYou've chosen to add a new product. Firstly, what is his name: "); //название товара
			scanf_s("%s", descrip[index], sizeof(descrip[index]));
			printf("Enter the price of the %s: ", descrip[index]); //цена
			do {
				flag = 0;
				r = scanf_s("%d", &price[index]);
				if (r != 1 || price[index] < 1) {
					printf("\nPlease, enter valid price: ");
					flag = 1;
				}
			} while (flag != 0);
			printf("Enter the discount for this product in %(maximum 50, 0 if there won't be any): "); // скидка на товар
			do{
				flag = 0;
				r = scanf_s("%d", &discount[index]);
				if (r != 1 || r < 0 || r > 50) {
					printf("Please, enter valid discount: ");
					flag = 1;
				}
			} while (flag != 0);

			printf("Now, enter the barcode. Remember that there is maximum 4 digits for the barcode.\n");
			flush();
			do { 
				flag = 0;
				barcode(code); 
				for (int i = 0; i < index; i++) {
					int countofn = 0;
					for (int j = 0; j < 4; j++) {
						if (products[i][j] == code[j]) {
							countofn++;
						}
					}
					if (countofn == 4) {
						printf("There's already another product with the same barcode. Enter another.\n");
							flag = 1;
					}
				}
			} while (flag != 0);
			printf("You've added a new product into the system.\n");
			for (int i = 0; i < 4; i++) {
				products[index][i] = code[i];
			}
			index++;
			break;
		case 2:
			printf("\nYou've chosen to see an info about a product.");
			printf("Here's a list of available products:\n");
			for (int i = 0; i < index; i++) {
				for (int j = 0; j < 4; j++) {
					printf("%d", products[i][j]);
				}
				printf(" - %s\n", descrip[i]);
			}
			flush();
			do {
				flag = 1;
				barcode(code);
				for (int i = 0; i < index; i++) {
					int countofn = 0;
					for (int j = 0; j < 4; j++) {
						if (products[i][j] == code[j]) {
							countofn++;
						}
					}
					if (countofn == 4) {
						printf("\n%s - %d rubles, discount on it is - %d percents.\n", descrip[i], price[i], discount[i]);
						flag = 0;
						break;
					}
				}
				if (flag == 1) {
					printf("You've entered a barcode of a non-existent product. Try again.\n");
				}
			} while (flag != 0);
			break;
		case 3:
			printf("\nYou've chosen to add a product to the cart."); 
			printf("Here's a list of available products:\n"); 
			for (int i = 0; i < index; i++) {
				for (int j = 0; j < 4; j++) {
					printf("%d", products[i][j]); 
				}
				printf(" - %s\n", descrip[i]); 
			} 
			flush();
			do {
				flag = 0;
				barcode(code);
				for (int i = 0; i < index; i++) {
					int countofn = 0;
					for (int j = 0; j < 4; j++) {
						if (products[i][j] == code[j]) {
							countofn++;
						}
					}
					if (countofn == 4) {
						flag = 0;
						cart[countcart] = i;
						countcart++;
						printf("%s was added to the cart.\n", descrip[i]);
						break;
					}
				}

			} while (flag != 0);
			break; 
		case 4:
			printf("\nYou've chosen to see your current receipt.");
			printf("\nHere it is.\n");
			int count = 1;
			for (int i = 0; i < countcart; i++) {
				res = (double)price[cart[i]] * ((100 - (double)discount[cart[i]]) / 100);
				printf("\n%d - %s - price with discount - %lf", count++, descrip[cart[i]], res);
			}
			printf("\n");
			break;
		case 5:
			printf("\nYou've chosen to finish current receipt.");
			printf("\nHere it is.\n");
			count = 1;
			for (int i = 0; i < countcart; i++) {
				res = (double)price[cart[i]] * ((100 - (double)discount[cart[i]]) / 100);
				summa += res;
				printf("\n%d - %s - price with discount - %lf", count++, descrip[cart[i]], res);
			}
			printf("\n\nPrice for whole cart is - %lf\n", summa);
			printf("\nDo you want to continue with programm? 1 if yes, 2 if no: ");
			int choice;
			do {
				flag = 0;
				r = scanf_s("%d", &choice);
				if (r != 1 || choice < 1 || choice > 2) {
					printf("Enter valid number: ");
					flag = 1;
				}
			} while (flag != 0);
			if (choice == 1) {
				for (int i = 0; i < countcart; i++) {
					cart[i] = 0;
				}
				countcart = 0;
				summa = 0;
			}
			else {
				flagall = 0;
			}
			break;
		default:

			break;
		}
	} while (flagall != 0);
}