#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXOP 100
#define NUMBER '0'

int getop(char []);
void push(double);
double pop(void);
void clear(void);
void top(void);

main(){
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF){
        switch (type){
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if(op2 != 0.0){
                    push(pop() / op2);
                    break;
                }
                else{
                    printf("you / by 0");
                }
            case '%':
                op2 = pop();
                push(fmod(pop(),op2));
                break;
            case '\n':
                printf("\t%.8lf\n", pop());
                break;
            default:
                printf("error: unkown command %s\n", s);
                break;
        }
    }
}

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push(double f){
    if(sp < MAXVAL){
        //for(int i=0; i < 10;i++){
          //  printf(" %lf",val[i]);
        // }
        val[sp++] = f;
    }
    else{
        printf("error: stack full can't push");
    }
}

double pop(void){
    if(sp > 0){
        return val[--sp];
    }
    else{
        printf("error: stack empty");
        return 0.0;
    }
}
void clear(void){
    for(int i = 0; i < MAXVAL; i++){
        val[i] = 0;
    }
}
void top(void){
    
}


#include <ctype.h>

int getch(void);
void ungetch(int);

int getop(char s[]){
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if(!isdigit(c) && c != '.'){
        return c;
    }
    i = 0;
    if (isdigit(c)){
        while (isdigit((s[++i] = c = getch()))){ 
            printf(" %d ",c);
        }
    }
    //for(int i = 0; i < 10; i++){
    //        printf("%c",s[i]);
    //    }
    if (c == '.'){
        while (isdigit(s[++i] = c = getch()))
            ;
    }
    s[i] = '\0';
    if (c != EOF){
        ungetch(c);
    }
    return NUMBER;
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
