#include <stdio.h>
#include <stdlib.h>

int main(){
    char m;
    printf("Select mode:\n 1 - first mode\n 2 - second mode\n");
    int incorrect = 0;
    int t = 0;
    do{
        if(incorrect){ printf("Incorrect data. Try again: ");}
        t = scanf(" %c", &m);
        char tc;
        while ((tc = getchar()) != '\n' && tc != EOF){}
        incorrect = 1;
    }
    while(t != 1 || (m != '1' && m != '2'));
    if (m == '1'){
        int a =  (rand() % 1000) + 1;
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
        return 0;
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
                t = scanf(" %c", &c);
                printf("\n");
                char tc;
                while ((tc = getchar()) != '\n' && tc != EOF){}
                incorrect = 1;
            }
            while(t != 1 || (c != '>' && c != '<' && c != '='));
            if(c == '>'){
                l = (l + r)/2+1;
            }
            else{
                r = (l + r)/2-1;
            }
        }
        while (c != '=');
        printf("Total moves: %d", count);
        return 0;
    }
}