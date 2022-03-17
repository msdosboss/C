#include "j_getinput.h"
#include <stdio.h>
int state = 0;
int main(){
    int i;
    char s[512];
    int j = i = 0;
    i = j_getinput(s);
    while (j < i){
        if (s[j] == '"') state = !state;
        if(state == 0){
            if (s[j] == '/' && s[j++] =='/'){
                while (s[j] != '\n'){
                    j++;
                }
                continue;            
            }
        }
        putchar(s[j]);
        j++;
    }
}