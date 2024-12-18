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

// Предустановленный список товаров
Product product_list[MAX_PRODUCTS] = {
    {"1001", "Milk", 50, 10, 0},
    {"1002", "Bread", 30, 5, 0},
    {"1003", "Butter", 150, 15, 0},
    {"1004", "Cheese", 200, 20, 0},
    {"1005", "Eggs", 70, 0, 0}
};
int product_count = 5; // Количество товаров в памяти

// Функция для поиска товара по штрих-коду
Product* find_product(const char* barcode) {
    for (int i = 0; i < product_count; i++) {
        if (strcmp(product_list[i].barcode, barcode) == 0) {
            return &product_list[i];
        }
    }
    return NULL; // Если товар не найден
}

// Функция для добавления нового товара
void add_product() {
    if (product_count >= MAX_PRODUCTS) {
        printf("Error! No more products can be added.\n");
        return;
    }

    Product p;
    printf("Enter the product barcode (4 digits): ");
    scanf("%4s", p.barcode);

    if (find_product(p.barcode)) {
        printf("Error! A product with this barcode already exists.\n");
        return;
    }

    printf("Enter the product name: ");
    scanf(" %[^\n]", p.name);

    printf("Enter the product price (rubles): ");
    scanf("%d", &p.price);

    do {
        printf("Enter the product discount (1-50%%): ");
        if (scanf("%d", &p.discount) != 1) {
            while (getchar() != '\n'); // Очистка буфера
            printf("Invalid input. Please enter a valid discount.\n");
            continue;
        }
        if (p.discount < 1 || p.discount > 50)
            printf("Error! The discount must be between 1 and 50%%.\n");
    } while (p.discount < 1 || p.discount > 50);

    p.quantity = 0; // Изначально количество равно 0

    product_list[product_count++] = p;
    printf("Product \"%s\" has been added successfully.\n", p.name);
}

// Функция для вывода информации о товаре
void print_product(Product p) {
    printf("Barcode: %s | Name: %s | Price: %d rub. | Discount: %d%% | Quantity: %d\n",
        p.barcode, p.name, p.price, p.discount, p.quantity);
}

// Функция для добавления товара в чек
void add_to_receipt(Receipt* receipt, const char* barcode, int quantity) {
    Product* p = find_product(barcode);

    if (!p) {
        printf("Error! Product with barcode %s not found.\n", barcode);
        return;
    }

    if (quantity <= 0) {
        printf("Error! Quantity must be greater than zero.\n");
        return;
    }

    for (int i = 0; i < receipt->count; i++) {
        if (strcmp(receipt->items[i].barcode, barcode) == 0) {
            receipt->items[i].quantity += quantity;
            printf("The quantity of product \"%s\" has been updated to %d.\n",
                p->name, receipt->items[i].quantity);
            return;
        }
    }

    if (receipt->count < MAX_PRODUCTS) {
        receipt->items[receipt->count] = *p;
        receipt->items[receipt->count].quantity = quantity;
        receipt->count++;
        printf("Product \"%s\" has been added to the receipt.\n", p->name);
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
    int choice;

    do {
        printf("\nSelect an operation:\n");
        printf("1. Add a new product\n");
        printf("2. Display all products\n");
        printf("3. Add product to receipt\n");
        printf("4. Generate receipt\n");
        printf("5. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_product();
            break;
        case 2:
            printf("\nAvailable products:\n");
            for (int i = 0; i < product_count; i++) {
                print_product(product_list[i]);
            }
            break;
        case 3: {
            char barcode[5];
            int quantity;
            printf("Enter the product barcode: ");
            scanf("%4s", barcode);
            printf("Enter the quantity: ");
            scanf("%d", &quantity);
            add_to_receipt(&receipt, barcode, quantity);
            break;
        }
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
