// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

void cleanUp(node *ptr);
void count(node *ptr);

const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int index = hash(word); // get the index ID of the word

    char holder[strlen(word) + 1]; // create a holder for the word

    for (int i = 0; i < strlen(word); i++) // copy the word into the holder
    {
        holder[i] = tolower(word[i]); // convert to lower case
    }
    holder[strlen(word)] = '\0'; // add null terminator

    for (node *ptr = table[index]; ptr != NULL; ptr = ptr->next)
    {
        if (strcmp(holder, ptr->word) == 0)
        {
            return true;
        }
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{

    // TODO: Improve this hash function
    return tolower(word[0]) - 'a';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        printf("Error: could not open dictionary");
        return false;
    }

    int indexBasis = 'a'; // declare the ascii value of 'a'
                          // so we can use it to subtract later
    char string[LENGTH + 1];

    int placement = 0;
    char buffer[1]; // Let's create a buffer to
                    // store the data we're reading

    node *container;

    int index = 0;

    while (fread(&buffer, sizeof(char), 1, dict)) // While there is still data to read
    {
        if (buffer[0] == '\n' || (buffer[0] > 32 && buffer[0] < 65)) // If the buffer is a new line
        {
            if (buffer[0] == '\n')
            {
                string[placement] = '\0';

                if (isalpha(string[0]))
                {
                    index = tolower(string[0]) - 'a';
                }
                else
                {
                    continue;
                }
            }
            else if (buffer[0] > 32 && buffer[0] < 65)
            {
                string[placement] = buffer[0];
                placement++;
                continue;
            }

            // Assign a null terminator to our word
            // subtract the value of the first
            // item in buffer with a to get the
            // key of where we should store
            // the data into our hash table

            container = malloc(sizeof(node)); // allocate memory for the container node
            if (container == NULL)
            {
                printf("Not enough memory to allocate for node!\n");
                return false;
            }

            strcpy(container->word, string);

            if (table[index] != NULL) // If the key is not empty
            {
                container->next = table[index];
                table[index] = container;
            }
            else
            {
                table[index] = container;
                container->next = NULL;
            }
            for (int i = 0; i < strlen(string); i++)
            {
                string[i] = '\0'; // Reset the string array
            }
            placement = 0;
        }
        else
        {
            string[placement] = buffer[0];

            placement++;
        }
    }
    fclose(dict);
    return true;
}

int wordCount = 0;
// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    for (int i = 0; i < N; i++)
    {
        if (table[i] != NULL)
        {
            count(table[i]);
        }
    }
    return wordCount;
}

void count(node *ptr)
{
    if (ptr == NULL)
    {
        return;
    }
    wordCount++;
    count(ptr->next);
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{

    for (int i = 0; i < N; i++)
    {
        if (table[i] != NULL)
        {
            cleanUp(table[i]);
        }
    }

    return true;
    // It's not exactly possible to return false since free will just crash if it tries to free an invalid pointer
}

void cleanUp(node *ptr)
{
    if (ptr == NULL)
    {
        return;
    }

    cleanUp(ptr->next);
    free(ptr);
    ptr = NULL;
}
