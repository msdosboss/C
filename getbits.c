#include <stdio.h>
int getbits(unsigned int,int,int,unsigned int);
int invert(unsigned int, int, int);
int rightrot(unsigned int,int);
int bitcount(unsigned int);
int main(){
    int bits;
    //bits = getbits(81,2,5,218);
    //bits = invert(81,2,5);
    //bits = rightrot(81,5);
    //printf("%x",bits);
}

int getbits(unsigned int x,int p,int n,unsigned int y){
    y =  y >> p; //y = 00110110                         this is all assumeing (81,2,5,218)
    y = y & ~(~0 << n);//y = 00010110
    x = x & ~(~(~0 << n)); //x = 01000000
    x = x | y; // x = 01010110
    return x;
}

int invert(unsigned int x,int p,int n){
    x = x >> p;//00010100                                    this is all assumeing (81,2,5)
    unsigned int y = ~(~0 << n); //00011111
    y = y & x; // 00010100
    y = ~y; //11101011
    y = y & ~(~0 << n); //00001011
    x = x & ~0 << n; //00000000
    x = x | y; //00001011
    return x;
}
int rightrot(unsigned int x,int n){
    x = x >> n;
    return x;
}
int bitcount(unsigned int x){
    int bc;
    while(x !=0){
        x &= (x-1);
        bc++;
    }
    return bc;
}

// better name for program might be getcancer