#include <stdio.h>
#include <stdlib.h>
int *getmove(void);
int *makemove(char,char);
void printboard(int[][8]);
int pawn(int[][8], int*, int);
int knight(int[][8], int*, int);
int bishop(int[][8], int*, int);
int rook(int[][8], int*, int);
int queen(int[][8], int*, int);
int king(int[][8], int*, int);
char *givecords(int *);
int ischeck(int[][8],int*,int);
int ispawncheck(int[][8],int*,int*,int);
int isknightcheck(int[][8],int*,int*);
int isbishopcheck(int[][8],int*,int*,int);
int isqueencheck(int[][8],int*,int*,int);

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
        //printf("---%d---",ischeck(board,getmove(),color));
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
                case 50:
                    if(!color){
                        rook(board, squarecord1, color);
                        break;
                    }
                    else{
                        printf("that is a white rook");
                        break;
                    }
                case 51:
                    if(color){
                        rook(board, squarecord1, color);
                        break;
                    }
                    else{
                        printf("that is a black rook");
                        break;
                    }
                case 90:
                    if(!color){
                        queen(board, squarecord1, color);
                        break;
                    }
                    else{
                        printf("that is a white queen");
                        break;
                    }
                case 91:
                    if(color){
                        queen(board, squarecord1, color);
                        break;
                    }
                    else{
                        printf("that is a black queen");
                        break;
                    }
                case 100:
                    if(!color){
                        king(board, squarecord1, color);
                        break;
                    }
                    else{
                        printf("that is a white king");
                        break;
                    }
                case 101:
                    if(color){
                        king(board, squarecord1, color);
                        break;
                    }
                    else{
                        printf("that is a black king");
                        break;
                    }
            }
        }
        else{
            printf("that square does not have a piece on it");
        }
        color = (color == 0) ? (1) : (0);
    }
}


// getmove returns the cords for the board array in usable ints 
int *getmove(){                             
    char c;
    int *squarecord;
    int flag = 0;

    squarecord = (int *) malloc(5);

                                                              
    while(1){
        printf("\n");
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
                printf("wrong\n");
            }
        }
    }
}

int *makemove(char c, char d){
    int *squarecord;
    int flag = 0;
    
    squarecord = (int *) malloc(5);

    if (c >= 'a' && c <='h'){
        *squarecord++ = (c - 'a');                                              //-1 is and offset for the array since it starts at 0
        flag = 1;
    }
    if (d >= '1' && d <= '8' && flag ==1){
        *squarecord++ = d - '0' - 1;
        return squarecord - 2;
    }
    else{
        printf("wrong\n");
    }
}

void printboard(int board[][8]){
    for(int i = 0; i < 8; i++){
        printf("\n");
        for(int j = 0; j < 8;j++){
            printf("-%d",board[i][j]);
            if(!board[i][j])
                putchar('-');
        }
    }
}
char *givecords(int *cords){                                //converts from array notation to chess notation
    char *newcords;
    newcords = (char *) malloc(5);

    *(newcords + 1) = *(cords + 1) + '0' + 1;
    *newcords = *(cords + 1) + '0';
    *newcords = *newcords + 20;
    return newcords;
}

int ispawncheck(int board [][8], int *square, int *currentsquare,int color){
    if((*(currentsquare + 1) - 1 == *(square + 1) && *currentsquare + 1 == *square) || (*(currentsquare + 1) - 1 == *(square + 1) && *currentsquare - 1 == *square) && !color){
        return 1;
    }
    if(*(currentsquare + 1))
    return 0;
}

int isknightcheck(int board[][8], int *square, int *currentsquare){
    if((*(square + 1) == *(currentsquare + 1) + 2 && *square == *currentsquare + 1) || (*(square + 1) == *(currentsquare + 1) + 1 && *square == *currentsquare + 2) || (*(currentsquare + 1) - *(square + 1) == 1 && *square == *currentsquare + 2) || (*(currentsquare + 1) - *(square + 1) == 2 && *square == *currentsquare + 1) || (*(square + 1) == *(currentsquare + 1) + 1 && *currentsquare - *square == 2) || (*(square + 1) == *(currentsquare + 1) + 2 && *currentsquare - *square == 1) || (*(currentsquare + 1) - *(square + 1) == 1 && *currentsquare - *square == 2) || (*(currentsquare + 1) - *(square + 1) == 2 && *currentsquare - *square == 1)){
        return 1;
    }
    return 0;
}

