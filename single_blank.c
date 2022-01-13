#include <stdio.h>
main(){
    int flag = 0;
    char c,l;
    c = l = getchar();
    while(c !=EOF){
        if ( c != ' '){
            putchar(c);
    }
        else if (l == ' '&& flag == 0){
            putchar(c);
            flag = 1;
        }
        else if(l == ' ' && flag == 1){}
        else{
        putchar(c);
        }
    c = getchar();
    l=c;
    }
}