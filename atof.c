#include <ctype.h>
#include <stdio.h>
double atof(char[]);
int main(){
    printf("%lf",atof("1231231232.366e-6"));
}
double atof(char s[]){
    double val, power, flag;
    int i, sign, sign2;
    for (i = 0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++){
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    if (s[i] == 'e')
        i++;
    printf(" %d ",i);
    sign2 = (s[i] == '-') ? 0 : 1;
    i++;
    flag = 1.0;
    if (sign2){
        putchar(s[i]);
        for (int j = 0;j < (s[i]-'0');j++){
            flag *= 10.0;
        }
    }
    else{
        for (int j = 0;j < (s[i]-'0');j++)
        flag /= 10.0;
    }
    printf(" %lf ",flag);
    return flag *(sign * val / power);
}