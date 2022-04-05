#include <stdio.h>
#include <ctype.h>

void strcat1(char * , char *);
int strend(char *, char *);
char *strncpy1(char *, char *, int);
void strncat1(char *, char *, int);

int main(){
    int i = 0;
    char *s, *t;
    char x[50] , y[50];
    scanf("%s", x);
    scanf("%s", y);
/*    for (int i = 0; x[i] != '\n'; i++){
      x[i] = getchar();
    }
    for (int i = 0; y[i] != '\n'; i++){
        y[i] = getchar();
    }*/
    s = x;
    t = y;    
    strncat1(s,t,3);
    //printf("%d",strend(s , t));
    //strncpy1(s,t,5);
    //printf("--%s--",t);
    printf("-- %s --",s);
}

void strcat1(char *s,char *t){
    while (*++s != '\0')
        ;
    while((*s++ = *t++) != '\0')
        ;
}
int strend(char *s,char *t){
    int len = 0;
    while(*++s !='\0')
        ;
    while(*++t !='\0'){
        len++;
    }
    s = s - len;
    t = t - len;
    for(int i = 0;i < len; i++){
        if (*s++ == *t++){

        }
        else{
            return 0;
        }
    }
    return 1;


}
char *strncpy1(char *s,char *t, int n){
    for (int i = 0; i < n; i++){
        *(t+i)=*(s+i);
    }
    return t;
}
void strncat1(char *s,char *t,int n){
    int i = 0;
    while (*++s != '\0')
        ;
    while((*s++ = *t++) != '\0' && i < (n-1)){
        i++;
    }
}

int strncmp(char *s, char *t, int n){
    for(int i = 0; i < n; i++){
        if (*s++ == *t++){

        }
        else{
            return *s - *t;
        }
        if (*s == '\0'){
            return 0;
        }
        return 0;
    }
}