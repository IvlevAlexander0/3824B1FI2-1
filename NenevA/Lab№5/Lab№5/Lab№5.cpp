#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PEOPLE 1100

//Временные затраты видны только на файле people_in_test

void bubble_sort(char** names, int ages[], int Max_length, int count, int order) {
    clock_t fTimeStart, fTimeStop;
    fTimeStart = clock() * 1000 / CLOCKS_PER_SEC;
    char* temp_name = (char*)malloc(Max_length * sizeof(char));
    int flg = 1;
    for (int j = 0; j < count; j++) {
        flg = 0;
        for (int i = 0; i < count - 1; i++) {
            if ((order && ages[i] > ages[i + 1]) || (order == 0 && ages[i] < ages[i + 1])) {
                int temp_age = ages[i];
                ages[i] = ages[i + 1];
                ages[i + 1] = temp_age;

                if (temp_name != NULL) {
                    strcpy(temp_name, names[i]);
                    strcpy(names[i], names[i + 1]);
                    strcpy(names[i + 1], temp_name);

                    flg = 1;
                }
            }
        }
        if (flg == 0) {
            break;
        }
    }
    fTimeStop = clock() * 1000 / CLOCKS_PER_SEC;
    for (int i = 0; i < count; i++) {
        printf("%s %d\n", names[i], ages[i]);
    }
    printf("\nSorting time is %i(ms)\n", fTimeStop - fTimeStart);
    free(temp_name);
}

void insert_sort(char** names, int ages[], int Max_length, int count, int order) {
    clock_t fTimeStart, fTimeStop;
    fTimeStart = clock() * 1000 / CLOCKS_PER_SEC;
    char* curr_name = (char*)malloc(Max_length * sizeof(char));
    for (int i = 1; i < count; i++) {
        int curr_age = ages[i];
        if (curr_name != NULL) {
            strcpy(curr_name, names[i]);
        }

        int j = i - 1;
        if (order) {
            while (j >= 0 && ages[j] > curr_age) {
                ages[j + 1] = ages[j];
                strcpy(names[j + 1], names[j]);
                j--;
            }
        }
        else {
            while (j >= 0 && ages[j] < curr_age) {
                ages[j + 1] = ages[j];
                strcpy(names[j + 1], names[j]);
                j--;
            }
        }
        ages[j + 1] = curr_age;
        if (curr_name != NULL) {
            strcpy(names[j + 1], curr_name);
        }
    }
    fTimeStop = clock() * 1000 / CLOCKS_PER_SEC;
    for (int i = 0; i < count; i++) {
        printf("%s %d\n", names[i], ages[i]);
    }
    printf("\nSorting time is %i(ms)\n", fTimeStop - fTimeStart);
    free(curr_name);
}

void comb_sort(char** names, int ages[], int Max_length, int count, int order) {
    int step = count;
    int swapped = 1;
    clock_t fTimeStart, fTimeStop;
    fTimeStart = clock() * 1000 / CLOCKS_PER_SEC;
    char* name = (char*)malloc(Max_length * sizeof(char));
    while (step != 1 || swapped) {
        if (step > 1) {
            step = (step * 10) / 13;
        }
        swapped = 0;
        for (int i = 0; i < count - step; i++) {
            if ((order && ages[i] > ages[i + step]) || (!order && ages[i] < ages[i + step])) {
                int tmp = ages[i];
                ages[i] = ages[i + step];
                ages[i + step] = tmp;


                if (name != NULL) {
                    strcpy(name, names[i]);
                    strcpy(names[i], names[i + step]);
                    strcpy(names[i + step], name);

                    swapped = 1;
                }
            }
        }
    }
    fTimeStop = clock() * 1000 / CLOCKS_PER_SEC;
    for (int i = 0; i < count; i++) {
        printf("%s %d\n", names[i], ages[i]);
    }
    printf("\nSorting time is %i(ms)\n", fTimeStop - fTimeStart);
    free(name);
}


int main() {
    int ages[MAX_PEOPLE] = { 0 };
    int count = 0;
    // В используемом файле people_in 13 строк 
    FILE* file = fopen("People_in.txt", "r"); // В файле people_in_test 999 строк работает корректно
    if (file == NULL) {                       // Изменил места, где программа давала недостаточно памяти 
        printf("Your file is empty");
        return 1;
    }
    char c;
    int Length = 1, Strings = 1, Max_length = 0;
    while ((c = getc(file)) != EOF) {
        if (c == '\n') {
            Strings++;
            if (Max_length < Length) {
                Max_length = Length;
            }
            Length = 1;
        }
        else {
            Length++;
        }
    }

    if (Max_length <= 0) {
        return 1;
    }
    if (Strings <= 1) {
        return 1;
    }

    fseek(file, 0, SEEK_SET);
    char** names;
    names = (char**)malloc(Strings * sizeof(char*));

    for (int i = 0; i < Strings; i++) {
        names[i] = (char*)malloc((Max_length + 1) * sizeof(char));
        if (names[i] == NULL) {
            printf("Something has gone wrong");
            for (int j = 0; j < i; j++) {
                free(names[j]);
            }
            free(names);
            return 1;
        }
    }

    char* line = (char*)calloc(Max_length + 1, sizeof(char));
    while (count < Strings && fgets(line, Max_length, file)) {
        size_t len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') {
            line[len - 1] = '\0';
        }
        char* name = strtok(line, " ");
        char* age_str = strtok(NULL, " ");

        if (name != NULL && age_str != NULL) {
            strncpy(names[count], name, Max_length);
            names[count][Max_length] = '\0';
            ages[count] = atoi(age_str);
            count++;
        }
    }
    free(line);
    fclose(file);
    int mode = 0;
    do {
        printf("Choose the sorting method\n1 - bubble sort\n2 - insertion sort\n3 - comb sort\n4 - Finish the process\n");

        do {
            scanf_s("%d", &mode);
        } while (mode < 1 || mode >= 5);
        if (mode <= 3 && mode >= 1) {
            printf("Choose the order of sorting\nascending order (enter 1)\ndescending order (enter 0)?\n");
            int order;
            do {
                scanf_s("%d", &order);
            } while (order != 1 && order != 0);


            if (mode == 1) {
                bubble_sort(names, ages, Max_length, count, order);
            }

            else if (mode == 2) {
                insert_sort(names, ages, Max_length, count, order);
            }

            else if (mode == 3) {
                comb_sort(names, ages, Max_length, count, order);
            }
        }
    } while (mode != 4);

    FILE* output_file = fopen("People_out.txt", "w");

    for (int i = 0; i < count; i++) {
        fprintf(output_file, "%s %d\n", names[i], ages[i]);
    }
    fclose(output_file);
    for (int i = 0; i < Strings; i++) { //Память освобождена
        free(names[i]);
    }
    free(names);
    return 0;
}