#include <stdio.h>
void main(){
    int c, flag, orca;
    int count[100];
    orca = flag = 0;
    for (int i = 0; i < 100; i++ ){
        count[i] = 0;
    }
    while ((c=getchar()) != EOF){
        flag = 0;
        for(int i = 0; i < 50; i++){
            if (c == count[i]){
                ++count[i+50];
                flag = 1; 
            }
        }
        if(flag == 0){
            count[orca] = c;
            ++count[orca + 50];
            ++orca;
        }
    }
    for (int i = 0; i <50; i++){
        putchar('\n');
        putchar(count[i]);
        for (int j = count[i+50]; j > 0; j--){
            putchar('-');
        }
    }
}