// detect outliers
// Zexin Lin 
// 07/08/2018

#include <stdio.h>

int main(void) {

    int number, noRead;
    int counter = 0;
    
    printf("Enter number: ");
    noRead = scanf("%d", &number);
    
    while (noRead == 1) {
        if (number >= 5 && number <= 25) {
           
            counter = counter + 0;
        }
        else {
            
            counter = counter + 1;
        }
    
        printf("Enter number: ");
        noRead = scanf("%d", &number);
    }
    
    printf("\nOutliers: %d\n", counter);
    
    return 0;
}
