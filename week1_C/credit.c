#include <stdio.h>

int main(void)
{
    //input
    long long num;
    printf("Number: ");
    scanf("%lld", &num);
    //printf("%lld", num);
    long long tmp = num;
    long long sum = 0;
    while (tmp > 0)
    {
        long long mod = tmp % 100;
        long long t = mod;
        tmp /= 100;
        mod = mod / 10;
        mod *= 2;
        while (mod > 0)
        {
            sum += mod % 10;
            mod /= 10;
        }
        sum += t % 10;
    }

    int digit = 0;
    long long tmp2 = num;
    while (tmp2 > 0)
    {
        digit++;
        tmp2 /= 10;
    }
    //printf("%d", digit);

    if (sum % 10 != 0)
        printf("INVALID\n");
    else
    {
        if (digit == 15)
        {
            if (num / 10000000000000 == 34 || num / 10000000000000 == 37)
                printf("AMEX\n");
            else
                printf("INVALID\n");
        }
        else if (digit == 13)
        {
            if (num / 1000000000000 == 4)
                printf("VISA\n");
            else
                printf("INVALID\n");
        }
        else if (digit == 16)
        {
            if (num / 100000000000000 >= 51 && num / 100000000000000 <= 55)
                printf("MASTERCARD\n");
            else if (num / 1000000000000000 == 4)
                printf("VISA\n");
            else
                printf("INVALID\n");
        }
        else
            printf("INVALID\n");
    }
}
