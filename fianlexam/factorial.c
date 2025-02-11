#include <stdio.h>
int factorial(int n)
{
    if (n == 0)
    {
        return (1);
    }
    else
    {
        return (n * factorial(n - 1));
    }
}

int fibonacci(int n)
{
    if (n < 2)
    {
        return (0);
    }
    else
    {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main()
{
    int result = factorial(5);
    printf("%d", result);
    return 0;
}
