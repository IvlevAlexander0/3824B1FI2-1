#include <stdio.h>
#include <math.h>
#define MAX 256
char prds[MAX][50] = { "milk", "salt", "sugar", "eggs", "tea"};
float prices[MAX] = { 89, 59, 69, 101, 119 };
int codes[MAX][4] = { {0, 0, 0, 1}, {0, 0, 0, 2}, {0, 0, 0, 3}, {0, 0, 0, 4}, {0, 0, 0, 5} };
int discounts[MAX] = { 10, 1, 1, 2, 25 };

int main() {
	int id = 5, flag = 0; // id  - количество позиций в программе
	char c = 0;
	int mode, c_id = 0, curr_id = 0; //c_id кол-во позиций в чеке
	for (int i = id; i < MAX; ++i) {
		for (int j = 0; j < 4; ++j) {
			codes[i][j] = -1;
		}
	}
	char c_prds[MAX][20] = { '\0' };
	float c_prices[MAX] = { -1 };
	for (int i = 0; i < MAX; ++i) {
		c_prices[i] = -1;
	}
	int c_discounts[MAX] = { -1 };
	for (int i = 0; i < MAX; ++i) {
		c_discounts[i] = -1;
	}
	int count[MAX] = { 0 };
	int was[MAX][5] = { -1 };
	for (int i = 0; i < MAX; ++i) {
		for (int j = 0; j < 5; ++j) {
			was[i][j] = -1;
		}
	}
	while (1) {
		double sum_p =  0, sum_d = 0, topay = 0;
		printf("\nChoose mode:\n1.Add description \t 2.Scan product and print description  \t 3.Scan the product and add it to check \n4.Print check \t 5.Form check and go on or end\n");
		scanf_s("%d", &mode);
		switch (mode) {
		case 1:
			printf("Type product barcode: ");
			getchar();
			for(int i = 0; i < 4; ++i) {
				codes[id][i] = getchar() - '0';
			}
			printf("Type product name: ");
			while ((c = getchar()) != '\n');
			for (int i = 0; (c = getchar()) != '\n'; prds[id][i++] = c);
			printf("Type product price: ");
			scanf_s("%f", &prices[id]);
			printf("Type product discount(1%% - 50%%): ");
			scanf_s("%d%%", &discounts[id]);
			printf("\n");
			++id;
			break;
		case 2:
			printf("Type product barcode: ");
			int tmp_2[1][4] = { 0 };
			curr_id = 0;
			while ((c = getchar()) != '\n');
			for (int i = 0; i < 4; ++i) {
				tmp_2[0][i] = getchar() - '0';
			}
			for (int i = 0; i < MAX; ++i) {
				int cnt = 0;
				for (int j = 0; j < 4; ++j) {
					if (codes[i][j] == tmp_2[0][j]) {
						++cnt;
					}
				}
				if (cnt == 4) {
					flag = 1;
					curr_id = i;
					break;
				}
			}
			if(flag) {
				printf("Product name: %s\nPrice: %.2f\nDiscount: %d%%\n\n", prds[curr_id], prices[curr_id], discounts[curr_id]);
			}
			else {
				printf("Error! Product not found.\n\n");
			}
			flag = 0;
			break;
		case 3:
			printf("Type product barcode: ");
			int tmp_3[1][4] = { 0 };
			curr_id = -1;
			while ((c = getchar()) != '\n');
			for (int i = 0; i < 4; ++i) {
				tmp_3[0][i] = getchar() - '0';
			}
			for (int i = 0; i < MAX; ++i) {
				int cnt = 0;
				for (int j = 0; j < 4; ++j) {
					if (was[i][j] == tmp_3[0][j]) {
						++cnt;
					}
				}
				if (cnt == 4) {
					curr_id = was[i][4];
					flag = 1;
					break;
				}
			}
			if(!flag)
			{
				for (int i = 0; i < MAX; ++i) {
					int cnt = 0;
					for (int j = 0; j < 4; ++j) {
						if (codes[i][j] == tmp_3[0][j]) {
							++cnt;
						}
					}
					if (cnt == 4) {
						flag = 1;
						curr_id = i;
						for (int j = 0; j < 4; ++j) {
							was[c_id][j] = tmp_3[0][j];
						}
						was[c_id][4] = c_id;
						break;
					}
				}
				if (flag) {
					for (int i = 0; prds[curr_id][i] != '\0'; ++i) {
						c_prds[c_id][i] = prds[curr_id][i];
					}

					c_discounts[c_id] = discounts[curr_id];
					c_prices[c_id] = prices[curr_id];
					for (int i = 0; i < 4; ++i) {
						was[c_id][i] = tmp_3[0][i];
					}
					++count[c_id];
					++c_id;
					printf("\n");
				}
				else {
					printf("Error! Product not found.\n");
				}
			}
			else {
				if (curr_id != -1) {
					++count[curr_id];
				}
				else {
					printf("Error! Product not found.\n");
				}
			}
			flag = 0;
			break;
		case 5:
		case 4:
			putchar('\n');
			printf("Total check\n");
			printf("____________________________________________________\n");
			printf("# - price per unit - amount - discount - total cost\n");
			for (int i = 0; i < c_id; ++i) {
				sum_p += c_prices[i] * count[i] * 100;
				sum_d += c_prices[i] * count[i] * (100. - c_discounts[i]);
				printf("%d.", i + 1);
				for (int j = 0; c_prds[i][j] != '\0'; ++j) {
					putchar(c_prds[i][j]);
				}
				topay = round(c_prices[i] * count[i] * (100. - c_discounts[i])) / 100;
				printf(" - %0.2f - %d - %0.2f - %.2f\n", c_prices[i], count[i], c_prices[i] * count[i] - topay, topay);
			}
			topay = round(sum_d) / 100;
			sum_p = round(sum_p) / 100;
			sum_d = sum_p - topay;
			printf("____________________________________________________\n");
			printf("Total price without discount - %.2lf\nTotal discount - %.2lf\nTotal amount to be paid - %.2lf\n", sum_p, sum_d, topay);
			printf("____________________________________________________\n\n");
			if (mode == 5) {
				printf("What do you want to do next?(Type a number)\n");
				printf("1.End \t 2.Generate a new check\n");
				getchar();
				scanf_s("%d", &mode);
				if (mode == 1) {
					return 0;
				}
				else {
					c_id = 0, curr_id = 0;
					for (int i = 0; c_prds[i][0] != '\0'; ++i){
						for (int j = 0; c_prds[i][j] != '\0'; ++j) {
							c_prds[i][j] = '\0';
						}
					}
					for (int i = 0; c_prices[i] != -1; ++i) {
						c_prices[i] = -1;
					}
					for (int i = 0; c_discounts[i] != -1; ++i) {
						c_discounts[i] = -1;
					}
					for (int i = 0; count[i] != 0; ++i) {
						count[i] = 0;
					}
					for (int i = 0; i < MAX; ++i) {
						for (int j = 0; j < 5; ++j) {
							was[i][j] = -1;
						}
					}
				}
			}
			break;
		default:
			break;
		}
	}
	return 0;
}