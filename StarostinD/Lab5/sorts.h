#pragma once
#include <stdio.h>
#define NAME_SIZE 50
typedef
struct {
	char* name[NAME_SIZE];
	int age;
} Person;

void swap(Person* a, Person* b);

void quick_sort(Person* arr, size_t size);
void quick_rstn_even(Person* arr, size_t size, int l, int r);
void quick_rstn_odd(Person* arr, size_t size, int l, int r);

void merge_sort(Person* arr, size_t size);
Person* merge_sort_even(Person* src, Person* dst, int l, int r);
Person* merge_sort_odd(Person* src, Person* dst, int l, int r);

void shell_sort(Person* arr, size_t size);
void shell_sort_even(Person* arr, size_t size);
void shell_sort_odd(Person * arr, size_t size);