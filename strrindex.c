#include <stdio.h>
#include <string.h>
int strrindex(char[],char[]);
int main(){
    int i = 0;
    char c;
    char s[512];
    char t[] = "test";
    while ((c = getchar()) != EOF){
        s[i] = c;
        i++;
    }
    printf("%d",strrindex(s,t));
}
int strrindex(char s[], char t[]){
    int i = 0; 
    int j = 0;
    int flag = 0;
    int flag2 = 0;
    int offset;
    int orca = strlen(t);

    while (s[i] != '\0'){
        if (s[i] == t[j]){
            flag++;
            j++;
        }
        else j = 0;
        if (flag == orca){
            flag2++;
            offset = (i-flag);
            j = 0;
            flag = 0;
        }
        i++;
    }
    if (flag2){
        return offset; 
    }
    else{
        return -1;
    }
}