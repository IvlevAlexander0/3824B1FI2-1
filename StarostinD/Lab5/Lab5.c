#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include "sorts.h"
#define NAME_SIZE 50

int main() {
	FILE* in = fopen("People_in.txt", "r+");
	if (in == NULL) {
		return 0;
	}
	size_t num_of_people = 0;
	char* s = calloc(NAME_SIZE, sizeof(char));
	while (!feof(in)) {
		fgets(s, NAME_SIZE, in);
		if (s != "\n" && s != "" && s != '\0' && strlen(s) > 1) {
			++num_of_people;
		}
	}
	if (num_of_people == 0) {
		printf("Error! Empty list given\n");
		return 0;
	}
	fseek(in, 0, SEEK_SET);
	int flag = 1;
	Person *people = calloc(num_of_people, sizeof(Person));
	size_t ii = 0;
	while (!feof(in)) {
		fgets(s, NAME_SIZE, in);
		char* ptr_start = s, * ptr_end = strstr(s, " ");
		if (ptr_end != NULL) {
			strncpy((people[ii]).name, ptr_start, ptr_end - ptr_start);
			(people[ii]).age = atoi(ptr_end + 1);
			++ii;
		}
	}
	num_of_people = ii;
	free(s);
	while (flag) {
		Person* people_tmp = calloc(num_of_people, sizeof(Person));
		for (int i = 0; i < num_of_people; ++i) {
			strcpy(people_tmp[i].name, people[i].name);
			people_tmp[i].age = people[i].age;
		}
		int mode;
		printf("Select sorting:\n1. quick sort\t2 merge sort\t3. Shell sort\n");
		scanf_s("%d", &mode);
		--mode;
		void (*modes[])(Person*, size_t) = { quick_sort, merge_sort, shell_sort };
		void (*sort)(Person*, size_t) = modes[mode];
		clock_t time = clock();
		sort(people_tmp, num_of_people);
		double t = (double)(clock() - time) / CLOCKS_PER_SEC;
		FILE* out = fopen("People_out.txt", "w");
		for (int i = 0; i < num_of_people - 1; ++i) {
			printf("%d. %s %d\n", i + 1, people_tmp[i].name, people_tmp[i].age);
			fprintf(out, "%s %d\n", people_tmp[i].name, people_tmp[i].age);
		}
		printf("%d. %s %d\n", num_of_people, people_tmp[num_of_people - 1].name, people_tmp[num_of_people - 1].age);
		fprintf(out, "%s %d", people_tmp[num_of_people - 1].name, people_tmp[num_of_people - 1].age);
		printf("time: %.15lf\n", t);
		fclose(in);		
		fclose(out);
		printf("Do you want to change sorting method and sort again?(Y/N): ");
		char ans;
		while ((ans = getchar()) != '\n');
		scanf_s("%c", &ans);
		if (toupper(ans) == 'N') {
			flag = 0;
		}
		free(people_tmp);
	}
	free(people);
	return 0;
}