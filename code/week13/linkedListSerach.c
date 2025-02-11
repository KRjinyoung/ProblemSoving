#include <stdlib.h>
#include <stdio.h>

struct NODE
{
    int key;
    struct NODE *next;
} node[1000];

int main()
{
    struct NODE *ptr;
    int srchkey, found = 0;
    srchkey = 467;
    ptr = &node[0];
    while (ptr)
    {
        if ((*ptr).key == srchkey)
        {
            found = 1;
            break;
        }
        ptr = (*ptr).next;
    }
    if (found)
        printf("search key found");
    else
        printf("search key not found");
}