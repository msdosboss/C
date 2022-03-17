#include <stdio.h>
#include <ctype.h>
#include <math.h>
void htoi(char *);
void reverse(char *,int);
int main(){
    int c,j;
    char s[512];
    j = 0;
    for(register int i = 0;i < 512; i++) s[i] = 0;
    while((c=getchar()) != EOF && c != '\n'){
        s[j] = c;
        j++;
    }
    reverse(s,j);
    htoi(s);
}
void htoi(char *s){
    double ans;
    ans = 0;
    int j = 0;
    for(int i = 0;s[i] != 0 && i < 512;i++){
        if(isdigit(s[i])){
            s[i] = s[i]-'0';  
            ans = (pow(16,i)*s[i]) + ans;  
            continue;
        }
        s[i] = tolower(s[i]);
        s[i] = s[i] - 'W';            //(f - W = 15)
        ans = pow(16,i)*s[i] + ans;   //fa673b = 16,410,427
    }
    printf("%f",ans);
}
void reverse(char s[],int j){
    int q = 0;
    char temp[512];
    for(int i = 0;i < 512; i++) temp[i] = 0;
    for (;j >= 0; j--){
        temp[q] = s[j-1]; 
        q++; 
    }
    for (int i = 0;temp[i]!=0;i++){
        s[i]=temp[i];
    }
}
