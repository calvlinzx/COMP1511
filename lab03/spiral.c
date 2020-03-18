#include <stdio.h>

int main(void) {
    int num;
    int row, column;
    
    // Obtain input
    printf("Enter size: ");
    scanf("%d", &num);

    row = 1;
    while (row <= num) {
        column = 1;
        while (column <= num / 2 + 1 ) { // left 
            if (row % 2 != 0) { // odd row left
                if (row == 1 || row == num) {
                    printf("*");
                }
                else {
                    //if (num % 4 == 1) {
                        if (row <= num / 2 + 1) {// top including middle 
                            if (column < row - 2 && column % 2 == 0) {
                                printf("-");
                            }
                            else {
                                printf("*");
                            }
                        }    
                        else { // left bottom
                            if (column < num + 2 -row && column % 2 == 0) {
                                printf("-");
                            }
                            else {
                                printf("*");
                            }
                        }
                }
            }
            else { // even row left
                if (row == 2) {
                    printf("-");
                }
                else {
                    if (num % 4 == 1) {
                        if (row <= num / 2) { // left top
                            if (column < row -2 && column % 2 != 0) {
                                printf("*");    
                            }
                            else {
                                printf("-");
                            }
                        }
                        else { 
                            if (column < num + 1 -row && column % 2 != 0) {
                            printf("*");
                            }
                            else {
                            printf("-");
                            }
                        }
                    }
                    else {
                        if (row <= num / 2) { // left top
                            if (column < row -2 && column % 2 != 0) {
                                printf("*");    
                            }
                            else {
                                printf("-");
                            }
                        }
                        else if (row == num / 2 + 1) {
                            if (column < row - 1 && column % 2 != 0) {
                                printf("*");
                            }
                            else {
                                printf("-");
                            }    
                        }
                        else { 
                            if (column < num + 1 -row && column % 2 != 0) {
                            printf("*");
                            }
                            else {
                            printf("-");
                            }
                        }
                    }   
                }
            }
            column ++;
        }
        while (column > (num / 2 + 1) && column <= num) { // right part
            if (row % 2 != 0) { // odd row
                if (row == 1 || row == num) {
                    printf("*");
                }
                else {
                    if (row <= num / 2 + 1) {
                        if (column > (num + 1 - row) && column % 2 == 0) {
                            printf("-");
                        }
                        else {
                            printf("*");
                        }
                    }    
                    else { 
                        if (column > row && column % 2 == 0) {
                            printf("-");
                        }
                        else {
                            printf("*");
                        }
                    }
                }
            }
            else { 
                if (row <= num / 2) { 
                    if (column > (num + 1 - row) && column % 2 != 0) {
                        printf("*");    
                    }
                    else {
                        printf("-");
                    }
                }
                else { 
                    if (column > row && column % 2 != 0) {
                        printf("*");
                    }
                    else {
                        printf("-");
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
