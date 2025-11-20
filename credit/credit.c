#include <cs50.h>
#include <stdio.h>

// AMEX: 15-Digit #'s, Star with: 34 or 37
// MASTERCARD: 16-Digit #'s, Start with: 51, 52, 53, 54, or 55
// VISA: 13-16-Digit #'s, Start with: 4

// Luhn's Algorithm:
// 1. Multiply every other digit by 2, starting with the second number to the last
// 2. Add the sum of those digits
// 3. Add the sum of the other digits
// 4. If the total sum ends with a 0, it is valid!

int sum_multiplied(long n);
int other_sum(long n);
int length(long n);
int start(long n);

int main(void)
{

    long cc = get_long("Enter credit card number: ");

    // check if the last digit in that sum is a 0.
    int sum = sum_multiplied(cc) + other_sum(cc);
    if (sum % 10 == 0)
    {
        if (length(cc) == 15 && (start(cc) == 34 || start(cc) == 37))
        {
            printf("AMEX\n");
        }
        else if (length(cc) == 16 && (start(cc) == 51 || start(cc) == 52 || start(cc) == 53 ||
                                      start(cc) == 54 || start(cc) == 55))
        {
            printf("MASTERCARD\n");
        }
        else if (length(cc) == 13 && (start(cc) / 10) == 4)
        {
            printf("VISA\n");
        }
        else if (length(cc) == 16 && (start(cc) / 10) == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

// adding and multipying other digit by 2, starting with the second number to the last
int sum_multiplied(long n)
{
    n /= 10;
    int sum = 0;

    while (n > 0)
    {
        int digit = (n % 10) * 2;
        if (digit > 9)
        {
            sum += digit / 10 + digit % 10;
        }
        else
        {
            sum += digit;
        }
        n /= 100;
    }
    return sum;
}

// adding the other digits
int other_sum(long n)
{
    int sum = 0;
    int last = n % 10;
    sum += last;
    n = n / 100;

    while (n > 0)
    {
        int digit = n % 10;
        sum += digit;
        n = n / 100;
    }
    return sum;
}

// check length
int length(long n)
{
    int count = 0;
    while (n != 0)
    {
        n /= 10;
        count++;
    }
    return count;
}

// check start digits
int start(long n)
{
    while (n >= 100)
    {
        n /= 10;
    }
    return (int) n;
}
