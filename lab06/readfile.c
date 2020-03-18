#include <stdio.h>
#include <stdlib.h> // For exit()
 
int main(int argc, char *argv[])
{
    FILE *fptr;
 
    //char filename[100], c;
 
    //printf("Enter the filename to open \n");
    //scanf("%s", filename);
 
    // Open file
    fptr = fopen(argv[1], "r");
    if (fptr == NULL)
    {
        printf("Cannot open file \n");
        exit(0);
    }
 
    // Read contents from file
    char c = fgetc(fptr);
    int n = 0;
    
    while (c != EOF && n < 10) {
    
        printf ("%c", c);
        if (c == '\n') {
            n++;
        }
        c = fgetc(fptr);
    }
 
    fclose(fptr);
    // printf("%d\n", n);
    return 0;
}

