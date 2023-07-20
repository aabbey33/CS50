#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

string substitute(string key, string input);

/*
Intended usage:
$ ./substitution YTNSHKVEFXRBAUQZCLWDMIPGJO
plaintext: HELLO
ciphertext: EHBBQ

*/

int main(int argc, string argv[])
{

    // prevent core dump by too few arguments and make sure only a key is supplied
    if (argc > 2 || argc < 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // ensure the key is 26 characters long
    if (strlen(argv[1]) != 26)
    {
        printf("key must contain 26 characters.\n");
    }

    // This section checks to verify that there are no numbers in the key and characters only appear once
    int letters[26] = {0}; // create an empty array and initialize as zero
    string key = argv[1];
    for (int i = 0; i < 26; i++)
    {
        int temp = (int) toupper(key[i]) - 'A'; // convert letter to uppercase and then subtract A's position

        if (temp < 0 || temp > 25)
        {
            printf("The key cannot contain any numbers.\n"); // Check to verify that the its not a number.
            return 1;
        }

        letters[temp]++; // increment the character to a non-zero number
    }

    for (int i = 0; i < 26; i++)
    {
        if (letters[i] > 1) // verify that there are no longer any characters remaining as zero
        {
            printf("A letter can only occur once in the key!\n");
            return 1;
        }
    }

    // This section handles the plaintext input
    string input = "";
    do
    {
        input = get_string("Plaintext: ");
    }
    while (strlen(input) < 1); // make sure there is at least a single character entered

    string ciphertext = substitute(argv[1], input); // call the substitute function

    printf("ciphertext: %s\n", ciphertext);
    return 0;
}

string substitute(string key, string input)
{
    int n = strlen(input); // get the length of the input string
    for (int i = 0; i < n; i++)
    {
        if (isalpha(input[i])) // verify the character is part of the alphabet
        {
            if (isupper(input[i])) // if the character is uppercase...
            {
                int toreplace = (int) input[i] - 'A'; // use capital A as a reference point

                input[i] = toupper(key[toreplace]); // use the location of our character in our key for replacement
            }
            else // otherwise...
            {
                int toreplace = (int) input[i] - 'a'; // use lower a as a reference point

                input[i] = tolower(key[toreplace]); // use the location of our character in our key for replacement
            }
        }
    }

    return input;
}