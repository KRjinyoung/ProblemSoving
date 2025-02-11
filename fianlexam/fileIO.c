#include <stdio.h>
void main()
{
    int a, sum = 0;
    FILE *inFile, *outFile;
    inFile = fopen("myinFile.txt", "r");
    if (inFile == NULL)
    {
        printf("Input File Could Not Be Opened.");
        exit(1);
    }
    outFile = fopen("myoutFile.txt", "w");
    if (outFile == NULL)
    {
        printf("Output File Could Not Be Opened.");
        exit(1);
    }
    /* Read and sum the integers from the input file and
        write the sum to the output file */
    while (fscanf(inFile, "%d", &a) == 1) /* loops until EOF  */
        sum = sum + a;
    fprintf(outFile, "The sum is %d \n", sum);
    fclose(inFile);
    fclose(outFile);
}