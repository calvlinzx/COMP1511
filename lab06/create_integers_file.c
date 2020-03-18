// create a file containing integers between the first and second arguments
// By Zexin Lin (z5217017)
// 28-08-2018

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    FILE *outputStream;

    outputStream = fopen(argv[3], "a");
    if (outputStream == NULL) {
        fprintf(stderr, "%s: open of file failed\n", argv[0]);
        return 1;
    }
    
    if (atoi(argv[1]) > atoi(argv[2])) {
        fprintf(stderr, "%s: creating file failed\n", argv[0]);
        return 1;
    }
    else {
        int i = atoi(argv[1]);
        while (i <= atoi(argv[2])) {
            fprintf(outputStream, "%d\n", i);
            i++;
        }
    }
    fclose(outputStream);

    return 0;
}
