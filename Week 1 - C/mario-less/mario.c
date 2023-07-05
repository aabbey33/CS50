#include <cs50.h>
#include <stdio.h>

void construct_blocks(int height);

int main(void)
{

    int height = 0; // Establish the height variable externally from my do statement.
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);
    construct_blocks(height);
}

void construct_blocks(int height)
{
    for (int k = 0; k < height; k++) // walk each row
    {
        int hashcount = k + 1; // how many hashes this row?

        for (int l = 0; l < height; l++) // walk each character in the row
        {
            if (l < (height - hashcount))
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        printf("\n");
    }
}