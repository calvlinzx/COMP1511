// print the frequency of the last input


#define MAX 10000

#include <stdio.h>

int main(void) {

    int num, numRead;
    int array[MAX];
    int i = 0;
    numRead = scanf("%d", &num);
    
    while (numRead == 1) {        
        array[i] = num;
        i++;    
        numRead = scanf("%d", &num);
    }
    int j = 0;
    int counter = 0;
    // printf("%d\n", i);
    while (j < i) {
    
        if (array[j] == array[i - 1]) {
            counter++;
        }
        j++;
    }
    printf("%d\n", counter);
    return 0;
}
