// frequency analysis
// 22/08/2018
// By Zexin Lin

#include <stdio.h>
#include <ctype.h>


int main(void) {

    int letter_count['z'+1];
    int i;
    double total_count;
    
    i = 'a';
    while (i <= 'z') {
        letter_count[i] = 0;
        i++;
    }
    
    int ch = getchar();
    while (ch != EOF) {
        ch = tolower(ch);
        if (ch >= 'a' && ch <= 'z') {
            letter_count[ch]++;
        }
        ch = getchar();
    }
    
    i = 'a';
    total_count = 0;
    while (i <= 'z') {
        total_count = total_count + letter_count[i];
        i++;
    }
    
    i = 'a';
    while (i <= 'z') {
        printf("'%c' %lf %d\n", i, letter_count[i] / total_count, letter_count[i]);
        i++;
    }    
    
    return 0;
} 
