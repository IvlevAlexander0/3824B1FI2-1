#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    //выбор длины числа
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
    printf("First number is the number of <bulls> (the number of digits guessed both by value and position in the number\n");
    printf("The second number is the number of cows (the number matched in value, but not in position)\n\n");
    printf("Attention! If you enter a longer number, the program will only work with the first l characters!!!!\n");

    while (1) {
        int A[10] = { 0 };
        int k = 0;
        int flag2 = 0;
        int dlina = 0;

        do {
            flag2 = 0;
            k = 0;
            int dlina = 0;
            int m;

            for (int i = 0; i < l; i++) {

                char c;
                c = getchar();
                if (c == '\n') {
                    if (dlina != l) {
                        printf("Error: Number must be exactly %d digits long\n", l);
                        for (int i = 0; i < 10; i++) {
                            A[i] = 0;
                        }
                        k = 0;
                        dlina = 0;
                        break;
                    }
                    break;
                }

                if (c < '0' || c>'9') {
                    printf("Error. Not a digit\n");
                    flag2 = 1;
                    break;
                }
                if (i == 0 && c == '0') {
                    printf("The first digit cannot be 0\n");
                    flag2 = 1;
                    break;
                }
                int digit = c - '0';
                if (A[digit] == 1) {
                    printf("Digits must not repeat\n");
                    flag2 = 1;
                    break;
                }

                A[digit] = 1;
                k = k * 10 + (c - '0');
                dlina++;
            }
            if (flag2 == 1) {
                for (int i = 0; i < 10; i++) {
                    A[i] = 0;
                }
            }
            while ((m = getchar()) != '\n' && m != EOF) {
            }
        } while (flag2 != 0);
        //перевод k в массив
        int mass[5];
        int index = 0;
        while (k > 0) {
            mass[index] = k % 10;
            k /= 10;
            index++;
        }
        for (size_t j = 0; j < index / 2; j++) {
            int h = mass[j];
            mass[j] = mass[index - 1 - j];
            mass[index - 1 - j] = h;
        }
        //подсчет быков и коров
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
        if (bulls == l) {
            printf("\nWin!!!\n");
            break;

        }
    }
    return 0;
}