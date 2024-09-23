#include <cs50.h>
#include <stdbool.h>
#include <stdio.h>

int checksum(long);
int multiply_digit(int);
int length(long);
int amex(long);
int visa(int, long);
int mastercard(long);
int card(int, long);

int main(void)
{
    long number = get_long("Credit Card Number : ");
    int sum_checksum = checksum(number);
    // printf("%d\n", sum_checksum);
    if (sum_checksum % 10 == 0)
    {
        int len = length(number);
        card(len, number);
    }
    else
    {
        printf("INVALID\n");
    }
}

int checksum(long number)
{
    int sum_alternate_digit = 0;
    int sum_remaining_digit = 0;
    bool alternate_digit = false;
    while (number > 0)
    {
        int last_digit = number % 10;
        if (alternate_digit == true)
        {
            int lastdigit = multiply_digit(last_digit);
            sum_alternate_digit += lastdigit;
        }
        else if (alternate_digit == false)
        {
            sum_remaining_digit += last_digit;
        }
        alternate_digit = !alternate_digit;
        number = number / 10;
    }
    int sum = sum_alternate_digit + sum_remaining_digit;
    return sum;
}

int multiply_digit(int last_digit)
{
    int multiply = last_digit * 2;
    int sum = 0;
    while (multiply > 0)
    {
        int multiply_digit = multiply % 10;
        sum += multiply_digit;
        multiply = multiply / 10;
    }
    return sum;
}

int length(long number)
{
    int temp = 0;
    while (number > 0)
    {
        temp++;
        number = number / 10;
    }
    return temp;
}

int amex(long number)
{
    int first_two = number / 10000000000000;
    return first_two;
}

int mastercard(long number)
{
    int first_two = number / 100000000000000;
    return first_two;
}

int visa(int len, long number)
{
    int first_one = 0;
    if (len == 13)
    {
        first_one = number / 1000000000000;
    }
    else if (len == 16)
    {
        first_one = number / 1000000000000000;
    }
    else
    {
        printf("INVALID\n");
        return 1;
    }
    return first_one;
}

int card(int len, long number)
{
    if (len == 15)
    {
        int first_two = amex(number);
        if (first_two == 34 || first_two == 37)
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
            return 1;
        }
    }
    else if (len == 13)
    {
        int first_one = visa(len, number);
        if (first_one == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
            return 1;
        }
    }
    else if (len == 16)
    {
        int first_one = visa(len, number);
        int last_two = mastercard(number);
        if (last_two == 51 || last_two == 52 || last_two == 53 || last_two == 54 || last_two == 55)
        {
            printf("MASTERCARD\n");
        }
        else if (first_one == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
            return 1;
        }
    }
    else
    {
        printf("INVALID\n");
        return 1;
    }
    return number;
}
