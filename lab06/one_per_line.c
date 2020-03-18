// one character every line
// By Zexin Lin (z5217017)
// 28-08-2018

#include <stdio.h>

#define MAX_WORD 4096

int main(void) {
    
    int i;
    char string[MAX_WORD];
    
    printf("Enter a string: ");
    
    while (fgets(string, MAX_WORD, stdin) != NULL) {
        i = 0;
        while (string[i] != '\n') {
            printf("%c\n", string[i]);
            i++;
        }
    }
    
    return 0;

}
