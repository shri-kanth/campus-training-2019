// Outputs number of coins required while dispensing change

// Author : Koraveni Srikanth
// 24 January 2018
// Week : 1, Problem : 3

#include <stdio.h>
#include <math.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 50

// Helper functions
float get_float(const char *message);
int is_float_array(const char *array);

int main(void)
{
    int coins[4] = {25,10,5,1};
    int size = sizeof(coins)/sizeof(coins[0]);
    int required_coins = 0;
    float change;

    // Prompt user to enter change owned
    do
    {
        change = get_float("Change owed: ");
    } while(change < 0);

    // Round the input
    int amount = change*100;

    // Compute required coins
    for (int i = 0; i < size; ++i)
    {
        while (amount >= coins[i])
        {
            amount -= coins[i];
            required_coins++;
        }
    }

    printf("%d\n",required_coins);

    return 0;
}

// Returns a valid float value entered through stdin
float get_float(const char* message)
{
    char input[MAX_INPUT_LENGTH];
    float value;
    do
    {
        printf("%s",message);
        scanf("%s",input);
    }while(!is_float_array(input));
    sscanf(input, "%f", &value);
    return value;
}

// Returns if given char array conatins valid float
// Returns false for empty array
int is_float_array(const char *array)
{
    // Empty array
    if(*array == '\0')
    {
        return 0;
    }
    while (*array)
    {
        if (*array == '.')
        {
            *array++;
        }
        if (isdigit(*array++) == 0)
        {
            return 0;
        }
    }
    return 1;
}
