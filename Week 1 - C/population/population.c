#include <cs50.h>
#include <stdio.h>

int start_size(void);
int end_size(int n);
int calc(int start, int end);
void print_years(int n);

int main(void)
{
    // TODO: Prompt for start size
    int i = start_size();

    // TODO: Prompt for end size
    int j = end_size(i);

    // TODO: Calculate number of years until we reach threshold
    int k = calc(i, j);

    // TODO: Print number of years
    print_years(k);
}

int start_size(void)
{
    // prompt for starting population count
    // if population count is less than 9, prompt again
    int n;
    do
    {
        n = get_int("Start size: : ");
    }
    while (n < 9);

    return n;
}

int end_size(int n)
{
    // prompt for ending population count

    int y;
    do
    {
        y = get_int("End size: ");
    }
    while (y < n); // if the population size is less than the starting size, prompt again

    return y;
}

int calc(int start, int end)
{
    // calculate the number of years required to reach the desired ending population count

    int current_llama = start;
    int year_count = 0;

    for (int years = 0; current_llama < end; years++)
    {
        // ex. 1200 llama's results in 400 llama's born
        int llama_birth = current_llama / 3;
        // ex. 1200 llama's results in 300 dead llama's. sad.
        int llama_death = current_llama / 4;
        // adding the born llama's, then subtracting the dead.

        current_llama = ((current_llama + llama_birth) - llama_death);

        year_count++;
    }

    return year_count;
}

void print_years(int n)
{
    // print the years calcualted
    printf("Years: %i\n", n);
}