#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>

char name[10000][100];
int price[10000] = { 0 }, discount[10000] = { 0 }, number_of_products[10000] = { 0 }, barcodes[10000] = { 0 }, barcodes_in_shop_list[10000] = { 0 };

print_product(int barcode) //Выводит описание товара по штрих-коду(индексу), который есть в программе
{
	//Делает так, чтобы выводился штрих код в виде четырёх цифр
	if (price[barcode] != 0)
	{
		int local_barcode[4] = { 0 }, extra_num = barcode, i = 0, index = 0, t = 0;
		printf("Barcode: ");
		while (extra_num != 0)
		{
			index = fabs(i - 3);
			local_barcode[index] = extra_num % 10;
			extra_num /= 10;
			i++;
		}
		while (t < 4)
		{
			printf("%d", local_barcode[t++]);
		}
		printf("\nName: %s\n", name[barcode]);
		printf("Price: %d\n", price[barcode]);
		printf("Discount: %d\n", discount[barcode]);
	}
	else
		printf("This product is not available.\n");
}

print_full_list_of_products() //Выводит список товаров, которые есть в программе
{
	int i = 0;
	while (i < 10000)
	{
		if (barcodes[i] != 0 || (barcodes[i] == 0 && price[i] != 0))
		{
			print_product(i);
			printf("--------------------\n");
		}
		i++;
	}
}

add_product_in_program()
{
	int barcode;
	char c;
	while (((c = getchar()) != '\n' && c != EOF)) {}
	while (1)
	{
		barcode = 0;
		int local_barcode[4] = { 0 }, i = 0;
		printf("Enter the unique barcode:\n"); // Ввод происходит в виде записи четырёх цифр. Они преобразуются в индекс массива
		while (i < 4)
		{
			local_barcode[i] = getchar();
			if (local_barcode[i] != '0')
			{
				barcode += (local_barcode[i] - '0') * pow(10, abs(i - 3));
			}
			i++;
		}
		//printf("barcode: %d\n", barcode);
		//Проверка на совпадение товара в штрих коде + Проверка на совпадение товара в штрих коде 0000
		if ( (barcodes[barcode] != 0 && barcode != 0) || (barcode == 0 && price[barcode] != 0))
		{
			char c;
			while (((c = getchar()) != '\n' && c != EOF)) {}
		}
		else
			break;
	}
	barcodes[barcode] = barcode;
	printf("Enter the product name:\n");
	scanf("%s", name[barcode]); //scanf_s не работает, требует ещё один параметр
	printf("Enter the cost of the product:\n");
	scanf_s("%d", &price[barcode]);
	printf("Enter the product discount:\n");
	scanf_s("%d", &discount[barcode]);
	printf("The product has been successfully added to the program.\n");
}

scan_and_add_product_in_shop_list()
{
	int barcode = 0;

	char c;
	while (((c = getchar()) != '\n' && c != EOF)) {}

	int local_barcode[4] = { 0 }, i = 0;
	printf("Enter the barcode:\n"); // Ввод происходит в виде записи четырёх цифр. Они преобразуются в индекс массива
	while (i < 4)
	{
		local_barcode[i] = getchar();
		if (local_barcode[i] != '0')
		{
			barcode += (local_barcode[i] - '0') * pow(10, abs(i - 3));
		}
		i++;
	}

	char t;
	while (((t = getchar()) != '\n' && t != EOF)) {}

	if (price[barcode] == 0)
	{
		printf("This product is not available.\n");
	}
	else if (price[barcode] != 0)
	{
		barcodes_in_shop_list[barcode] = barcode;
		number_of_products[barcode] += 1;
		printf("The product was successfully added to the shop list.\n");
	}
}

scan_and_print_product()
{
	int barcode = 0;
	char c;
	while (((c = getchar()) != '\n' && c != EOF)) {}

	int local_barcode[4] = { 0 }, i = 0;
	printf("Enter the barcode:\n"); // Ввод происходит в виде записи четырёх цифр. Они преобразуются в индекс массива
	while (i < 4)
	{
		local_barcode[i] = getchar();
		if (local_barcode[i] != '0')
		{
			barcode += (local_barcode[i] - '0') * pow(10, abs(i - 3));
		}
		i++;
	}

	if (price[barcode] == 0)
	{
		printf("This product is not available.\n");
	}
	else if (price[barcode] != 0)
		print_product(barcode);
}

