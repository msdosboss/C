#include <stdio.h>
#define MAXLINE 512
int main(){
    int c, i, j, n;
    i = n = j = 0;
    char s[MAXLINE];
    for(i=0;i < MAXLINE;i++){
        s[i]=0;
    }
    i = 0;
    while((c=getchar()) != EOF && i < MAXLINE){
        s[i] = c;
        i++;
    }
    while(j < i){
        while(s[j] !='\n' && n < 10 && s[j] != 0){
            putchar(s[j]);
            j++;
            n++;
        }
        putchar('\n');
        n = 0;
        j++;
    }
}