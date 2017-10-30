#include <stdio.h>
#include <stdlib.h>

//#define TRUE 1
//#define FALSE 0
#define SIZE 5
#define NONE -1
#define NOUGETS 0
#define CROSSES 1
#define EMPTY 2

void scanBoard(int board[SIZE][SIZE]);
void printBoard(int board[SIZE][SIZE]);
int getWinner(int board[SIZE][SIZE]);

int main(int argc, char *argv[])
{
	int board[SIZE][SIZE];
    
    printf("Please enter the board:\n");
    scanBoard(board);
    printf("Here is the board:\n");
    printBoard(board);
    int winner = getWinner(board);
    if(winner == 0){
       printf("Noughts Win\n");
    }else if(winner == 1) {
       printf("Crosses Win\n");
    }else if(winner == 2) {
       printf("No Winner\n");
    }
	return EXIT_SUCCESS;
}

void scanBoard(int board[SIZE][SIZE]){
    int row = 0;
    while (row < SIZE) {
        int col = 0;
        while (col < SIZE) {
            scanf("%d", &board[row][col]);
            col++;
        }
        row++;
    }
}

void printBoard(int board[SIZE][SIZE]){
    int row = 0;
    while (row < SIZE) {
        int col = 0;
        while (col < SIZE){
            if (board[row][col] == 0) {
               printf(" O");
            } else if (board[row][col] == 1) {
               printf(" X");
            } else if(board[row][col] == 2) {
               printf(" .");
            } 
               col++;
        
        }
        printf("\n");
        row++;
    }
}

int getWinner(int board[SIZE][SIZE]){
    int row = 0;
    int winner = 2;
    int col = 0;
    int count = 0;
    while (row < SIZE-1 && col < SIZE-1) {    
      if(board[row][col] != board[row+1][col+1]) {
         winner = 2;
       } else {
         count++;
       } 
       col++;
       row++;
    }
    if (count == SIZE-1) {
      winner = board[row][col];
    }
    count = 0;
    row = 0;
    col = 0;
    while (row > 0 && col < SIZE-1) {
       if (board[row+SIZE-1][col] != board[row+SIZE-2][col+1]) {
           winner = 2;
       } else { 
           count++;
       }
       row--;
       col++;
    }
    if (count == SIZE-1) {
      winner = board[row][col];
    }
    count = 0;
    row = 0;
    col = 0;
    while(row < SIZE-1 && col < SIZE) {
       if(board[row][col] != board[row][col+1]){
       row++;
       col = 0;
    } else {
       col++;
       count++;
       } 
    }
    if (count == SIZE-1) {
      winner = board[row][col];
    }
    count = 0;
    row = 0;
    col = 0;
    while (row < SIZE && col < SIZE-1) {
       if (board[row][col] != board[row+1][col]){
          col++;
          row = 0;
       } else {
         row++;
         count++;
       }
    }
    if (count == SIZE-1) {
       winner = board[row][col];
    }
    return winner;
}
