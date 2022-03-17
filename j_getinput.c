#include <stdio.h>
#define MAXLINE 2000
int j_getinput (char *s){
    int c;
    int i = 0;
    while((c=getchar()) != EOF && i < MAXLINE){
        s[i] = c;
        i++;
    }
    return i;
}