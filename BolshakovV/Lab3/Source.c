#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    srand(time(NULL));
    //проверка на корректность ввода длины
    int l;
    printf("Please choose the length of the number [2-5]\n");
    int flag;
    int c;
    do {
        flag = 0;
        int r = scanf_s("%d", &l);
        if (r != 1 || (l < 2 || l>5)) {
            printf("Error. PLease enter the correct values\n");
            flag = 1;
        }
        while ((c = getchar()) != '\n' && c != EOF)
        {
        }
    } while (flag != 0);

    //генерация числа
    int zifr[5] = { 0 };
    int k = 0;
    int flag1;
    for (int i = 0; i < l; i++) {
        int a;
        do {
            flag1 = 0;
            a = rand() % 10;
            for (int j = 0; j < k; j++) {
                if (zifr[j] == a) {
                    flag1 = 1;
                }
            }

        } while (flag1 != 0 || (k == 0 && a == 0));
        zifr[k] = a;
        k++;
    }
    //вывод созданного числа (для пользователя не нужно)
    for (int i = 0; i < l; i++) {
        printf("%d", zifr[i]);
    }

    printf("\nPlease enter a number of the selected length with non-repeating digits\n");
    printf("First number is the number of <bulls> (the number of digits guessed both by value and position in the number)\n");
    printf("The second number is the number of cows (the number matched in value, but not in position\n");

    if (l == 2) {
        while (1) {
            int flag;
            int chislo;
            int c;
            do {
                flag = 0;
                int r = scanf_s("%d", &chislo);

                int mass[2] = { 0 };
                mass[0] = chislo / 10;
                mass[1] = chislo % 10;
                if (r != 1 || (mass[0] == mass[1])) {
                    printf("Error. Please enter the correct values\n");
                    flag = 1;
                }
                while ((c = getchar()) != '\n' && c != EOF)
                {
                }

            } while (flag != 0);
            //printf("%d\n", chislo);
            int mass[2] = { 0 };
            mass[0] = chislo / 10;
            mass[1] = chislo % 10;
            int cows = 0;
            int bulls = 0;

            for (int i = 0; i < l; i++) {
                for (int j = 0; j < l; j++) {
                    if (zifr[j] == mass[i]) {
                        if (i == j) {
                            bulls++;
                        }
                        else {
                            cows++;
                        }
                    }
                }
            }
            printf("%d %d\n", bulls, cows);
            if (bulls == 2) {
                printf("\nWin!!!\n");
                break;
            }

        }
    }
    if (l == 3) {
        while (1) {
            int flag;
            int chislo;
            int c;
            do {
                flag = 0;
                int r = scanf_s("%d", &chislo);

                int mass[3] = { 0 };
                mass[0] = chislo / 100;
                mass[1] = (chislo / 10) % 10;
                mass[2] = chislo % 10;
                if (r != 1 || (mass[0] == mass[1] || mass[0] == mass[2] || mass[1] == mass[2])) {
                    printf("Error. Please enter the correct values\n");
                    flag = 1;
                }
                while ((c = getchar()) != '\n' && c != EOF)
                {
                }

            } while (flag != 0);
            //printf("%d\n", chislo);
            int mass[3] = { 0 };
            mass[0] = chislo / 100;
            mass[1] = (chislo / 10) % 10;
            mass[2] = chislo % 10;

            int cows = 0;
            int bulls = 0;
            for (int i = 0; i < l; i++) {
                for (int j = 0; j < l; j++) {
                    if (zifr[j] == mass[i]) {
                        if (i == j) {
                            bulls++;
                        }
                        else {
                            cows++;
                        }
                    }
                }
            }
            printf("%d %d\n", bulls, cows);
            if (bulls == 3) {
                printf("\nWin!!!\n");
                break;

            }

        }
    }
    if (l == 4) {
        while (1) {
            int flag;
            int chislo;
            int c;
            do {
                flag = 0;
                int r = scanf_s("%d", &chislo);

                int mass[4] = { 0 };
                mass[0] = chislo / 1000;
                mass[1] = (chislo / 100) % 10;
                mass[2] = (chislo / 10) % 10;
                mass[3] = (chislo % 10);
                if (r != 1 || (mass[0] == mass[1] || mass[0] == mass[2] || mass[0] == mass[3] || mass[1] == mass[2] || mass[1] == mass[3] || mass[2] == mass[3])) {
                    printf("Error. Please enter the correct values\n");
                    flag = 1;
                }
                while ((c = getchar()) != '\n' && c != EOF)
                {
                }

            } while (flag != 0);
            //printf("%d\n", chislo);
            int mass[4] = { 0 };
            mass[0] = chislo / 1000;
            mass[1] = (chislo / 100) % 10;
            mass[2] = (chislo / 10) % 10;
            mass[3] = (chislo % 10);

            int cows = 0;
            int bulls = 0;
            for (int i = 0; i < l; i++) {
                for (int j = 0; j < l; j++) {
                    if (zifr[j] == mass[i]) {
                        if (i == j) {
                            bulls++;
                        }
                        else {
                            cows++;
                        }
                    }
                }
            }
            printf("%d %d\n", bulls, cows);
            if (bulls == 4) {
                printf("\nWin!!!\n");
                break;

            }

        }
    }
    if (l == 5) {
        while (1) {
            int flag;
            int chislo;
            int c;
            do {
                flag = 0;
                int r = scanf_s("%d", &chislo);

                int mass[5] = { 0 };
                mass[0] = chislo / 10000;
                mass[1] = (chislo / 1000) % 10;
                mass[2] = (chislo / 100) % 10;
                mass[3] = (chislo / 10) % 10;
                mass[4] = (chislo % 10);
                if (r != 1 || (mass[0] == mass[1] || mass[0] == mass[2] || mass[0] == mass[3] || mass[0] == mass[4])
                    || (mass[1] == mass[2] || mass[1] == mass[3] || mass[1] == mass[4] || mass[2] == mass[3] || mass[2] == mass[4] || mass[3] == mass[4])) {
                    printf("Error. Please enter the correct values\n");
                    flag = 1;
                }
                while ((c = getchar()) != '\n' && c != EOF)
                {
                }

            } while (flag != 0);
            //printf("%d\n", chislo);
            int mass[5] = { 0 };

            mass[0] = chislo / 10000;
            mass[1] = (chislo / 1000) % 10;
            mass[2] = (chislo / 100) % 10;
            mass[3] = (chislo / 10) % 10;
            mass[4] = (chislo % 10);
            int cows = 0;
            int bulls = 0;
            for (int i = 0; i < l; i++) {
                for (int j = 0; j < l; j++) {
                    if (zifr[j] == mass[i]) {
                        if (i == j) {
                            bulls++;
                        }
                        else {
                            cows++;
                        }
                    }
                }
            }
            printf("%d %d\n", bulls, cows);
            if (bulls == 5) {
                printf("\nWin!!!\n");
                break;

            }

        }
    }

    return 0;
}