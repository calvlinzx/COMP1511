// Returm the greatest common divisor of two integers, a and b
//
//

#include <stdio.h>

int  gcdRec (int a, int b) {
    int gcd,r;
    if (b != 0) {
        r = a % b;
        if (r == 0) {
            gcd = b;
        }
        else {
            
            gcd = gcdRec(b,r);
        }
    }
    else {
        gcd = a;
    }

    return gcd;
}
