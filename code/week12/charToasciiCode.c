#include <stdio.h>

int main()
{
    char ch;
    printf("Enter a character: ");
    scanf("%c", &ch);

    unsigned char mask = 0x80; // 0x80 is 10000000 in binary, which helps us check each bit from left to right.

    printf("The bits of the character '%c' are: ", ch);
    for (int i = 0; i < 8; i++)
    {
        // Check if the current bit is 1 or 0
        if (ch & mask)
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
        // mask = mask >> 1;
        mask >>= 1; // Shift the mask one bit to the right
    }

    printf("\n");
    return 0;
}
