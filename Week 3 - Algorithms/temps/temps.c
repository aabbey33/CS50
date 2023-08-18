// Practice working with structs
// Practice applying sorting algorithms

#include <cs50.h>
#include <stdio.h>

#define NUM_CITIES 10

typedef struct
{
    string city;
    int temp;
}
avg_temp;

avg_temp temps[NUM_CITIES];

void sort_cities(void);

int main(void)
{
    temps[0].city = "Austin";
    temps[0].temp = 97;

    temps[1].city = "Boston";
    temps[1].temp = 82;

    temps[2].city = "Chicago";
    temps[2].temp = 85;

    temps[3].city = "Denver";
    temps[3].temp = 90;

    temps[4].city = "Las Vegas";
    temps[4].temp = 105;

    temps[5].city = "Los Angeles";
    temps[5].temp = 82;

    temps[6].city = "Miami";
    temps[6].temp = 97;

    temps[7].city = "New York";
    temps[7].temp = 85;

    temps[8].city = "Phoenix";
    temps[8].temp = 107;

    temps[9].city = "San Francisco";
    temps[9].temp = 66;

    sort_cities();

    printf("\nAverage July Temperatures by City\n\n");

    for (int i = 0; i < NUM_CITIES; i++)
    {
        printf("%s: %i\n", temps[i].city, temps[i].temp);
    }
}

// TODO: Sort cities by temperature in descending order
void sort_cities(void)
{
    /*
    Bubble Sort cities
    
    set swap count to non-zero value
    Repeat until swap counter is zero
        reset swap counter to 0
        Look at each adjacent pair
            if two adjacent cities are not in order, then swap them and iterate up the swap count.


    */

    int swapcount = 1; // initializing as a non-zero value and then will reset on cycle.
    avg_temp holding_city; // re-purposing the pre-existing struct to hold some temporary data.

    do
    {
        swapcount = 0; // Reset swap count for the current
        for (int i = 0; i < NUM_CITIES - 1;  i++)
        {
            if (temps[i].temp < temps[i + 1].temp)
            {      
                holding_city = temps[i]; // Store current city
                temps[i] = temps[i + 1]; // Replace with next city
                temps[i + 1] = holding_city; // Replace next city with stored city
                swapcount++; // Increment swap count
            }
        }
    }
    while (swapcount > 0); // Repeat until no swaps are performed
}
