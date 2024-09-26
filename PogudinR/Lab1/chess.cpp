#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int x; 
    int y; 
} Cell;

Cell convert_cell(char col, int row) {
    Cell cell;
    cell.x = row;              
    cell.y = col - 'a' + 1;    
    return cell;
}

int can_king_move(Cell k1, Cell k2) {
    return abs(k1.x - k2.x) <= 1 && abs(k1.y - k2.y) <= 1;
}

int can_queen_move(Cell k1, Cell k2) {
    return (k1.x == k2.x || k1.y == k2.y || abs(k1.x - k2.x) == abs(k1.y - k2.y));
}

int can_rook_move(Cell k1, Cell k2) {
    return (k1.x == k2.x || k1.y == k2.y);
}

int can_bishop_move(Cell k1, Cell k2) {
    return abs(k1.x - k2.x) == abs(k1.y - k2.y);
}

int can_knight_move(Cell k1, Cell k2) {
    int dx = abs(k1.x - k2.x);
    int dy = abs(k1.y - k2.y);
    return (dx == 2 && dy == 1) || (dx == 1 && dy == 2);
}

int main() {
    Cell k1, k2;
    char figure;
    char col1, col2;
    int row1, row2;

    printf("Enter the first cell (for example, a1): ");
    scanf_s(" %c%d", &col1, &row1);
    printf("Enter the second cell (for example, h8): ");
    scanf_s(" %c%d", &col2, &row2);
    printf("Choose figure (K - king, Q - Quenn, R - Rook, B - Bishop, N - Knight): ");
    scanf_s(" %c", &figure);

    k1 = convert_cell(col1, row1);
    k2 = convert_cell(col2, row2);

    int can_move = 0;

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
