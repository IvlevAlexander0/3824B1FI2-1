#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#define _CRT_SECURE_NO_WARNINGS
#define MAX_NAME_LENGTH 50
#define MAX_PEOPLE 50

struct Person {
    char name[MAX_NAME_LENGTH];
    int age;
};

void swap(Person* a, Person* b) {
    Person temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(Person* people, int n, char type, FILE* outputFile) {
    bool swapped;
    clock_t start = clock();

    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - 1 - i; j++) {
            if (type) { // Сортировка по убыванию
                if (people[j].age < people[j + 1].age) {
                    swap(&people[j], &people[j + 1]);
                    swapped = true;
                }
            }
            else { // Сортировка по возрастанию
                if (people[j].age > people[j + 1].age) {
                    swap(&people[j], &people[j + 1]);
                    swapped = true;
                }
            }
        }
        if (!swapped) break;
    }

    double time_taken = ((double)(clock() - start)) / CLOCKS_PER_SEC;
    printf("Bubble Sort Time: %f seconds\n", time_taken);

    // Записываем результат в файл
    fprintf(outputFile, "Bubble Sort Results:\n");
    for (int i = 0; i < n; i++) {
        fprintf(outputFile, "%s %d\n", people[i].name, people[i].age);
    }
}

void shellSort(Person* people, int n, char type, FILE* outputFile) {
    clock_t start = clock();

    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            Person temp = people[i];
            int j;
            for (j = i; j >= gap; j -= gap) {
                if (type) { // Сортировка по убыванию
                    if (people[j - gap].age < temp.age) {
                        people[j] = people[j - gap];
                    }
                    else {
                        break;
                    }
                }
                else { // Сортировка по возрастанию
                    if (people[j - gap].age > temp.age) {
                        people[j] = people[j - gap];
                    }
                    else {
                        break;
                    }
                }
            }
            people[j] = temp;
        }
    }

    double time_taken = ((double)(clock() - start)) / CLOCKS_PER_SEC;
    printf("Shell Sort Time: %f seconds\n", time_taken);

    // Записываем результат в файл
    fprintf(outputFile, "Shell Sort Results:\n");
    for (int i = 0; i < n; i++) {
        fprintf(outputFile, "%s %d\n", people[i].name, people[i].age);
    }
}

void insertionSort(Person* people, int n, char type, FILE* outputFile) {
    clock_t start = clock();

    for (int i = 1; i < n; i++) {
        Person key = people[i];
        int j = i - 1;

        while (j >= 0) {
            if (type) { // Сортировка по убыванию
                if (people[j].age < key.age) {
                    people[j + 1] = people[j];
                    j--;
                }
                else {
                    break;
                }
            }
            else { // Сортировка по возрастанию
                if (people[j].age > key.age) {
                    people[j + 1] = people[j];
                    j--;
                }
                else {
                    break;
                }
            }
        }
        people[j + 1] = key;
    }

    double time_taken = ((double)(clock() - start)) / CLOCKS_PER_SEC;
    printf("Insertion Sort Time: %f seconds\n", time_taken);

    // Записываем результат в файл
    fprintf(outputFile, "Insertion Sort Results:\n");
    for (int i = 0; i < n; i++) {
        fprintf(outputFile, "%s %d\n", people[i].name, people[i].age);
    }
}

void printPeople(Person* people, int n) {
    for (int i = 0; i < n; i++) {
        printf("%s %d\n", people[i].name, people[i].age);
    }
}

int main() {
    Person people[MAX_PEOPLE];
    FILE* inputFile;

    if (fopen_s(&inputFile, "People_in.txt", "r") != 0) {
        printf("Failed to open file.\n");
        return 1;
    }

    int count = 0;
    while (fscanf_s(inputFile, "%s %d", people[count].name, MAX_NAME_LENGTH, &people[count].age) != EOF) {
        count++;
        if (count >= MAX_PEOPLE) break;
    }
    fclose(inputFile);

    FILE* outputFile;
    if (fopen_s(&outputFile, "people_out.txt", "w") != 0) {
        printf("Failed to open output file.\n");
        return 1;
    }

    char flag = 0;
    while (1) {
        printf("\nMENU:\n");
        printf("1. Bubble sort\n");
        printf("2. Shell's sort\n");
        printf("3. Insertion sort\n");
        printf("4. Exit\n");
        printf("Choose option: ");

        char choice;
        if (flag) getchar();
        else flag = 1;

        scanf_s("%c", &choice);

        if (choice == '4') {
            break;
        }

        if (choice < '1' || choice > '4') {
            printf("Uncorrect data! Try again.\n");
            continue;
        }

        Person copy[MAX_PEOPLE];
        memcpy(copy, people, sizeof(people));

        char sort_type;
        while (1) {
            printf("\nChoose type of sort:\n");
            printf("1. Ascending\n");
            printf("2. Descending\n");
            getchar();
            scanf_s("%c", &sort_type);

            if (sort_type < '1' || sort_type > '2') {
                printf("Uncorrect data! Try again.\n");
                continue;
            }
            else {
                break;
            }
        }

        if (choice == '1') {
            bubbleSort(copy, count, sort_type == '2', outputFile);
        }
        else if (choice == '2') {
            shellSort(copy, count, sort_type == '2', outputFile);
        }
        else if (choice == '3') {
            insertionSort(copy, count, sort_type == '2', outputFile);
        }

        printf("\nSorted results:\n");
        printPeople(copy, count);
    }

    fclose(outputFile);
    printf("Goodbye!\n");
    return 0;
}