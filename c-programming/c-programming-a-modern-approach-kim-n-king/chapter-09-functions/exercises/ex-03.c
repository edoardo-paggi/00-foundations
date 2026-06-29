/*
 * Name: ex-03.c
 * Author: Edoardo Paggi
 * Task: modify the Programming Project in Chapter 8 to include the following 
         functions:
         
         void generate_random_walk(char walk[10][10]);
         void print_array(char walk[10][10]);
         
         First, the main program will need to call generate_random_walk, which 
         initializes the array to contain the characters '.' and then replaces 
         some of these with the letters A to Z, as described in the original 
         project. The main program will then need to call the print_array 
         function to print the array to the screen.
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

void generate_random_walk(char walk[][SIZE]);
void print_array(char walk[][SIZE]);

int main(void) {

    char walk[SIZE][SIZE];
    char ch;
    
    generate_random_walk(walk);

    print_array(walk);

    return 0;
}

void generate_random_walk(char walk[][SIZE]) {

    int moves[MOVES] = {0};
    int move;

    // Board initialize
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++) 
            walk[i][j] = '.';

    // Random seed initialize
    srand((unsigned) time(NULL));

    // First letter initialize
    int i = 0, j = 0;
    char ch = 'A';
    walk[i][j] = ch;

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
                    if (walk[i][j] != '.') {
                        i++;
                        moves[UP]++;
                    } else {
                        ch++;
                        walk[i][j] = ch;
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
                    if (walk[i][j] != '.') {
                        j--;
                        moves[RIGHT]++;
                    } else {
                        ch++;
                        walk[i][j] = ch;
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
                    if (walk[i][j] != '.') {
                        i--;
                        moves[DOWN]++;
                    } else {
                        ch++;
                        walk[i][j] = ch;
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
                    if (walk[i][j] != '.') {
                        j++;
                        moves[LEFT]++;
                    } else {
                        ch++;
                        walk[i][j] = ch;
                        for (int k = 0; k < MOVES; k++)
                            moves[k] = 0;
                    }
                    break;
            }
        } 
    } 
}

void print_array(char walk[][SIZE]) {

    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c  ", walk[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}