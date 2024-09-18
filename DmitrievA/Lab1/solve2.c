#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

enum chess_pieces {
        KING = 1,
        QUEEN = 2,
        ROOK = 3,
        BISHOP = 4,
        KNIGHT = 5
    };

void validate_square(char *x, short *y){
    while(*x < 'A' || *x > 'H' || *y < 1|| *y > 8)
    {
        printf("Incorrect data. Try again: ");
        scanf(" %c %hd", x, y);
        *x = toupper(*x);
    }
}

short validate_king(char x1, short y1, char x2, short y2){
    if (abs(x1-x2)<2 && abs(y1-y2) < 2){
        printf("King can move from %c%d to %c%d\n", x1, y1, x2, y2);
        return 1;
    }
    return 0;
}

short validate_queen(char x1, short y1, char x2, short y2){
    if(x1 == x2 || y1 == y2 || abs(x1-x2) == abs(y1-y2)){
        printf("Queen can move from %c%d to %c%d\n", x1, y1, x2, y2);
        return 1;
    }
    return 0;
}

short validate_rook(char x1, short y1, char x2, short y2){
    if(x1 == x2 || y1 == y2){
        printf("Rook can move from %c%d to %c%d\n", x1, y1, x2, y2);
        return 1;
    }
    return 0;
}

short validate_bishop(char x1, short y1, char x2, short y2){
    if(abs(x1-x2) == abs(y1-y2)){
        printf("Bishop can move from %c%d to %c%d\n", x1, y1, x2, y2);
        return 1;
    }
    return 0;
}

short validate_knight(char x1, short y1, char x2, short y2){
    if(abs(x1-x2) + abs(y1-y2) == 3 && abs(x1-x2)!= 0 && abs(y1-y2)!=0){
        printf("Knight can move from %c%d to %c%d\n", x1, y1, x2, y2);
        return 1;
    }
    return 0;
}

void validate_pieces(char x1, short y1, char x2, short y2, short exclude){
    for(int i = 1; i < 6; i++){
        if (i == exclude) continue;
        switch (i)
        {
        case KING:
            validate_king(x1, y1, x2, y2);
            break;
        case QUEEN:
            validate_queen(x1, y1, x2, y2);
            break;
        case ROOK:
            validate_rook(x1, y1, x2, y2);
            break;
        case BISHOP:
            validate_bishop(x1, y1, x2, y2);
            break;
        case KNIGHT:
            validate_knight(x1, y1, x2, y2);
            break;
        }
    }

}

void main(){
    short y1, y2;
    short figure;
    
    char x1, x2;
    printf("Input figure:\n1 - King\n2 - Queen\n3 - Rook\n4 - Bishop\n5 - Knight\n");
    scanf("%d", &figure);
    while(figure < 1 || figure > 5){
        printf("Incorrect data. Try again: ");
        scanf("%d", &figure);
    }

    printf("Input first square: ");
    scanf(" %c  %hd", &x1, &y1);
    x1 = toupper(x1);
    validate_square(&x1, &y1);

    printf("Input second square: ");
    scanf(" %c  %hd", &x2, &y2);
    x2 = toupper(x2);
    validate_square(&x2, &y2);

    switch (figure)
    {
    case KING:
        if(!validate_king(x1, y1, x2, y2)){
            printf("King can't move from %c%d to %c%d\n", x1, y1, x2, y2);
            validate_pieces(x1, y1, x2, y2, KING);
        }
        break;
    case QUEEN:
        if(!validate_queen(x1, y1, x2, y2)){
            printf("Queen can't move from %c%d to %c%d\n", x1, y1, x2, y2);
            validate_pieces(x1, y1, x2, y2, QUEEN);
        }
        break;
    case ROOK:
        if(!validate_rook(x1, y1, x2, y2)){
            printf("Rook can't move from %c%d to %c%d\n", x1, y1, x2, y2);
            validate_pieces(x1, y1, x2, y2, ROOK);
        }
        break;
    case BISHOP:
        if(!validate_bishop(x1, x2, y1, y2)){
            printf("Bishop can't move from %c%d to %c%d\n", x1, y1, x2, y2);
            validate_pieces(x1, y1, x2, y2, BISHOP);
        }
        break;
    
    case KNIGHT:
        if(!validate_knight(x1, x2, y1, y2)){
            printf("Knight can't move from %c%d to %c%d\n", x1, y1, x2, y2);
            validate_pieces(x1, y1, x2, y2, KNIGHT);
        }
        break;
    }
}