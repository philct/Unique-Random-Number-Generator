#include <stdio.h>

int main(void)
{
    int input = 0;
    int n, a, b;
    scanf("%c", &input);

    printf("%d == %c\n", input, input);

    if (input == 113 || input == 81)
    {
        printf(" I was told to quit! \n");
    }
    else
    {
        //     input = (int)input - 48;
        //     for (size_t i = 0; i < input; i++)
        //     {
        //         printf("I was told to keep going %d\n", i);
        //     }
    }

    // a = input;
    // n = input / 48;
    // b = (input % 48) + (n * 48);

    // printf(" %d***%d********\n", b, a);

    return 0;
}