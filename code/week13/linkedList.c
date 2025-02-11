#include <stdlib.h>
#include <stdio.h>

struct NODE
{
    int key;
    struct NODE *next;
}

main()
{
    struct NODE *node[3];

    for (int i = 0; i < 3; i++)
    {
        node[i] = (struct NODE *)malloc(sizeof(struct NODE) * 1);

        if (node[i] == (struct NODE *)NULL)
            exit(1);

        node[i]->key = 100;
        node[i]->next = NULL;

        free(node[i]);
    }
}