int isbishopcheck(int board[][8], int *square, int *currentsquare, int color){
    int *upright, *downright, *upleft, *downleft;
    upright = (int *) malloc(5);
    downright = (int *) malloc(5);
    upleft = (int *) malloc(5);
    downleft = (int *) malloc(5);
    //color = (color == 0) ? (1) : (0); // we are seeing if the oppisite color can check here so we have to switch color. Had to comment it all out because it was not accounting for a piece defending another piece of its own color
    
    for(int i = 0; i + *(currentsquare + 1) <= 7 && i + *currentsquare <= 7; i++){
        *upright = *currentsquare;
        *(upright + 1) = *(currentsquare + 1);
        *upright = i + *upright;
        *(upright + 1) = i + *(upright + 1);                         //upright is now the right and up most square you can move
        if(*(upright + 1)== 7){
            break;
        }
        if(*upright == 7){
            break;
        }
        if(board[*(currentsquare + 1) + i + 1][*currentsquare + i + 1] > 0){
            if(!color){
                if(board[*(currentsquare + 1) + i + 1][*currentsquare + i + 1] % 2 != 0 && *(currentsquare + 1) + i + 1 <= 7 && *currentsquare + i + 1 <= 7){
                    *upright = *currentsquare;
                    *(upright + 1) = *(currentsquare + 1);
                    *upright = i + *upright + 1;
                    *(upright + 1) = i + *(upright + 1) + 1;                         //upright is now the right and up most square you can move including takes
                }
            }
            else{
                if(board[*(currentsquare + 1) + i + 1][*currentsquare + i + 1] % 2 == 0 && board[*(currentsquare + 1) + i + 1][*currentsquare + i + 1] != 0 && *(currentsquare + 1) + i + 1 <= 7 && *currentsquare + i + 1 <= 7){
                    *upright = *currentsquare;
                    *(upright + 1) = *(currentsquare + 1);
                    *upright = i + *upright + 1;
                    *(upright + 1) = i + *(upright + 1) + 1;                         //upright is now the right and up most square you can move including takes
                }
            }
            break;
        }
    }
    for(int i = 0; *(currentsquare + 1) - i >= 0 && i + *currentsquare <= 7; i++){
        *downright = *currentsquare;
        *(downright + 1) = *(currentsquare + 1);
        *downright = i + *downright;
        *(downright + 1) = (*(downright + 1) - i);                         //down is now the right and down most square you can move
        if(*(downright + 1) == 0){
            break;
        }
        if(*downright == 7){
            break;
        }
        if(board[(*(currentsquare + 1) - i) - 1][*currentsquare + i + 1] > 0){
            if(!color){
                if(board[(*(currentsquare + 1) - i) - 1][*currentsquare + i + 1] % 2 != 0 && (*(currentsquare + 1 ) - i) - 1 >= 0 && *currentsquare + i + 1 <= 7){
                    *downright = *currentsquare;
                    *(downright + 1) = *(currentsquare + 1);
                    *downright = i + *downright + 1;
                    *(downright + 1) = (*(downright + 1) - i) - 1;                         //down is now the right and down most square you can move    
                }
            }
            else{
                if(board[(*(currentsquare + 1) - i) - 1][*currentsquare + i + 1] % 2 == 0 && board[(*(currentsquare + 1) - i) - 1][*currentsquare + i + 1] != 0 && (*(currentsquare + 1) - i) - 1 >= 0 && *currentsquare + i + 1 <= 7){
                    *downright = *currentsquare;
                    *(downright + 1) = *(currentsquare + 1);
                    *downright = i + *downright + 1;
                    *(downright + 1) = (*(downright + 1) - i) - 1;                         //down is now the right and down most square you can move 
                }
            }
            break;
        }
    }
    for(int i = 0; *(currentsquare + 1) - i >= 0 && *currentsquare - i >= 0; i++){
        *downleft = *currentsquare;
        *(downleft + 1) = *(currentsquare + 1);
        *downleft = (*downleft - i);
        *(downleft + 1) = (*(downleft + 1) - i);                         //down is now the left and down most square you can move
        if(*(downleft + 1) == 0){
            break;
        }
        if (*downleft == 0){
            break;
        }
        if(board[(*(currentsquare + 1) - i) - 1][(*currentsquare - i) - 1] > 0){
            if(!color){
                if(board[(*(currentsquare + 1) - i) - 1][(*currentsquare - i) - 1] % 2 != 0 && (*(currentsquare + 1) - i) - 1 >= 0 && (*currentsquare - i) - 1 >= 0){
                    *downleft = *currentsquare;
                    *(downleft + 1) = *(currentsquare + 1);
                    *downleft = (*downleft - i) - 1;
                    *(downleft + 1) = ((*(downleft + 1) - i) - 1);                         //down is now the left and down most square you can move
                }
            }
            else{
                if(board[(*(currentsquare + 1) - i) - 1][(*currentsquare - i) - 1] % 2 == 0 && board[(*(currentsquare + 1) - i) - 1][(*currentsquare - i) - 1] != 0 && (*(currentsquare + 1) - i) - 1 >= 0 && (*currentsquare - i) - 1 >= 0){
                    *downleft = *currentsquare;
                    *(downleft + 1) = *(currentsquare + 1);
                    *downleft = (*downleft - i) - 1;
                    *(downleft + 1) = ((*(downleft + 1) - i) - 1);                         //down is now the left and down most square you can move
                }
            }
            break;
        }
    }
    for(int i = 0; i + *(currentsquare + 1) <= 7 && *currentsquare - i >= 0; i++){
        *(upleft + 1) = *(currentsquare + 1);
        *upleft = *currentsquare;
        *upleft = (*upleft - i);
        *(upleft + 1) = i + *(upleft + 1);                         //upleft is now the left and up most square you can move
        if(*(upleft + 1) == 7){
            break;
        }
        if(*upleft == 0){
            break;
        }
        if(board[*(currentsquare + 1) + i + 1][(*currentsquare - i) - 1] > 0){
            if(!color){
                if(board[*(currentsquare + 1) + i + 1][(*currentsquare - i) - 1] % 2 != 0 && *(currentsquare + 1) + i + 1 <= 7 && (*currentsquare - i) - 1 >= 0){         //checks if you can capture
                    *(upleft + 1) = *(currentsquare + 1);
                    *upleft = *currentsquare;
                    *upleft = (*upleft - i) - 1;
                    *(upleft + 1) = i + *(upleft + 1) + 1;                         //upleft is now the left and up most square you can move
                }
            }
            else{
                if(board[*(currentsquare + 1) + i + 1][(*currentsquare - i) - 1] % 2 == 0 && board[*(currentsquare + 1) + i + 1][(*currentsquare - i) - 1] != 0 && *(currentsquare + 1) + i + 1 <= 7 && (*currentsquare - i) - 1 >= 0){   //checks if black can capture
                    *(upleft + 1) = *(currentsquare + 1);
                    *upleft = *currentsquare;
                    *upleft = (*upleft - i) - 1;
                    *(upleft + 1) = i + *(upleft + 1) + 1;                         //upleft is now the left and up most square you can move
                }
            }
            break;        
        }
    }
    for(int i = 0;i + *(currentsquare + 1) <=8 && i + *currentsquare <=8 && *downleft + i <= *upright && *(downleft + 1) + i <= *(upright + 1); i++){
        if(*square == (*downleft + i) && *(square + 1) == *(downleft + 1) + i && *(currentsquare + 1) != *(downleft + 1) + i && *currentsquare != *downleft + i){
            return 1;
        }
    }
    for(int i = 0;*(currentsquare + 1) + i <= 8 &&  *currentsquare - i >=0 && *downright - i >= *upleft && *(downright + 1) + i <= *(upleft + 1); i++){
        if(*square == (*downright - i) && *(square + 1) == *(downright + 1) + i && *(currentsquare + 1) != *(downright + 1) + i && *currentsquare != *downright - i){
            return 1;
        }
    }
    return 0;
}

int isrookcheck(int board[][8], int *square, int *currentsquare, int color){
    int *right, *down, *up, *left;
    up = (int *) malloc(5);
    down = (int *) malloc(5);
    left = (int *) malloc(5);
    right = (int *) malloc(5);
    //color = (color == 0) ? (1) : (0);
    for(int i = 0;*(currentsquare + 1) + i <= 7;i++){
        *(up + 1) = *(currentsquare + 1);
        *up = *currentsquare;
        *(up + 1) = i + *(up + 1);
        if(*(up + 1) == 7){
            break;
        }
        if(board[*(currentsquare + 1) + i + 1][*currentsquare] > 0){
            if(!color){
                if(board[*(currentsquare + 1) + i + 1][*currentsquare] % 2 != 0 && *(currentsquare + 1) + i + 1 <= 7){
                    *(up + 1) = *(currentsquare + 1);
                    *up = *currentsquare;
                    *(up + 1) = i + *(up + 1) + 1;
                }
            }
            else{
                if(board[(*(currentsquare + 1) + i) + 1][*currentsquare] % 2 == 0 && board[(*(currentsquare + 1) + i) + 1][*currentsquare] != 0 && *(currentsquare + 1) + i + 1 <= 7){
                    *(up + 1) = *(currentsquare + 1);
                    *up = *currentsquare;
                    *(up + 1) = i + *(up + 1) + 1;
                }
            }
            break;
        }
    }
    for(int i = 0;*(currentsquare + 1) - i >= 0;i++){
        *(down + 1) = *(currentsquare + 1) - i;
        *down = *currentsquare;
        if(*(down + 1) == 0){
            break;
        }
        if(board[*(currentsquare + 1) - i - 1][*currentsquare] > 0){
            if(!color){
                if(board[*(currentsquare + 1) - i - 1][*currentsquare] % 2 != 0 && *(currentsquare + 1) - i - 1 >= 0){
                    *(down + 1) = *(currentsquare + 1) - i - 1;
                    *down = *currentsquare;
                }
            }
            else{
                if(board[(*(currentsquare + 1) + i) + 1][*currentsquare] % 2 == 0 && board[(*(currentsquare + 1) + i) + 1][*currentsquare] != 0 && *(currentsquare + 1) - i - 1 >= 0){
                    *(down + 1) = *(currentsquare + 1) - i - 1;
                    *down = *currentsquare;
                }
            }
            break;
        }
    }
    for(int i = 0;*(currentsquare) + i <= 7;i++){
        *(right) = *(currentsquare) + i;
        *(right + 1) = *(currentsquare + 1);
        if(*right == 7){
            break;
        }
        if(board[*(currentsquare + 1)][*currentsquare + i + 1] > 0){
            if(!color){
                if(board[*(currentsquare + 1)][*currentsquare + i + 1] % 2 != 0 && *currentsquare + i + 1 <= 7){
                    *(right) = *(currentsquare) + i + 1;
                    *(right + 1) = *(currentsquare + 1);
                }
            }
            else{
                if(board[*(currentsquare + 1)][*currentsquare + i + 1] % 2 == 0 && board[*(currentsquare + 1)][*currentsquare + i + 1] != 0 && *currentsquare + i + 1 <= 7){
                    *(right) = *(currentsquare) + i + 1;
                    *(right + 1) = *(currentsquare + 1);
                }
            }
            break;
        }
    }
    for(int i = 0;*(currentsquare) - i >= 0;i++){
        *(left) = *(currentsquare) - i;
        *(left + 1) = *(currentsquare + 1);
        if(*left == 0){
            break;
        }
        if(board[*(currentsquare + 1)][*currentsquare - i - 1] > 0){
            if(!color){
                if(board[*(currentsquare + 1)][*currentsquare - i - 1] % 2 != 0 && *currentsquare - i - 1 >= 0){
                    *(left) = *(currentsquare) - i - 1;
                    *(left + 1) = *(currentsquare + 1);
                }
            }
            else{
                if(board[*(currentsquare + 1)][*currentsquare - i - 1] % 2 == 0 && board[*(currentsquare + 1)][*currentsquare - i - 1] != 0 && *currentsquare - i - 1 >= 0){
                    *(left) = *(currentsquare) - i - 1;
                    *(left + 1) = *(currentsquare + 1);
                }
            }
            break;
        }
    }
    for(int i = 0;i + *(currentsquare + 1) <=8 && *currentsquare <=8 && *(down + 1) + i <= *(up + 1); i++){
        if(*square == (*down) && *(square + 1) == *(down + 1) + i && *(currentsquare + 1) != *(down + 1) + i){
            return 1;
        }
    }
    for(int i = 0;*(currentsquare + 1)<= 8 &&  *currentsquare + i <=8 && *left + i <= *right; i++){
        if(*square == (*left + i) && *(square + 1) == *(left + 1) && *currentsquare != *left + i){
            return 1;
        }
    }
    return 0;
}

