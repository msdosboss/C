#include <stdio.h>
void main(){
    char s[500];
    int tab_count = 0;
    int space_count = 0;
    int c, i, j, n;
    i = 0;
    j = 0;
    n = 0;
    while((c=getchar()) != EOF){
        s[i] = c;
        i++;
    }
    while(j < i){
        if(s[j] != ' ' && s[j] != '\t' && s[j] != '\n'){
            putchar(s[j]);
            n++;
            j++;
        }
        else{
            while(s[j] == ' ' && n < 8){
                n++;
                j++;
                space_count++;
            }
            if(n > 7){
                putchar('\t');
                n = 0;
                space_count = 0;
                //j++;
            }
            if(s[j]=='\t'){
                putchar('\t');
                j++;
            }
            while (space_count > 0){
                putchar('-');
                space_count--;
                //n = 0; if this is uncommented it will work on the first the words but after it will not be alligned
            }


        }
    }



}
