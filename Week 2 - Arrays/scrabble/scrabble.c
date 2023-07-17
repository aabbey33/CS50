#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{

    int score = 0;
    int offset = 65; // (int)'A'

    /*
    You should be able to get the index of POINTS by subtracting the decimal
    value of each character by the offset of the decimal of A (65) since it's
    in linear order from A-Z.
    */

    for (int i = 0, stringlength = strlen(word); i < stringlength; i++) // from 0 to the last character in a word
    {
        char convert = toupper(word[i]);
        if ((int) convert <= 90 && (int) convert >= 65)
        {
            score = score + POINTS[(int) convert - offset];
        }
    }

    return score;
}
