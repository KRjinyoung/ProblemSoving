#include <stdio.h>

void liquid(int totalCups, int *gallons, int *quarts, int *pints, int *cups)
{
    *gallons = totalCups / 16;
    totalCups %= 16;
    *quarts = totalCups / 4;
    totalCups %= 4;
    *pints = totalCups / 2;
    *cups = totalCups % 2;
}

int main()
{
    int totalCups = 100;
    int gallons, quarts, pints, cups;
    liquid(totalCups, &gallons, &quarts, &pints, &cups);
    printf("Gallons : %d , Quarts : %d , Pints : %d , Cups : %d", gallons, quarts, pints, cups);
}
