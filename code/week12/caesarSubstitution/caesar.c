#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define N 3

int main()
{
    FILE *input = fopen("original.txt", "r");
    FILE *output = fopen("cypher.txt", "w");
    char ch;
    while (ch = fgetc(input) != EOF)
    {
        if (isalpha(ch) == 0)
        {
            fputc(ch, output);
        }
        else
        {
            ch = (ch + N) / 26;
            fputc(ch, output);
        }
    }
}