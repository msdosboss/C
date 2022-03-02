#include <stdio.h>
void main(){
    char s[500];
    int c, len;
    len = 0;
    while((c = getchar()) != EOF && c != '\n'){
        s[len]= c;
        len++;
    }
    if(len>79){
        for(int i=0;s[i]!=0;i++){
            putchar(s[i]);
        }
    }
}

    
