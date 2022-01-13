#include <stdio.h>
main(){
    int c, nl, tab, blank;
    nl = 0;
    tab = 0;
    blank = 0;
    while ((c=getchar()) != EOF){
        if (c == '\n'){
            ++nl;
        }
        if (c == '\t'){
            ++tab;
        }
        if (c == ' '){
            ++blank;
        }
        printf("#of nl %d #of tab %d #of blanks %d\n", nl, tab, blank);
    } 
}