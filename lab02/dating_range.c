//dating_range
//Lin Zexin
//31/07/2018

#include <stdio.h>

int main(void) {

    int age, lower, upper;
    
    printf("Enter your age: ");
    scanf("%d", &age);
    
    if (age>14) {
        lower = age/2+7;
        upper = (age-7)*2;
        printf("Your dating range is %d to %d years old.\n",lower, upper);    
    }

    else {
        printf("You are too young to be dating.\n");
    }

    return 0;
}
