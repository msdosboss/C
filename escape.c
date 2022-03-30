#include <stdio.h>
char* escape(char s[],char t[]);
char* reverse(char s[],char t[]);
int main(){
    char x[512];
    char y[512];
    char *z;
    char c;
    int i = 0;
    while(i < 512){
        x[i] = 0;
        y[i] = 0;
        i++;
    }
    i = 0;
    while ((c = getchar()) != EOF){
        x[i] = c;
        i++;
    }
    z = escape(x, y);
    i = 0;
    while(z[i] != 0){
        putchar(z[i]);
        i++;
    }
}
char* escape(char s[], char t[]){
    int n = 0;
    int j = 0;
    while(s[n] != 0){
        switch (s[n]){
            case '\t':
                t[j] = '/';
                j++;
                t[j] = 't';
                break;    
            case '\n':
                t[j] = '/';
                j++;
                t[j] = 'n';
                break;
            default:
                t[j] = s[n];
        }
        j++;
        n++;
    }
    return t;
}
char* reverse(char s[], char t[]){
    int n = 0;
    while(t[n] != 0){
        switch (t[n]){
            
        }
    }
}
