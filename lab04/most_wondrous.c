// Print Wondrous
// Created by
// By Zexin Lin (z5217017)
// Written on 2018-08-16
// Tutor Elizabeth(Tuesday6pm-8pm-lab)

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // PUT YOUR CODE HERE
    
    unsigned long long int num = 2;
    int counter = 1;
    
    while (counter <= 1234) {
        counter = 1;
        while (num >= 2) {
            printf("%lld\n", num);   
            if (num % 2 == 0) {
                num = num / 2;
            }
            else { // (num % 2 == 1) 
                num = num * 3 + 1;
            }
            counter++;
        
        printf("%d\n", counter);
        
        
        }
    }
    
    return 0; 
}
