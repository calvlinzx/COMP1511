// caesar cipher
// 21/08/2018
// By Zexin Lin

#include <stdio.h>
#include <stdlib.h>

int encrypt(int character, int shift) {

    //if (shift < 0) {
        while (shift < 0) {
            shift = shift + 26;
        }
    //}
    
    if (character >= 'a' && character <= 'z') {
        character = (character - 'a' + shift) % 26 + 'a';
    }
    else if (character >= 'A' && character <= 'Z') {
        character = (character - 'A' + shift) % 26 + 'A';
    }
    

    return character;
}

int main(int argc, char *argv[]) {

    int shiftValue; 
    
    shiftValue = atoi(argv[1]);
        
    int c = getchar();
    
    while (c != EOF) {
        c = encrypt(c, shiftValue);
        c = putchar(c); 
        c = getchar(); 
    }
    
    return 0;
}

