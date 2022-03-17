#include "j_getinput.h"
#include <stdio.h>
int semi_bracket_state = 0;
int full_bracket_state = 0;
int par = 0;
int quote = 0;
int main(){
    char s[2000];
    int i = j_getinput(s);
    int j = -1;
    while(i > j){
        j++;
        if(quote) continue;
        switch (s[j]){
            case '{':
            semi_bracket_state++;
            break;
            case '}':
            semi_bracket_state--;
            break;
            case '(':
            par++;
            break;
            case ')':
            par--;
            break;
            case '"':
            quote = !quote;
            break;

        }
    }
    if(semi_bracket_state > 0){
        for(int q = 0;q < semi_bracket_state;q++){
            printf("semi");
        }
    }
    if(par > 0){
        for(int q = 0;q < par;q++){
            printf("par");
        }
    }
    if(quote>0){
        printf("quote");
    }
}