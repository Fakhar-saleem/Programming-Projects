#include<stdio.h>
#include<cs50.h>

int main(void)
{
    int start = 0;
    int end = 0;
    do
    {
        start = get_int("Start: ");
    }
    while (start < 9);

    do
    {
        end = get_int("End: ");
    }
    while (end < start);

    int years = 0;

    if (start < end)
    {
        do
        {
            start = start + (start / 3) - (start / 4);
            //start+=start/12;
            years++;
        }
        while (start < end);

        printf("Years: %i\n", years);
    }
    else
    {
        printf("Years: 0\n");
    }
}