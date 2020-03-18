// leap year function
// Zexin Lin 
// 07/08/2018

#include <stdio.h>

int isLeapYear(int year) {

    if (year % 4 != 0) {
        return 0;
    }
    else if (year % 100 != 0) {
        return 1;
    }
    else if (year % 400 != 0) {
        return 0;
    }
    else {
        return 1;
    }

}


int main(void) {

    int year;
    
    printf("Enter year: ");
    scanf("%d", &year);
    
    if (isLeapYear(year) == 1) {
        printf("%d is a leap year.\n", year);
    }
    else {
        printf("%d is not a leap year.\n", year);
    }

    return 0;
}
