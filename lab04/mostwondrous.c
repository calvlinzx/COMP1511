// Print Wondrous
// Created by
// By Zexin Lin (z5217017)
// By Phan Nguyen (z5158422)
// Written on 2018-08-16
// Tutor Elizabeth(Tuesday6pm-8pm-lab)

#include <stdio.h>
#include <stdlib.h>

int printWondrous(unsigned long long int num);

// DO NOT CHANGE THIS MAIN FUNCTION
int main (int argc, char *argv[]) {
    // Get the number.
     unsigned long long int number;
    printf ("Enter a number: ");
    scanf("%lld", &number);

    // Call printWondrous and save the count.
    int count = printWondrous(number);

    printf("The count is %d.\n", count);

    return EXIT_SUCCESS;
}
// END OF MAIN FUNCTION

int printWondrous(unsigned long long int num) {
    // PUT YOUR CODE HERE
    
    int counter = 1;
    
    // printf("%d ", num);
    if (num != 1) {
        while (num >= 2) {
            
            if (num % 2 == 0) {
                num = num / 2;
                if (num != 1) {
                    // printf("%d ", num);
                }
                else {
                    // printf("%d\n", num);
                }
            }
            else { // (num % 2 == 1) 
                num = num * 3 + 1;
                // printf("%d ", num);
            }
            counter++;
        }
    }
    else {
        printf("\n");
    }
    
    return counter; // CHANGE THIS TO YOUR RETURN VALUE
}