int isqueencheck(int board[][8], int *square, int *currentsquare, int color){
    int *upright, *downright, *upleft, *downleft;
    upright = (int *) malloc(5);
    downright = (int *) malloc(5);
    upleft = (int *) malloc(5);
    downleft = (int *) malloc(5);
    int *right, *down, *up, *left;
    up = (int *) malloc(5);
    down = (int *) malloc(5);
    left = (int *) malloc(5);
    right = (int *) malloc(5);
    //color = (color == 0) ? (1) : (0);
    
    for(int i = 0; i + *(currentsquare + 1) <= 7 && i + *currentsquare <= 7; i++){
        *upright = *currentsquare;
        *(upright + 1) = *(currentsquare + 1);
        *upright = i + *upright;
        *(upright + 1) = i + *(upright + 1);                         //upright is now the right and up most square you can move
        if(*(upright + 1)== 7){
            break;
        }
        if(*upright == 7){
            break;
        }
        if(board[*(currentsquare + 1) + i + 1][*currentsquare + i + 1] > 0){
            if(!color){
                if(board[*(currentsquare + 1) + i + 1][*currentsquare + i + 1] % 2 != 0 && *(currentsquare + 1) + i + 1 <= 7 && *currentsquare + i + 1 <= 7){
                    *upright = *currentsquare;
                    *(upright + 1) = *(currentsquare + 1);
                    *upright = i + *upright + 1;
                    *(upright + 1) = i + *(upright + 1) + 1;                         //upright is now the right and up most square you can move including takes
                }
            }
            else{
                if(board[*(currentsquare + 1) + i + 1][*currentsquare + i + 1] % 2 == 0 && board[*(currentsquare + 1) + i + 1][*currentsquare + i + 1] != 0 && *(currentsquare + 1) + i + 1 <= 7 && *currentsquare + i + 1 <= 7){
                    *upright = *currentsquare;
                    *(upright + 1) = *(currentsquare + 1);
                    *upright = i + *upright + 1;
                    *(upright + 1) = i + *(upright + 1) + 1;                         //upright is now the right and up most square you can move including takes
                }
            }
            break;
        }
    }
    for(int i = 0; *(currentsquare + 1) - i >= 0 && i + *currentsquare <= 7; i++){
        *downright = *currentsquare;
        *(downright + 1) = *(currentsquare + 1);
        *downright = i + *downright;
        *(downright + 1) = (*(downright + 1) - i);                         //down is now the right and down most square you can move
        if(*(downright + 1) == 0){
            break;
        }
        if(*downright == 7){
            break;
        }
        if(board[(*(currentsquare + 1) - i) - 1][*currentsquare + i + 1] > 0){
            if(!color){
                if(board[(*(currentsquare + 1) - i) - 1][*currentsquare + i + 1] % 2 != 0 && (*(currentsquare + 1 ) - i) - 1 >= 0 && *currentsquare + i + 1 <= 7){
                    *downright = *currentsquare;
                    *(downright + 1) = *(currentsquare + 1);
                    *downright = i + *downright + 1;
                    *(downright + 1) = (*(downright + 1) - i) - 1;                         //down is now the right and down most square you can move    
                }
            }
            else{
                if(board[(*(currentsquare + 1) - i) - 1][*currentsquare + i + 1] % 2 == 0 && board[(*(currentsquare + 1) - i) - 1][*currentsquare + i + 1] != 0 && (*(currentsquare + 1) - i) - 1 >= 0 && *currentsquare + i + 1 <= 7){
                    *downright = *currentsquare;
                    *(downright + 1) = *(currentsquare + 1);
                    *downright = i + *downright + 1;
                    *(downright + 1) = (*(downright + 1) - i) - 1;                         //down is now the right and down most square you can move 
                }
            }
            break;
        }
    }
    for(int i = 0; *(currentsquare + 1) - i >= 0 && *currentsquare - i >= 0; i++){
        *downleft = *currentsquare;
        *(downleft + 1) = *(currentsquare + 1);
        *downleft = (*downleft - i);
        *(downleft + 1) = (*(downleft + 1) - i);                         //down is now the left and down most square you can move
        if(*(downleft + 1) == 0){
            break;
        }
        if (*downleft == 0){
            break;
        }
        if(board[(*(currentsquare + 1) - i) - 1][(*currentsquare - i) - 1] > 0){
            if(!color){
                if(board[(*(currentsquare + 1) - i) - 1][(*currentsquare - i) - 1] % 2 != 0 && (*(currentsquare + 1) - i) - 1 >= 0 && (*currentsquare - i) - 1 >= 0){
                    *downleft = *currentsquare;
                    *(downleft + 1) = *(currentsquare + 1);
                    *downleft = (*downleft - i) - 1;
                    *(downleft + 1) = ((*(downleft + 1) - i) - 1);                         //down is now the left and down most square you can move
                }
            }
            else{
                if(board[(*(currentsquare + 1) - i) - 1][(*currentsquare - i) - 1] % 2 == 0 && board[(*(currentsquare + 1) - i) - 1][(*currentsquare - i) - 1] != 0 && (*(currentsquare + 1) - i) - 1 >= 0 && (*currentsquare - i) - 1 >= 0){
                    *downleft = *currentsquare;
                    *(downleft + 1) = *(currentsquare + 1);
                    *downleft = (*downleft - i) - 1;
                    *(downleft + 1) = ((*(downleft + 1) - i) - 1);                         //down is now the left and down most square you can move
                }
            }
            break;
        }
    }
    for(int i = 0; i + *(currentsquare + 1) <= 7 && *currentsquare - i >= 0; i++){
        *(upleft + 1) = *(currentsquare + 1);
        *upleft = *currentsquare;
        *upleft = (*upleft - i);
        *(upleft + 1) = i + *(upleft + 1);                         //upleft is now the left and up most square you can move
        if(*(upleft + 1) == 7){
            break;
        }
        if(*upleft == 0){
            break;
        }
        if(board[*(currentsquare + 1) + i + 1][(*currentsquare - i) - 1] > 0){
            if(!color){
                if(board[*(currentsquare + 1) + i + 1][(*currentsquare - i) - 1] % 2 != 0 && *(currentsquare + 1) + i + 1 <= 7 && (*currentsquare - i) - 1 >= 0){         //checks if you can capture
                    *(upleft + 1) = *(currentsquare + 1);
                    *upleft = *currentsquare;
                    *upleft = (*upleft - i) - 1;
                    *(upleft + 1) = i + *(upleft + 1) + 1;                         //upleft is now the left and up most square you can move
                }
            }
            else{
                if(board[*(currentsquare + 1) + i + 1][(*currentsquare - i) - 1] % 2 == 0 && board[*(currentsquare + 1) + i + 1][(*currentsquare - i) - 1] != 0 && *(currentsquare + 1) + i + 1 <= 7 && (*currentsquare - i) - 1 >= 0){   //checks if black can capture
                    *(upleft + 1) = *(currentsquare + 1);
                    *upleft = *currentsquare;
                    *upleft = (*upleft - i) - 1;
                    *(upleft + 1) = i + *(upleft + 1) + 1;                         //upleft is now the left and up most square you can move
                }
            }
            break;        
        }
    }
    for(int i = 0;*(currentsquare + 1) + i <= 7;i++){
        *(up + 1) = *(currentsquare + 1);
        *up = *currentsquare;
        *(up + 1) = i + *(up + 1);
        if(*(up + 1) == 7){
            break;
        }
        if(board[*(currentsquare + 1) + i + 1][*currentsquare] > 0){
            if(!color){
                if(board[*(currentsquare + 1) + i + 1][*currentsquare] % 2 != 0 && *(currentsquare + 1) + i + 1 <= 7){
                    *(up + 1) = *(currentsquare + 1);
                    *up = *currentsquare;
                    *(up + 1) = i + *(up + 1) + 1;
                }
            }
            else{
                if(board[(*(currentsquare + 1) + i) + 1][*currentsquare] % 2 == 0 && board[(*(currentsquare + 1) + i) + 1][*currentsquare] != 0 && *(currentsquare + 1) + i + 1 <= 7){
                    *(up + 1) = *(currentsquare + 1);
                    *up = *currentsquare;
                    *(up + 1) = i + *(up + 1) + 1;
                }
            }
            break;
        }
    }
    for(int i = 0;*(currentsquare + 1) - i >= 0;i++){
        *(down + 1) = *(currentsquare + 1) - i;
        *down = *currentsquare;
        if(*(down + 1) == 0){
            break;
        }
        if(board[*(currentsquare + 1) - i - 1][*currentsquare] > 0){
            if(!color){
                if(board[*(currentsquare + 1) - i - 1][*currentsquare] % 2 != 0 && *(currentsquare + 1) - i - 1 >= 0){
                    *(down + 1) = *(currentsquare + 1) - i - 1;
                    *down = *currentsquare;
                }
            }
            else{
                if(board[(*(currentsquare + 1) + i) + 1][*currentsquare] % 2 == 0 && board[(*(currentsquare + 1) + i) + 1][*currentsquare] != 0 && *(currentsquare + 1) - i - 1 >= 0){
                    *(down + 1) = *(currentsquare + 1) - i - 1;
                    *down = *currentsquare;
                }
            }
            break;
        }
    }
    for(int i = 0;*(currentsquare) + i <= 7;i++){
        *(right) = *(currentsquare) + i;
        *(right + 1) = *(currentsquare + 1);
        if(*right == 7){
            break;
        }
        if(board[*(currentsquare + 1)][*currentsquare + i + 1] > 0){
            if(!color){
                if(board[*(currentsquare + 1)][*currentsquare + i + 1] % 2 != 0 && *currentsquare + i + 1 <= 7){
                    *(right) = *(currentsquare) + i + 1;
                    *(right + 1) = *(currentsquare + 1);
                }
            }
            else{
                if(board[*(currentsquare + 1)][*currentsquare + i + 1] % 2 == 0 && board[*(currentsquare + 1)][*currentsquare + i + 1] != 0 && *currentsquare + i + 1 <= 7){
                    *(right) = *(currentsquare) + i + 1;
                    *(right + 1) = *(currentsquare + 1);
                }
            }
            break;
        }
    }
    for(int i = 0;*(currentsquare) - i >= 0;i++){
        *(left) = *(currentsquare) - i;
        *(left + 1) = *(currentsquare + 1);
        if(*left == 0){
            break;
        }
        if(board[*(currentsquare + 1)][*currentsquare - i - 1] > 0){
            if(!color){
                if(board[*(currentsquare + 1)][*currentsquare - i - 1] % 2 != 0 && *currentsquare - i - 1 >= 0){
                    *(left) = *(currentsquare) - i - 1;
                    *(left + 1) = *(currentsquare + 1);
                }
            }
            else{
                if(board[*(currentsquare + 1)][*currentsquare - i - 1] % 2 == 0 && board[*(currentsquare + 1)][*currentsquare - i - 1] != 0 && *currentsquare - i - 1 >= 0){
                    *(left) = *(currentsquare) - i - 1;
                    *(left + 1) = *(currentsquare + 1);
                }
            }
            break;
        }
    }
    for(int i = 0;i + *(currentsquare + 1) <=8 && i + *currentsquare <=8 && *downleft + i <= *upright && *(downleft + 1) + i <= *(upright + 1); i++){
        if(*square == (*downleft + i) && *(square + 1) == *(downleft + 1) + i && *(currentsquare + 1) != *(downleft + 1) + i && *currentsquare != *downleft + i){
            return 1;
        }
    }
    for(int i = 0;*(currentsquare + 1) + i <= 8 &&  *currentsquare - i >=0 && *downright - i >= *upleft && *(downright + 1) + i <= *(upleft + 1); i++){
        if(*square == (*downright - i) && *(square + 1) == *(downright + 1) + i && *(currentsquare + 1) != *(downright + 1) + i && *currentsquare != *downright - i){
            return 1;
        }
    }
    for(int i = 0;i + *(currentsquare + 1) <=8 && *currentsquare <=8 && *(down + 1) + i <= *(up + 1); i++){
        if(*square == (*down) && *(square + 1) == *(down + 1) + i && *(currentsquare + 1) != *(down + 1) + i){
            return 1;
        }
    }
    for(int i = 0;*(currentsquare + 1)<= 8 &&  *currentsquare + i <=8 && *left + i <= *right; i++){
        if(*square == (*left + i) && *(square + 1) == *(left + 1) && *currentsquare != *left + i){
            return 1;
        }
    }
    return 0;
}

