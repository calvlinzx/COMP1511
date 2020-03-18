// printing palindrome which is the same forwards as backwards
// By Zexin Lin (z5217017)
// 28-08-2018

#include <stdio.h>
#include <string.h>

#define MAX_WORD 4096

int main(void) {
    
    int i = 0;
    int len;
    char string[MAX_WORD];
    int result = 0;
    
    printf("Enter a string: ");
    
    while (fgets(string, MAX_WORD, stdin) != NULL) {
    
        len = strlen(string);
        if (len > 2) {
            while (i <= len / 2) {
                if (string[i] != string[len - i - 2]) {
                    result = 1;   
                }
                i++;
            }
        }
        else if (len == 2){
            result = 1;
        }

    }
    if (result == 1) {
        printf("String is not a palindrome\n"); 
    }
    else {
        printf("String is a palindrome\n");    
    }
    return 0;
}
