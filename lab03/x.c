// X
// Zexin Lin 
// 07/08/2018

#include <stdio.h>

int main(void) {

    int row, column;
    int num;
    
    printf("Enter size: ");
    scanf("%d", &num);
    
    row = 1;
    while (row <= num) {
        column = 1;
        //if (row == (num + 1) / 2) {
            //while (column <= num) {
                //if (column == (num + 1) / 2) {
                    //printf("*");
                //}
                //else {
                    //printf("-");
                //}
                //column ++;
            //}
        //}
       // else {
            while (column <= num) {
                if (column == row || column == num - row + 1) {
                    printf("*");
                }
                else {
                    printf("-");
                }
                column ++;
            }
        }
        printf("\n");
        row ++;
    }

    
    return 0;
}
