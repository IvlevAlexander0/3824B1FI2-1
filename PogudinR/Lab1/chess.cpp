#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//x — номер строки, y — номер столбца (буква преобразуется в число)
typedef struct {
    int x;
    int y;
} Cell;

//Буква преобразуется в число
Cell convert_cell(char col, int row) {
    Cell cell;
    cell.x = row;
    cell.y = col - 'a' + 1;
    return cell;
}

//Может ли король переместиться на соседнюю клетку
int can_king_move(Cell k1, Cell k2) {
    return abs(k1.x - k2.x) <= 1 && abs(k1.y - k2.y) <= 1;
}

//Может ли ферзь переместиться по прямой линии или по диагонали
int can_queen_move(Cell k1, Cell k2) {
    return (k1.x == k2.x || k1.y == k2.y || abs(k1.x - k2.x) == abs(k1.y - k2.y));
}

//Может ли ладья переместиться по прямой линии
int can_rook_move(Cell k1, Cell k2) {
    return (k1.x == k2.x || k1.y == k2.y);
}

//Может ли слон переместиться по диагонали
int can_bishop_move(Cell k1, Cell k2) {
    return abs(k1.x - k2.x) == abs(k1.y - k2.y);
}

//Может ли конь переместиться "буквой Г" (dx и dy для удобства)
int can_knight_move(Cell k1, Cell k2) {
    int dx = abs(k1.x - k2.x);
    int dy = abs(k1.y - k2.y);
    return (dx == 2 && dy == 1) || (dx == 1 && dy == 2);
}

//Проверка ввода в виде функции (для удобства)
void clear_input_buffer() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    Cell k1, k2;
    char figure;
    char col1, col2;
    int row1, row2;

    printf("Enter the first cell (for example, a1): ");
    while (scanf_s(" %c%d", &col1, 1, &row1) != 2 || col1 < 'a' || col1 > 'h' || row1 < 1 || row1 > 8) {
        printf("Incorrect input. Enter the first cell (for example, a1): ");
        clear_input_buffer();
    }

    printf("Enter the second cell (for example, h8): ");
    while (scanf_s(" %c%d", &col2, 1, &row2) != 2 || col2 < 'a' || col2 > 'h' || row2 < 1 || row2 > 8) {
        printf("Incorrect input. Enter the second cell (for example, h8): ");
        clear_input_buffer();
    }

    printf("Choose figure (K - King, Q - Queen, R - Rook, B - Bishop, N - Knight): ");
    while (scanf_s(" %c", &figure, 1) != 1 || (figure != 'K' && figure != 'Q' && figure != 'R' && figure != 'B' && figure != 'N')) {
        printf("Incorrect input. Choose figure (K - King, Q - Queen, R - Rook, B - Bishop, N - Knight): ");
        clear_input_buffer();
    }

    //Преобразует введенные клетки в координаты x и y
    k1 = convert_cell(col1, row1);
    k2 = convert_cell(col2, row2);

    int can_move = 0;

    //Проверка перемещения фигуры в новую клетку
    switch (figure) {
    case 'K': can_move = can_king_move(k1, k2); break;
    case 'Q': can_move = can_queen_move(k1, k2); break;
    case 'R': can_move = can_rook_move(k1, k2); break;
    case 'B': can_move = can_bishop_move(k1, k2); break;
    case 'N': can_move = can_knight_move(k1, k2); break;
    default: printf("Incorrect figure!\n"); return 1;
    }

    if (can_move) {
        printf("A piece can move from K1 to K2 in one move.\n");
    }
    else {
        printf("A piece cannot move in one move. There may be other shapes:\n");
        if (can_king_move(k1, k2)) printf("King\n");
        if (can_queen_move(k1, k2)) printf("Queen\n");
        if (can_rook_move(k1, k2)) printf("Rook\n");
        if (can_bishop_move(k1, k2)) printf("Bishop\n");
        if (can_knight_move(k1, k2)) printf("Knight\n");
    }

    return 0;
}
