#include <cs50.h>
#include <stdio.h>

bool prime(int number);

int main(void)
{
    int min;
    do
    {
        min = get_int("Minimum: ");
    }
    while (min < 1);

    int max;
    do
    {
        max = get_int("Maximum: ");
    }
    while (min >= max);

    for (int i = min; i <= max; i++)
    {
        if (prime(i))
        {
            printf("%i\n", i);
        }
    }
}

bool prime(int number)
{
  int counter = 0;
  if (number != 1)
  {
   for (int i = 2; i <= number - 1; i++)
    {
    if (number % i == 0)
      {
        counter++;
      }
    }
  }

  else
  {
    counter++;
  }

  if (counter > 0)
  {
    return false;
  }

  else
  {
    return true;
  }
}
