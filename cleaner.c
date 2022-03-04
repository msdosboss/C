#include<stdio.h>
void main(){
    char s[500];
    int c, len, orca;
    len = 0;
    orca = 0;
    while((c=getchar()) != EOF){
        if(c != '\n'){
            s[len] = c;
            len++;
        }
        else orca = 1;
        if (orca == 1){
            len--;
            while ((s[len] ==' ')|| (s[len]=='\t')|| (s[len]=='\n')){
                
                len--;
            }
            len++;
            for(int i = 0; i < len; i++){
                putchar(s[i]);
            }
                printf("%d\n",len);
            orca = 0;
        }
    }
}