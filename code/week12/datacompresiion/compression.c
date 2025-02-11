#include <stdio.h>

int main()
{
    FILE *input = fopen("address.txt", "r");
    FILE *output = fopen("compressed.txt", "w");
    char ch;
    while ((ch = fgetc(input)) != EOF)
    {
        if (ch != '-' && ch != ' ')
        {
            fputc(ch, output);
        }
    }
}