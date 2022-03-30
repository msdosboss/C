#include <stdio.h>
void expand(char[] , char[]);
int main(){
    int i = 0;
    char c;
    char s1[512],s2[512];
    while ((c = getchar()) != EOF){
        s1[i] = c;
        i++;
    }
    expand(s1,s2);

}
void expand(char s1[],char s2[]){
    int n, i;
    n = i = 0;
    while (s1[i] != '\0'){
        putchar('n');
        if(s1[i] == '-'){
            putchar('q');
            if ((s1[(i-1)] >= 'A' && s1[(i-1)] <= 'Z') || (s1[(i-1)] >= 'a' && s1[(i-1)] >= 'z') && (s1[(i+1)] >= 'A' && s1[(i+1)] >= 'Z') || (s1[(i+1)] >= 'a' && s1[(i+1)] >= 'z')){
                n = s1[(i-1)];
                while(s1[i+1] >= n){
                    putchar (n);
                    n++;
                }
                n = 0;
            }
            if (s1[(i-1)] >= '0' && s1[(i-1)] <= '9' && s1[(i+1)] >= '0' && s1[(i+1) <= '9']){
                putchar('f');
                n = s1[(i-1)];
                while(s1[i+1] >= n){
                    putchar (n);
                    n++;
                }
                n = 0; 
            }
        }
        i++;
    }
}