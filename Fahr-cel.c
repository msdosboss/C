#include <stdio.h>
#define LOW 0
#define HIGH 300
#define STEP 20
void main(){
    /*
    float fahr, cel;
    int low = 0, high = 200, step = 20;
    fahr = low;
    printf("cel to fahr\n");
    while (fahr <= high){
        cel = (5.0/9.0) * (fahr-32);
        printf("%3.1f %6.0f\n",cel,fahr);
        fahr = fahr + step;
    } 
        */
    int fahr;
    for(fahr = HIGH; fahr > LOW; fahr = fahr - STEP ){
     printf("%3d %6.1f\n",fahr,5.0/9.0*(fahr-32));   
    }
    
}