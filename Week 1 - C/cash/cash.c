#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);
int abstract_calculate(int cents, int divisor);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}

int get_cents(void)
{
    /*
    Asks user for number of cents using get_int() function,
    re-prompts user for number if negative number.
    */
    int cents = 0;
    do
    {
        cents = get_int("Total Change: ");
    }
    while (cents < 0);

    return cents;
}

int calculate_quarters(int cents)
{
    /*
    Returns the number of quarters the customer is owed by taking
    the input and seeing if its divisible by 25.


    if (cents >= 25)
    {
        printf("Quarters: %i\n", cents / 25);
        return cents / 25;
    }
    else
    {
        return 0;
    }

    Further abstraction developed, this will be used for reference purposes.

    These functions will remain in place due to check50 potentially looking for them.
    */

    return abstract_calculate(cents, 25);
}

int calculate_dimes(int cents)
{
    /*
    Returns the number of dimes the customer is owed by taking
    the input and seeing if its divisible by 10.
    */

    return abstract_calculate(cents, 10);
}

int calculate_nickels(int cents)
{
    /*
    Returns the number of nickels the customer is owed by taking
    the input and seeing if its divisible by 5.
    */

    return abstract_calculate(cents, 5);
}

int calculate_pennies(int cents)
{
    /*
    Returns the number of pennies the customer is owed by taking
    the input and seeing if its divisible by 1.
    */

    return abstract_calculate(cents, 1);
}

int abstract_calculate(int cents, int divisor)
{
    /*
    abstracting the calculation of the number of cents
    so that i dont need to add the exact same logic
    with a single changing variable to every function.

    I may keep the original functions however as
    I am not sure if check50 is looking for them.
    */

    if (cents >= divisor)
    {
        return cents / divisor;
    }
    else
    {
        return 0;
    }
}