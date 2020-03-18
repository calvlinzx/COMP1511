// printing palindrome which is the same forwards as backwards, ignoring 
// characters which are not letters
// By Zexin Lin (z5217017)
// 31-08-2018

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD 4096

int main(void) {
    
    int i,j;
    int len;
    char string[MAX_WORD];
    int result = 0;
    
    printf("Enter a string: ");
    
    j = 0;
    int c = getchar();
    while (c != EOF) {
        if (isalpha(c)) {
            string[j] = c;
            j++;
        }
        c = getchar();
    }
              
    len = j;
    i = 0;
    if (len > 2) {
        while (i <= len / 2) {
            if (tolower(string[i]) != tolower(string[len - i - 1])) {
                result = 1;   
            }
            i++;
        }
    }
    else if (len == 1){
        result = 1;
    }

    if (result == 1) {
        printf("String is not a palindrome\n"); 
    }
    else {
        printf("String is a palindrome\n");    
    }
    return 0;
}
