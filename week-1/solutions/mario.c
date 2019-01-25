// Outputs mario wall given valid input

// Author : Koraveni Srikanth
// 24 January 2018
// Week : 1, Problem : 1

#include <stdio.h>
#include <math.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 50
#define MAX_HEIGHT 8
#define MIN_HEIGHT 1

// Helper functions
int get_int(const char *message);
int is_digit_array(const char *array);

int main(void)
{
    int height;

    // Prompt user to enter height
    do
    {
        height = get_int("Height: ");
    } while(MIN_HEIGHT > height || height > MAX_HEIGHT);

    char wall[height][2*height+2];

    // Constructing the wall
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < height; ++j)
        {
            if (height-1-j > i)
            {
                wall[i][j] = ' ';
            }
            else
            {
                wall[i][j] = '#';
            }
        }

        wall[i][height] = ' ';

        for (int j = height+1; j < 2*height+1; ++j)
        {
            if (j-(height+1) > i)
            {
                wall[i][j] = ' ';
            }
            else
            {
                wall[i][j] = '#';
            }
        }

        wall[i][2*height+1] = '\0';

        // Output single wall layer
        printf("%s\n",wall[i]);
    }
    return 0;
}

// Returns a valid int value entered through stdin
int get_int(const char *message)
{
    char input[MAX_INPUT_LENGTH];
    int value;
    do
    {
        printf("%s",message);
        scanf("%s",input);
    }while (!is_digit_array(input));
    sscanf(input, "%d", &value);
    return value;
}

// Returns if given char array conatins digits exclusively
// Returns false for empty array
int is_digit_array(const char *array)
{
    // Empty array
    if (*array == '\0')
    {
        return 0;
    }
    while (*array)
    {
        if (isdigit(*array++) == 0)
        {
            return 0;
        }
    }
    return 1;
}
