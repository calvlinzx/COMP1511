#include <stdio.h>

int main(void) {
    int num;
    int row, column;
    
    // Obtain input
    printf("How many boxes: ");
    scanf("%d", &num);

    row = 1;
    while (row <= (num * 4 - 1)) {
        column = 1;
        while (column <= (num * 4 - 1)) {
            if (row % 2 == 0) {
                if (row <= 2 * num) {
                    if ((column < row || column > num * 4 - row) && column % 2 != 0) {
                        printf("#");
                    }
                    else {
                        printf(" ");
                    }
                }
                else { // row > 2 * num
                    if ((column < num * 4 - row || column > row) && column % 2 != 0) {
                        printf("#");
                    }
                    else {
                        printf(" ");
                    }
                }    
            }
            else { // row % 2 != 0
                if (row <= 2 * num) {
                    if ((column < row || column > num * 4 - row) && column % 2 == 0) {
                        printf(" ");
                    }
                    else {
                        printf("#");
                    }   
                }
                else { // row > 2 * row
                    if ((column < num * 4 - row || column > row) && column % 2 == 0) {
                        printf(" ");
                    }
                    else {
                        printf("#");
                    }   
                }
            }
            column ++;
        }
        
        printf("\n");
        row = row + 1;
    }

    return 0;
}
