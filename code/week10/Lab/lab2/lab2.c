#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *file;
    char voteTo[20];

    int washington = 0, lincoln = 0, roosevelt = 0;
    int totalVote = 0;
    file = fopen("vote.txt", "r");
    while (fscanf(file, "%*s %*d %s", voteTo) != EOF)
    {
        if (strcmp(voteTo, "Washington") == 0)
        {
            washington++;
        }
        else if (strcmp(voteTo, "Lincoln") == 0)
        {
            lincoln++;
        }
        else if (strcmp(voteTo, "Roosevelt") == 0)
        {
            roosevelt++;
        }
        totalVote++;
    }
    fclose(file);

    printf("*All Data*\n");
    printf("Washington ( %d voted ) : %.2f%%\n", washington, (float)washington / totalVote * 100);
    printf("Lincoln ( %d voted ) : %.2f%%\n", lincoln, (float)lincoln / totalVote * 100);
    printf("Roosevelt ( %d voted ) : %.2f%%\n", roosevelt, (float)roosevelt / totalVote * 100);
    printf("----------------------------------------------------------------------\n");
    // Sampling every third row
    washington = 0, lincoln = 0, roosevelt = 0;
    totalVote = 0;
    int row = 1;
    file = fopen("vote.txt", "r");
    while (fscanf(file, "%*s %*d %s", voteTo) != EOF)
    {
        if (row % 3 == 0)
        {
            if (strcmp(voteTo, "Washington") == 0)
            {
                washington++;
            }
            else if (strcmp(voteTo, "Lincoln") == 0)
            {
                lincoln++;
            }
            else if (strcmp(voteTo, "Roosevelt") == 0)
            {
                roosevelt++;
            }
            totalVote++;
        }
        row++;
    }
    fclose(file);
    printf("*Sampling Every 3th row*\n");
    printf("Washington ( %d voted ) : %.2f%%\n", washington, (float)washington / totalVote * 100);
    printf("Lincoln ( %d voted ) : %.2f%%\n", lincoln, (float)lincoln / totalVote * 100);
    printf("Roosevelt ( %d voted ) : %.2f%%\n", roosevelt, (float)roosevelt / totalVote * 100);
    printf("----------------------------------------------------------------------\n");

    // Sampling every tenth row
    washington = 0, lincoln = 0, roosevelt = 0;
    totalVote = 0;
    row = 1;
    file = fopen("vote.txt", "r");
    while (fscanf(file, "%*s %*d %s", voteTo) != EOF)
    {
        if (row % 10 == 0)
        {
            if (strcmp(voteTo, "Washington") == 0)
            {
                washington++;
            }
            else if (strcmp(voteTo, "Lincoln") == 0)
            {
                lincoln++;
            }
            else if (strcmp(voteTo, "Roosevelt") == 0)
            {
                roosevelt++;
            }
            totalVote++;
        }
        row++;
    }
    fclose(file);
    printf("*Sampling Every 10th row*\n");
    printf("Washington ( %d voted ) : %.2f%%\n", washington, (float)washington / totalVote * 100);
    printf("Lincoln ( %d voted ) : %.2f%%\n", lincoln, (float)lincoln / totalVote * 100);
    printf("Roosevelt ( %d voted ) : %.2f%%\n", roosevelt, (float)roosevelt / totalVote * 100);
    return 0;
}
