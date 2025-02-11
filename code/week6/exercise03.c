// 2000년 1월 1일부터 이날짜까지 얼마가 지났나 days()
// 두 날짜를 입력받아 가장 최근날짜를 알려주는 recent()
#include <stdio.h>

struct Date
{
    int month;
    int day;
    int year;
};

int days(struct Date date)
{
    return ((date.year - 2000) * 365 + date.day + date.month * 30);
}

int days2(struct Date* date)
{
    
}

void recent(struct Date date, struct Date date2)
{
    days(date) > days(date2) ? : ;
}

int main()
{
    struct Date today = {10, 07, 2024};
    struct Date yesterday = {10, 06, 2024};
    {
        /* data */
    };
    
    int result = days(today);
    printf("%d", result);
}