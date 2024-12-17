#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PEOPLE 50
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    int age;
} Person;

// Функция для чтения данных из файла
int read_file(const char* filename, Person people[]) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return -1;
    }

    int count = 0;
    while (fscanf(file, "%s %d", people[count].name, &people[count].age) == 2) {
        count++;
        if (count >= MAX_PEOPLE) break;
    }

    fclose(file);
    return count;
}

// Функция для записи данных в файл
void write_file(const char* filename, Person people[], int count) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        perror("Error opening file");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%s %d\n", people[i].name, people[i].age);
    }

    fclose(file);
}

// Сортировка вставками
void insertion_sort(Person people[], int count, int ascending) {
    for (int i = 1; i < count; i++) {
        Person key = people[i];
        int j = i - 1;
        while (j >= 0 && ((ascending && people[j].age > key.age) || (!ascending && people[j].age < key.age))) {
            people[j + 1] = people[j];
            j--;
        }
        people[j + 1] = key;
    }
}

// Сортировка "расческой"
void comb_sort(Person people[], int count, int ascending) {
    int gap = count;
    int swapped = 1;
    while (gap > 1 || swapped) {
        gap = (gap * 10) / 13;
        if (gap < 1) gap = 1;

        swapped = 0;
        for (int i = 0; i + gap < count; i++) {
            if ((ascending && people[i].age > people[i + gap].age) || (!ascending && people[i].age < people[i + gap].age)) {
                Person temp = people[i];
                people[i] = people[i + gap];
                people[i + gap] = temp;
                swapped = 1;
            }
        }
    }
}

// Пузырьковая сортировка
void bubble_sort(Person people[], int count, int ascending) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if ((ascending && people[j].age > people[j + 1].age) || (!ascending && people[j].age < people[j + 1].age)) {
                Person temp = people[j];
                people[j] = people[j + 1];
                people[j + 1] = temp;
            }
        }
    }
}

int main() {
    // Объявление массива структур "people", который будет хранить данные о людях
    Person people[MAX_PEOPLE];
    int count;
    char input_file[] = "People_in.txt";
    char output_file[] = "People_out.txt";
    count = read_file(input_file, people);
    // Если чтение данных прошло с ошибкой (например, файл не найден), завершить программу
    if (count < 0) return 1;

    // Переменные для выбора метода сортировки и порядка сортировки
    int choice;
    int ascending;

    // Переменные для измерения времени сортировки
    clock_t start, end;

    while (1) {
        // Предложение пользователю выбрать метод сортировки
        printf("Choose sorting method:\n");
        printf("1. Insertion Sort\n");
        printf("2. Comb Sort\n");
        printf("3. Bubble Sort\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 4) break;

        // Предложение выбрать порядок сортировки (по возрастанию или по убыванию)
        printf("Choose order:\n");
        printf("1. Ascending\n");
        printf("2. Descending\n");
        printf("Enter your choice: ");
        scanf("%d", &ascending);

        // Перевод введенного выбора в булево значение: 1 для ascending = true, 0 для false
        ascending = (ascending == 1);

        // Засекаем время начала сортировки
        start = clock();

        switch (choice) {
        case 1:
            insertion_sort(people, count, ascending);
            break;
        case 2:
            comb_sort(people, count, ascending);
            break;
        case 3:
            bubble_sort(people, count, ascending);
            break;
        default:
            printf("Invalid choice. Try again.\n");
            continue;
        }

        // Засекаем время окончания сортировки
        end = clock();

        printf("Sorted list:\n");
        for (int i = 0; i < count; i++) {
            // Печать каждого человека (имя и возраст)
            printf("%s %d\n", people[i].name, people[i].age);
        }

        // Вывод времени, затраченного на сортировку
        printf("Sorting time: %.2f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

        // Запись отсортированных данных в файл
        write_file(output_file, people, count);
        printf("Results saved to %s\n", output_file);
    }
    return 0;
}