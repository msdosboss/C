#include <stdio.h>
void main(){
    char s[500];
    int n, c, i;
    i = 0;
    n = 0;
    while ((c=getchar()) != EOF){
        s[i] = c;
        i++;
    }
    for (int j = 0;j <= i; j++){
        if(s[j] != '\t' && s[j] != '\n'){
            putchar(s[j]);
            if(n > 5){
                n = -1; 
            }
            n++;
        }
        if(s[j] == '\t'){
            while(n < 6){
                putchar(' ');
                n++;   
            }
            n = 0; 

        }
        if(s[j] == '\n'){
            n = 0;
            putchar('\n');
        }
        
    }
}