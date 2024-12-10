#include "sorts.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void swap(Person* a, Person* b) {
	Person t = *a;
	*a = *b;
	*b = t;
}

void quick_sort(Person* arr, size_t size) {
	if (size == 1) {
		return;
	}
	size_t l = 0, r = size - 1;
	quick_rstn(arr, size, l, r);
}
void quick_rstn(Person* arr, size_t size, int l, int r) {
	if (r <= l) return;
	int rnd = l + rand() % (r - l + 1);
	int pivot = arr[rnd].age;
	int i = l, j = r;
	while (i <= j) {
		while (i <= r && arr[i].age < pivot) ++i;
		while (j >= l && arr[j].age > pivot) --j;
		if (i <= j) {
			swap(&arr[i], &arr[j]);
			++i;
			--j;
		}
	}
	quick_rstn(arr, size, l, j);
	quick_rstn(arr, size, i, r);
}

void merge_sort(Person* arr, size_t size) {
	if (size == 1) {
		return;
	}
	Person* dst = calloc(size, sizeof(Person));
	Person* tmp = arr;
	tmp = merge_sort_rstn(tmp, dst, 0, size - 1);
	for (int i = 0; i < size; ++i) {
		arr[i] = tmp[i];
	}
	if (dst != NULL) {
		free(dst);
	}
}
Person* merge_sort_rstn(Person* src, Person* dst, int l, int r) {
	if (l == r) {
		dst[l] = src[l];
		return dst;
	}
	int m = l + (r - l) / 2;
	Person* left_buff = merge_sort_rstn(src, dst, l, m);
	Person* right_buff = merge_sort_rstn(src, dst, m + 1, r);
	Person* target = left_buff == src ? dst : src;
	int l_id = l, r_id = m + 1;
	for (int i = l; i <= r; i++) {
		if (l_id <= m && r_id <= r) {
			if (left_buff[l_id].age <= right_buff[r_id].age) {
				target[i] = left_buff[l_id++];
			}
			else {
				target[i] = right_buff[r_id++];
			}
		}
		else if (l_id <= m) {
			target[i] = left_buff[l_id++];
		}
		else if (r_id <= r) {
			target[i] = right_buff[r_id++];
		}
	}
	return target;
}

void shell_sort(Person* arr, size_t size) {
	if (size == 1) {
		return;
	}
	size_t step = size / 2;
	for (; step > 0; step /= 2) {
		for (size_t i = step; i < size; ++i) {
			Person tmp = arr[i];
			int j = i;
			while (j >= step && arr[j - step].age > tmp.age) {
				arr[j] = arr[j - step];
				j -= step;
			}
			arr[j] = tmp;
		}
	}
}