// Find and print the first, middle, and last elements of an array.
// Created by
//  Zexin Lin (z5217017)
//  Phan Nguyen (z5158422)
// Written on 2018-08-14
// Tutor Elizabeth(Tuesday6pm-8pm-lab)

#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 1024

void printFirstMiddleLast(int size, int array[MAX_LENGTH]);

// DO NOT CHANGE THIS MAIN FUNCTION
int main(int argc, char *argv[]) {
    // Get the array size.
    int size;
    printf("Enter array size: ");
    scanf("%d", &size);

    // Declare the array.
    int array[MAX_LENGTH];

    printf("Enter array values: ");
    // Intialise the array values.
    int i = 0;
    while (i < size) {
        scanf("%d", &array[i]);
        i = i + 1;
    }

    printFirstMiddleLast(size, array);

    return 0;
}

// Print the first, middle, and last values of an array,
// on separate lines.
void printFirstMiddleLast(int size, int array[MAX_LENGTH]) {
    // Your code goes here!
    int a,b,c;
   
    a = array[0];
    b = array[size - 1];
    c = array[size / 2];
    
        printf("%d\n%d\n%d\n", a, c, b);
   
}
