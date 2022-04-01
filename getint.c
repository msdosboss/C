#include <ctype.h>
#include <stdio.h>



int getch(void);
void ungetch(int);
int getint(int*);


int main(){
    int orca[10];
    for(int i = 0; i < 10; i++){
        orca[i] = 0;
    }
    for(int i = 0; i < 10 && getint(&orca[i]) != EOF; i++)
        printf(" %d ",orca[i]);
}

int getint(int *pn){
    int c, sign;

    while(isspace(c = getch()))
    ;
    if(!isdigit(c) && c != EOF && c != '+' && c != '-'){
        ungetch(c); 
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '-' || c == '+'){
        while(!isdigit((c = getch())))
            ;
    }
    for (*pn = 0; isdigit(c); c = getch()){
        *pn = 10 * *pn + (c - '0');
    }
    *pn *= sign;
    if (c != EOF){
        ungetch(c);
    }
    return c;

}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void){
    return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c){
    if(bufp >= BUFSIZE){
        printf("ungetch: too many chars\n");
    }
    else{
        buf[bufp++] = c;
    }
}