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
	int e_cnt = 0, o_cnt = 0;
	for (int i = 0, e = 0, o = 0; i < size; ++i) {
		if (i % 2) {
			++e_cnt;
		}
		else {
			++o_cnt;
		}
	}
	Person* even = calloc(e_cnt, sizeof(Person));
	Person* odd = calloc(o_cnt, sizeof(Person));
	for (int i = 0, e = 0, o = 0; i < size; ++i) {
		if (i % 2) {
			even[e++] = arr[i];
		}
		else {
			odd[o++] = arr[i];
		}
	}
	size_t l = 0, r = size - 1;
	quick_rstn_even(even, size, l + 1, e_cnt - 1);
	quick_rstn_odd(odd, size, l, o_cnt - 1);
	for (int i = 0, e = 0, o = 0; i < size; ++i) {
		if (i & 1) {
			arr[i] = even[o++];
		}
		else {
			arr[i] = odd[e++];
		}
	}
	if (even != NULL) {
		free(even);
	}
	if (odd != NULL) {
		free(odd);
	}
}
void quick_rstn_even(Person* arr, size_t size, int l, int r) {
	if (r <= l) return;
	int flag = 1;
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
	quick_rstn_even(arr, size, l, j);
	quick_rstn_even(arr, size, i, r);
}
void quick_rstn_odd(Person* arr, size_t size, int l, int r) {
	if (r <= l) return;
	int flag = 1;
	int pivot = arr[l + rand() % (r - l + 1)].age;
	int i = l, j = r;
	while (i <= j) {
		while (i <= r && arr[i].age > pivot) ++i;
		while (j >= l && arr[j].age < pivot) --j;
		if (i <= j) {
			swap(&arr[i], &arr[j]);
			++i;
			--j;
			flag = 0;
		}
	}
	quick_rstn_odd(arr, size, l, j);
	quick_rstn_odd(arr, size, i, r);
}

void merge_sort(Person* arr, size_t size) {
	if (size == 1) {
		return;
	}
	int e_cnt = 0, o_cnt = 0;
	for (int i = 0, e = 0, o = 0; i < size; ++i) {
		if (i % 2) {
			++e_cnt;
		}
		else {
			++o_cnt;
		}
	}
	Person* even = calloc(e_cnt, sizeof(Person));
	Person* odd = calloc(o_cnt, sizeof(Person));
	Person* dst_even = calloc(e_cnt, sizeof(Person));
	Person* dst_odd = calloc(o_cnt, sizeof(Person));
	for (int i = 0, e = 0, o = 0; i < size; ++i) {
		if (i % 2) {
			dst_even[e] = arr[i];
			even[e++] = arr[i];
		}
		else {
			dst_odd[o] = arr[i];
			odd[o++] = arr[i];
		}
	}
	int m = size / 2 + 1;
	even = merge_sort_even(even, dst_even, 0, e_cnt - 1);
	odd = merge_sort_odd(odd, dst_odd, 0, o_cnt - 1);
	for (int i = 0, e = 0, o = 0; i < size; ++i) {
		if (i & 1) {
			arr[i] = even[o++];
		}
		else {
			arr[i] = odd[e++];
		}
	}
	if (even != NULL) {
		free(even);
	}
	if (odd != NULL) {
		free(odd);
	}
}
Person* merge_sort_even(Person* src, Person* dst, int l, int r) {
	if (l == r) {
		dst[l] = src[l];
		return dst;
	}
	int m = l + (r - l) / 2;
	Person* left_buff = merge_sort_even(src, dst, l, m);
	Person* right_buff = merge_sort_even(src, dst, m + 1, r);

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
Person* merge_sort_odd(Person* src, Person* dst, int l, int r) {
	if (l == r) {
		dst[l] = src[l];
		return dst;
	}
	int m = l + (r - l) / 2;
	Person* left_buff = merge_sort_even(src, dst, l, m);
	Person* right_buff = merge_sort_even(src, dst, m + 1, r);

	Person* target = left_buff == src ? dst : src;
	int l_id = l, r_id = m + 1;
	for (int i = r; i >= l; i--) {
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
	int e_cnt = 0, o_cnt = 0;
	for (int i = 0, e = 0, o = 0; i < size; ++i) {
		if (i % 2) {
			++e_cnt;
		}
		else {
			++o_cnt;
		}
	}
	Person* even = calloc(e_cnt, sizeof(Person));
	Person* odd = calloc(o_cnt, sizeof(Person));
	for (int i = 0, e = 0, o = 0; i < size; ++i) {
		if (i % 2) {
			even[e++] = arr[i];
		}
		else {
			odd[o++] = arr[i];
		}
	}
	shell_sort_even(even, e_cnt);
	shell_sort_odd(odd, o_cnt);
	for (int i = 0, e = 0, o = 0; i < size; ++i) {
		if (i & 1) {
			arr[i] = even[o++];
		}
		else {
			arr[i] = odd[e++];
		}
	}
	if (even != NULL) {
		free(even);
	}
	if (odd != NULL) {
		free(odd);
	}
}
void shell_sort_even(Person* arr, size_t size) {
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
void shell_sort_odd(Person* arr, size_t size) {
	size_t step = size / 2;
	for (; step > 0; step /= 2) {
		for (size_t i = step; i < size; ++i) {
			Person tmp = arr[i];
			int j = i;
			while (j >= step && arr[j - step].age < tmp.age) {
				arr[j] = arr[j - step];
				j -= step;
			}
			arr[j] = tmp;
		}
	}
}
