#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");

    float te = count_letters(text);
    float wo = count_words(text);
    float se = count_sentences(text);

    float L = (te/w00;
    float S = (se/wo)*100;

    float index_1 = 0.0588 * L - 0.296 * S - 15.8;
    int index = (int)round(index_1);

    if (index >= 1 && index < 16)
    {
        printf("Grade %d\n",index);
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade 16+\n");
    }

}

int count_letters(string text)
{
    int letters = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if ((text[i] >= 'A' && text[i] <= 'Z') || (text[i] >= 'a' && text[i] <= 'z'))
        {
            letters++;
        }
    }
    return letters;
}

int count_words(string text)
{
    int words = 1;
    for (int i = 0; i < strlen(text); i++)
    {
        if(text[i] == 32)
        {
            words++;
        }
    }
    return words;
}

int count_sentences(string text)
{
    int sentences = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if(text[i] == 46 || text[i] == 33 || text[i] == 63)
        {
            sentences++;
        }
    }

    return sentences;
}