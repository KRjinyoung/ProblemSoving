#include <stdio.h>

void show(double rates[])
{
    for (int i = 0; i < 9; i++)
    {
        printf("%.1f ", rates[i]);
    }
}

int main()
{
    double rates[] = {6.5, 8.2, 8.5, 8.3, 8.6, 9.4, 9.6, 9.8, 10.0};

    show(rates);

    return 0;
}
