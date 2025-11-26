/*
 Program Name: Generate random numbers in set of six
 Description: Program to generate random numbers in sets
 Author: Philimon Tegegn (N01513784)
 Date: 02/25/2025
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define MAX_VAL 53
#define MIN_VAL 1

// function prototype
int RandomizeNum(void);
void SetRandVal(void);
int NumOfSets(void);

int main(void)
{
    bool conditionCheck;
    int numIn;
    char letterIn;

    srand(time(NULL));

    conditionCheck = true;
    numIn = 0;
    do
    {
        printf("**********************************************************************************\n");
        printf("* Enter in the number of randomly generated sets of numbers you want: \n");
        numIn = NumOfSets();

        printf("* Enter in a \'q\' or \'Q\' to quit or any other letter or character to continue: \n");
        scanf(" %c", &letterIn);
        printf("**********************************************************************************\n");

        if (letterIn == 'q' || letterIn == 'Q')
        {
            printf("* Your Input: %c\n", letterIn);
            printf("You have chosen to exit the application.\n");
            break;
        }
        else
        {
            printf("* Your Input: %d\n", numIn);
            for (int i = 1; i <= numIn; i++)
            {
                printf("Set # %3d of six numbers is: ", i);
                SetRandVal();
            }
        }

    } while (conditionCheck); // End of Loop

    return 0;
}

/*
function that generates random numbers between
Max and Min Values
*/
int RandomizeNum(void)
{
    return rand() % (MAX_VAL - MIN_VAL + 1) + MIN_VAL;
} // End of RandomizeNum function

/*
function to generate the six random numbers between
Max and Min Values for one set
*/
void SetRandVal(void)
{
    int numOne, numTwo, numThree, numFour, numFive, numSix;

    numOne = RandomizeNum();

    do
    {
        numTwo = RandomizeNum();
    } while (numTwo == numOne); // End of loop

    do
    {
        numThree = RandomizeNum();
    } while (numThree == numTwo || numThree == numOne); // End of loop

    do
    {
        numFour = RandomizeNum();
    } while (numFour == numThree || numFour == numTwo || numFour == numOne); // End of Loop

    do
    {
        numFive = RandomizeNum();
    } while (numFive == numFour || numFive == numThree || numFive == numTwo || numFive == numOne); // End of Loop

    do
    {
        numSix = RandomizeNum();
    } while (numSix == numFive || numSix == numFour || numSix == numThree || numSix == numTwo || numSix == numOne); // End of Loop

    printf("  %2d  %2d  %2d  %2d  %2d  %2d\n", numOne, numTwo, numThree, numFour, numFive, numSix);

    return;
} // End of SetRandVal function

/*
Function to ask the user how many sets
they want
*/
int NumOfSets(void)
{
    int numOne;

    scanf(" %d", &numOne);

    if (numOne <= 0)
    {
        while (numOne <= 0)
        {
            printf("       ******* Please Enter a number greater than zero *******         \n");
            printf("* Enter in the number of randomly generated sets of numbers you want:  \n");
            scanf(" %d", &numOne);
        } // End of loop

    } // End of condition

    return numOne;

} // End of NumOfSets function