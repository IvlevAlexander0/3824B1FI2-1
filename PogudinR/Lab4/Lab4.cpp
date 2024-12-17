#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTS 100

// Структура для описания товара
typedef struct {
    char barcode[5]; // Штрих-код (4 символа + '\0')
    char name[50];   // Наименование товара
    int price;       // Стоимость за единицу
    int discount;    // Скидка в процентах (1-50)
    int quantity;    // Количество товара
} Product;

// Структура для чека
typedef struct {
    Product items[MAX_PRODUCTS];
    int count;       // Количество различных товаров в чеке
} Receipt;

// Функция для ввода товара
Product scan_product() {
    Product p;

    printf("Enter the product barcode (4 digits): ");
    scanf("%4s", p.barcode);

    printf("Enter the product name: ");
    scanf(" %[^\n]s", p.name); // Считываем строку с пробелами

    printf("Enter the product price (rubles): ");
    scanf("%d", &p.price);

    do {
        printf("Enter the product discount (1-50%%): ");
        scanf("%d", &p.discount);
        if (p.discount < 1 || p.discount > 50)
            printf("Error! The discount must be between 1 and 50%%.\n");
    } while (p.discount < 1 || p.discount > 50);

    printf("Enter the product quantity: ");
    scanf("%d", &p.quantity);

    return p;
}

// Функция для вывода информации о товаре
void print_product(Product p) {
    printf("Barcode: %s | Name: %s | Price: %d rub. | Discount: %d%% | Quantity: %d\n",
        p.barcode, p.name, p.price, p.discount, p.quantity);
}

// Функция для добавления товара в чек
void add_to_receipt(Receipt* receipt, Product p) {
    // Проверяем, не добавляли ли мы этот товар ранее
    for (int i = 0; i < receipt->count; i++) {
        if (strcmp(receipt->items[i].barcode, p.barcode) == 0) {
            // Товар уже есть, обновляем количество
            receipt->items[i].quantity += p.quantity;
            printf("The quantity of product \"%s\" has been updated to %d.\n", p.name, receipt->items[i].quantity);
            return;
        }
    }

    // Добавляем новый товар в чек
    if (receipt->count < MAX_PRODUCTS) {
        receipt->items[receipt->count++] = p;
        printf("Product \"%s\" has been added to the receipt.\n", p.name);
    }
    else {
        printf("Error! No more products can be added to the receipt.\n");
    }
}

// Функция для формирования и вывода чека
void print_receipt(Receipt receipt) {
    int total = 0, total_discount = 0;

    printf("\n========== RECEIPT ==========\n");
    printf("Num  Name   Price  Qty   Discount  Cost\n");
    printf("---------------------------------------------------\n");

    for (int i = 0; i < receipt.count; i++) {
        Product p = receipt.items[i];
        int cost_without_discount = p.price * p.quantity;
        int discount_amount = cost_without_discount * p.discount / 100;
        int cost_with_discount = cost_without_discount - discount_amount;

        printf("%-3d %-7s %-6d %-5d %-8d%% %-7d rub.\n", i + 1, p.name, p.price,
            p.quantity, p.discount, cost_with_discount);

        total += cost_with_discount;
        total_discount += discount_amount;
    }

    printf("---------------------------------------------------\n");
    printf("Total discount: %d rub.\n", total_discount);
    printf("Final amount to pay: %d rub.\n", total);
    printf("=============================\n");
}

// Главная функция
int main() {
    Receipt receipt = { {0}, 0 }; // Инициализация чека
    Product current_product;    // Текущий отсканированный товар
    int choice;

    do {
        printf("\nSelect an operation:\n");
        printf("1. Scan a product\n");
        printf("2. Display product information\n");
        printf("3. Add product to receipt\n");
        printf("4. Generate receipt\n");
        printf("5. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            current_product = scan_product();
            printf("Product scanned!\n");
            break;
        case 2:
            printf("Product information:\n");
            print_product(current_product);
            break;
        case 3:
            add_to_receipt(&receipt, current_product);
            break;
        case 4:
            print_receipt(receipt);
            break;
        case 5:
            printf("Exiting the program. Thank you!\n");
            break;
        default:
            printf("Error! Please enter a valid operation number.\n");
            break;
        }
    } while (choice != 5);

    return 0;
}