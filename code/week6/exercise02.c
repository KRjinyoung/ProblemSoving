#include <stdio.h>
struct car
{
    int carNum;
    int mileDriven;
    int gallonsUsed;
} carList[5] = {
    {25, 1450, 62},
    {36, 3240, 136},
    {44, 1792, 76},
    {52, 2360, 105},
    {68, 2114, 67}};
// car number , Miles Driven(주행거리) / gallons used (연료량)
int main()
{
    double sumMPG = 0;
    for (int i = 0; i < 5; i++)
    {
        double mpg = carList[i].mileDriven / carList[i].gallonsUsed;
        printf("%d %.2lf\n", carList[i].carNum, mpg);
        sumMPG += mpg;
    }
    printf("avg : %.2lf", sumMPG / 5);
}