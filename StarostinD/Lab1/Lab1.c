#include <stdio.h>
#include <math.h>

enum PIECES { King, Queen, Rook, Bishop, Knight };

int main() {
	int x0 = -1, x1 = -1;
	char y0 = ' ', y1 = ' ';
	int fg = -1;
	printf("List of pieces:\n1. King \t 2. Queen \t 3. Rook \t 4. Bishop \t 5. Knight");
	printf("\nSelect a chess piece by writing its number: ");
	int fl;
	do {
		fl = 0;
		int c = scanf_s("%d", &fg);
		if (fg < 1 || fg > 5 || c != 1) {
			printf("Error\n");
			fl = 1;
			int t;
			while ((t = getchar()) != '\n' && t != EOF);
		}
	} while (fl);
	--fg;
	printf("\nType the first cell (1-8; a-h): ");
	do {
		fl = 0;
		int c = scanf_s("%d %c", &x0, &y0);
		if (x0 > 8 || x0 < 1 || y0 < 'a' || y0 > 'h' || c != 2) {
			if (y0 < 'a' || y0 > 'h') {
				if (y0 >= 'A' && y0 <= 'H') {
					y0 += ('a' - 'A');
				}
				else {
					printf("Error\n");
					fl = 1;
					int t;
					while ((t = getchar()) != '\n' && t != EOF);
				}
			}
			else {
				printf("Error\n");
				fl = 1;
				int t;
				while ((t = getchar()) != '\n' && t != EOF);
			}
		}
	} while (fl);
	printf("\nType the second cell (1-8; a-h): ");
	do {
		fl = 0;
		int c = scanf_s("%d %c", &x1, &y1);
		if (x1 > 8 || x1 < 1 || y1 < 'a' || y1 > 'h' || c != 2) {
			if (y1 < 'a' || y1 > 'h') {
				if (y1 >= 'A' && y1 <= 'H') {
					y1 += ('a' - 'A');
				}
				else {
					printf("Error\n");
					fl = 1;
					int t;
					while ((t = getchar()) != '\n' && t != EOF);
				}
			}
			else {
				printf("Error\n");
				fl = 1;
				int t;
				while ((t = getchar()) != '\n' && t != EOF);
			}
		}
	} while (fl);
	printf("\n");
	short flag = 0;
	switch (fg) {
	case(King):
		if (fabs(x1 - x0) <= 1 && fabs(y1 - y0) <= 1) {
			printf("You can do this move\n");
		}
		else {
			flag++;
		}
		break;
	case(Queen):
		if ((fabs(x1 - x0) <= 1 && fabs(y1 - y0) <= 1) || (y1 - y0 == 0 || x1 - x0 == 0) || (fabs(x1 - x0) == fabs(y1 - y0))) {
			printf("You can do this move\n");
		}
		else {
			flag++;
		}
		break;
	case(Rook):
		if (y1 - y0 == 0 || x1 - x0 == 0) {
			printf("You can do this move\n");
		}
		else {
			flag++;
		}
		break;
	case(Bishop):
		if (fabs(x1 - x0) == fabs(y1 - y0)) {
			printf("You can do this move\n");
		}
		else {
			flag++;
		}
		break;
	case(Knight):
		if ((fabs(x1 - x0) == 2 && fabs(y1 - y0) == 1) || (fabs(x1 - x0) == 1 && fabs(y1 - y0) == 2)) {
			printf("You can do this move\n");
		}
		else {
			flag++;
		}
		break;
	default:
		break;
	}
	short flag1 = 0;
	if (flag) {
		printf("You can't do this step with this figure.");
		if (fabs(x1 - x0) <= 1 && fabs(y1 - y0) <= 1) {
			if (flag1 == 0) {
				flag1++;
				printf("But you can choose another chess piece, for example:\n");
			}
			printf("-King\n");
		}
		if ((fabs(x1 - x0) <= 1 && fabs(y1 - y0) <= 1) || (y1 - y0 == 0 || x1 - x0 == 0) || (fabs(x1 - x0) == fabs(y1 - y0))) {
			if (flag1 == 0) {
				flag1++;
				printf("But you can choose another chess piece, for example:\n");
			}
			printf("-Queen\n");
		}
		if (y1 - y0 == 0 || x1 - x0 == 0) {
			if (flag1 == 0) {
				flag1++;
				printf("But you can choose another chess piece, for example:\n");
			}
			printf("-Rook\n");
		}
		if (fabs(x1 - x0) == fabs(y1 - y0)) {
			if (flag1 == 0) {
				flag1++;
				printf("But you can choose another chess piece, for example:\n");
			}
			printf("-Bishop\n");
		}
		if ((fabs(x1 - x0) == 2 && fabs(y1 - y0) == 1) || (fabs(x1 - x0) == 1 && fabs(y1 - y0) == 2)) {
			if (flag1 == 0) {
				flag1++;
				printf(" But you can choose another chess piece, for example:\n");
			}
			printf("-Knight\n");
		}
	}
	return 0;
}