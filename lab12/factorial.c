// Returm the factorial of a non-negative integer
//
//

#include <stdio.h>

long long factorial (long long n) {
    
    long long factorial_ans;
    
    if (n == 0) {
        factorial_ans = 1;
    }
    else {
        factorial_ans = n * factorial(n - 1);
    }
    
    return factorial_ans;
}
