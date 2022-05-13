#ifndef BOTBASELINE
#define BOTBASELINE

#include <iostream>
#include <stdlib.h>
#include "config.h"
const long atk_score[7]={0,3,21,192,1535,12288,98304};
const long def_score[7]={0,1,9,81,729,6561,59049};
void value_row(int board_game[][WIDTH], int player_id, int m, int n, int a[]){
    int value_max=0;
    int up=1;
    int down=1;
    int space=1;
    while(board_game[m][n+up]!=-player_id&&n+up<50){
        space++;
        up++;
    }
    while(board_game[m][n-down]!=-player_id&&n-down>-1){
        space++;
        down++;
    }
    if(space<6){
        return;
    }
    board_game[m][n]=player_id;
    for(int i=0;i<4;i++){
        if(n-3+i<0)
            i+=(0-(n-3+i));
        int valuer=0;
        if((n-4+i==-1||board_game[m][n-4+i]==-player_id)){
            valuer --;
        }
        if(board_game[m][n-3+i]==player_id){
            valuer +=2;
        }
        if(board_game[m][n-2+i]==player_id){
            valuer +=2;
        }
        if(board_game[m][n-1+i]==player_id){
            valuer +=2;
        }
        if(board_game[m][n+i]==player_id){
            valuer +=2;
        }
        if(board_game[m][n-3+i]==-player_id){
            valuer = 0;
        }
        if(board_game[m][n-2+i]==-player_id){
            valuer = 0;
        }
        if(board_game[m][n-1+i]==-player_id){
            valuer = 0;
        }
        if((n+1+i>49||board_game[m][n+1+i]==-player_id)){
            valuer --;
            i+=4;
        }
        if(valuer>value_max){
            value_max=valuer;
        }
    }
    a[value_max]++;
    board_game[m][n]=0;
}
void value_col(int board_game[][WIDTH], int player_id, int m, int n, int a[]){
    int value_max=0;
    int up=1;
    int down=1;
    int space=1;
    while(board_game[m+up][n]!=-player_id&&m+up<30){
        space++;
        up++;
    }
    while(board_game[m-down][n]!=-player_id&&m-down>-1){
        space++;
        down++;
    }
    if(space<6){
        return;
    }
    board_game[m][n]=player_id;
    for(int i=0;i<4;i++){
        if(m-3+i<0)
            i+=(0-(m-3+i));
        int valuer=0;
        if((m-4+i==-1||board_game[m-4+i][n]==-player_id)){
            valuer --;
        }
        if(board_game[m-3+i][n]==player_id){
            valuer +=2;
        }
        if(board_game[m-2+i][n]==player_id){
            valuer +=2;
        }
        if(board_game[m-1+i][n]==player_id){
            valuer +=2;
        }
        if(board_game[m+i][n]==player_id){
            valuer +=2;
        }
        if(board_game[m-3+i][n]==-player_id){
            valuer = 0;
        }
        if(board_game[m-2+i][n]==-player_id){
            valuer = 0;
        }
        if(board_game[m-1+i][n]==-player_id){
            valuer = 0;
        }
        if((m+1+i>29||board_game[m+1+i][n]==-player_id)){
            valuer --;
            i+=4;
        }
        if(valuer>value_max){
            value_max=valuer;
        }
    }
    a[value_max]++;
    board_game[m][n]=0;
}
void value_cross_1(int board_game[][WIDTH], int player_id, int m, int n, int a[]){
    int value_max=0;
    int up=1;
    int down=1;
    int space=1;
    while(board_game[m+up][n+up]!=-player_id&&m+up<30&&n+up<50){
        space++;
        up++;
    }
    while(board_game[m-down][n-down]!=-player_id&&m-down>-1&&n-down>-1){
        space++;
        down++;
    }
    if(space<6){
        return;
    }
    board_game[m][n]=player_id;
    for(int i=0;i<4;i++){
        while(m-3+i<0||n-3+i<0){
            i++;
        }
        int valuer=0;
        if((m-4+i==-1||n-4+i==-1||board_game[m-4+i][n-4+i]==-player_id)){
            valuer --;
        }
        if(board_game[m-3+i][n-3+i]==player_id){
            valuer +=2;
        }
        if(board_game[m-2+i][n-2+i]==player_id){
            valuer +=2;
        }
        if(board_game[m-1+i][n-1+i]==player_id){
            valuer +=2;
        }
        if(board_game[m+i][n+i]==player_id){
            valuer +=2;
        }
        if(board_game[m-3+i][n-3+i]==-player_id){
            valuer = 0;
        }
        if(board_game[m-2+i][n-2+i]==-player_id){
            valuer = 0;
        }
        if(board_game[m-1+i][n-1+i]==-player_id){
            valuer = 0;
        }
        if((m+1+i>29||n+1+i>49||board_game[m+1+i][n+1+i]==-player_id)){
            valuer --;
            i+=4;
        }
        if(valuer>value_max){
            value_max=valuer;
        }
    }
    a[value_max]++;
    board_game[m][n]=0;
}
void value_cross_2(int board_game[][WIDTH], int player_id, int m, int n, int a[]){
    int value_max=0;
    int up=1;
    int down=1;
    int space=1;
    while(board_game[m-up][n+up]!=-player_id&&m-up>-1&&n+up<50){
        space++;
        up++;
    }
    while(board_game[m+down][n-down]!=-player_id&&m+down<30&&n-down>-1){
        space++;
        down++;
    }
    if(space<6){
        return;
    }
    board_game[m][n]=player_id;
    for(int i=0;i<4;i++){
        while(m+3-i>29||n-3+i<0){
            i++;
        }
        int valuer=0;
        if((m+4-i==30||n-4+i==-1||board_game[m+4-i][n-4+i]==-player_id)){
            valuer --;
        }
        if(board_game[m+3-i][n-3+i]==player_id){
            valuer +=2;
        }
        if(board_game[m+2-i][n-2+i]==player_id){
            valuer +=2;
        }
        if(board_game[m+1-i][n-1+i]==player_id){
            valuer +=2;
        }
        if(board_game[m-i][n+i]==player_id){
            valuer +=2;
        }
        if(board_game[m+3-i][n-3+i]==-player_id){
            valuer = 0;
        }
        if(board_game[m+2-i][n-2+i]==-player_id){
            valuer = 0;
        }
        if(board_game[m+1-i][n-1+i]==-player_id){
            valuer = 0;
        }
        if((m-1-i<0||n+1+i>49||board_game[m-1-i][n+1+i]==-player_id)){
            valuer --;
            i+=4;
        }
        if(valuer>value_max){
            value_max=valuer;
        }
    }
    a[value_max]++;
    board_game[m][n]=0;
}
long value(int board_game[][WIDTH], int player_id, int m, int n){
    int a[9];
    int b[9];
    for(int i=0;i<9;i++){
        a[i]=0;
        b[i]=0;
    }
    value_row(board_game,player_id,m,n,a);
    value_col(board_game,player_id,m,n,a);
    value_cross_1(board_game,player_id,m,n,a);
    value_cross_2(board_game,player_id,m,n,a);
    value_row(board_game,-player_id,m,n,b);
    value_col(board_game,-player_id,m,n,b);
    value_cross_1(board_game,-player_id,m,n,b);
    value_cross_2(board_game,-player_id,m,n,b);
    if(a[8]>=1){
        return 10000000;
    }
    if(a[7]>=2){
        return 10000000;
    }
    if(a[7]>=1&&a[6]>=1){
        return 10000000;
    }
    if(b[8]>=1){
        return 4999999;
    }
    if(b[7]>=2){
        return 4999999;
    }
    if(b[7]>=1&&b[6]>=1){
        return 4999999;
    }
    if(a[6]>=2){
        return 2499999;
    }
    if(b[6]>=2){
        return 1249999;
    }
    long v=0;
    for(int i=1;i<8;i++){
        v+=atk_score[i-1]*a[i];
        v+=def_score[i-1]*b[i];
    }
    return v;
}

