#include <stdio.h>

int secs(int hours, int minutes, int seconds)
{
    int totalNumber;
    minutes += hours * 60;
    seconds += minutes * 60;
    totalNumber = seconds;
    return totalNumber;
}

int main()
{
    printf("%d초", secs(1, 10, 2)); // 1시간10분2초 == 4202초
}
