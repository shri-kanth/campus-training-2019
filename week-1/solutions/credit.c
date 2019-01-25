// Outputs credit card type for valid input

// Author : Koraveni Srikanth
// 24 January 2019
// Week : 1, Problem : 2

#include <stdio.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 50

// Helper functions
long long get_long(const char *message);
int is_digit_array(const char *array);
int get_digits_sum(int n);
int is_valid(const int check_sum);
char* get_card_type(long long card_number);
int get_first_two_digits(long long card_number);

int main(void)
{
    // Prompt user to enter number
    long long card_number = get_long("Number : ");
    long long card_number_copy = card_number;

    // Compute check sum
    int check_sum = 0;
    while (card_number_copy > 0)
    {
        // Odd place digits from end
        int odd_end_place_digit = card_number_copy%10;
        check_sum += odd_end_place_digit;
        card_number_copy /= 10;

        // Even place digits from end
        int even_end_place_digit = card_number_copy%10;
        check_sum += get_digits_sum((2*even_end_place_digit));
        card_number_copy /= 10;
    }

    if (is_valid(check_sum))
    {
       printf("%s",get_card_type(card_number));
    }
    else
    {
        printf("INVALID\n");
    }
    return 0;
}

// Returns card type from card number
char* get_card_type(long long card_number)
{
    int first_two_digits = get_first_two_digits(card_number);

    if (first_two_digits == 34 || first_two_digits == 37)
    {
        return "AMEX\n";
    }
    else if (40 <= first_two_digits && first_two_digits <= 49)
    {
        return "VISA\n";
    }
    else if (51 <= first_two_digits && first_two_digits <= 55)
    {
        return "MASTERCARD\n";
    }
    else
    {
        return "UNKNOWN\n";
    }
}

// Returns first two digits of a number
int get_first_two_digits(long long card_number)
{
    while (card_number >= 100)
    {
        card_number /= 10;
    }
    return card_number;
}

// Return if given credit card check sum is valid
int is_valid(const int check_sum)
{
    return (check_sum%10 == 0);
}

// Returns sum of digits of a non-negetive integer
int get_digits_sum(int n)
{
    int sum = 0;
    while (n > 0)
    {
        sum += n%10;
        n /= 10;
    }
    return sum;
}

// Returns a valid long long value entered through stdin
long long get_long(const char *message)
{
    char input[MAX_INPUT_LENGTH];
    long long value;
    do
    {
        printf("%s",message);
        scanf("%s",input);
    }while (!is_digit_array(input));
    sscanf(input, "%lld", &value);
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