Point check_win(int board_game[][WIDTH], int player_id){
    return Point(-1,-1);
}
Point defend(int board_game[][WIDTH], int player_id){
    return Point(-1,-1);
}
Point attack(int board_game[][WIDTH], int player_id){
    long value_max=0;
    int x;
    int y;
    for(int m=0;m<30;m++){
        for(int n=0;n<50;n++){
            if(board_game[m][n]==0){
                long v=value(board_game, player_id, m, n);
                if(v>value_max){
                    value_max=v;
                    x=m;
                    y=n;
                }
            }
        }
    }
    return Point(x,y);
}
Point check_n_tile(int board_game[][WIDTH], int player_id, int n){
}

// player_id = 1 || -1
Point player_rand(int board_game[][WIDTH], int player_id){
    int row, col;
    row = rand() % HEIGHT;
    col = rand() % WIDTH;
    return Point(row, col);
}

Point player_baseline(int board_game[][WIDTH], int player_id){
    Point p = check_win(board_game, player_id);
    if(p.x != -1 && p.y != -1){
        return p;
    } else {
        p = defend(board_game, player_id);
        if(p.x != -1 && p.y != -1){
            return p;
        } else {
            if(board_game[15][25]==0){
                return Point(15,25);
            }
            if(board_game[14][26]==0){
                return Point(14,26);
            }
            return attack(board_game, player_id);
            //return player_rand(board_game, player_id);
        }
    }
}

#endif // BOTBASELINE
