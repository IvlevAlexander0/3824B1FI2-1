#include <stdio.h>

int main() {
    char c;
    int part_word=0, part_number=0;
    int count_word=0, count_number=0;
    while ((c = getchar()) != '\n') {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            if (part_word == 0) {
                count_word++;
                part_word = 1;
            }
        }
        else if (c >= 0 && c <= 9) {
            if (part_number == 0) {
                count_number++;
                part_number = 1;
            }
        }
        else if (c == ' ' || c == '\t') {
            part_word = 0;
            part_number = 0;
        }
    } 
    printf("\nWords count is %d", count_word);
    printf("\nNumbres count is %d", count_number);
	return 0;
}