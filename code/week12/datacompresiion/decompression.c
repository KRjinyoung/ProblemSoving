#include <stdio.h>
int main()
{
    FILE *input = fopen("compressed.txt", "r");
    FILE *output = fopen("decompressed.txt", "w");
    char ch;
    int count = 0;
    while ((ch = fgetc(input)) != EOF)
    {
        fputc(ch, output);
        count++;
        // Re-insert hyphen after every 3 characters (for phone numbers)
        if (count == 3)
        {
            fputc(' ', output);
            fputc('-', output);
            fputc(' ', output);
        }
        else if (count == 7)
        {
            count = 0; // Reset count after one phone number is processed
            fputc(' ', output);
            fputc(' ', output);
            fputc(' ', output);
        }
    }
}