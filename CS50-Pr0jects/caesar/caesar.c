#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    // Check if the correct number of command-line arguments is provided
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Check if all characters of the command-line argument are digits
    for (int i = 0; argv[1][i] != '\0'; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    // Convert the command-line argument to an integer
    int key = atoi(argv[1]) % 26;

    // Prompt user for plaintext
    string plaintext = get_string("plaintext: ");

    printf("ciphertext: ");

    // Encrypt the plaintext using Caesar's cipher
    for (int i = 0; plaintext[i] != '\0'; i++)
    {
        if (isalpha(plaintext[i]))
        {
            // Preserve case
            char base = isupper(plaintext[i]) ? 'A' : 'a';
            // Apply Caesar's cipher
            char encrypted_char = (plaintext[i] - base + key) % 26 + base;
            printf("%c", encrypted_char);
        }
        else
        {
            // Non-alphabetical characters remain unchanged
            printf("%c", plaintext[i]);
        }
    }

    printf("\n");

    return 0;
}
