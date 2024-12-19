#include <stdio.h>
#define MAX 120

int code[MAX][4] = { {0,0,0,1},{0,0,0,2},{0,0,0,3},{0,0,0,4}, { 0,0,0,5 } };
char name[MAX][20] = { "bread","milk","sugar","tea","coffee" };
int price[MAX] = { 20,60,15,10,70 };
int discount[MAX] = { 5,10, 3, 2, 15 };
int id = 5;

//vvod shtrix-koda
void inputBarcode(int* barcode, int size) {
    int flag = 0;
    int dlina = 0;
    char c;
    do {
        printf("Barcode: ");
        flag = 0;
        dlina = 0;

        for (int i = 0; i < size; ++i) {
            c = getchar();


            if (c == '\n') {
                if (dlina != size) {
                    printf("Error. Please enter a valid 4-digit barcode\n");

                    for (int j = 0; j < size; j++) {
                        barcode[j] = 0;
                    }
                    dlina = 0;
                    flag = 1;
                    break;
                }
                break;
            }


            if (c < '0' || c > '9') {
                printf("Error. Not a digit\n");
                for (size_t i = 0; i < size; ++i) {
                    barcode[i] = 0;
                }
                flag = 1;
                dlina = 0;
                while (getchar() != '\n') {}
                break;
            }


            barcode[i] = c - '0';
            dlina++;
        }





    } while (flag != 0);
}

