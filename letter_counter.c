#include <stdio.h>
void main(){
    int legnth[20];
    int c;
    int wc;
    for (int i = 0; i < 20; i++){
        legnth[i] = 0;
    }
    printf("test1");
    while((c=getchar()) != EOF){
        wc = 0;
        while(c != ' ', c != '\t', c != '\n'){
            ++wc;
            putchar('wc');
        }
        ++legnth[wc];
    }
    for (int i = 0; i < 20; i++){
        printf("%d :",i+1);
        for (int j = 0; j < legnth[i]; j++){
            putchar('-');
        } 
    } 
}