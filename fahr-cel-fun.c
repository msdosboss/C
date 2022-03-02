#include <stdio.h>
int conv(int);
main(){
    printf("%d",conv(32));
}
int conv(int fahr){
    int cel;
    cel = 5.0/9.0*(fahr-32);
    return cel;
}
