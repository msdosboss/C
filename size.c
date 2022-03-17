#include <stdio.h>
#include <limits.h>
#include <float.h>
int main(){
    int lim = 500;
    char c;
    char s[500];
    for(int i = 0; i<lim-1; i++){
        if ((c = getchar())!=EOF){
            if(c !='\n'){
                s[i]=c;
                continue;
            }    
        }
        i = lim;
    }
} 