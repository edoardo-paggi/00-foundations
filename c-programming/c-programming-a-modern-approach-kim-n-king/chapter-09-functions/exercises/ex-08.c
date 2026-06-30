/*
 * Name: ex-08.c
 * Author: Edoardo Paggi
 * Task: write a program that simulates the game of craps, which is played with 
         two dice. On the first roll, the player wins if the sum of the dice is 
         7 or 11. The player loses if the sum is 2, 3, or 12. Any other result 
         is called the "point," and the game continues. On all subsequent 
         rolls, the player wins if he rolls a "point" again. He loses if he 
         rolls a 7. Any other result is ignored, and the game continues. At the 
         end of each game, the program should ask the user if he wants to play 
         again. If the user answers anything other than y or Y, the program 
         should display the number of wins and losses before terminating.
         
         You rolled: 8
         Your point is 8
         You rolled: 3
         You rolled: 10
         You rolled: 8
         You win!
         
         Play again? y
         
         You rolled: 6
         Your point is 6
         You rolled: 5
         You rolled: 12
         You rolled: 3
         You rolled: 7
         you lose!
         
         Play again? y
         
         You rolled: 11
         You win!
         
         Play again? n
         
         Wins: 2 Losses: 1
         
         Write your program so that it consists of three functions: main, 
         roll_dice, and play_game. These are the prototypes for the last two 
         functions:
         
         int roll_dice(void);
         bool play_game(void);
         
         roll_dice should generate two random numbers, each between 1 and 6, 
         and then return the sum. The play_game function should play a game of 
         craps (i.e., call roll_dice to determine the outcome of each roll of 
         the dice). The function should return true if the player wins, false 
         if the player loses. The play_game function should also be responsible 
         for displaying messages showing the outcomes of the various rolls. The 
         main program should repeatedly call the play_game function, keeping 
         track of the number of wins and losses. It should also display the 
         messages "you win" and "you lose."
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int roll_dice(void);
bool play_game(void);

int main(void) {
    char yes_no;
    bool game;
    int wins = 0, losses = 0;

    srand((unsigned) time(NULL));

    printf("\n");

    for (;;) {
        game = play_game();
        
        if (game) {
            printf("\nYou win!\n\n");
            wins++;
        } else {
            printf("\nYou lose!\n\n");
            losses++;
        }

        printf("Play again? ");
        scanf(" %c", &yes_no);

        while (getchar() != '\n')
            ;
        
        printf("\n");

        if (yes_no != 'y' && yes_no != 'Y')
            break;
    }

    printf("Wins: %d Losses: %d\n\n", wins, losses);

    return 0;
}

int roll_dice(void) {
    return rand() % 6 + 1;
}

bool play_game(void) {
    int dice1, dice2, result, point;

    dice1 = roll_dice();
    dice2 = roll_dice();

    result = dice1 + dice2;

    printf("You rolled: %d", result);

    if (result == 7 || result == 11) 
        return true;
    else if (result == 2 || result == 3 || result == 12) 
        return false;
    else {
        printf("\nYour point is %d", result);

        while (getchar() != '\n')
            ;

        point = result;

        for (;;) {
            dice1 = roll_dice();
            dice2 = roll_dice();

            result = dice1 + dice2;

            printf("You rolled: %d", result);

            if (result == point) return true;
            
            if (result == 7) return false;

            while (getchar() != '\n')
                ;
        }
    }
}