#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mode_1(); //Прототип функции для 1 режима
void mode_2(); //Прототип функции для 2 режима

int main() {
    int choice;
    printf("Choose a game mode:\n");
    printf("1. The program guesses a number, and you try to guess it.\n");
    printf("2. You think of a number, and the program tries to guess it.\n");
    printf("Enter 1 or 2: ");
    scanf_s("%d", &choice);

    switch (choice) {
    case 1:
        mode_1();
        break;
    case 2:
        mode_2();
        break;
    default:
        printf("Invalid choice. Please restart the program and choose either 1 or 2.\n");
    }

    return 0;
}

void mode_1() {
    int secret_number, guess, attempts = 0;

    srand((unsigned int)time(0));  //Рандомайзер
    secret_number = rand() % 1000 + 1; //Рандомное число от 1 до 1000

    printf("The program has selected a number between 1 and 1000. Try to guess it!\n");

    do {
        printf("Enter your guess: ");
        scanf_s("%d", &guess);
        attempts++;

        if (guess < secret_number) {
            printf("The secret number is higher.\n");
        }
        else if (guess > secret_number) {
            printf("The secret number is lower.\n");
        }
        else {
            printf("Congratulations! You guessed the number in %d attempts.\n", attempts);
        }
    } while (guess != secret_number);
}

void mode_2() {
    int low = 1, high = 1000, mid, attempts = 0;
    char response;

    printf("Think of a number between 1 and 1000 and keep it in your mind.\n");

    do {
        mid = (low + high) / 2;
        printf("The program guesses: %d. Is your number >, <, or =? ", mid);
        scanf_s(" %c", &response, 1);

        attempts++;

        if (response == '>') {
            low = mid + 1;
        }
        else if (response == '<') {
            high = mid - 1;
        }
        else if (response == '=') {
            printf("The program guessed your number in %d attempts!\n", attempts);
        }
    } while (response != '=');
}