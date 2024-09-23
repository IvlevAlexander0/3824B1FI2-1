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

void input_square(char *x, char *y){
    int a;
    char c;
    int incorrect = 0;
    do{
        if(incorrect){ printf("Incorrect data. Try again: ");}
        a = scanf(" %c %c", x, y);
        *x = toupper(*x);
        while ((c = getchar()) != '\n' && c != EOF){}
    }
    while(a != 2 || *x < 'A' || *x > 'H' || *y < '1' || *y > '8' );
}

char validate_king(char x1, char y1, char x2, char y2){
    return abs(x1-x2)<2 && abs(y1-y2) < 2;
}

char validate_queen(char x1, char y1, char x2, char y2){
    return x1 == x2 || y1 == y2 || abs(x1-x2) == abs(y1-y2);
}

char validate_rook(char x1, char y1, char x2, char y2){
    return x1 == x2 || y1 == y2;
}

char validate_bishop(char x1, char y1, char x2, char y2){
    return abs(x1-x2) == abs(y1-y2);
}

char validate_knight(char x1, char y1, char x2, char y2){
    return abs(x1-x2) + abs(y1-y2) == 3 && abs(x1-x2)!= 0 && abs(y1-y2)!=0;
}

void validate_pieces(char x1, char y1, char x2, char y2, char exclude){
    for(int i = 1; i < 6; i++){
        if (i == exclude) continue;
        switch (i)
        {
        case KING:
            if(validate_king(x1, y1, x2, y2)){
                printf(" King ");
            }
            break;
        case QUEEN:
            if(validate_queen(x1, y1, x2, y2)){
                printf(" Queen ");
            }
            break;
        case ROOK:
            if(validate_rook(x1, y1, x2, y2)){
                printf(" Rook ");
            }
            break;
        case BISHOP:
            if(validate_bishop(x1, y1, x2, y2)){
                printf(" Bishop ");
            }
            break;
        case KNIGHT:
            if(validate_knight(x1, y1, x2, y2)){
                printf(" Knight ");
            }
            break;
        }
    }

}

void main(){
    char y1, y2;
    short figure;
    
    char x1, x2;
    printf("Input figure:\n1 - King\n2 - Queen\n3 - Rook\n4 - Bishop\n5 - Knight\n");
    int sc;
    sc = scanf("%hd", &figure);
    
    while(sc != 1 || figure < 1 || figure > 5){
        char c;
        while ((c = getchar()) != '\n' && c != EOF){}
        printf("Incorrect data. Try again: ");
        sc = scanf("%hd", &figure);
    }

    printf("Input first square: ");
    input_square(&x1, &y1);

    printf("Input second square: ");
    input_square(&x2, &y2);

    switch (figure)
    {
    case KING:
        if(validate_king(x1, y1, x2, y2)){
            printf("King can move from %c%c to %c%c\n", x1, y1, x2, y2);
        }
        else{
            printf("King can't move from %c%c to %c%c\n", x1, y1, x2, y2);
            validate_pieces(x1, y1, x2, y2, KING);
        }
        break;
    case QUEEN:
        if(validate_queen(x1, y1, x2, y2)){
            printf("Queen can move from %c%c to %c%c\n", x1, y1, x2, y2);
        }
        else{
            printf("Queen can't move from %c%c to %c%c\n", x1, y1, x2, y2);
            validate_pieces(x1, y1, x2, y2, QUEEN);
        }
        break;
    case ROOK:
        if(validate_rook(x1, y1, x2, y2)){
            printf("Rook can move from %c%c to %c%c\n", x1, y1, x2, y2);           
        }
        else{
            printf("Rook can't move from %c%c to %c%c\n", x1, y1, x2, y2);
            validate_pieces(x1, y1, x2, y2, ROOK);
        }
        break;
    case BISHOP:
        if(validate_bishop(x1, x2, y1, y2)){
            printf("Bishop can move from %c%c to %c%c\n", x1, y1, x2, y2);    
        }
        else{
            printf("Bishop can't move from %c%c to %c%c\n", x1, y1, x2, y2);
            validate_pieces(x1, y1, x2, y2, BISHOP);
        }
        break;
    
    case KNIGHT:
        if(validate_knight(x1, x2, y1, y2)){
            printf("Knight can move from %c%c to %c%c\n", x1, y1, x2, y2);           
        }
        else{
            printf("Knight can't move from %c%c to %c%c\n", x1, y1, x2, y2);
            validate_pieces(x1, y1, x2, y2, KNIGHT);
        }
        break;
    }
}