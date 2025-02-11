#include <stdio.h>
int main()
{
    char input;
    scanf("%c", &input);
    int mask = 0x80;

    printf("The bits of the character '%c' are :", input);
    for (int i = 7; i >= 0; i--)
    {
        printf("%d", (mask & input) >> i);
        mask = mask >> 1;
    }
}