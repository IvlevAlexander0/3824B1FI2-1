#include <stdio.h>
#include <stdlib.h>  
#include <time.h>
#define NAME 40 //max col-vo simvolov in name people
#define PEOP 50

typedef struct {
	char name[NAME];
	int age;
} Person;

int chislo_peop(const char* filename, Person people[]) //chtobi uznat chislo ludey in fail and zapisat ludey in mass struct
{
	FILE* file = fopen(filename, "r");
	if (file == NULL) {
		printf("The file could not be opened\n");
		return -1;
	}
	int i = 0; //chislo ludey
	while ((fscanf_s(file, "%s %d", people[i].name, (sizeof(people[i].name) / sizeof(people[i].name[0])), &people[i].age) != EOF)) { 
		i++;
	}
	fclose(file);
	return i;
}

void rasheska(Person people[], int n)
{
	int step = n;
	int flag = 1; //flag for perestonovok 
	while (step > 1 || flag == 1) {
		step = step * 10 / 13;
		if (step < 1) {
			step = 1;
		}
		flag = 0;
		Person tmp;
		for (size_t i = 0; i < n - step; i++) {
			if (people[i].age > people[i + step].age) {
				tmp = people[i + step];
				people[i + step] = people[i];
				people[i] = tmp;
				flag = 1;
			}
		}
	}
}


void insertion_sort(Person people[], int size)
{
	for (size_t i = 1; i < size; i++) {
		for (size_t j = i; j > 0 && people[j - 1].age > people[j].age; j--) {
			Person tmp = people[j - 1];
			people[j - 1] = people[j];
			people[j] = tmp;
		}
	}
}

void merge(Person people[], int left, int mid, int right)
{
	int n1 = mid - left + 1;
	int n2 = right - mid;

	Person* L = (Person*)malloc(n1 * sizeof(Person));
	Person* R = (Person*)malloc(n2 * sizeof(Person));

	//copir dannix in massivi
	for (size_t i = 0; i < n1; i++) {
		L[i] = people[left + i];
	}

	for (size_t j = 0; j < n2; j++) {
		R[j] = people[mid + 1 + j];
	}

	//slianie
	int i = 0, j = 0, k = left;
	while (i < n1 && j < n2) {
		if (L[i].age < R[j].age) {
			people[k] = L[i];
			i++;
		}
		else {
			people[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1) {
		people[k] = L[i];
		i++;
		k++;
	}
	while (j < n2) {
		people[k] = R[j];
		j++;
		k++;
	}
	free(L);
	free(R);
}

void delenie(Person people[], int left, int right)
{
	if (left < right) {
		int mid = (left + right) / 2;
		delenie(people, left, mid);
		delenie(people, mid + 1, right);
		merge(people, left, mid, right);
	}
}


void write(const char* filename, Person people[], int n) // n - chislo for zapisi in fail
{
	FILE* file = fopen(filename, "w");
	if (file == NULL) {
		printf("The file could not be opened\n");
		return;
	}
	for (size_t i = 0; i < n; i++) {
		fprintf(file, "%s %d\n", people[i].name, people[i].age);
	}
	fclose(file);
}

void vivod(const char* filename)
{
	FILE* file = fopen(filename, "r");
	if (file == NULL) {
		printf("The file could not be opened\n");
		return;
	}

	char name[NAME];
	int b = sizeof(name) / sizeof(name[0]); //bez b (fscanf_s) ne budet rabotat
	int age;

	while (fscanf_s(file, "%s %d", name, b, &age) != EOF) { //EOF - okonchanie faila
		printf("%s %d\n", name, age);
	}
	fclose(file);
}


void obnul(const char* filename)
{
	FILE* file = fopen(filename, "w");
	if (file == NULL) {
		printf("The file could not be opened\n");
		return -1;
	}
	fclose(file);
}


int main() {
	obnul("People_out.txt");
	Person people[PEOP];
	printf("File People_in\n");
	vivod("People_in.txt");

	int count = chislo_peop("People_in.txt", people); //uznali chislo
	if (count == -1) return 1;

	int flag;
	int c;
	int m;

	while (1) {

		printf("\nPlease selcet a mode\n");
		printf("1 - sort by <comb>\n");//rasheska
		printf("2 - sort by <inserts>\n"); //vstavki
		printf("3 - sort by <Merge>\n"); //slianie
		printf("4 - finish the program or use another sorting\n");

		do {
			flag = 0;
			int r = scanf_s("%d", &m);
			if (r != 1 || (m < 0 || m>4)) {
				printf("Error. Please enter the correct values\n");
				flag = 1;
			}
			while ((c = getchar()) != '\n' && c != EOF) {};
		} while (flag != 0);

		switch (m) {
		case 1:
			write("People_out.txt", people, count);

			clock_t t = clock();

			rasheska(people, count);

			printf("\nSorting time: %.6lf\n", (double)(clock() - t) / CLOCKS_PER_SEC);

			write("People_out.txt", people, count);
			vivod("People_out.txt");
			printf("\nThe sorted data is recorded in the file People_out.txt\n");

			break;
		case 2:
			write("People_out.txt", people, count);

			clock_t j = clock();

			insertion_sort(people, count);

			printf("\nSorting time: %lf\n", (double)(clock() - j) / CLOCKS_PER_SEC);

			write("People_out.txt", people, count);
			vivod("People_out.txt");
			printf("\nThe sorted data is recorded in the file People_out.txt\n");
			break;
		case 3:
			write("People_out.txt", people, count);

			clock_t k = clock();

			delenie(people, 0, count - 1);

			printf("\nSorting time: %lf\n", (double)(clock() - k) / CLOCKS_PER_SEC);

			write("People_out.txt", people, count);
			vivod("People_out.txt");
			printf("\nThe sorted data is recorded in the file People_out.txt\n");
			break;
		case 4:
			printf("Please Please make a choice\n");
			printf("1 - end the program\n");
			printf("2 - use a different sort\n");

			int vibor;
			int flag1;
			char y;
			do {
				flag1 = 0;
				int r = scanf_s("%d", &vibor);
				if (r != 1 || (vibor < 0 || vibor>2)) {
					printf("Error. Please enter the correct valuse\n");
					printf("You need to enter <1> or <2>\n");
					flag1 = 1;
				}
				while ((y = getchar()) != '\n' && y != EOF) {};

			} while (flag1 != 0);

			if (vibor == 1) {
				printf("Have a nice day!\n");
				return;
			}
			else {

				break;
			}

		}
	}

	return 0;
}
