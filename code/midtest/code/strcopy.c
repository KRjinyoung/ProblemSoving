#include <stdio.h>

void strcopy(char string1[], char string2[])
{
    int i = 0;
    while (string2[i] != '\0')
    {
        string1[i] = string2[i];
        i = i + 1;
    }
    string1[i] = '\0';

    printf("Copied string: %s\n", string1);
}

int main()
{
    char source[] = "Hello, World!";
    char destination[50];

    strcopy(destination, source);

    return 0;
}
