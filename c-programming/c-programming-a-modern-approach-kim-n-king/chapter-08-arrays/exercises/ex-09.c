/* 
 * Name: ex-09.c
 * Author: Edoardo Paggi
 * Task: write a program that generates a "random walk" in a 10x10 array. The 
         array will contain characters (initially, all '.'). The program should 
         randomly move from one element to the next, moving up, down, left, or 
         right by only one position. The elements visited by the program should 
         be labeled with the letters A through Z in the order in which they are 
         visited. Here's an example of the desired output:
         
         A  .  .  .  .  .  .  .  .  .
         B  C  D  .  .  .  .  .  .  .
         .  F  E  .  .  .  .  .  .  .
         H  G  .  .  .  .  .  .  .  . 
         I  .  .  .  .  .  .  .  .  .
         J  .  .  .  .  .  .  .  Z  .
         K  .  .  R  S  T  U  V  Y  .
         L  M  P  Q  .  .  .  W  X  .
         .  N  O  .  .  .  .  .  .  .
         .  .  .  .  .  .  .  .  .  .

         If all four directions are blocked the program must terminate.
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10
#define MOVES 4
#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

int main(void) {

    char board[SIZE][SIZE];
    char ch;
    int moves[MOVES] = {0};
    int move;

    // Board initialize
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++) 
            board[i][j] = '.';

    // Random seed initialize
    srand((unsigned) time(NULL));

    // First letter initialize
    int i = 0, j = 0;
    ch = 'A';
    board[i][j] = ch;

    // Engine
    for (;;) {
        if (moves[UP] && moves[RIGHT] && moves[DOWN] && moves[LEFT])
            break;

        if (ch == 'Z')
            break;

        move = rand() % MOVES; // 0, 1, 2, 3

        if (moves[move] == 0) {
            switch (move) {
                case UP: 
                    i--;
                    if (i < 0) {
                        i++;
                        moves[UP]++;
                        break;
                    }
                    if (board[i][j] != '.') {
                        i++;
                        moves[UP]++;
                    } else {
                        ch++;
                        board[i][j] = ch;
                        for (int k = 0; k < MOVES; k++)
                            moves[k] = 0;
                    }
                    break;

                case RIGHT:
                    j++;
                    if (j >= SIZE) {
                        j--;
                        moves[RIGHT]++;
                        break;
                    }
                    if (board[i][j] != '.') {
                        j--;
                        moves[RIGHT]++;
                    } else {
                        ch++;
                        board[i][j] = ch;
                        for (int k = 0; k < MOVES; k++)
                            moves[k] = 0;
                    }
                    break;
                    
                case DOWN:
                    i++;
                    if (i >= SIZE) {
                        i--;
                        moves[DOWN]++;
                        break;
                    }
                    if (board[i][j] != '.') {
                        i--;
                        moves[DOWN]++;
                    } else {
                        ch++;
                        board[i][j] = ch;
                        for (int k = 0; k < MOVES; k++)
                            moves[k] = 0;
                    }
                    break;

                case LEFT: 
                    j--;
                    if (j < 0) {
                        j++;
                        moves[LEFT]++;
                        break;
                    }
                    if (board[i][j] != '.') {
                        j++;
                        moves[LEFT]++;
                    } else {
                        ch++;
                        board[i][j] = ch;
                        for (int k = 0; k < MOVES; k++)
                            moves[k] = 0;
                    }
                    break;
            }
        } 
    }    

    // Board stamp
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c  ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    return 0;
}