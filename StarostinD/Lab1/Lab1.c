#include <stdio.h>
#include <math.h>

enum PIECES { King, Queen, Rook, Bishop, Knight };

int main() {
	int x0 = -1, x1 = -1;
	char y0 = ' ', y1 = ' ';
	enum PIECES fg;
	char pieces[5][6] = { "King  ", "Queen ", "Rook  ", "Bishop", "Knight" };
	printf("List of pieces:\n");
	for (int i = 0; i < 5; ++i) {
		printf("%d. ", i + 1);
		for (int j = 0; j < 6; ++j) {
			printf("%c", pieces[i][j]);
		}
		printf("\t");
	}
	printf("\nSelect a chess piece by writing its number: ");
	scanf_s("%d", &fg);
	if (fg < 1 || fg > 5) {
		printf("Error");
		return 0;
	}
	--fg;
	printf("\nType the first cell: ");
	scanf_s("%d %c", &x0, &y0); // 1-8, a-h
	if (x0 > 8 || x0 < 1 || y0 < 'a' || y0 > 'h') {
		if (y0 < 'a' || y0 > 'h') {
			if (y0 >= 'A' && y0 <= 'H') {
				y0 = y0 + ('a' - 'A');
			}
			else {
				printf("Error\n");
				return 0;
			}
		}
		else {
			printf("Error\n");
			return 0;
		}
	}
	printf("\nType the second cell: ");
	scanf_s("%d %c", &x1, &y1); // 1-8, a-h
	if (x1 > 8 || x1 < 1 || y1 < 'a' || y1 > 'h') {
		if (y1 < 'a' || y1 > 'h') {
			if (y1 >= 'A' && y1 <= 'H') {
				y1 = y1 + ('a' - 'A');
			}
			else {
				printf("Error\n");
				return 0;
			}
		}
		else {
			printf("Error\n");
			return 0;
		}
	}
	printf("\n");
	short flag = 0;
	switch (fg) {
	case(0):
		if (fabs(x1 - x0) <= 1 && fabs(y1 - y0) <= 1) {
			printf("You can do this move\n");
		}
		else {
			flag++;
		}
		break;
	case(1):
		if ((fabs(x1 - x0) <= 1 && fabs(y1 - y0) <= 1) || (y1 - y0 == 0 || x1 - x0 == 0) || (fabs(x1 - x0) == fabs(y1 - y0))) {
			printf("You can do this move\n");
		}
		else {
			flag++;
		}
		break;
	case(2):
		if (y1 - y0 == 0 || x1 - x0 == 0) {
			printf("You can do this move\n");
		}
		else {
			flag++;
		}
		break;
	case(3):
		if (fabs(x1 - x0) == fabs(y1 - y0)) {
			printf("You can do this move\n");
		}
		else {
			flag++;
		}
		break;
	case(4):
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
		switch (0) {
		case(0):
			if (fabs(x1 - x0) <= 1 && fabs(y1 - y0) <= 1) {
				if (flag1 == 0) {
					flag1++;
					printf("But you can choose another chess piece, for example:\n");
				}
				printf("King\n");
			}
		case(1):
			if ((fabs(x1 - x0) <= 1 && fabs(y1 - y0) <= 1) || (y1 - y0 == 0 || x1 - x0 == 0) || (fabs(x1 - x0) == fabs(y1 - y0))) {
				if (flag1 == 0) {
					flag1++;
					printf("But you can choose another chess piece, for example:\n");
				}
				printf("Queen\n");
			}
		case(2):
			if (y1 - y0 == 0 || x1 - x0 == 0) {
				if (flag1 == 0) {
					flag1++;
					printf("But you can choose another chess piece, for example:\n");
				}
				printf("Rook\n");
			}
		case(3):
			if (fabs(x1 - x0) == fabs(y1 - y0)) {
				if (flag1 == 0) {
					flag1++;
					printf("But you can choose another chess piece, for example:\n");
				}
				printf("Bishop\n");
			}
		case(4):
			if ((fabs(x1 - x0) == 2 && fabs(y1 - y0) == 1) || (fabs(x1 - x0) == 1 && fabs(y1 - y0) == 2)) {
				if (flag1 == 0) {
					flag1++;
					printf(" But you can choose another chess piece, for example:\n");
				}
				printf("Knight\n");
			}
		default:
			break;
		}
	}
	return 0;
}