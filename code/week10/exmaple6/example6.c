#include <stdio.h>
#include <stdlib.h>
void main()
{
    FILE *myInFile, *myOutFile;
    char ch;
    myInFile = fopen(" charstream.txt", "r");
    if (myInFile == NULL)
    {
        printf("Could not open charstream.txt!\n");
        exit(1);
    }
    myOutFile = fopen("samedata.txt ", "w");
    if (myOutFile == NULL)
    {
        printf("Could not open samedata.txt!\n");
        exit(1);
    }
    while ((ch = fgetc(myInFile)) != EOF)
        fputc(ch, myOutFile);
    fclose(myInFile);
    fclose(myOutFile);
}