print_shop_list()
{
	printf("***SHOP LIST***\n");
	int i = 0;
	while (i < 10000)
	{
		if (barcodes_in_shop_list[i] != 0 || (barcodes_in_shop_list[i] == 0 && number_of_products[i] !=0) )
		{
			printf("Name: %s\n", name[i]);
			printf("Price: %d\n", price[i] * number_of_products[i]);
			printf("Count: %d\n", number_of_products[i]);
			printf("Discount: %d\n", discount[i]);
			printf("Price including discount: %.2lf\n", ((double)price[i] - ( (double)price[i] * ( (double)discount[i] / 100.0) )) * (double)number_of_products[i]); // Вычесть из цены скидку.
			printf("===================\n");
		}
		i++;
	}
}

print_result_shop_list()
{
	printf("***RESULT SHOP LIST***\n");
	int i = 0, total_price = 0;
	double total_price_including_discount = 0, total_discount = 0;
	while (i < 10000)
	{
		if (barcodes_in_shop_list[i] != 0 || (barcodes_in_shop_list[i] == 0 && number_of_products[i] != 0))
		{
			printf("Name: %s\n", name[i]);
			printf("Price: %d\n", price[i] * number_of_products[i]);
			printf("Count: %d\n", number_of_products[i]);
			printf("Discount: %d\n", discount[i]);
			printf("Price including discount: %.2lf\n", ((double)price[i] - ((double)price[i] * ((double)discount[i] / 100.0))) * (double)number_of_products[i]); // Вычесть из цены скидку.
			printf("===================\n");
			total_price += (price[i] * number_of_products[i]);
			total_price_including_discount += ((( (double)price[i] - ( (double)price[i] * ( (double)discount[i] / 100.0 ) ) ) ) * (double)number_of_products[i]);
		}
		i++;
	}
	total_discount = ((total_price - total_price_including_discount) * 100.0) / total_price;
	printf("Total price of the product at the time of purchase: %d\n", total_price);
	printf("Total discount: %.2lf\n", total_discount);
	printf("Total price of the product at the time of purchase including discount: %.2lf\n", total_price_including_discount);
}

initial_products()
{
	//strcpy - единственный способ, который нашёл, чтобы передать строку в массив, в котором несколько строк
	strcpy(name[9482], "A bottle of drinking water");
	price[9482] = 54;
	discount[9482] = 12;
	barcodes[9482] = 9482;

	strcpy(name[2945], "Milk chocolate");
	price[2945] = 92;
	discount[2945] = 21;
	barcodes[2945] = 2945;

	strcpy(name[4038], "White bread");
	price[4038] = 47;
	discount[4038] = 3;
	barcodes[4038] = 4098;

	strcpy(name[6721], "Sausage");
	price[6721] = 289;
	discount[6721] = 33;
	barcodes[6721] = 6721;

	strcpy(name[1204], "Tomato sauce");
	price[1204] = 234;
	discount[1204] = 18;
	barcodes[1204] = 1204;
}

void main()
{
	initial_products();

	print_full_list_of_products();

	printf("1.Adding a product description to the program for the duration of its operation.\n");
	printf("2.Scan the product and displaying its description.\n");
	printf("3.Scan the product and add it to the shop list.\n");
	printf("4.Withdrawal of the shop list for the purchase.\n");
	printf("5.Generate a final shop list and choose either to complete the work or start generating a new shop list.\n");

	while (1)
	{
		char i = 0;
		printf("Hello, what do you want to do?\n");
		i = getchar();
		switch (i)
		{
		case '1':
			add_product_in_program();
			break;
		case '2':
			scan_and_print_product();
			break;
		case '3':
			scan_and_add_product_in_shop_list();
			break;
		case '4':
			print_shop_list();
			break;
		case '5':
			print_result_shop_list();
			while (1)
			{
				char l;
				while (((l = getchar()) != '\n' && l != EOF)) {}
				printf("What's next?\n");
				printf("1.Program shutdown.\n");
				printf("2.Start generating a new shop list.\n");
				i = getchar();
				switch (i)
				{
				case '1':
					i = -1;
					break;
				case '2':
					i = -2;
					break;
				default:
					printf("Incorrect input.\n");
					continue;
				}
				if (i == -1 || i == -2)
					break;
			}
			break;
		default:
			printf("Incorrect input.\n");
		}
		char c;
		while (((c = getchar()) != '\n' && c != EOF)) {}
		if (i == -1)
			break;
		if (i == -2)
		{
			int t = 0;
			while (t < 10000)
			{
				if (barcodes[t] != 0 || (barcodes[t] == 0 && price[t] != 0))
				{
					price[t] = 0;
					discount[t] = 0;
					number_of_products[t] = 0;
					barcodes[t] = 0;
					barcodes_in_shop_list[t] = 0;
				}
				t++;
			}
		}
	}
}