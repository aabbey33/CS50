#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int BLOCK_SIZE = 512;

int main(int argc, char *argv[])
{
    // Ensure only one file has been provided
    if (argc > 2)
    {
        printf("Please provide only one input file!\n");
        return 1;
    }

    // Ensure a file has been provided
    if (argc < 2)
    {
        printf("Please provide a file!\n");
        return 1;
    }

    // Check whether the input file is in RAW
    char *extension = strrchr(argv[1], '.');
    if (extension == NULL || strcmp(extension, ".raw") != 0)
    {
        printf("Please provide a file in .raw format!\n");
        return 3;
    }

    char *infile = argv[1];

    FILE *inptr = fopen(infile, "r"); // Open the input file
    if (inptr == NULL)
    {
        printf("Could not open %s \n", infile);
        return 4;
        ;
    }

    int filecounter = 0; // Lets set an incremental counter to 0 so we can do 000.jpg

    char *buffer = malloc(BLOCK_SIZE); // Allocate memory for the buffer stream
    if (buffer == NULL)
    {
        printf("Buffer: Out of Memory!\n");
        return 5;
    }

    char *namebuffer = malloc(8 * sizeof(char)); // Allocate 8 bytes for the filename
    if (namebuffer == NULL)
    {
        printf("NameBuffer: Out of memory!\n");
        return 5;
    }
    // had to look up string formatting for the name.
    // "%03d" good to know, 0 sets a padding of 0, 3 sets the width.

    FILE *outfile = NULL; // Let's initialize an empty file pointer for now since I'm going to have to reference it soon but wont
                          // have a file ready

    while (fread(buffer, 1, BLOCK_SIZE, inptr) == BLOCK_SIZE)
    {
        if ((unsigned char) buffer[0] == 0xff && (unsigned char) buffer[1] == 0xd8 && (unsigned char) buffer[2] == 0xff &&
            ((unsigned char) buffer[3] & 0xf0) == 0xe0) // check the headers to verify if this is a jpg
        {
            sprintf(namebuffer, "%03d.jpg", filecounter); // This should initialize namebuffer as 0##.jpg.

            if (outfile != NULL) // I'll need to close any previous files before I write a new one, so let's check if it's not NULL.
            {
                fclose(outfile);
            }

            outfile = fopen(namebuffer, "w"); // Open a writeable output file.
            if (outfile == NULL)
            {
                printf("Cannot Open File: %s\n", namebuffer);
                return 6;
            }

            fwrite(buffer, BLOCK_SIZE, 1, outfile); // Let's write to it.

            // Assuming it's currently 0, the next time this whole section runs will be for 001.jpg.
            filecounter++;
        }
        else
        {
            // If headers were detected, then this will be any runs after a file is beginning to be written.
            if (outfile != NULL)
            {
                fwrite(buffer, BLOCK_SIZE, 1, outfile);
            }
        }
    }

    // Time to free up memory
    fclose(inptr);       // close the input file
    if (outfile != NULL) // Not every circumstance will have an outfile. Let's close it if it exists.
    {
        fclose(outfile);
    }

    free(buffer);     // empty the buffer
    free(namebuffer); // empty my namebuffer

    return 0;
}