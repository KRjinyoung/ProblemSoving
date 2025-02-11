#include <stdio.h>
#define MAXNUM 1000

int findMax(int array[MAXNUM]);

int main()
{
    int numList[MAXNUM];
    int newmax;

    for (int i = 0; i < MAXNUM; i++)
    {
        numList[i] = i + 1;
    }

    newmax = findMax(numList);

    printf("The maximum value is: %d\n", newmax);

    return 0;
}

int findMax(int local_array[])
{
    int max = local_array[0];

    for (int i = 1; i < MAXNUM; i++)
    {
        if (max < local_array[i])
        {
            max = local_array[i];
        }
    }

    return max;
}
