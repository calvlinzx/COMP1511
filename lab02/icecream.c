//Matilda wants to buy some ice-cream!!

#include <stdio.h>

int main(void) {

    int scoop, cost;
    
    printf("How many scoops? ");
    scanf("%d", &scoop);
    printf("How many dollars does each scoop cost? ");
    scanf("%d", &cost);
    
    if (scoop*cost<= 10 ) {
        printf("You have enough money!\n");
    }
    else {
        printf("Oh no, you don't have enough money :(\n");
    }
    
return 0;
}
