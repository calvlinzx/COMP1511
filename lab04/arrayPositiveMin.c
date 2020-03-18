// Find and return the minimum positive value
// from the values in a given array.
// By Zexin Lin (z5217017)
// Written on 2018-08-15
// Tutor Elizabeth(Tuesday 6pm-8pm-lab)


// You need to implement this function

// Returns the minimum positive value from a given array.
// A value is a positive value if it is greater than zero.
// If there are no positive values in a given list,
// the function should return zero.

int arrayPositiveMin(int a[], int size) {
 
    // Implement this function 
    // You also need to change the return value.
    
    int i = 0;
    int curMin = 1000000;
    int tmp = 0;
    
    while (i < size) {
        if (a[i] > 0 && a[i] <= curMin) {
            curMin = a[i];
            tmp = 1;
        }
        i++;    
    }
    if (tmp == 0) {     
        curMin = 0;
    }
    
    return curMin;
    
}
