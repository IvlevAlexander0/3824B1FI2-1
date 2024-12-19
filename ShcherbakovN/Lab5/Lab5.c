#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define STR_LENGTH 40

void shellsort(int* arr, int size, char** str) //Сортировка Шелла
{
	int tmp, step, i, j;

	char* str_extra = (char*)calloc(STR_LENGTH, sizeof(char));
	if (str_extra == NULL)
	{
		printf("Memory allocation error.");
		exit(EXIT_FAILURE);
	}

	for (step = size / 2; step > 0; step /= 2)
		for (i = step; i < size; i++)
			for (j = i - step; j >= 0 && arr[j] > arr[j + step]; j -= step)
			{
				tmp = arr[j];
				arr[j] = arr[j + step];
				arr[j + step] = tmp;

				strcpy(str_extra, str[j]);
				strcpy(str[j], str[j + step]);
				strcpy(str[j + step], str_extra);
			}
	free(str_extra);
}

int find_min_ind(int* arr, int start, int finish) //Поиск индекса минимального элемента в массиве возрастов начиная со start и до finish. start и finish - индексы массива
{
	int i = start, min_ind = start;
	for (; i < finish; i++)
		if (arr[i] < arr[min_ind])
			min_ind = i;
	return min_ind;
}

void selectionsort(int* arr, int size, char** str) //Сортировка "выбором"
{
	char* str_extra = (char*)calloc(STR_LENGTH, sizeof(char));
	if (str_extra == NULL)
	{
		printf("Memory allocation error.");
		exit(EXIT_FAILURE);
	}

	int min_ind, tmp;
	//printf("size:%d\n", size);
	for (int i = 0; i < size - 1; i++)
	{
		min_ind = find_min_ind(arr, i, size);
		//printf("min_i:%d, min:%d, i:%d\n", min_ind, arr[min_ind], arr[i]);
		tmp = arr[min_ind];
		arr[min_ind] = arr[i];
		arr[i] = tmp;

		strcpy(str_extra, str[min_ind]);
		strcpy(str[min_ind], str[i]);
		strcpy(str[i], str_extra);
	}

	free(str_extra);
}

void bubblesort(int *arr, int size, char** str) //Сортировка "пузырьком" (стандартная)
{
	int tmp;

	char* str_extra = (char*)calloc(STR_LENGTH, sizeof(char));
	if (str_extra == NULL)
	{
		printf("Memory allocation error.");
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < size - 1; i++)
	{
		for (int j = size - 1; j > i; j--)
		{
			if (arr[j] < arr[j - 1])
			{
				tmp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = tmp;

				strcpy(str_extra, str[j]);
				strcpy(str[j], str[j - 1]);
				strcpy(str[j - 1], str_extra);

			}
		}
	}

	free(str_extra);
}

int count_of_strings_in_file()
{
	FILE* peoples = NULL;
	peoples = fopen("People_in.txt", "r");

	if (peoples == NULL)
	{
		printf("File reading error!");
		exit(EXIT_FAILURE);
	}

	char* str = (char*)calloc(STR_LENGTH, sizeof(char));
	if (str == NULL)
	{
		printf("Memory allocation error.");
		exit(EXIT_FAILURE);
	}

	int count = 0;
	while (fgets(str, STR_LENGTH, peoples) != NULL)
	{
		count++;
	}

	free(str);
	fclose(peoples);
	return count;
}

void getting_array_of_ages(int *ages, int count) //Формирует массив возрастов
{
	FILE* peoples = NULL;
	peoples = fopen("People_in.txt", "r");

	if (peoples == NULL)
	{
		printf("File reading error!");
		exit(EXIT_FAILURE);
	}

	char* str = (char*)calloc(STR_LENGTH, sizeof(char));
	if (str == NULL)
	{
		printf("Memory allocation error.");
		exit(EXIT_FAILURE);
	}

	for (int j = 0; j < count && fgets(str, STR_LENGTH, peoples) != NULL; j++)
	{
		int i = 0, age = 0;
		while (str[i] != ' ')
			i++;
		i++;
		while (str[i] != '\0' && str[i] != '\n')
		{
			//printf("str[%d]=  %d, code:%d\n", i, str[i]-'0', str[i]);
			age *= 10;
			age = age + (str[i] - '0');
			i++;
		}
		ages[j] = age;
	}

	free(str);
	fclose(peoples);
}

