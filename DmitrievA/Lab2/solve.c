#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    char m;
    printf("Select mode:\n 1 - first mode\n 2 - second mode\n");
    int incorrect = 0;
    int t = 0;
    do{
        if(incorrect){ printf("Incorrect data. Try again: ");}
        m = getchar();
        incorrect = 1;
    }
    while(m != '1' && m != '2');
    if (m == '1'){
        srand(time(NULL));
        int a =  ( rand() % 1000) + 1;
        int temp = 0;
        int count = 0;
        while(temp != a){
            count++;
            printf("input the number: ");
            int incorrect = 0;
            do{
                if(incorrect){ printf("\nNot a number. Try again: ");}
                t = scanf(" %d", &temp);
                char tc;
                while ((tc = getchar()) != '\n' && tc != EOF){}
                incorrect = 1;
            }
            while(t != 1);
            if(temp < a){
                printf("\nThe number guessed is higher\n");
            }
            else if(temp > a ){
                printf("\nThe number guessed is less\n");
            }
        }
        printf("You guessed the number. Total moves: %d", count);
    }
    else{
        char c;
        int l, r;
        l = 1;
        r = 1000;
        int count = 0;
        do{
            count++;
            printf("is guessed number %d?\n" , (l+r)/2);
            incorrect = 0;
            do{
                if(incorrect){ printf("Incorrect data. Try again: ");}
                c = getchar();
                printf("\n");
                incorrect = 1;
            }
            while(c != '>' && c != '<' && c != '=');
            if(c == '>'){
                l = (l + r)/2+1;
            }
            else{
                r = (l + r)/2-1;
            }
        }
        while (c != '=' && l != r);
        if (l == r){
            printf("guessed number is %d", l);
        }
        printf("Total moves: %d", count);
    }
    return 0;
}