int main() {
    int mode;
    int code2[4] = { 0 };
    int metca = 0;
    int count[MAX] = { 0 };

    while (1) {
        double sum_plata = 0.0, sum_d = 0.0, plata = 0.0;
        printf("\nSelect a mode\n");
        printf("1 - add a product description\n");
        printf("2 - display the product description\n");
        printf("3 - adding a product to a receipt\n");
        printf("4 - initial receipt\n");
        printf("5 - final receipt and either complete the work, or start generating a new receipt\n");
        int flag;
        int c;
        do {
            flag = 0;
            int r = scanf_s("%d", &mode);
            if (r != 1 || (mode < 1 || mode > 5)) {
                printf("Error. PLease enter the correct values\n");
                flag = 1;
            }
            while ((c = getchar()) != '\n' && c != EOF) {}
        } while (flag != 0);

        switch (mode) {
        case 1:
            printf("Get ready to enter the barcode of the product\n");
            printf("\nAttention!!! If you enter a barcode of a longer length (5 or more digits), the program will process only the first 4 digits (because the barcode consists of 4 digits)\n");

            printf("Please, enter the barcode of the product. You need  to enter 4 digits\n");

            inputBarcode(code[id], 4);

            printf("\nPlease, enter the name of the product you want to add: ");
            scanf_s("%s", name[id], sizeof(name[id]));


            do {
                printf("\nPlease, enter the price of the product: ");
                flag = 0;
                int r = scanf_s("%d", &price[id]);
                if (r != 1 || price[id] <= 0) {
                    printf("Error. Please enter a valid correct price\n");
                    flag = 1;
                }
                while (getchar() != '\n');
            } while (flag != 0);

            do {
                printf("\nPlease enter the discount value from 1 to 50%% of the value of the product: ");
                flag = 0;
                int r = scanf_s("%d", &discount[id]);
                if (r != 1 || (discount[id] < 1 || discount[id] > 50)) {
                    printf("Error. Please enter a valid discount between 1 and 50%%\n");
                    flag = 1;
                }
                while (getchar() != '\n');
            } while (flag != 0);

            id++;
            break;

        case 2:
            printf("Please enter the barcode of the product\n");
            printf("\nAttention!!! If you enter a barcode of a longer length (5 or more digits), the program will process only the first 4 digits (because the barcode consists of 4 digits)\n");
            printf("\nProducts that are initially available:\n");
            printf("0001 - bread, 0002 - milk, 0003 - sugar, 0004 - tea, 0005 - coffee\n");

            inputBarcode(code2, 4);

            for (size_t i = 0; i < id; i++) {
                if (code[i][0] == code2[0] && code[i][1] == code2[1] &&
                    code[i][2] == code2[2] && code[i][3] == code2[3]) {
                    printf("Product: %s, Price: %d, Discount: %d\n", name[i], price[i], discount[i]);
                    metca = 0;
                    break;
                }
                else {
                    metca = 1;
                }
            }
            if (metca == 1) {
                printf("Error. Product not found. Please enter the correct barcode\n");
            }
            break;

        case 3:
            printf("Please enter the barcode of the product you want to add to the receipt\n");
            printf("\nAttention!!! If you enter a barcode of a longer length (5 or more digits),"
                "the program will process only the first 4 digits (because the barcode consists of 4 digits).\n");
            printf("\nProducts that are initially available:\n");
            printf("0001 - bread, 0002 - milk, 0003 - sugar, 0004 - tea, 0005 - coffee\n");


            inputBarcode(code2, 4);

            for (size_t i = 0; i < id; ++i) {
                if (code[i][0] == code2[0] && code[i][1] == code2[1] && code[i][2] == code2[2] && code[i][3] == code2[3]) {
                    printf("The product %s was added to the receipt\n", name[i]);
                    count[i]++;
                    metca = 0;
                    break;
                }
                else {
                    metca = 1;
                }
            }
            if (metca == 1) {
                printf("Error. Product not found. Please enter the correct barcode\n");
            }
            break;

        case 4:
            printf("Receipt\n");
            for (size_t i = 0; i < id; i++) {
                if (count[i] > 0) {
                    double cena1 = count[i] * (double)price[i];
                    double scidka = cena1 * discount[i] / 100.0;
                    double cena2 = cena1 - scidka;
                    sum_plata += cena1;
                    sum_d += scidka;
                    plata += cena2;
                    printf("Product: %s -- price per unit: %.2lf -- quantity: %d -- the total cost of the product, including the discount: %.2lf\n", name[i], (double)price[i], count[i], cena2);
                }
            }
            break;

        case 5:
            printf("Final receipt\n");
            for (size_t i = 0; i < id; i++) {
                if (count[i] > 0) {
                    double cena1 = count[i] * (double)price[i];
                    double scidka = (double)cena1 * (double)discount[i] / 100.0;
                    double cena2 = cena1 - scidka;
                    sum_plata += cena1;
                    sum_d += scidka;
                    plata += cena2;
                }
            }
            printf("The total cost of the goods in the purchase: %.2lf -- total discount: %.2lf -- the total amount: %.2lf\n", sum_plata, sum_d, plata);

            int vibor;
            printf("\nPlease make a choice:");
            printf("\n1 - shut down the program\n");
            printf("2 - reset the first receipt and start forming a new one\n");

            int flg;
            int e;
            do {
                printf("\nChoice:");
                flg = 0;
                int r = scanf_s("%d", &vibor);
                if (r != 1 || (vibor < 1 || vibor>2)) {
                    printf("Error. PLease enter the correct values\n");
                    flg = 1;
                }
                while ((e = getchar()) != '\n' && e != EOF) {}
            } while (flg != 0);

            if (vibor == 1) {
                printf("Come back again. Have a nice day!\n");
                return;
            }
            else {
                sum_plata = 0;
                sum_d = 0;
                plata = 0;
                for (size_t i = 0; i < MAX; ++i) {
                    count[i] = 0;
                }

                id = 5;
                for (size_t i = 5; i < MAX; ++i) {
                    for (size_t j = 0; j < 4; ++j) {
                        code[i][j] = 0;
                    }
                    name[i][0] = '\0';
                    price[i] = 0;
                    discount[i] = 0;
                }
            }
            printf("Starting a new receipt...\n");
            break;
        }
    }

    return 0;
}