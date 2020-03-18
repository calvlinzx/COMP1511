// prints the first 10 lines of the file
// If the file has less than 10 lines the entire file should be printed
// pass -n to specify different number of lines to be printed 
// By Zexin Lin (z5217017)
// 28-08-2018

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]) {

    int line_num;
    FILE *inputStream;

    if (argc == 2) {
        inputStream = fopen(argv[1], "r");
        
        if (inputStream == NULL) {
            fprintf(stderr, "%s: file reading failed\n", argv[1]);
            return 1;
        }
        
        char ch = fgetc(inputStream);
        int n_count = 0;
        while (ch != EOF && n_count < 10) {
        
            if (ch == '\n') {
                n_count++;
            }
            printf("%c", ch);
        
            ch = fgetc(inputStream); 
        }
        fclose(inputStream);
    }
    else if (argc == 4 && strcmp(argv[1], "-n") == 0) {
        inputStream = fopen(argv[3], "r");
        
        if (inputStream == NULL) {
            fprintf(stderr, "%s: file reading failed\n", argv[3]);
            return 1;
        }
    
        char ch = fgetc(inputStream);
        int n_count = 0;
        while (ch != EOF && n_count < atoi(argv[2])) {
        
            if (ch == '\n') {
                n_count++;
            }
            printf("%c", ch);
        
            ch = fgetc(inputStream); 
        }
        fclose(inputStream);
    }
    else {
        printf("Wrong input...\n");
    } 
    

    return 0;

}