int ischeck(int board [][8],int *square, int color){
    int *currentsquare;
    currentsquare = (int *) malloc(5);
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8;j++){
            *currentsquare = j;
            *(currentsquare + 1) = i;
                switch(board[i][j]){
                    case 0:
                        break;
                    case 10:
                        if(color){
                            if(ispawncheck(board, square, currentsquare,color)){
                                return 1;
                            }
                        }
                        break;
                    case 11:
                        if(!color){
                            if(ispawncheck(board, square, currentsquare,color)){
                                printf(" pawn ");
                                return 1;
                            }
                        }
                        break;
                    case 20:
                        if(color){
                            if(isknightcheck(board, square, currentsquare)){
                                return 1;
                            }
                        }
                        break;
                    case 21:
                        if(!color){
                            if(isknightcheck(board, square, currentsquare)){
                                printf(" knight ");
                                return 1;
                            }
                        }
                        break;
                    case 30:
                        if(color){
                            if(isbishopcheck(board, square, currentsquare, color)){
                                return 1;
                            }
                        }
                        break;
                    case 31:
                        if(!color){
                            if(isbishopcheck(board, square, currentsquare, color)){
                                printf(" bishop ");
                                return 1;
                            }
                            break;
                        }
                    case 50:
                        if(color){
                            if(isrookcheck(board, square, currentsquare, color)){
                                return 1;
                            }
                        }
                        break;
                    case 51:
                        if(!color){
                            if(isrookcheck(board, square, currentsquare, color)){
                                printf(" rook ");
                                printf(" %d %d ", *(currentsquare + 1), *currentsquare);
                                return 1;
                            }
                        }
                        break;
                    case 90:
                        if(color){
                            if(isqueencheck(board, square, currentsquare, color)){
                                return 1;
                            }
                        }
                        break;
                    case 91:
                        if(!color){
                            if(isqueencheck(board, square, currentsquare, color)){
                                printf(" queen ");
                                return 1;
                            }
                        }
                        break;
                }
        }
    }
    return 0;
}

