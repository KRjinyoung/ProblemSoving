#include <stdio.h>
#include <stdlib.h>

struct NODE
{
    int key;
    struct NODE *next;
};

int main()
{
    struct NODE node[100];
    int isFound = 0;
    int searchkey = 467;
    struct NODE *ptr;
    ptr = &node[0];

    while (ptr != NULL)
    {
        if (ptr->key == searchkey)
        {
            isFound = 1;
            break;
        }

        ptr = ptr->next;
    }
}