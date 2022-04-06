#include <stdio.h>
#include <stdlib.h>
int *getmove(void);
void printboard(int[][8]);
int pawn(int[][8], int*, int);
int knight(int[][8], int*, int);
int bishop(int[][8], int*, int);

int main(){
    system("color 0a");                                             //should be comment out for non windows machine

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
        if(!color){
            printf("\nyou are white");
        }
        else{
            printf("\nyou are black");
        }
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
                case 20:
                    if(!color){
                        knight(board,squarecord1,color);
                        break;
                    }
                    else{
                        printf("that is a white knight");
                        break;
                    }
                case 21:
                    if(color){
                        knight(board, squarecord1, color);
                        break;
                    }
                    else{
                        printf("that is a black knight");
                        break;
                    }
                case 30:
                    if(!color){
                        bishop(board, squarecord1, color);
                        break;
                    }
                    else{
                        printf("that is a white bishop");
                        break;
                    }
                case 31:
                    if(color){
                        bishop(board, squarecord1, color);
                        break;
                    }
                    else{
                        printf("that is a black bishop");
                        break;
                    }
            }
        }
        else{
            printf("that square does not have a piece on it");
        }
        //color = (color == 0) ? (1) : (0);
    }
}


// getmove returns the cords for the board array in usable ints 
int *getmove(){                             
    char c;
    int *squarecord;
    int flag = 0;

    squarecord = (int *) malloc(5);

    printf("\n");                                                                 //makes it more readable
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

int pawn(int board[][8],int *currentsquare, int color){
    int *squarecord2;
    printf("current square %d ",*(currentsquare+1));
    printf("%d",*currentsquare);
    squarecord2 = (int *) malloc(5);

    printf(" where would you like to move your pawn? ");
    squarecord2 = getmove();
    if(!color){                                                                                                                                //checks for color
        if(board[(*(currentsquare + 1) + 1 <= 7 ) ? (*(currentsquare + 1) + 1) : 0][(*currentsquare + 1 <= 7) ? (*currentsquare + 1) : 0] % 2 != 0 || board[(*(currentsquare + 1) + 1 <= 7) ? (*(currentsquare + 1) - 1) : 0][(*currentsquare - 1 <= 0) ? (*currentsquare - 1) : 0] % 2 != 0){    //checks if you can capture 
            printf(" can capture ");
            if(*(currentsquare + 1) + 1 == *(squarecord2 + 1) && *currentsquare + 1 == *squarecord2){
                board[*(squarecord2+1)][*squarecord2] = board[*(currentsquare + 1)][*currentsquare];
                board[*(currentsquare + 1)][*currentsquare] = 0;
                return 0;
            }
            if(*(currentsquare + 1) + 1 == *(squarecord2 + 1) && *currentsquare - 1 == *squarecord2){
                board[*(squarecord2+1)][*squarecord2] = board[*(currentsquare + 1)][*currentsquare];
                board[*(currentsquare + 1)][*currentsquare] = 0;
                return 0;
            }
        }                   
        if(*(currentsquare + 1) == 1){                                                                            //this if checks if a pawn can move 2           
            if(*(squarecord2 + 1) - *(currentsquare + 1) > 0 && *(squarecord2 + 1) - *(currentsquare + 1) < 3 && *(squarecord2) == *(currentsquare)){               //checks if double or single square move 
                if(board[*(squarecord2 + 1)][(*squarecord2)] == 0){                                                //this is collision check
                    board[*(squarecord2 + 1)][*squarecord2] = board[*(currentsquare + 1)][*currentsquare];
                    board[*(currentsquare + 1)][*currentsquare] = 0;
                }
                else{
                    printf(" not a avaliable move collision ");
                    pawn(board,currentsquare,color);
                }
            }
            else    {
                printf(" not a avaliable move ");
                pawn(board,currentsquare,color);
            }
        }
        else{
            if(*(squarecord2 + 1) - *(currentsquare + 1) == 1 && *squarecord2 == *currentsquare){                                                                    //checks if it is a single square move
                if(board[*(squarecord2 + 1)][*squarecord2] == 0){                           //collision check
                    board[*(squarecord2 + 1)][*squarecord2] = board[*(currentsquare + 1)][*currentsquare];
                    board[*(currentsquare + 1)][*currentsquare] = 0;
                }
                else{
                    printf(" not a avaliable move collision ");
                    pawn(board,currentsquare,color);
                }
            }
            else    {
                printf(" not a avaliable move ");
                pawn(board,currentsquare,color);
            }
        }
    }
    else{
        if((board[(*(currentsquare + 1) - 1 >= 0 ) ? (*(currentsquare + 1) - 1) : 0][(*currentsquare + 1 <= 7) ? (*currentsquare + 1) : 0] % 2 == 0 && board[(*(currentsquare + 1) - 1 >= 0 ) ? (*(currentsquare + 1) - 1) : 0][(*currentsquare + 1 <= 7) ? (*currentsquare + 1) : 0] != 0 ) || (board[(*(currentsquare + 1) - 1 >= 0) ? (*(currentsquare + 1) - 1) : 0][(*currentsquare - 1 <= 0) ? (*currentsquare - 1) : 0] % 2 == 0 && board[(*(currentsquare + 1) - 1 >= 0) ? (*(currentsquare + 1) - 1) : 0][(*currentsquare - 1 <= 0) ? (*currentsquare - 1) : 0] != 0)){                    //checks if you can capture
            printf(" can capture ");
            if(*(currentsquare + 1) - 1 == *(squarecord2 + 1) && *currentsquare + 1 == *squarecord2){
                board[*(squarecord2+1)][*squarecord2] = board[*(currentsquare + 1)][*currentsquare];
                board[*(currentsquare + 1)][*currentsquare] = 0;
                return 0;
            }
            if(*(currentsquare + 1) - 1 == *(squarecord2 + 1) && *currentsquare - 1 == *squarecord2){
                board[*(squarecord2+1)][*squarecord2] = board[*(currentsquare + 1)][*currentsquare];
                board[*(currentsquare + 1)][*currentsquare] = 0;
                return 0;
            }
        }
        if(*(currentsquare + 1) == 6){                                                                            //this if checks if a pawn can move 2           
            if(*(currentsquare + 1) -  *(squarecord2 + 1)> 0 && *(currentsquare + 1) - *(squarecord2 + 1) < 3 && *(squarecord2) == *(currentsquare)){
                if(board[*(squarecord2 + 1)][(*squarecord2)] == 0){                   //collision detection
                    board[*(squarecord2 + 1)][*squarecord2] = board[*(currentsquare + 1)][*currentsquare];
                    board[*(currentsquare + 1)][*currentsquare] = 0;
                }
                else{
                    printf(" not a avaliable move collision ");
                    pawn(board,currentsquare,color);
                }
            }
            else    {
                printf(" not a avaliable move ");
                pawn(board,currentsquare,color);
            }
        }
        else{
            if(*(currentsquare + 1) - *(squarecord2 + 1) == 1 && *squarecord2 == *currentsquare){
                if(board[*(squarecord2 + 1)][*squarecord2] == 0){                           //collision check
                    board[*(squarecord2 + 1)][*squarecord2] = board[*(currentsquare + 1)][*currentsquare];
                    board[*(currentsquare + 1)][*currentsquare] = 0;
                }
                else{
                    printf(" not a avaliable move collision ");
                    pawn(board,currentsquare,color);
                }
            }
            else    {
                printf(" not a avaliable move ");
                pawn(board,currentsquare,color);
            }
        }
    }
}

int knight(int board[][8],int *currentsquare,int color){
    int *squarecord2;
    printf("current square %d ",*(currentsquare+1));
    printf("%d",*currentsquare);
    squarecord2 = (int *) malloc(5);

    printf(" where would you like to move your knight? ");
    squarecord2 = getmove();
    if(!color){
        if(board[*(squarecord2+1)][*squarecord2] % 2 != 0 || board[*(squarecord2+1)][*squarecord2] == 0){
            if((*(squarecord2 + 1) == *(currentsquare + 1) + 2 && *squarecord2 == *currentsquare + 1) || (*(squarecord2 + 1) == *(currentsquare + 1) + 1 && *squarecord2 == *currentsquare + 2) || (*(currentsquare + 1) - *(squarecord2 + 1) == 1 && *squarecord2 == *currentsquare + 2) || (*(currentsquare + 1) - *(squarecord2 + 1) == 2 && *squarecord2 == *currentsquare + 1) || (*(squarecord2 + 1) == *(currentsquare + 1) + 1 && *currentsquare - *squarecord2 == 2) || (*(squarecord2 + 1) == *(currentsquare + 1) + 2 && *currentsquare - *squarecord2 == 1) || (*(currentsquare + 1) - *(squarecord2 + 1) == 1 && *currentsquare - *squarecord2 == 2)){
                printf(" test 2 ");
                board[*(squarecord2 + 1)][*squarecord2] = board[*(currentsquare + 1)][*currentsquare];
                board[*(currentsquare + 1)][*currentsquare] = 0;
            }
            else{
                printf("not a legal move");
                knight(board, currentsquare, color);
            }
        }
        else{
            printf("not a legal move collision");
            knight(board, currentsquare, color);
        }
    }
    else{
        if(board[*(squarecord2+1)][*squarecord2] % 2 == 0){
            if((*(squarecord2 + 1) == *(currentsquare + 1) + 2 && *squarecord2 == *currentsquare + 1) || (*(squarecord2 + 1) == *(currentsquare + 1) + 1 && *squarecord2 == *currentsquare + 2) || (*(currentsquare + 1) - *(squarecord2 + 1) == 1 && *squarecord2 == *currentsquare + 2) || (*(currentsquare + 1) - *(squarecord2 + 1) == 2 && *squarecord2 == *currentsquare + 1) || (*(squarecord2 + 1) == *(currentsquare + 1) + 1 && *currentsquare - *squarecord2 == 2) || (*(squarecord2 + 1) == *(currentsquare + 1) + 2 && *currentsquare - *squarecord2 == 1) || (*(currentsquare + 1) - *(squarecord2 + 1) == 1 && *currentsquare - *squarecord2 == 2)){
                printf(" test 2 ");
                board[*(squarecord2 + 1)][*squarecord2] = board[*(currentsquare + 1)][*currentsquare];
                board[*(currentsquare + 1)][*currentsquare] = 0;
            }
            else{
                printf("not a legal move");
                knight(board, currentsquare, color);
            }
        }
    }
}

int bishop(int board[][8],int *currentsquare,int color){
    int *squarecord2;
    int *upright, *downright, *upleft, *downleft;
    printf("current square %d ",*(currentsquare+1));
    printf("%d",*currentsquare);
    upright = (int *) malloc(5);
    downright = (int *) malloc(5);
    upleft = (int *) malloc(5);
    downleft = (int *) malloc(5);
    squarecord2 = (int *) malloc(5);

    for(int i = 0; i + (*currentsquare + 1) <= 7 && i + *currentsquare <= 7; i++){
        if(board[*(currentsquare + 1) + i + 1][*currentsquare + i + 1] > 0){
            printf(" test ");
            upright = currentsquare;
           *upright = i + *upright;
           *(upright + 1) = i + *(upright + 1);                         //upright is now the right and up most square you can move
            break;
        }
    }
    for(int i = 0; (*currentsquare + 1) - i >= 0 && i + *currentsquare <= 7; i++){
        if(board[*(currentsquare + 1) - i][*currentsquare + i] > 0){
            downright = currentsquare;
           *downright = i + *downright;
           *(downright + 1) = (*(downright + 1) - i);                         //down is now the right and down most square you can move
            break;
        }
    }
    for(int i = 0; (*currentsquare + 1) - i >= 0 && *currentsquare - i >= 0; i++){
        if(board[*(currentsquare + 1) - i][*currentsquare - i] > 0){
            downleft = currentsquare;
           *downleft = (*downleft - i);
           *(downleft + 1) = (*(downleft + 1) - i);                         //down is now the left and down most square you can move
            break;
        }
    }
        for(int i = 0; i + (*currentsquare + 1) <= 7 && *currentsquare - i >= 0; i++){
        if(board[*(currentsquare + 1) + i][*currentsquare - i] > 0){
            upleft = currentsquare;
           *upleft = (*upleft - i);
           *(upleft + 1) = i + *(upleft + 1);                         //upleft is now the left and up most square you can move
            break;        
        }
    }
    printf("upleft %d %d\n",(*upleft +1),*upleft);
    printf("upright %d %d\n",(*upright +1),*upright);
    printf("downleft %d %d\n",(*downleft + 1),*downleft);
    printf("downright %d %d\n",(*downright +1),*downright);
    
    printf(" where would you like to move your knight? ");
    squarecord2 = getmove();    
}
