// Practice writing a function to find a max value

#include <cs50.h>
#include <stdio.h>

int max(int array[], int n);

int main(void)
{
    int n;
    do
    {
        n = get_int("Number of elements: ");
    } 
    while (n < 1);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = get_int("Element %i: ", i);
    }

    printf("The max value is %i.\n", max(arr, n));
}

// TODO: return the max value
int max(int array[], int n)
{
    int maxvalue = array[0]; 
    /* I would set a non-zero value but since this is a simple conditional loop, 
    I'll just assign the first item in the array to the max value.
    */

    for (int i = 0; i < n; i++)
    {
        if (array[i] > maxvalue) // if the next item in the array is larger than the max value currently
        {
            maxvalue = array[i]; // set the max value to the next item in the array
        }

    }
    return maxvalue;
}
