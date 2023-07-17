#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{

    string text = get_string("Text: ");
    int lettercount = count_letters(text);
    int wordcount = count_words(text);
    int sentcount = count_sentences(text);

    // coleman liau

    float L = (float) lettercount / (float) wordcount * 100;
    float S = (float) sentcount / (float) wordcount * 100;

    float gradescore = 0.0588 * L - 0.296 * S - 15.8;

    gradescore = round(gradescore); // rounding the float to a whole number

    if ((int) gradescore > 16)
    {
        printf("Grade 16+\n");
    }
    else if ((int) gradescore < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", (int) gradescore);
    }
}

int count_letters(string text)
{
    /*
    Admittedly the easiest loop in the program. simply convert all characters to uppercase so we can define a range, check if the
    character is within the range, and if it is, add it.
    */
    int charcount = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        char convert = toupper(text[i]); // convert to uppercase

        if ((int) convert <= 90 && (int) convert >= 65) // check if the character is within a range
        {
            charcount++;
        }
    }
    return charcount;
}

int count_words(string text)
{
    /*
    We will count spaces until we reach a line break, otherwise we cannot count the final word.
    */

    int wordcount = 0;
    for (int i = 0, n = strlen(text); i <= n; i++)
    {
        int iterval = (int) text[i];

        /*
        Space in Decimal seems to be DLE/32. Need to account for the line break as well so
        I can count the final word as a sentence.
        */
        if (iterval == 32 || text[i] == '\0')
        {
            wordcount++;
        }
    }
    return wordcount;
}

int count_sentences(string text)
{
    /*
    We will count any punctuation in the input text. this should reuslt in our total sentence count.
    */
    int punctcount = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        int iterval = (int) text[i];

        if (iterval == 46 || iterval == 33 || iterval == 63) // check for period, question mark, and exclamation.
        {
            punctcount++;
        }
    }
    return punctcount;
}
