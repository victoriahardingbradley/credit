// Credit by Victoria harding Bradley
//October 16, 2022
//cs1

#include <cs50.h>
# include <stdio.h>
# include <math.h>

int main(void)
{
    long long creditnum = 0;
    //getting the creditcard number
    creditnum = get_long_long("What is your creditcard number? \n");
    long long digits = creditnum;
    int sum = 0;
    while (digits > 0)
    {
        digits = digits / 10;
        sum = sum + 1;
    }
    if (sum >= 13 && sum <= 16)
    {

        //while there's  still a number to work with:
        int step1;
        int sumofcard = 0;
        long long original = creditnum;
        int seconddigit;
        while (creditnum > 0)
        {
            //multiplying the final digit
            step1 = creditnum % 10;
            sumofcard = sumofcard + step1;
            creditnum = creditnum / 10;
            step1 = creditnum % 10;
            step1 = step1 * 2;
            //seeing if I need to add the digits together
            if(step1 > 9)
            {
                seconddigit = step1 % 10;
                step1 = seconddigit + step1 / 10;
            }
            //removing that digit
            sumofcard = sumofcard + step1;
            creditnum = creditnum / 10;
        }
        while (original >= 100)
        {
            original = original / 10;
        }
        if (sumofcard % 10 == 0)
            if (sum == 15 && (original == 34 || original == 37))
            {
                printf("AMEX\n");
            }
            else if (sum == 16 && (original >= 51 && original <= 55))
            {
                printf("MASTERCARD\n");
            }
            else if ((sum == 13 || sum == 16) && original / 10 == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
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