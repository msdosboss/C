#include <stdio.h>
void main(){
    char s[500];
    int c, len, orca;
    len = 0;
    orca = 0;
    while((c = getchar()) != EOF){
        if(c != '\n'){
            s[len]= c;
            len++;
        }
        else orca = 1;
        if(len > 20 && orca == 1){
            for(int i=0; s[i]!=0; i++){
                putchar(s[i]);
                s[i]=0;
            }
        }
        if(orca == 1){
            orca = 0;
            len = 0;
            for(int i=0; s[i]!=0; i++){
                s[i]=0;
            }
            putchar('\n');
        }

    }
}

    


    