int pawn(int board[][8],int *currentsquare, int color){
    int *squarecord2;
    printf("current square %d ",*(currentsquare+1));
    printf("%d",*currentsquare);
    squarecord2 = (int *) malloc(5);

    printf(" where would you like to move your pawn? ");
    squarecord2 = getmove();
    //squarecord2 = makemove('e','4');
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
            if((*(squarecord2 + 1) == *(currentsquare + 1) + 2 && *squarecord2 == *currentsquare + 1) || (*(squarecord2 + 1) == *(currentsquare + 1) + 1 && *squarecord2 == *currentsquare + 2) || (*(currentsquare + 1) - *(squarecord2 + 1) == 1 && *squarecord2 == *currentsquare + 2) || (*(currentsquare + 1) - *(squarecord2 + 1) == 2 && *squarecord2 == *currentsquare + 1) || (*(squarecord2 + 1) == *(currentsquare + 1) + 1 && *currentsquare - *squarecord2 == 2) || (*(squarecord2 + 1) == *(currentsquare + 1) + 2 && *currentsquare - *squarecord2 == 1) || (*(currentsquare + 1) - *(squarecord2 + 1) == 1 && *currentsquare - *squarecord2 == 2) || (*(currentsquare + 1) - *(squarecord2 + 1) == 2 && *currentsquare - *squarecord2 == 1)){
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
            if((*(squarecord2 + 1) == *(currentsquare + 1) + 2 && *squarecord2 == *currentsquare + 1) || (*(squarecord2 + 1) == *(currentsquare + 1) + 1 && *squarecord2 == *currentsquare + 2) || (*(currentsquare + 1) - *(squarecord2 + 1) == 1 && *squarecord2 == *currentsquare + 2) || (*(currentsquare + 1) - *(squarecord2 + 1) == 2 && *squarecord2 == *currentsquare + 1) || (*(squarecord2 + 1) == *(currentsquare + 1) + 1 && *currentsquare - *squarecord2 == 2) || (*(squarecord2 + 1) == *(currentsquare + 1) + 2 && *currentsquare - *squarecord2 == 1) || (*(currentsquare + 1) - *(squarecord2 + 1) == 1 && *currentsquare - *squarecord2 == 2) || (*(currentsquare + 1) - *(squarecord2 + 1) == 2 && *currentsquare - *squarecord2 == 1)){
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
    int orca = 0;
    printf("current square %d ",*(currentsquare+1));
    printf("%d",*currentsquare);
    upright = (int *) malloc(5);
    downright = (int *) malloc(5);
    upleft = (int *) malloc(5);
    downleft = (int *) malloc(5);
    squarecord2 = (int *) malloc(5);

    for(int i = 0; i + *(currentsquare + 1) <= 7 && i + *currentsquare <= 7; i++){
        *upright = *currentsquare;
        *(upright + 1) = *(currentsquare + 1);
        *upright = i + *upright;
        *(upright + 1) = i + *(upright + 1);                         //upright is now the right and up most square you can move
        if(*(upright + 1)== 7){
            break;
        }
        if(*upright == 7){
            break;
        }
        if(board[*(currentsquare + 1) + i + 1][*currentsquare + i + 1] > 0){
            if(!color){
                if(board[*(currentsquare + 1) + i + 1][*currentsquare + i + 1] % 2 != 0 && *(currentsquare + 1) + i + 1 <= 7 && *currentsquare + i + 1 <= 7){
                    *upright = *currentsquare;
                    *(upright + 1) = *(currentsquare + 1);
                    *upright = i + *upright + 1;
                    *(upright + 1) = i + *(upright + 1) + 1;                         //upright is now the right and up most square you can move including takes
                }
            }
            else{
                if(board[*(currentsquare + 1) + i + 1][*currentsquare + i + 1] % 2 == 0 && board[*(currentsquare + 1) + i + 1][*currentsquare + i + 1] != 0 && *(currentsquare + 1) + i + 1 <= 7 && *currentsquare + i + 1 <= 7){
                    *upright = *currentsquare;
                    *(upright + 1) = *(currentsquare + 1);
                    *upright = i + *upright + 1;
                    *(upright + 1) = i + *(upright + 1) + 1;                         //upright is now the right and up most square you can move including takes
                }
            }
            break;
        }
    }
    for(int i = 0; *(currentsquare + 1) - i >= 0 && i + *currentsquare <= 7; i++){
        *downright = *currentsquare;
        *(downright + 1) = *(currentsquare + 1);
        *downright = i + *downright;
        *(downright + 1) = (*(downright + 1) - i);                         //down is now the right and down most square you can move
        if(*(downright + 1) == 0){
            break;
        }
        if(*downright == 7){
            break;
        }
        if(board[(*(currentsquare + 1) - i) - 1][*currentsquare + i + 1] > 0){
            if(!color){
                if(board[(*(currentsquare + 1) - i) - 1][*currentsquare + i + 1] % 2 != 0 && (*(currentsquare + 1 ) - i) - 1 >= 0 && *currentsquare + i + 1 <= 7){
                    *downright = *currentsquare;
                    *(downright + 1) = *(currentsquare + 1);
                    *downright = i + *downright + 1;
                    *(downright + 1) = (*(downright + 1) - i) - 1;                         //down is now the right and down most square you can move    
                }
            }
            else{
                if(board[(*(currentsquare + 1) - i) - 1][*currentsquare + i + 1] % 2 == 0 && board[(*(currentsquare + 1) - i) - 1][*currentsquare + i + 1] != 0 && (*(currentsquare + 1) - i) - 1 >= 0 && *currentsquare + i + 1 <= 7){
                    *downright = *currentsquare;
                    *(downright + 1) = *(currentsquare + 1);
                    *downright = i + *downright + 1;
                    *(downright + 1) = (*(downright + 1) - i) - 1;                         //down is now the right and down most square you can move 
                }
            }
            break;
        }
    }
    for(int i = 0; *(currentsquare + 1) - i >= 0 && *currentsquare - i >= 0; i++){
        *downleft = *currentsquare;
        *(downleft + 1) = *(currentsquare + 1);
        *downleft = (*downleft - i);
        *(downleft + 1) = (*(downleft + 1) - i);                         //down is now the left and down most square you can move
        if(*(downleft + 1) == 0){
            break;
        }
        if (*downleft == 0){
            break;
        }
        if(board[(*(currentsquare + 1) - i) - 1][(*currentsquare - i) - 1] > 0){
            if(!color){
                if(board[(*(currentsquare + 1) - i) - 1][(*currentsquare - i) - 1] % 2 != 0 && (*(currentsquare + 1) - i) - 1 >= 0 && (*currentsquare - i) - 1 >= 0){
                    *downleft = *currentsquare;
                    *(downleft + 1) = *(currentsquare + 1);
                    *downleft = (*downleft - i) - 1;
                    *(downleft + 1) = ((*(downleft + 1) - i) - 1);                         //down is now the left and down most square you can move
                }
            }
            else{
                if(board[(*(currentsquare + 1) - i) - 1][(*currentsquare - i) - 1] % 2 == 0 && board[(*(currentsquare + 1) - i) - 1][(*currentsquare - i) - 1] != 0 && (*(currentsquare + 1) - i) - 1 >= 0 && (*currentsquare - i) - 1 >= 0){
                    *downleft = *currentsquare;
                    *(downleft + 1) = *(currentsquare + 1);
                    *downleft = (*downleft - i) - 1;
                    *(downleft + 1) = ((*(downleft + 1) - i) - 1);                         //down is now the left and down most square you can move
                }
            }
            break;
        }
    }
    for(int i = 0;*(currentsquare + 1) + i <= 7 && *currentsquare - i >= 0; i++){
        *(upleft + 1) = *(currentsquare + 1);
        *upleft = *currentsquare;
        *upleft = (*upleft - i);
        *(upleft + 1) = i + *(upleft + 1);                         //upleft is now the left and up most square you can move
        if(*(upleft + 1) == 7){
            printf("test1");
            break;
        }
        if(*upleft == 0){
            printf("test2");
            break;
        }
        if(board[(*(currentsquare + 1) + i + 1 > 7) ? (7) : (*(currentsquare + 1) + i + 1)][((*currentsquare - i) - 1 < 0) ? (0) : ((*currentsquare - i) - 1)] > 0){
            printf("\norca 2\n");
            if(!color){
                if(board[*(currentsquare + 1) + i + 1][(*currentsquare - i) - 1] % 2 != 0 && *(currentsquare + 1) + i + 1 <= 7 && (*currentsquare - i) - 1 >= 0){         //checks if you can capture
                    printf("\norca\n");
                    *(upleft + 1) = *(currentsquare + 1);
                    *upleft = *currentsquare;
                    *upleft = (*upleft - i) - 1;
                    *(upleft + 1) = i + *(upleft + 1) + 1;                         //upleft is now the left and up most square you can move
                }
            }
            else{
                if(board[*(currentsquare + 1) + i + 1][(*currentsquare - i) - 1] % 2 == 0 && board[*(currentsquare + 1) + i + 1][(*currentsquare - i) - 1] != 0 && *(currentsquare + 1) + i + 1 <= 7 && (*currentsquare - i) - 1 >= 0){   //checks if black can capture
                    *(upleft + 1) = *(currentsquare + 1);
                    *upleft = *currentsquare;
                    *upleft = (*upleft - i) - 1;
                    *(upleft + 1) = i + *(upleft + 1) + 1;                         //upleft is now the left and up most square you can move
                }
            }
            break;        
        }
    }
    printf("\nupleft %d %d\n",*(upleft + 1),*upleft);
    printf("upright %d %d\n",*(upright + 1),*upright);
    printf("downleft %d %d\n",*(downleft + 1),*downleft);
    printf("downright %d %d\n",*(downright +1),*downright);
    
    printf(" where would you like to move your Bishop? ");
    squarecord2 = getmove();
    for(int i = 0;i + *(currentsquare + 1) <=8 && i + *currentsquare <=8 && *downleft + i <= *upright && *(downleft + 1) + i <= *(upright + 1); i++){
        if(*squarecord2 == (*downleft + i) && *(squarecord2 + 1) == *(downleft + 1) + i){
            board[*(squarecord2 + 1)][*squarecord2] = board[*(currentsquare + 1)][*currentsquare];
            board[*(currentsquare + 1)][*currentsquare] = 0;
            orca = 1;
        }
    }
    for(int i = 0;*(currentsquare + 1) + i <= 8 &&  *currentsquare - i >=0 && *downright - i >= *upleft && *(downright + 1) + i <= *(upleft + 1); i++){
        if(*squarecord2 == (*downright - i) && *(squarecord2 + 1) == *(downright + 1) + i){
            board[*(squarecord2 + 1)][*squarecord2] = board[*(currentsquare + 1)][*currentsquare];
            board[*(currentsquare + 1)][*currentsquare] = 0;
            orca = 1;
        }
    }
    if(!orca){
        printf("\nthat is not a valid move\n");
        bishop(board,currentsquare,color);
    }        
}

int rook(int board[][8],int *currentsquare,int color){
    int *squarecord2;
    int *right, *down, *up, *left;
    int orca = 0;
    printf("current square %d ",*(currentsquare+1));
    printf("%d",*currentsquare);
    up = (int *) malloc(5);
    down = (int *) malloc(5);
    left = (int *) malloc(5);
    right = (int *) malloc(5);
    squarecord2 = (int *) malloc(5);
    for(int i = 0;*(currentsquare + 1) + i <= 7;i++){
        *(up + 1) = *(currentsquare + 1);
        *up = *currentsquare;
        *(up + 1) = i + *(up + 1);
        if(*(up + 1) == 7){
            break;
        }
        if(board[*(currentsquare + 1) + i + 1][*currentsquare] > 0){
            if(!color){
                if(board[*(currentsquare + 1) + i + 1][*currentsquare] % 2 != 0 && *(currentsquare + 1) + i + 1 <= 7){
                    *(up + 1) = *(currentsquare + 1);
                    *up = *currentsquare;
                    *(up + 1) = i + *(up + 1) + 1;
                }
            }
            else{
                if(board[(*(currentsquare + 1) + i) + 1][*currentsquare] % 2 == 0 && board[(*(currentsquare + 1) + i) + 1][*currentsquare] != 0 && *(currentsquare + 1) + i + 1 <= 7){
                    *(up + 1) = *(currentsquare + 1);
                    *up = *currentsquare;
                    *(up + 1) = i + *(up + 1) + 1;
                }
            }
            break;
        }
    }
    for(int i = 0;*(currentsquare + 1) - i >= 0;i++){
        *(down + 1) = *(currentsquare + 1) - i;
        *down = *currentsquare;
        if(*(down + 1) == 0){
            break;
        }
        if(board[*(currentsquare + 1) - i - 1][*currentsquare] > 0){
            if(!color){
                if(board[*(currentsquare + 1) - i - 1][*currentsquare] % 2 != 0 && *(currentsquare + 1) - i - 1 >= 0){
                    *(down + 1) = *(currentsquare + 1) - i - 1;
                    *down = *currentsquare;
                }
            }
            else{
                if(board[(*(currentsquare + 1) + i) + 1][*currentsquare] % 2 == 0 && board[(*(currentsquare + 1) + i) + 1][*currentsquare] != 0 && *(currentsquare + 1) - i - 1 >= 0){
                    *(down + 1) = *(currentsquare + 1) - i - 1;
                    *down = *currentsquare;
                }
            }
            break;
        }
    }
    for(int i = 0;*(currentsquare) + i <= 7;i++){
        *(right) = *(currentsquare) + i;
        *(right + 1) = *(currentsquare + 1);
        if(*right == 7){
            break;
        }
        if(board[*(currentsquare + 1)][*currentsquare + i + 1] > 0){
            if(!color){
                if(board[*(currentsquare + 1)][*currentsquare + i + 1] % 2 != 0 && *currentsquare + i + 1 <= 7){
                    *(right) = *(currentsquare) + i + 1;
                    *(right + 1) = *(currentsquare + 1);
                }
            }
            else{
                if(board[*(currentsquare + 1)][*currentsquare + i + 1] % 2 == 0 && board[*(currentsquare + 1)][*currentsquare + i + 1] != 0 && *currentsquare + i + 1 <= 7){
                    *(right) = *(currentsquare) + i + 1;
                    *(right + 1) = *(currentsquare + 1);
                }
            }
            break;
        }
    }
    for(int i = 0;*(currentsquare) - i >= 0;i++){
        *(left) = *(currentsquare) - i;
        *(left + 1) = *(currentsquare + 1);
        if(*left == 0){
            break;
        }
        if(board[*(currentsquare + 1)][*currentsquare - i - 1] > 0){
            if(!color){
                if(board[*(currentsquare + 1)][*currentsquare - i - 1] % 2 != 0 && *currentsquare - i - 1 >= 0){
                    *(left) = *(currentsquare) - i - 1;
                    *(left + 1) = *(currentsquare + 1);
                }
            }
            else{
                if(board[*(currentsquare + 1)][*currentsquare - i - 1] % 2 == 0 && board[*(currentsquare + 1)][*currentsquare - i - 1] != 0 && *currentsquare - i - 1 >= 0){
                    *(left) = *(currentsquare) - i - 1;
                    *(left + 1) = *(currentsquare + 1);
                }
            }
            break;
        }
    }
    printf("\nup %d %d\n",*(up + 1),*up);
    printf("right %d %d\n",*(right + 1),*right);
    printf("left %d %d\n",*(left + 1),*left);
    printf("down %d %d\n",*(down +1),*down);
    
    printf(" where would you like to move your rookn\n? ");
    squarecord2 = getmove();
    for(int i = 0;i + *(currentsquare + 1) <=8 && *currentsquare <=8 && *(down + 1) + i <= *(up + 1); i++){
        if(*squarecord2 == (*down) && *(squarecord2 + 1) == *(down + 1) + i){
            board[*(squarecord2 + 1)][*squarecord2] = board[*(currentsquare + 1)][*currentsquare];
            board[*(currentsquare + 1)][*currentsquare] = 0;
            orca = 1;
        }
    }
    for(int i = 0;*(currentsquare + 1)<= 8 &&  *currentsquare + i <=8 && *left + i <= *right; i++){
        if(*squarecord2 == (*left + i) && *(squarecord2 + 1) == *(left + 1)){
            board[*(squarecord2 + 1)][*squarecord2] = board[*(currentsquare + 1)][*currentsquare];
            board[*(currentsquare + 1)][*currentsquare] = 0;
            orca = 1;
        }
    }
    if(!orca){
        printf("\nthat is not a valid move\n");
        rook(board,currentsquare,color);
    }            
}
int queen(int board[][8],int *currentsquare,int color){
    int *squarecord2;
    int *right, *down, *up, *left;
    int orca = 0;
    printf("current square %d ",*(currentsquare+1));
    printf("%d",*currentsquare);
    up = (int *) malloc(5);
    down = (int *) malloc(5);
    left = (int *) malloc(5);
    right = (int *) malloc(5);
    squarecord2 = (int *) malloc(5);
    int *upright, *downright, *upleft, *downleft;
    upright = (int *) malloc(5);
    downright = (int *) malloc(5);
    upleft = (int *) malloc(5);
    downleft = (int *) malloc(5);

    for(int i = 0; i + *(currentsquare + 1) <= 7 && i + *currentsquare <= 7; i++){
        *upright = *currentsquare;
        *(upright + 1) = *(currentsquare + 1);
        *upright = i + *upright;
        *(upright + 1) = i + *(upright + 1);                         //upright is now the right and up most square you can move
        if(*(upright + 1)== 7){
            break;
        }
        if(*upright == 7){
            break;
        }
        if(board[*(currentsquare + 1) + i + 1][*currentsquare + i + 1] > 0){
            if(!color){
                if(board[*(currentsquare + 1) + i + 1][*currentsquare + i + 1] % 2 != 0 && *(currentsquare + 1) + i + 1 <= 7 && *currentsquare + i + 1 <= 7){
                    *upright = *currentsquare;
                    *(upright + 1) = *(currentsquare + 1);
                    *upright = i + *upright + 1;
                    *(upright + 1) = i + *(upright + 1) + 1;                         //upright is now the right and up most square you can move including takes
                }
            }
            else{
                if(board[*(currentsquare + 1) + i + 1][*currentsquare + i + 1] % 2 == 0 && board[*(currentsquare + 1) + i + 1][*currentsquare + i + 1] != 0 && *(currentsquare + 1) + i + 1 <= 7 && *currentsquare + i + 1 <= 7){
                    *upright = *currentsquare;
                    *(upright + 1) = *(currentsquare + 1);
                    *upright = i + *upright + 1;
                    *(upright + 1) = i + *(upright + 1) + 1;                         //upright is now the right and up most square you can move including takes
                }
            }
            break;
        }
    }
    for(int i = 0; *(currentsquare + 1) - i >= 0 && i + *currentsquare <= 7; i++){
        *downright = *currentsquare;
        *(downright + 1) = *(currentsquare + 1);
        *downright = *downright + i;
        *(downright + 1) = (*(downright + 1) - i);                         //down is now the right and down most square you can move
        if(*(downright + 1) == 0){
            break;
        }
        if(*downright == 7){
            break;
        }
        if(board[(*(currentsquare + 1) - i) - 1][*currentsquare + i + 1] > 0){
            if(!color){
                if(board[(*(currentsquare + 1) - i) - 1][*currentsquare + i + 1] % 2 != 0 && (*(currentsquare + 1 ) - i) - 1 >= 0 && *currentsquare + i + 1 <= 7){
                    printf(" orca ");
                    *downright = *currentsquare;
                    *(downright + 1) = *(currentsquare + 1);
                    *downright = i + *downright + 1;
                    *(downright + 1) = (*(downright + 1) - i) - 1;                         //down is now the right and down most square you can move    
                }
            }
            else{
                if(board[(*(currentsquare + 1) - i) - 1][*currentsquare + i + 1] % 2 == 0 && board[(*(currentsquare + 1) - i) - 1][*currentsquare + i + 1] != 0 && (*(currentsquare + 1 ) - i) - 1 >= 0 && *currentsquare + i + 1 <= 7){
                    *downright = *currentsquare;
                    *(downright + 1) = *(currentsquare + 1);
                    *downright = i + *downright + 1;
                    *(downright + 1) = (*(downright + 1) - i) - 1;                         //down is now the right and down most square you can move 
                }
            }
            break;
        }
    }
    for(int i = 0; *(currentsquare + 1) - i > 0 && *currentsquare - i >= 0; i++){
        *downleft = *currentsquare;
        *(downleft + 1) = *(currentsquare + 1);
        *downleft = (*downleft - i);
        *(downleft + 1) = (*(downleft + 1) - i);                         //down is now the left and down most square you can move
        if(*(downleft + 1) == 0){
            break;
        }
        if (*downleft == 0){
            break;
        }
        if(board[(*(currentsquare + 1) - i) - 1][(*currentsquare - i) - 1] > 0){
            if(!color){
                if(board[(*(currentsquare + 1) - i) - 1][(*currentsquare - i) - 1] % 2 != 0 && (*(currentsquare + 1) - i) - 1 >= 0 && (*currentsquare - i) - 1 >= 0){
                    printf("orca");
                    *downleft = *currentsquare;
                    *(downleft + 1) = *(currentsquare + 1);
                    *downleft = (*downleft - i) - 1;
                    *(downleft + 1) = ((*(downleft + 1) - i) - 1);                         //down is now the left and down most square you can move
                }
            }
            else{
                if(board[(*(currentsquare + 1) - i) - 1][(*currentsquare - i) - 1] % 2 == 0 && board[(*(currentsquare + 1) - i) - 1][(*currentsquare - i) - 1] != 0 && (*(currentsquare + 1) - i) - 1 >= 0 && (*currentsquare - i) - 1 >= 0){
                    *downleft = *currentsquare;
                    *(downleft + 1) = *(currentsquare + 1);
                    *downleft = (*downleft - i) - 1;
                    *(downleft + 1) = ((*(downleft + 1) - i) - 1);                         //down is now the left and down most square you can move
                }
            }
            break;
        }
    }
    for(int i = 0; i + *(currentsquare + 1) <= 7 && *currentsquare - i >= 0; i++){
        *(upleft + 1) = *(currentsquare + 1);
        *upleft = *currentsquare;
        *upleft = (*upleft - i);
        *(upleft + 1) = i + *(upleft + 1);                         //upleft is now the left and up most square you can move
        if(*(upleft + 1) == 7){
            break;
        }
        if(*upleft == 0){
            break;
        }
        if(board[*(currentsquare + 1) + i + 1][(*currentsquare - i) - 1] > 0){
            if(!color){
                if(board[*(currentsquare + 1) + i + 1][(*currentsquare - i) - 1] % 2 != 0 && *(currentsquare + 1) + i + 1 <= 7 && (*currentsquare - i) - 1 >= 0){         //checks if you can capture
                    *(upleft + 1) = *(currentsquare + 1);
                    *upleft = *currentsquare;
                    *upleft = (*upleft - i) - 1;
                    *(upleft + 1) = i + *(upleft + 1) + 1;                         //upleft is now the left and up most square you can move
                }
            }
            else{
                if(board[*(currentsquare + 1) + i + 1][(*currentsquare - i) - 1] % 2 == 0 && board[*(currentsquare + 1) + i + 1][(*currentsquare - i) - 1] != 0 && *(currentsquare + 1) + i + 1 <= 7 && (*currentsquare - i) - 1 >= 0){   //checks if black can capture
                    *(upleft + 1) = *(currentsquare + 1);
                    *upleft = *currentsquare;
                    *upleft = (*upleft - i) - 1;
                    *(upleft + 1) = i + *(upleft + 1) + 1;                         //upleft is now the left and up most square you can move
                }
            }
            break;        
        }
    }




    for(int i = 0;*(currentsquare + 1) + i <= 7;i++){
        *(up + 1) = *(currentsquare + 1);
        *up = *currentsquare;
        *(up + 1) = i + *(up + 1);
        if(*(up + 1) == 7){
            break;
        }
        if(board[*(currentsquare + 1) + i + 1][*currentsquare] > 0){
            if(!color){
                if(board[*(currentsquare + 1) + i + 1][*currentsquare] % 2 != 0 && *(currentsquare + 1) + i + 1 <= 7){
                    *(up + 1) = *(currentsquare + 1);
                    *up = *currentsquare;
                    *(up + 1) = i + *(up + 1) + 1;
                }
            }
            else{
                if(board[(*(currentsquare + 1) + i) + 1][*currentsquare] % 2 == 0 && board[(*(currentsquare + 1) + i) + 1][*currentsquare] != 0 && *(currentsquare + 1) + i + 1 <= 7){
                    *(up + 1) = *(currentsquare + 1);
                    *up = *currentsquare;
                    *(up + 1) = i + *(up + 1) + 1;
                }
            }
            break;
        }
    }
    for(int i = 0;*(currentsquare + 1) - i >= 0;i++){
        *(down + 1) = *(currentsquare + 1) - i;
        *down = *currentsquare;
        if(*(down + 1) == 0){
            break;
        }
        if(board[*(currentsquare + 1) - i - 1][*currentsquare] > 0){
            if(!color){
                if(board[*(currentsquare + 1) - i - 1][*currentsquare] % 2 != 0 && *(currentsquare + 1) - i - 1 >= 0){
                    *(down + 1) = *(currentsquare + 1) - i - 1;
                    *down = *currentsquare;
                }
            }
            else{
                if(board[(*(currentsquare + 1) + i) + 1][*currentsquare] % 2 == 0 && board[(*(currentsquare + 1) + i) + 1][*currentsquare] != 0 && *(currentsquare + 1) - i - 1 >= 0){
                    *(down + 1) = *(currentsquare + 1) - i - 1;
                    *down = *currentsquare;
                }
            }
            break;
        }
    }
    for(int i = 0;*(currentsquare) + i <= 7;i++){
        *(right) = *(currentsquare) + i;
        *(right + 1) = *(currentsquare + 1);
        if(*right == 7){
            break;
        }
        if(board[*(currentsquare + 1)][*currentsquare + i + 1] > 0){
            if(!color){
                if(board[*(currentsquare + 1)][*currentsquare + i + 1] % 2 != 0 && *currentsquare + i + 1 <= 7){
                    *(right) = *(currentsquare) + i + 1;
                    *(right + 1) = *(currentsquare + 1);
                }
            }
            else{
                if(board[*(currentsquare + 1)][*currentsquare + i + 1] % 2 == 0 && board[*(currentsquare + 1)][*currentsquare + i + 1] != 0 && *currentsquare + i + 1 <= 7){
                    *(right) = *(currentsquare) + i + 1;
                    *(right + 1) = *(currentsquare + 1);
                }
            }
            break;
        }
    }
    for(int i = 0;*(currentsquare) - i >= 0;i++){
        *(left) = *(currentsquare) - i;
        *(left + 1) = *(currentsquare + 1);
        if(*left == 0){
            break;
        }
        if(board[*(currentsquare + 1)][*currentsquare - i - 1] > 0){
            if(!color){
                if(board[*(currentsquare + 1)][*currentsquare - i - 1] % 2 != 0 && *currentsquare - i - 1 >= 0){
                    *(left) = *(currentsquare) - i - 1;
                    *(left + 1) = *(currentsquare + 1);
                }
            }
            else{
                if(board[*(currentsquare + 1)][*currentsquare - i - 1] % 2 == 0 && board[*(currentsquare + 1)][*currentsquare - i - 1] != 0 && *currentsquare - i - 1 >= 0){
                    *(left) = *(currentsquare) - i - 1;
                    *(left + 1) = *(currentsquare + 1);
                }
            }
            break;
        }
    }
    char *newup;
    newup = (char *) malloc(5);
    newup = givecords(up);
    printf("\nup %c %c\n",*(newup),*(newup + 1));
    printf("right %d %d\n",*(right + 1),*right);
    printf("left %d %d\n",*(left + 1),*left);
    printf("down %d %d\n",*(down +1),*down);
    printf("\nupleft %d %d\n",*(upleft + 1),*upleft);
    printf("upright %d %d\n",*(upright + 1),*upright);
    printf("downleft %d %d\n",*(downleft + 1),*downleft);
    printf("downright %d %d\n",*(downright +1),*downright);

    printf(" where would you like to move your queen?\n ");
    squarecord2 = getmove();
    for(int i = 0;i + *(currentsquare + 1) <=8 && *currentsquare <=8 && *(down + 1) + i <= *(up + 1); i++){
        if(*squarecord2 == (*down) && *(squarecord2 + 1) == *(down + 1) + i){
            board[*(squarecord2 + 1)][*squarecord2] = board[*(currentsquare + 1)][*currentsquare];
            board[*(currentsquare + 1)][*currentsquare] = 0;
            orca = 1;
        }
    }
    for(int i = 0;*(currentsquare + 1)<= 8 &&  *currentsquare + i <=8 && *left + i<= *right; i++){
        if(*squarecord2 == (*left + i) && *(squarecord2 + 1) == *(left + 1)){
            board[*(squarecord2 + 1)][*squarecord2] = board[*(currentsquare + 1)][*currentsquare];
            board[*(currentsquare + 1)][*currentsquare] = 0;
            orca = 1;
        }
    }
    for(int i = 0;i + *(currentsquare + 1) <=8 && i + *currentsquare <=8 && *downleft + i <= *upright && *(downleft + 1) + i <= *(upright + 1); i++){
        if(*squarecord2 == (*downleft + i) && *(squarecord2 + 1) == *(downleft + 1) + i){
            board[*(squarecord2 + 1)][*squarecord2] = board[*(currentsquare + 1)][*currentsquare];
            board[*(currentsquare + 1)][*currentsquare] = 0;
            orca = 1;
        }
    }
    for(int i = 0;*(currentsquare + 1) + i <= 8 &&  *currentsquare - i >=0 && *downright - i >= *upleft && *(downright + 1) + i <= *(upleft + 1); i++){
        if(*squarecord2 == (*downright - i) && *(squarecord2 + 1) == *(downright + 1) + i){
            board[*(squarecord2 + 1)][*squarecord2] = board[*(currentsquare + 1)][*currentsquare];
            board[*(currentsquare + 1)][*currentsquare] = 0;
            orca = 1;
        }
    }
    if(!orca){
        printf("\nthat is not a valid move\n");
        queen(board,currentsquare,color);
    }            
}

int wking = 0;
int bking = 0;

int king(int board[][8],int *currentsquare,int color){
    int *squarecord2;
    int orca = 0;
    squarecord2 = (int *) malloc(5);
    squarecord2 = getmove();
    if((*squarecord2 == *currentsquare + 1 && *(squarecord2 + 1) == *(currentsquare + 1) + 1) || (*squarecord2 == *currentsquare && *(squarecord2 + 1) == *(currentsquare + 1) + 1) || (*squarecord2 == *currentsquare - 1 && *(squarecord2 + 1) == *(currentsquare + 1) + 1) || (*squarecord2 == *currentsquare - 1 && *(squarecord2 + 1) == *(currentsquare + 1) || (*squarecord2 == *currentsquare + 1 && *(squarecord2 + 1) == *(currentsquare + 1)) || (*squarecord2 == *currentsquare - 1 && *(squarecord2 + 1) == *(currentsquare + 1) - 1) || (*squarecord2 == *currentsquare && *(squarecord2 + 1) == *(currentsquare + 1) - 1) || (*squarecord2 == *currentsquare + 1 && *(squarecord2 + 1) == *(currentsquare + 1) - 1))){
        board[*(squarecord2 + 1)][*squarecord2] = board[*(currentsquare + 1)][*currentsquare];
        board[*(currentsquare + 1)][*currentsquare] = 0;
        orca = 1;
        if (!color){
            wking = 1;
        }
        else{
            bking = 1;
        }
    }
    if(!color){
        if(*currentsquare == *squarecord2 - 2 && *(currentsquare + 1) == *(squarecord2 + 1) && !wking && !ischeck(board,makemove('f','1'),color) && !ischeck(board,makemove('g','1'),color) && board[0][5] == 0 && board[0][6] == 0){
            board[*(squarecord2 + 1)][*squarecord2] = board[*(currentsquare + 1)][*currentsquare];
            board[0][5] = board[0][7];
            board[0][7] = 0;
            board[*(currentsquare + 1)][*currentsquare] = 0;
            orca = 1;
            wking = 1;
        }
        if(*currentsquare == *squarecord2 + 2 && *(currentsquare + 1) == *(squarecord2 + 1) && !wking && !ischeck(board,makemove('b','1'),color) && !ischeck(board,makemove('c','1'),color) && !ischeck(board,makemove('d','1'),color) && board[0][1] == 0 && board[0][2] == 0 && board[0][3] == 0){
            board[*(squarecord2 + 1)][*squarecord2] = board[*(currentsquare + 1)][*currentsquare];
            board[0][3] = board[0][0];
            board[0][0] = 0;
            board[*(currentsquare + 1)][*currentsquare] = 0;
            orca = 1;
            wking = 1;
        }
    }
    else{
        if(*currentsquare == *squarecord2 - 2 && *(currentsquare + 1) == *(squarecord2 + 1) && !bking && !ischeck(board,makemove('f','8'),color) && !ischeck(board,makemove('g','8'),color) && board[7][5] == 0 && board[7][6] == 0){
            board[*(squarecord2 + 1)][*squarecord2] = board[*(currentsquare + 1)][*currentsquare];
            board[7][5] = board[7][7];
            board[7][7] = 0;
            board[*(currentsquare + 1)][*currentsquare] = 0;
            orca = 1;
            bking = 1;
        }
        if(*currentsquare == *squarecord2 + 2 && *(currentsquare + 1) == *(squarecord2 + 1) && !bking && !ischeck(board,makemove('b','8'),color) && !ischeck(board,makemove('c','8'),color) && !ischeck(board,makemove('d','8'),color) && board[7][1] == 0 && board[7][2] == 0 && board[7][3] == 0){
            board[*(squarecord2 + 1)][*squarecord2] = board[*(currentsquare + 1)][*currentsquare];
            board[7][3] = board[7][0];
            board[7][0] = 0;
            board[*(currentsquare + 1)][*currentsquare] = 0;
            orca = 1;
            bking = 1;
        }
    }
    //printf("%d %d",)
    if(!orca){
        printf("\nthat is not a valid move\n");
        king(board,currentsquare,color);
    }
}