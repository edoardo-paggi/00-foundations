/*
 * Name: ex-03.c
 * Author: Edoardo Paggi
 * Task: books are identified by a number called the International Standard
         Book Number (ISBN). ISBN numbers assigned after January 1, 2007,
         contain 13 digits divided into five groups, such as 978-0-393-97950-3(older ISBNs used 10 digits). The first group of digits (the GS1 prefix) is currently 978 or 979. The next group specifies the language or country of origin (for example, 0 and 1 are used in English-speaking countries). The publisher code identifies the publisher (393 is the code for W.W. Norton). The item number is assigned by the publisher to identify a specific book (97950 is the code for the original version of this book). An ISBN ends with a check digit that is used to verify the correctness of the preceding digits. Write a program that divides the ISBN code entered by the user into groups:

         Enter ISBN: 978-0-393-97950-3
         GS1 prefix: 978
         Group identifier: 0
         Publisher code: 393
         Item number: 97950
         Check digit: 3

         Note: the number of digits in each group may vary. You cannot assume that the groups always have the same length as shown in this example. Test your program with real ISBNs.
 */

#include <stdio.h>

int main(void) {
    int gs1, id, publisher, itemNumber, checkDigit;

    printf("Enter ISBN: ");
    scanf("%d-%d-%d-%d-%d", &gs1, &id, &publisher, &itemNumber, &checkDigit);

    printf("GS1 prefix: %d\n", gs1);
    printf("Group identifier: %d\n", id);
    printf("Publisher code: %d\n", publisher);

    /* With the knowledge acquired at this point in the book it is not possible to solve the zero problem in front of an int: 00178 => 178 */
    printf("Item number: %d\n", itemNumber);
    printf("Check digit: %d\n", checkDigit);

    return 0;
}