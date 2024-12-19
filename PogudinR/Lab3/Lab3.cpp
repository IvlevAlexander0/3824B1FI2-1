#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Функция для проверки ввода и очистки буфера
void check() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Функция для проверки уникальности цифр числа загаданного компьютером
int isUnique(int number[], int index, int digit) {
    for (int i = 0; i < index; i++) {
        if (number[i] == digit) {
            return 0;
        }
    }
    return 1;
}

// Функция для проверки уникальности цифр числа
int hasUniqueDigits(int number) {
    int digits[10] = { 0 };

    // Проверяем каждую цифру числа
    while (number > 0) {
        int digit = number % 10;  
        if (digits[digit]) {
            return 0;  // Если цифра уже встречалась, значит не уникальна
        }
        digits[digit] = 1;
        number /= 10;
    }
    return 1;  // Все цифры уникальны
}

// Функция для генерации числа длины lenght
void generate(int number[], int lenght) {
    int i = 0;
    while (i < lenght) {
        int digit = rand() % 10;
        if (isUnique(number, i, digit)) {
            number[i] = digit;
            i++;
        }
    }
}

// Функция для подсчета быков и коров
void countBullsAndCows(int secret[], int guess[], int lenght, int* bulls, int* cows) {
    *bulls = 0;
    *cows = 0;
    int secretDigits[10] = { 0 }; // Для учёта цифр в загаданном числе
    int guessDigits[10] = { 0 };  // Для учёта цифр в вводимом числе

    // Считаем быков
    for (int i = 0; i < lenght; i++) {
        if (secret[i] == guess[i]) {
            (*bulls)++;
        }
        else {
            secretDigits[secret[i]]++;
            guessDigits[guess[i]]++;
        }
    }

    //Альтернативный способ счета коров
//    for (int i = 0; i < 10; i++) {
//        if (secretDigits[i] < guessDigits[i]) {
//            *cows += secretDigits[i];
//        }
//        else {
//            *cows += guessDigits[i];
//        }
//    }
//}

    // Считаем коров
    for (int i = 0; i < 10; i++) {
        *cows += (secretDigits[i] < (guessDigits[i]) ? secretDigits[i] : guessDigits[i]); // Сокращённый способ записи условного оператора if (условие ? выражение1 : выражение2;) 
    }
}

// Функция для степени десятки в диапазоне вводимых пользователем чисел через параметр lenght
int powerOf10(int exponent) {
    int result = 1;
    for (int i = 0; i < exponent; i++) {
        result *= 10;
    }
    return result;
}

int main() {
    int lenght;
    printf("Input lenght of number (from 2 to 5): ");
    while (scanf_s("%d", &lenght) != 1 || lenght < 2 || lenght > 5) {
        printf("Error. Input correct lenght of number (from 2 to 5): ");
        check();
    }

    int secretnumber[5];
    srand((unsigned int)time(NULL));
    generate(secretnumber, lenght);

    int yournumber;
    printf("Input your %d-digit number: ", lenght);
    while (scanf_s("%d", &yournumber) != 1 || yournumber < powerOf10(lenght - 1) || yournumber >= powerOf10(lenght) || !hasUniqueDigits(yournumber)) {
        printf("The number contains duplicate digits or lenght of number is incorrect. Input correct number: ");
        check();
    }

    // Цикл для угадывания числа
    do {
        int guess[5] = { 0 };
        for (int i = lenght - 1; i >= 0; i--) {
            guess[i] = yournumber % 10;
            yournumber /= 10;
        }

        int bulls = 0, cows = 0;
        countBullsAndCows(secretnumber, guess, lenght, &bulls, &cows);

        printf("Bulls: %d, Cows: %d\n", bulls, cows);

        // Проверяем, угадано ли число
        if (bulls == lenght) {
            printf("Congratulations! You've guessed the number!\n");
            break;
        }

        printf("Input your %d-digit number: ", lenght);
        while (scanf_s("%d", &yournumber) != 1 || yournumber < powerOf10(lenght - 1) || yournumber >= powerOf10(lenght) || !hasUniqueDigits(yournumber)) {
            printf("The number contains duplicate digits or lenght of number is incorrect. Input correct number: ");
            check();
        }

    } while (1); // Бесконечный цикл, пока не будет угадано число

    return 0;
}