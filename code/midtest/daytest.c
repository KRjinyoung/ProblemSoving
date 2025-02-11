#include <stdio.h>
struct Date
{
    int month;
    int day;
    int year;
} dates[2] = {
    {1, 1, 2001},
    {2, 2, 2001}};

int Days(struct Date *date)
{
    int day = 0;
    day += (date->day) - 1;
    day += (date->year - 2000) * 365;
    day += (date->month - 1) * 30;
    return day;
}

struct Date *recent(struct Date *date1, struct Date *date2)
{
    return Days(date1) > Days(date2) ? date1 : date2;
}

int main()
{
    printf("%d, %d, %d", recent(&date[0], &date[1])->day, recent(&date[0], &date[1])->month, recent(&date[0], &date[1])->year);
    return 0;
}