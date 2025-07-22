// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <string.h>
#include <cs50.h>
#include <stdio.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    int first=0;
    int sec=0;
    int third=0;
    int forth=0;
    int fifth=0;

    for(int i=0;i<strlen(password);i++)
    {
        for(int j=48;j<=57;j++)
        {
            if(password[i]==j)
            {
                first++;
            }
        }

        for(int z=33;z<=47;z++)
        {
            if(password[i]==z)
            {
                sec++;
            }
        }

        for(int k=58;k<=64;k++)
        {
            if(password[i]==k)
            {
                third++;
            }
        }

        for(int l=65;l<=90;l++)
        {
            if(password[i]==l)
            {
                forth++;
            }
        }

        for(int b=97;b<=122;b++)
        {
            if(password[i]==b)
            {
                fifth++;
            }
        }

    }

    if(first>0 && (sec>0 || third>0) && forth>0 && fifth>0)
    {
        return true;
    }
    else
    {
        return false;
    }

}
