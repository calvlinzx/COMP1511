// Prints out an array.
// Created by
// Zexin Lin (z5217017)
// Written on 2018-08-14
// Tutor Elizabeth(Tuesday6pm-8pm-lab)

#include <stdio.h>
#include <assert.h>

void show_array(int size, int array[size]);

// DO NOT CHANGE THIS MAIN FUNCITON
int main(int argc, char *argv[]) {
    // Get the array size.
    int size;
    printf("Enter array size: ");
    assert(scanf("%d", &size) == 1);
    assert(size > 0);

    // Declare the array.
    int array[size];

    printf("Enter array values: ");
    // Initialise the array values.
    int i = 0;
    while (i < size) {
        assert(scanf("%d", &array[i]) == 1);
        i = i + 1;
    }

    show_array(size, array);

    return 0;
}

// Print the array in the format [1, 2, 3, ...]
void show_array(int size, int array[size]) {
    // Put your code here
    int i = 1;
    
    if (size != 1) {
        printf("[%d, ", array[0]);
        
        while (i < size - 1) {
            printf("%d, ", array[i]);
            i++;    
        }
        
            printf("%d]\n", array[size - 1]);
    }
    else {
        printf("[%d]\n",array[0]);
    }   
}
