// Find the average of the values in a given array.
// By Zexin Lin (z5217017)
// Written on 2018-08-14
// Tutor Elizabeth(Tuesday6pm-8pm-lab)

// You need to implement this function

// Calculates the average of all the values in a given array,
// and returns the average value.
double arrayAverage(int a[], int size) {

    // implement this function and 
    // change return value

    int i = 0;
    double sum = 0;
    
    while (i < size) {
        sum = sum + a[i];
        i++;
    }
    
    return sum / size;

}
