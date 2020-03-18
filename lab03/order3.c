// order of 3 integers
// Zexin Lin 
// 07/08/2018

#include <stdio.h>

int main(void) {

    int a,b,c;
    
    printf("Enter integer: ");
    scanf("%d", &a);
    
    printf("Enter integer: ");
    scanf("%d", &b);
    
    printf("Enter integer: ");
    scanf("%d", &c);
    //printf("The integers in order are: ");
    if (a < b ) {
        if (c < a) {
            printf("The integers in order are: %d %d %d\n", c, a, b);
        }
        else if (b < c) {
            printf("The integers in order are: %d %d %d\n", a, b, c);
        }
        else {
            printf("The integers in order are: %d %d %d\n", a, c, b);
        }
    } 
    else { //b<a
        if (c < b) {
            printf("The integers in order are: %d %d %d\n", c, b, a);
        }
        else if (a < c) {
            printf("The integers in order are: %d %d %d\n", b, a, c);
        }
        else {
            printf("The integers in order are: %d %d %d\n", b, c, a);
        }    
    }

    return 0;
}
