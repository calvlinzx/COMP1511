// prints the first 10 lines of the file
// If the file has less than 10 lines the entire file should be printed
// pass -n to specify different number of lines to be printed 
// By Zexin Lin (z5217017)
// 28-08-2018

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count_line_number(FILE *stream);

int main(int argc, char *argv[]) {

    int line_num;
    FILE *inputStream;

        inputStream = fopen(argv[1], "r");
        
        if (inputStream == NULL) {
            fprintf(stderr, "%s: file reading failed\n", argv[1]);
            return 1;
        }
        
        char ch = fgetc(inputStream);
        int n_count = 0;
        int total = count_line_number(inputStream);
        while (ch != EOF && n_count < total - 10) {
        
            if (ch == '\n') {
                n_count++;
            }
            printf("%c\n", ch);
        
            ch = fgetc(inputStream); 
        }
        fclose(inputStream);

    return 0;
    printf("\n%d\n", total);
} 

int count_line_number(FILE *stream) {

    char c = fgetc(stream);
    int line_num = 0;
    while(c != EOF) {
        if (c == '\n') {
            line_num++;
        }
        c = fgetc(stream);
    }

    return line_num;
}
   
