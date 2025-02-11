/* #include <stdio.h>
typedef struct
{
    char name[20];
    float eps; // stock earnings per share
    float pe;  // price to earnings ratio
}C;

int main()
{
    C companies[5];
    for (int i = 0; i < 5; i++)
    {
        scanf("%s %f %f", companies[i].name, companies[i].eps, companies[i].pe);
    }
    for (int i = 0; i < 5; i++)
    {
       printf("Company name : %s\nStock price : %f\n",companies[i].name, companies[i].eps* companies[i].p);
    }

} */

#include <stdio.h>
#define SIZE 1
typedef struct
{
    char name[20];
    float earnings;
    float ratio;
} Stock;
