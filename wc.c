#include <stdio.h>
void main(){
    int legnth[20];
    int c;
    int wc;
    for (int i = 0; i < 20; i++){
        legnth[i] = 0;
    }
    wc = 0;
    while((c=getchar()) != EOF){
        if(c == ' ' || c == '\t' || c == '\n'){
            ++legnth[wc];
            wc = 0;
        }
        else{
            ++wc;
        }

    }
    for (int i = 0; i < 20; i++){
        printf("\n%d :",i);
        for (int j = 0; j < legnth[i]; j++){
            putchar('-');
        } 
    } 
}