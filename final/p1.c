#include <stdio.h>



int main(void) {
    /*char s[] = "Hello World!";
    char *cp = s;
    char *cp2 = &s[8];
    
    printf("%p\n", s);
    printf("%p\n", cp);
    printf("%c\n", *cp);
    printf("%c\n", cp[6]);
    printf("%s\n",cp2);
    printf("%c\n",*cp2);
    
    char goals[] = "all your goals belong to us.";
    char *a, *b, *c;

    a = goals + 5;
    b = &goals[10];
    c = goals + (b - goals) + (b - a);
    
    printf("a is %s\n", a);
    printf("%d\n", goals[a - goals] == *a);
    
    printf("b is %s\n", b);
    printf("%d\n", a[0] != b[0]);
    
    printf("c is %s\n", c);
    printf("%d\n", c - b);
    printf("*c is %c\n", *c);
    printf("a-b is %d\n", a - b);
    printf("c is %c%c%c%c%c\n", c[-1],c[-2],c[-3],c[-4],c[-5]);
    
    
    int i;
    char *str = "Hello";
    for (i = 0; str[i] != '\0'; i++) {
        putchar(str[i]);
    }
    printf("%d!!!!\n",i);
    */
    int x = 5, *z = &x;
    *z = *z + 3;
    z++;
    x++;
    printf("%d\n", x);   
    return 0;
}




// x/y <= x/y

// argc is the number of arguments in the comment line

// argv[0] is ./p1, max = argc - 1

// x % y is the remainder
// if x is negative, then the remainder is also negative

// strcmp(s1, s2) == 0 if s1 and s2 are the same
// if not the same, it cmps the first letter by lexicographic order
// if s1 is after s2, strcmp > 0; if s1 is before s2, strcmp < 0
  
// pointer is a data tpye storing address
   
// variable names only use letters, digits and underscore
// the first lettr of a variable is a letter or underscore

// array[0][0] is the left top corner
// fot array[i][j], i is the column number, j is the row number



