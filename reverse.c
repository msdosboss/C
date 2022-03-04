#include <stdio.h>
void reverse(char s[500],int j);
void main(){
    int c, i;
    char s[500];
    i = 0;
    while(( c = getchar()) != EOF){
        if (c != '\n'){
            s[i] = c;
            i++;
        }
        else reverse(s,i-1);
    }
}
void reverse(char s[500],int j){
    for (int k = j;k >= 0; k--){
        putchar (s[k]);
    }
    putchar('\n');
}