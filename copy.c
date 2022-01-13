#include <stdio.h>
void main(){
    int flag = 0;
    int orca = 5;
    int c = getchar();
    while (c != EOF){
        putchar(c);
        c = getchar();
        flag = flag + 1;
        if (flag == orca){
            c = -1;
            printf("test");
        }
        
    }
}