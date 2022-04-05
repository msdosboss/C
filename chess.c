#include <stdio.h>
#include <stdlib.h>
int *getmove(void);
void printboard(int[][8]);
void pawn(int[][8], int*, int);

int main(){
    int color = 0;                                                  // 0 = white and 1 = black
    int end = 0;                                                    // 0 means games still going, 1 means white wins, -1 means black wins
    int *squarecord1;
    int board[8][8] =
    {
        {50,20,30,90,100,30,20,50},                                          // 50 = white rook, 20 = white knight, 30 = white bishop, 90 = white queen, 100 = white king, 10 = white pawn, 51 = black rook, 21 = black knight, 31 = black bishop, 91 = black queen, 101 = black king, 11 = black pawn
        {10,10,10,10,10,10,10,10},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {11,11,11,11,11,11,11,11},
        {51,21,31,91,101,31,21,51},
    };

    squarecord1 = (int *) malloc(5);
    while(end == 0){
        printboard(board);
        squarecord1 = getmove();
        printf("--%d--",board[*(1+squarecord1)][*squarecord1]);
        if(board[*(1+squarecord1)][*squarecord1] > 0){
            switch(board[*(1+squarecord1)][*squarecord1]){
                case 10:
                    if(!color){
                        pawn(board,squarecord1,color);
                        break;
                    }
                    else{
                        printf("that is a white pawn");
                        break;
                    }
                case 11:
                    if(color){
                    pawn(board,squarecord1,color);
                    break;
                    }
                    else{
                        printf("that is a black pawn");
                        break;
                    }
            }
        }
        else{
            printf("that square does not have a piece on it");
        }
    }
}


// getmove returns the cords for the board array in usable ints 
int *getmove(){                             
    char c;
    int *squarecord;
    int flag = 0;

    squarecord = (int *) malloc(5);

    while ((c = getchar()) != '\0'){
        if (c == ' ' || c == '\t' || c == '\n') 
            continue;
        if (c >= 'a' && c <='h'){
            *squarecord++ = (c - 'a');                                              //-1 is and offset for the array since it starts at 0
            flag = 1;
            continue;
        }
        if (c >= '1' && c <= '8' && flag ==1){
            *squarecord++ = c - '0' - 1;
            return squarecord - 2;
        }
        else{
            printf("wrong");
            return 0;
        }
         
        
        

    }
}
void printboard(int board[][8]){
    for(int i = 0; i < 8; i++){
        printf("\n");
        for(int j = 0; j < 8;j++){
            printf("%d-",board[i][j]);
        }
    }
}

void pawn(int board[][8],int *currentsquare, int color){
    int *squarecord2;
    printf("current square %d ",*(currentsquare+1));
    printf("%d",*currentsquare);
    squarecord2 = (int *) malloc(5);

    printf("where would you like to move your pawn?");
    squarecord2 = getmove();
    if(!color){                                                                                                                                //checks for color
        if(board[(*(currentsquare + 1) + 1 <= 7 ) ? (*(currentsquare + 1) + 1) : 0][(*currentsquare + 1 <= 7) ? (*currentsquare + 1) : 0] % 2 != 0 || board[(*(currentsquare + 1) - 1 >= 0) ? (*(currentsquare + 1) - 1) : 0][(*currentsquare + 1 >= 7) ? (*currentsquare + 1) : 0] % 2 != 0){    //checks if you can capture
            printf("can capture");
        }                   
        else{
            if(*(currentsquare + 1) == 1 || *(currentsquare + 1) == 6){                                                                            //this if checks if a pawn can move 2           
                if(*(squarecord2 + 1) - *(currentsquare + 1) > 0 && *(squarecord2 + 1) - *(currentsquare + 1) < 3 && *(squarecord2) == *(currentsquare)){
                    board[*(squarecord2 + 1)][*squarecord2] = board[*(currentsquare + 1)][*currentsquare];
                    board[*(currentsquare + 1)][*currentsquare] = 0;
                }
                else    {
                    printf("not a avaliable move");
                }
            }
            else{
                if(*(squarecord2 + 1) - *(currentsquare + 1) == 1 && *squarecord2 == *currentsquare){
                    board[*(squarecord2 + 1)][*squarecord2] = board[*(currentsquare + 1)][*currentsquare];
                    board[*(currentsquare + 1)][*currentsquare] = 0;
                }
                else    {
                    printf("not a avaliable move");
                }
            }
        }
    }
    else{
        if(*(currentsquare + 1) == 1 || *(currentsquare + 1) == 6){                                                                            //this if checks if a pawn can move 2           
            if(*(currentsquare + 1) -  *(squarecord2 + 1)> 0 && *(currentsquare + 1) - *(squarecord2 + 1) < 3 && *(squarecord2) == *(currentsquare)){
                board[*(squarecord2 + 1)][*squarecord2] = board[*(currentsquare + 1)][*currentsquare];
                board[*(currentsquare + 1)][*currentsquare] = 0;
            }
            else    {
                printf("not a avaliable move");
            }
        }
        else{
            if(*(currentsquare + 1) - *(squarecord2 + 1) == 1 && *squarecord2 == *currentsquare){
                board[*(squarecord2 + 1)][*squarecord2] = board[*(currentsquare + 1)][*currentsquare];
                board[*(currentsquare + 1)][*currentsquare] = 0;
            }
            else    {
                printf("not a avaliable move");
            }
        }
    }
}