void filling_an_array_of_strings(char**arr, int count) //Заполняет массив строк, строками из файла
{
	FILE* peoples = NULL;
	peoples = fopen("People_in.txt", "r");

	if (peoples == NULL)
	{
		printf("File reading error!");
		exit(EXIT_FAILURE);
	}

	char* str = (char*)calloc(STR_LENGTH, sizeof(char));
	if (str == NULL)
	{
		printf("Memory allocation error.");
		exit(EXIT_FAILURE);
	}

	int i = 0;

	while (fgets(str, STR_LENGTH, peoples) != NULL && i < count)
	{
		arr[i] = (char*)malloc(STR_LENGTH * sizeof(char));
		if (arr[i] == NULL)
		{
			printf("Memory allocation error.");
			exit(EXIT_FAILURE);
		}
		strcpy(arr[i], str);

		//Убираем символ '\n' из каждой строки:
		int j = 0;
		while (arr[i][j] != '\n' && arr[i][j] != '\0')
		{
			j++;
		}
		if (arr[i][j] == '\n' && arr[i][j + 1] == '\0')
		{
			arr[i][j] = '\0';
			arr[i][j + 1] = '0';
		}
		//printf("String %d:%s\n", i, arr[i]);
		i++;
	}

	free(str);
	fclose(peoples);
}

void writing_to_file(char** str, int count) //Запись отсортированного массива строк в файл
{
	FILE* sorted = NULL;
	sorted = fopen("People_out.txt", "w");

	if (sorted == NULL)
	{
		printf("File reading error!");
		exit(EXIT_FAILURE);
	}

	for (size_t i = 0; i < count; i++)
	{
		if (fputs(str[i], sorted) == EOF)
		{
			printf("File writing error!");
			exit(EXIT_FAILURE);
		}

		//Делаем переход на новую стрку:
		if (i != (count-1) ) //-1 так как в последнюю строку не записываем '\n'
		{
			if (fputc('\n', sorted) == EOF)
			{
				printf("File writing error!");
				exit(EXIT_FAILURE);
			}
		}
	}

	fclose(sorted);
}

void print_strings(int count, char** str)
{
	for (size_t i = 0; i < count; i++)
	{
		printf("String %zu: %s\n", i + 1, str[i]);
	}
}


int main()
{
	int count = count_of_strings_in_file();
	//printf("%d", count);

	int* ages = (int*)calloc(count, sizeof(int));
	if (ages == NULL)
	{
		printf("Memory allocation error.");
		exit(EXIT_FAILURE);
	}

	getting_array_of_ages(ages, count);

	char**str = (char**)malloc(count * sizeof(char*)); // Массив указателей (для строк из файла). Но сами указатели неопределены(в filling_an_array_of_strings для них выделяется память)
	if (str == NULL)
	{
		printf("Memory allocation error.");
		exit(EXIT_FAILURE);
	}

	while (1)
	{
		count = count_of_strings_in_file();
		getting_array_of_ages(ages, count);

		filling_an_array_of_strings(str, count); //Ещё и count передаём, чтобы точно быть уверенными, что не выделится лишняя память в функции

		print_strings(count, str);

		int sort_method = 0, answer = 0;
		clock_t t;

		printf("Hello, select the sorting method (1 - bubble_sort, 2 - shell_sort, 3 - selection_sort):\n");
		while (scanf("%d", &sort_method) != 1 || (sort_method != 1 && sort_method != 2 && sort_method != 3))
		{
			while ((sort_method = getchar()) != '\n' && sort_method != EOF)
			{
				;
			}
		}

		switch (sort_method)
		{
		case 1:
			printf("=====Bubble_sort=====\n");
			t = clock();
			bubblesort(ages, count, str);
			printf("Sorting time:%.6lf\n", (double)((clock() - t) / CLOCKS_PER_SEC));
			writing_to_file(str, count);
			break;
		case 2:
			printf("=====Shell_sort=====\n");
			t = clock();
			shellsort(ages, count, str);
			printf("Sorting time:%.6lf\n", (double)((clock() - t) / CLOCKS_PER_SEC));
			writing_to_file(str, count);
			break;
		case 3:
			printf("=====Selection_sort=====\n");
			t = clock();
			selectionsort(ages, count, str);
			printf("Sorting time:%.6lf\n", (double)((clock() - t) / CLOCKS_PER_SEC));
			writing_to_file(str, count);
			break;
		}

		print_strings(count, str);

		printf("What do you want: 1 - end the program, 2 - sort again:\n");
		while ((answer = getchar()) != '\n' && answer != EOF)
			;
		while (scanf("%d", &answer) != 1 || (answer != 1 && answer != 2))
		{
			while ((answer = getchar()) != '\n' && answer != EOF)
			{
				;
			}
		}

		//Очистка выделенной памяти под строки:
		for (size_t i = 0; i < count; i++)
			free(str[i]);

		if (answer == 1)
			exit(EXIT_SUCCESS);
	}

	//Очистка выделенной памяти:
	free(str);
	free(ages);
}