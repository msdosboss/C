#include <stdio.h>
main(){
    int flag = 0;
    char c;
    c = getchar();
    while(c !=EOF){
        if ( c != ' '){
            putchar(c);
            flag = 0;
        }
        else if (c == ' '&& flag == 0){
            putchar(c);
            flag = 1;
        }
        else if(c == ' ' && flag == 1){}
        else{
        putchar(c);
        flag=0;
        }
    c = getchar();
    }
}