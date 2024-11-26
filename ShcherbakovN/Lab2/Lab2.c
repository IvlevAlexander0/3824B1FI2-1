#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand(time(NULL));
	int choice;
	printf("Select the game mode(<1> mode - you guess, <2> mode - the computer guesses): \n");

	do
	{
		if(scanf_s("%d", &choice) != 1)
		{
			char c;
			while ((c = getchar()) != '\n' && c != EOF)
			{
				c = scanf_s("%d", &choice);
			}
		}
	} while (choice != 1 && choice != 2);

	if (choice == 1)
	{
		int rand_num = 1 + rand() % 1001, user_num, flag, trys = 0;
		printf("Enter the expected number:\n");
		do
		{
			if (scanf_s("%d", &user_num) != 1)
			{
				char c;
				while ((c = getchar()) != '\n' && c != EOF)
				{
					c = scanf_s("%d", &user_num);
				}
			}
			if (user_num > rand_num)
			{
				printf("user_num > rand_num\n");
				trys++;
				continue;
			}
			else if (user_num < rand_num)
			{
				printf("user_num < rand_num\n");
				trys++;
				continue;
			}
			else
			{
				trys++;
				printf("user_num = rand_num\nAttempts: %d", trys);
				break;
			}
		} while (1);
	}

	else if(choice == 2)
	{
		printf("Enter a random number from 1 to 1000:\n");
		int user_num, trys = 0;

		do
		{
			if (scanf_s("%d", &user_num) != 1)
			{
				char c;
				while ((c = getchar()) != '\n' && c != EOF)
				{
					c = scanf_s("%d", &user_num);
				}
			}
		} while (user_num > 1000 || user_num < 1);
		int rand_num = 1 + rand() % 1001, split_up = 1001, extra_num, split_down = 1;

		char compare;
		while(1)
		{
			int rand_num = split_down + rand() % split_up;
			printf("Random number: %d\n", rand_num);

			// Enter > < =:
			printf("Enter >, < or = (user_number (?) rand_number): \n");
			do
			{
				if (scanf_s("%c", &compare) != 1)
				{
					char c;
					while ((c = getchar()) != '\n' && c != EOF)
					{
						c = scanf_s("%c", &compare);
					}
				}
			} while ( (user_num - rand_num > 0 && compare != '>') || (user_num - rand_num < 0 && compare != '<') || (user_num - rand_num == 0 && compare != '=') );


			if (/*user_num > rand_num*/ compare == '>')
			{
				extra_num = split_down;
				split_down = rand_num + 1; //+1 т.к неравенство строгое
				split_up = split_up - (split_down - extra_num);
				trys++;
				continue;
			}
			else if (/*user_num < rand_num*/ compare == '<')
			{
				split_up = rand_num - split_down;
				trys++;
				continue;
			}
			else if (/*user_num == rand_num*/ compare == '=')
			{
				trys++;
				printf("Successfully! User number: %d\n", user_num);
				printf("Attempts: %d", trys);
				break;
			}
		}
	}
	return 0;
}
