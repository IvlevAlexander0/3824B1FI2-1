#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int correct_memory_allocation(char* arr) //Проверка корректности выделения памяти
{
	if (arr == NULL)
	{
		printf("Memory allocation error.");
		return -3;
	}
	
	return 0;
}

int shellsort(int* arr, int size, char** str) //Сортировка Шелла
{
	int tmp, step, i, j;

	char* str_extra = (char*)calloc(50, sizeof(char));
	if (str_extra == NULL)
	{
		printf("Memory allocation error.");
		return -3;
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
	return 0;
}

int find_min_ind(int* arr, int start, int finish) //Поиск индекса минимального элемента в массиве возрастов начиная со start и до finish. start и finish - индексы массива
{
	int i = start, min_ind = start;
	for (; i < finish; i++)
		if (arr[i] < arr[min_ind])
			min_ind = i;
	return min_ind;
}

int selectionsort(int* arr, int size, char** str) //Сортировка "выбором"
{
	char* str_extra = (char*)calloc(50, sizeof(char));
	if (str_extra == NULL)
	{
		printf("Memory allocation error.");
		return -3;
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
	return 0;
}

int bubblesort(int *arr, int size, char** str) //Сортировка "пузырьком" (стандартная)
{
	int tmp;

	char* str_extra = (char*)calloc(50, sizeof(char));
	if (str_extra == NULL)
	{
		printf("Memory allocation error.");
		return -3;
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
	return 0;
}

int getting_array_of_ages(int ages[]) //Формирует массив возрастов
{
	FILE* peoples = NULL;
	peoples = fopen("People_in.txt", "r");

	if (peoples == NULL)
	{
		printf("File reading error!");
		return -2;
	}

	char* str = (char*)calloc(50, sizeof(char));
	if (correct_memory_allocation(str) == -3)
		return -3;

	int count = 0;

	while (fgets(str, 50, peoples) != NULL)
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
		ages[count] = age;
		count++;
	}

	free(str);
	fclose(peoples);
	return count;
}

int filling_an_array_of_strings(char**arr, int count) //Заполняет массив строк, строками из файла
{
	FILE* peoples = NULL;
	peoples = fopen("People_in.txt", "r");

	if (peoples == NULL)
	{
		printf("File reading error!");
		return -2;
	}

	char* str = (char*)calloc(50, sizeof(char));
	if (correct_memory_allocation(str) == -3)
		return -3;

	int i = 0;

	while (fgets(str, 50, peoples) != NULL && i < count)
	{
		arr[i] = (char*)malloc(50 * sizeof(char));
		if (arr[i] == NULL)
		{
			printf("Memory allocation error.");
			return -3;
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
	return 0;
}

int writing_to_file(char** str, int count) //Запись отсортированного массива строк в файл
{
	FILE* sorted = NULL;
	sorted = fopen("People_out.txt", "w");

	if (sorted == NULL)
	{
		printf("File reading error!");
		return -2;
	}

	for (size_t i = 0; i < count; i++)
	{
		if (fputs(str[i], sorted) == EOF)
		{
			printf("File writing error!");
			return -4;
		}

		//Делаем переход на новую стрку:
		if (i != (count-1) ) //-1 так как в последнюю строку не записываем '\n'
		{
			if (fputc('\n', sorted) == EOF)
			{
				printf("File writing error!");
				return -4;
			}
		}
	}

	fclose(sorted);
	return 0;
}

void print_ages_and_strings(int count, int* ages, char** str)
{
	for (size_t i = 0; i < count; i++)
	{
		printf("Age %zu:%d\n", i+1, ages[i]);
	}
	for (size_t i = 0; i < count; i++)
	{
		printf("String %zu: %s\n", i+1, str[i]);
	}
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
	int* ages = (int*)calloc(50, sizeof(int));
	if (ages == NULL)
	{
		printf("Memory allocation error.");
		return -3;
	}

	int count = getting_array_of_ages(ages);

	if (count == -2)
	{
		return -2;
	}
	else if (count == -3)
	{
		return -3;
	}

	char**str = (char**)malloc(count * sizeof(char*)); // Массив указателей (для строк из файла). Но сами указатели неопределены(в filling_an_array_of_strings для них выделяется память)
	if (str == NULL)
	{
		printf("Memory allocation error.");
		return -3;
	}

	int answer = 0;

	while (1)
	{
		int count = getting_array_of_ages(ages);
		if (count == -2)
		{
			return -2;
		}
		else if (count == -3)
		{
			return -3;
		}

		filling_an_array_of_strings(str, count); //Ещё и count передаём, чтобы точно быть уверенными, что не выделится лишняя память в функции

		//print_ages_and_strings(count, ages, str);
		print_strings(count, str);

		int sort_method = 0, ref = 0;
		clock_t t;

		printf("Hello, select the sorting method (1 - bubble_sort, 2 - shell_sort, 3 - selection_sort):\n");
		char c;
		while ((c = getchar()) != '\n' && c != EOF)
		{
			;
		}
		while ((sort_method = getchar() - '0') != 1 && sort_method != 2 && sort_method != 3)
		{
			while ((c = getchar()) != '\n' && c != EOF)
			{
				;
			}
			printf("Error. Enter the correct value:\n");
		}

		switch (sort_method)
		{
		case 1:
			printf("=====Bubble_sort=====\n");
			t = clock();
			if (bubblesort(ages, count, str) == -3)
				return -3;
			printf("Sorting time:%.6lf\n", (double)((clock() - t) / CLOCKS_PER_SEC));
			ref = 0;
			if (ref = writing_to_file(str, count) == -2)
				return -2;
			if (ref == -4)
				return -4;
			break;
		case 2:
			printf("=====Shell_sort=====\n");
			t = clock();
			if (shellsort(ages, count, str) == -3)
				return -3;
			printf("Sorting time:%.6lf\n", (double)((clock() - t) / CLOCKS_PER_SEC));
			ref = 0;
			if (ref = writing_to_file(str, count) == -2)
				return -2;
			if (ref == -4)
				return -4;
			break;
		case 3:
			printf("=====Selection_sort=====\n");
			t = clock();
			if (selectionsort(ages, count, str) == -3)
				return -3;
			printf("Sorting time:%.6lf\n", (double)((clock() - t) / CLOCKS_PER_SEC));
			ref = 0;
			if (ref = writing_to_file(str, count) == -2)
				return -2;
			if (ref == -4)
				return -4;
			break;
		}

		//print_ages_and_strings(count, ages, str);
		print_strings(count, str);

		printf("What do you want: 1 - end the program, 2 - sort again:\n");
		while ((c = getchar()) != '\n' && c != EOF)
		{
			;
		}
		while ((answer = getchar() - '0') != 1 && answer != 2)
		{
			while ((c = getchar()) != '\n' && c != EOF)
			{
				;
			}
			printf("Error. Enter the correct value:\n");
		}

		//Очистка выделенной памяти под строки:
		for (size_t i = 0; i < count; i++)
			free(str[i]);

		if (answer == 1)
			break;
		if (answer == 2)
			continue;
	}

	//Очистка выделенной памяти:

	free(str);
	free(ages);
	if (answer == 1)
		return 0;
}