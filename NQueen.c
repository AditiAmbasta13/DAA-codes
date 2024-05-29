#include<stdio.h>
#include<stdbool.h>
#define N 4

//print board
void print(int board[N][N]){
    printf("\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

//check same row and diagonals
bool safe(int board[N][N], int row, int col){
     for(int i=0;i<col;i++){
        if(board[row][i]){   //checks same row
            return false;
        }
    }
    for(int i=row , j=col ; i>=0 && j>=0 ; i--,j--){
        if(board[i][j]){    //checks LEFT diagonal / down up
            return false;
        }
    }
    for(int i=row , j=col ; i<N && j>=0 ; i++,j--){
        if(board[i][j]){    //checks RIGHT diagonal / < up down
            return false;
        }
    }
    return true;
}

//next col and backtrack
bool solve_util(int board[N][N], int col){
    if(col>=N){
        return true;
    }
    for(int i=0;i<N;i++){
        if(safe(board,i,col)){
            board[i][col] = 1;
            if(solve_util(board , col+1)){  //checks next column
                return true;
            }
            board[i][col] = 0;  //backtracks if not 
        }
    }
    return false;
}

bool solve(){
    int board[N][N] = {0};
    if(!solve_util(board,0)){
        printf("Solution does not exist");
        return false;
    }
    printf("Solution is : ");
    print(board);
    return true;
}

void main(){
    solve();
}