#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int arr_pc[5] = { -1, -1, -1, -1, -1 }, arr_user[5] = { -1, -1, -1, -1, -1 };
	srand(time(NULL));
	//Determining the length of a hidden word
	size_t n = 0;
	while (n > 5 || n < 2)
	{
		printf("Enter the length of the number: ");
		scanf_s("%zu", &n);
		char c;
		while ((c = getchar()) != '\n' && c != EOF) {}
	}
	//Checking for a match of numbers in a hidden word
	for (size_t i = 0; i < n; i++) {

		int rand_num = rand() % 10;
		arr_pc[i] = rand_num;

		for (size_t j = 0; j < i; j++) {
			if (arr_pc[j] == arr_pc[i]) {
				while (arr_pc[j] == arr_pc[i])
				{
					rand_num = rand() % 10;
					arr_pc[i] = rand_num;
				}
				j = -1; //так как после этого идёт j++
			}
		}
		if (arr_pc[0] == 0)
			i = -1;
		//printf("%d", arr_pc[i]);
	}

	//Guessing the hidden number
	while (1)
	{
		while (1)
		{
			int user_num, flag, count = 0;
			flag = 0;
			printf("\nThe computer conceived the number of length %zu. Try to guess:\n", n);
			scanf_s("%d", &user_num);

			//Checking the length of the user's number
			while (1)
			{
				int num_len = user_num;
				for (size_t u = 0; u < n; u++)
				{
					num_len = num_len / 10;
					if (num_len == 0 && u != n - 1)
					{
						num_len = 1;
						break;
					}
				}
				if (num_len != 0)
				{
					char c;
					while ((c = getchar()) != '\n' && c != EOF) {}
					printf("Enter a number of length %zu:\n", n);
					scanf_s("%d", &user_num);
				}
				else
					break;
			}

			//Mirroring the user's number
			int extra_user_num = user_num, remain = 0;
			user_num = 0;
			while (extra_user_num > 0)
			{
				remain = extra_user_num % 10;
				user_num = user_num * 10 + remain;
				extra_user_num = extra_user_num / 10;
			}

			//Checking for matching numbers
			int extra_num = user_num;
			for (size_t i = 0; i < n; i++)
			{
				arr_user[i] = extra_num % 10;
				extra_num = extra_num / 10;
				for (size_t j = 0; j < i; j++)
				{
					if (arr_user[j] == arr_user[i])
					{
						flag = 1;
						break;
					}
				}
				if (flag)
				{
					for (size_t k = 0; k < 6; k++)
						arr_user[i] = -1;
					printf("Error! The numbers should not be repeated!");
					count = 0;
					break;
				}
				count++;
			}
			if (count == n)
				break;
		}

		//Definition of bulls and cows
		int cows = 0, bulls = 0;
		for (size_t b = 0; b < n; b++)
		{
			for (size_t v = 0; v < n; v++)
			{
				if (arr_user[b] == arr_pc[v])
				{
					if (b != v)
						cows++;
					if (b == v)
						bulls++;
				}
			}
		}

		if (bulls != n)
			printf("Result: %d cows, %d bulls.", cows, bulls);
		else if (bulls == n)
		{
			printf("Successfully! The hidden number: ");
			for (size_t p = 0; p < n; p++)
				printf("%d", arr_pc[p]);
			break;
		}
	}
	return 0;
}