#include <stdio.h>

int main() {
    char c;
    int part_word=0, part_number=0;
    int count_word=0, count_number=0;
    int wrong = 0;
    while ((c = getchar()) != '\n') {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            if (!part_word && !part_number) {
                count_word++;
                part_word = 1;
            }
            if (part_number) {
                wrong = 1;
            }
        }
        else if (c >= '0' && c <= '9') {
            if (!part_number && !part_word) {
                count_number++;
                part_number = 1;
            }
            if (part_word) {
                wrong = 1;
            }
        }
        else if (c == ' ' || c == '\t') {
            if (wrong) {
                if (part_word) {
                    count_word--;
                }
                if (part_number) {
                    count_number--;
                }
            }
            part_word = 0;
            part_number = 0;
            wrong = 0;
        }
        else {
            wrong = 1;
        }
    }
    if (wrong) {
        if (part_word) {
            count_word--;
        }
        if (part_number) {
            count_number--;
        }
    }
    printf("\nWords count is %d", count_word);
    printf("\nNumbres count is %d", count_number);
	return 0;
}