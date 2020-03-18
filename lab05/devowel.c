// delete the vowels
// 21/08/2018
// By Zexin Lin

#include <stdio.h>


int is_vowel(int character) {

    if (character == 'a' || character == 'e' || character == 'i' || character == 'o' || character == 'u') {
        return 1;
    }
    else {
        return 0;
    }

}

int main(void) {

    int c = getchar();
    
    while (c != EOF) {
        if (is_vowel(c) == 0) {
            putchar(c);
        }
        c = getchar();
    }

    return 0;
}
