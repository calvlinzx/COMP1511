// print the even integers


#define MAX 10000

#include <stdio.h>

int main(void) {
    
    int num, numRead;
    int array[MAX];
    int i = 0;
    numRead = scanf("%d", &num);
    
    while (numRead == 1) {
        if (num % 2 == 0) {
            array[i] = num;
            i++;    
        }
        numRead = scanf("%d", &num);
    }
    int j = 0;
    while (j < i) {
        printf("%d ", array[j]);
        j++;
    }
    printf("\n");
    return 0;
}
