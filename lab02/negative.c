//Don't be so negative

#include <stdio.h>

int main(void) {

    double num = 0;
    scanf("%lf", &num);
    
    if (num > 0) {
        printf("You have entered a positive number.\n");
    }
    else if (num < 0) {
        printf("Don't be so negative!\n");
    }
    else {
        printf("You have entered zero.\n");
    }

return 0;
}
