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
int NumOfSets(int numIn);
char UserInputCheck(void);

int main(void)
{
    bool conditionCheck;
    int userInput;

    srand(time(NULL));

    conditionCheck = true;
    userInput = 0;
    do
    {
        userInput = (char)UserInputCheck();

        if (userInput == 113 || userInput == 81)
        {
            printf("* Your Input: %c                                                                  *\n", userInput);
            printf("* You have chosen to exit the application.                                       *\n");
            break;
        }
        else
        {
            userInput = NumOfSets(userInput);
            printf("* Your Input: %d\n", userInput);

            for (int i = 1; i <= userInput; i++)
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
Function to check if the user entered a number greater than zero
for the number of sets
*/
int NumOfSets(int numIn)
{

    if (numIn <= 0)
    {
        while (numIn <= 0)
        {
            printf("       ******* Please Enter a number greater than zero *******         \n");
            printf("* Enter in the number of randomly generated sets of numbers you want:  \n");
            scanf(" %d", &numIn);
        } // End of loop

    } // End of condition

    return numIn;

} // End of NumOfSets function

/*
 *Function to check if the user want to continue or quit
 */
char UserInputCheck(void)
{
    char userInput;

    printf("**********************************************************************************\n");
    printf("* Enter in the number of randomly generated sets of numbers you want or          *\n");
    printf("* enter in a \'q\' or \'Q\' to quit:                                                 *\n");
    scanf(" %c", &userInput);
    printf("**********************************************************************************\n");

    return userInput;
} // End of UserInputCheck function