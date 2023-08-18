#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert(string input);

int number;

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(input));
}

int convert(string input)
{

    /* 177685
    index of last character = 5
    convert thsi character into it's numerical value = 53  - 49 = 4
    remove the last character from the stirng by repalcing the index with '\0' = 17768
    return this value plus t0 times the integer value of the new shortened string 


    start with last character and conver tot an integer value = 53
    shorten the string by repalcing the index with '\0' =
    */

    
    int charIndex = strlen(input);

    if (charIndex == 0)
    {
        return input[charIndex - 1] - (int)'0';
    }

    int current = input[charIndex - 1] - (int)'0';


    input[charIndex - 1] = '\0';

    int lastResult = convert(input);

    return current + 10 * lastResult;

    // TODO
}

/*

    Start by getting the index of the last char in the string (the char before the \0).
    Convert this char into its numeric value. Can you subtract some char to do this?
    Remove the last char from the string by moving the null terminator one position to the left.
    Return this value plus 10 times the integer value of the new shortened string.
    Remember you need a base case when creating a recursive function.


*/