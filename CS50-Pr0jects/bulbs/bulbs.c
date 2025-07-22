#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{

    string message=get_string("MESSAGE: ");

    int n = strlen(message);

    for (int i = 0; i < n; i++)
    {
        unsigned char ch = message[i];

        for (int j = 7; j >= 0; j--)
        {
            int bit = (ch >> j) & 1;
            print_bulb(bit);
        }

        printf("\n");
    }

}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
