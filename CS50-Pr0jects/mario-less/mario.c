#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int size = 0;

    do
    {
        size = get_int("Size of Pyramid: ");
    }
    while (size <= 0 || size > 8);

    int x = 1;
    int temp = size + 1;

    for (int i = 1; i <= size; i++)
    {

        temp--;
        while (x < temp)
        {
            printf(" ");
            x++;
        }
        x = 1;

        for (int z = 1; z <= i; z++)
        {

            printf("#");

        }

        printf("\n");

    }
}