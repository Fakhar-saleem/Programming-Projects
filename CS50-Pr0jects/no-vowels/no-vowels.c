// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

string replace_str(string destination);

int main(int argc, string argv[])
{
    char destination[20];
    if(argc!=2)
    {
        printf("Error");
        return 1;
    }
    else
    {
        strcpy(destination,argv[1]);
        printf("%s\n",replace_str(destination));

    }

}

string replace_str(string destination)
{
    for(int i=0;i<strlen(destination);i++)
    {
       switch(tolower(destination[i]))
       {
        case 'a':
        destination[i]='6';
        break;

        case 'e':
        destination[i]='3';
        break;

        case 'i':
        destination[i]='1';
        break;

        case 'o':
        destination[i]='0';
        break;

        default:
        break;

       }
    }
    return destination;
}