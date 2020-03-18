// three or five
// Zexin Lin 
// 07/08/2018

#include <stdio.h>

int main(void) {

    int num, counter;
    
    printf("Enter number: ");
    scanf("%d", &num);
    
    counter = 1;
    while (counter < num) {
        if (counter % 3 == 0 || counter % 5 == 0) {
            printf("%d\n", counter);
            counter ++;
        }
        else {
            counter ++;
        }
        
    }
    
    return 0;
}
