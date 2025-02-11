#include <stdio.h>

int secs(int *tot, int hours, int minutes, int seconds)
{
    minutes += hours * 60;
    seconds += minutes * 60;
    *tot = seconds;
}

int main()
{
    int totSec;
    secs(&totSec, 1, 10, 2); // 1시간10분2초 == 4202초
    printf("%d초", totSec);
}
