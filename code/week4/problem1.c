#include <stdio.h>

void change(float dollar, int *quarters, int *dimes, int *nickels, int *pennies)
{
    int coin = dollar * 100;
    *quarters = coin / 25;
    *dimes = coin % 25 / 10;
    *nickels = coin % 25 % 10 / 5;
    *pennies = coin % 25 % 10 % 5;
}

int main()
{
    float dollar;
    int quarters, dimes, nickels, pennies;
    printf("Enter your dollar :");
    scanf("%f", &dollar);
    printf("\n");
    change(dollar, &quarters, &dimes, &nickels, &pennies);
    printf("quarters : %d\ndimes : %d\nnickels : %d\npennies : %d", quarters, dimes, nickels, pennies);

    return 0;
}