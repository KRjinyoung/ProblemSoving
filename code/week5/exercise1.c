#include <stdio.h>
struct calender
{
    int month;
    int day;
    int year;
} today;

int main()
{
    scanf("%d", &today.day);
    scanf("%d", &today.month);
    scanf("%d", &today.year);
    printf("%d년 %d월 %d일", today.year, today.month, today.day);
}
