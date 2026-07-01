/*
 * Name: ex-03.c
 * Author: Edoardo Paggi
 * Task: remove the num_in_rank, num_in_suit, and card_exists vectors from the 
         poker.c program. Instead, have the program store the cards in a 5 x 2 vector. Each row in the vector should represent a card. For example, if the vector is named hand, then hand[0][0] will contain the rank of the top card, while hand[0][1] will contain the suit of the top card.
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS 5

int hand[NUM_CARDS][2];
bool straight, flush, four, three;
int pairs;

void read_cards(void);
void analyze_hand(void);
void print_result(void);

int main(void) {
    for (;;) {
        read_cards();
        analyze_hand();
        print_result();
    }
}

void read_cards(void) {
    bool bad_card;
    char ch, rank_ch, suit_ch;
    int rank, suit;
    int cards_read = 0;
    int index = 0;
    
    while (cards_read < NUM_CARDS) {
        read_card:
            bad_card = false;

            printf("Enter a card: ");

            rank_ch = getchar();
            switch (rank_ch) {
                case '0':           exit(EXIT_SUCCESS);          
                case '2':           rank = 0;  break;
                case '3':           rank = 1;  break;
                case '4':           rank = 2;  break;
                case '5':           rank = 3;  break;
                case '6':           rank = 4;  break;
                case '7':           rank = 5;  break;
                case '8':           rank = 6;  break;
                case '9':           rank = 7;  break;
                case 't': case 'T': rank = 8;  break;
                case 'j': case 'J': rank = 9;  break;
                case 'q': case 'Q': rank = 10; break;
                case 'k': case 'K': rank = 11; break;
                case 'a': case 'A': rank = 12; break;
                default:            bad_card = true;
            }

            suit_ch = getchar();
            switch (suit_ch) {
                case 'c': case 'C': suit = 0; break;
                case 'd': case 'D': suit = 1; break;
                case 'h': case 'H': suit = 2; break;
                case 's': case 'S': suit = 3; break;
                default:            bad_card = true;
            }
            
            while ((ch = getchar()) != '\n')
                if (ch != ' ') bad_card = true;

            if (bad_card) {
                printf("Bad card; ignored.\n");
                continue;
            }

            /* check duplicate cards */
            for (int i = 0; i < NUM_CARDS; i++) 
                if (hand[i][0] == rank && hand[i][1] == suit) {
                    printf("Duplicate card; ignored.\n");
                    goto read_card;
                }
            
            hand[index][0] = rank;
            hand[index][1] = suit;
            index++;
            cards_read++;
        }
}

void analyze_hand(void) {
    int value;
    int rank[NUM_RANKS] = {0};
    straight = true;
    flush = true;
    four = false;
    three = false;
    pairs = 0;

    /* check if it's a flush */
    for (int i = 1; i < NUM_CARDS; i++)
        if (hand[i - 1][1] != hand[i][1]) {
            flush = false;
            break;
        }

    /* check if it's a straight */ 
    for (int i = 0; i < NUM_CARDS - 1; i++) {
        for (int j = 0; j < NUM_CARDS - 1 - i; j++) {
            if (hand[j + 1][0] < hand[j][0]) {
                int temp = hand[j + 1][0];
                hand[j + 1][0] = hand[j][0];
                hand[j][0] = temp;
            }
        }
    }
    for (int i = 1; i < NUM_CARDS; i++) 
        if (hand[i - 1][0] != hand[i][0] - 1) {
            straight = false;
            break;
        }

    /* checks for poker, three of a kind and pairs */
    for (int i = 0; i < NUM_CARDS; i++) {
        value = hand[i][0];
        rank[value]++;
    }
    for (int i = 0; i < NUM_RANKS; i++) {
        if (rank[i] == 4) four = true;
        if (rank[i] == 3) three = true;
        if (rank[i] == 2) pairs++;
    }
}

void print_result(void) {
    if (straight && flush)        printf("Straight flush");
    else if (four)                printf("Four of a kind");
    else if (three && pairs == 1) printf("Full house");
    else if (flush)               printf("Flush");
    else if (straight)            printf("Straight");
    else if (three)               printf("Three of a kind");
    else if (pairs == 2)          printf("Two pairs");
    else if (pairs == 1)          printf("Pair");
    else                          printf("High card");

    printf("\n\n");
}