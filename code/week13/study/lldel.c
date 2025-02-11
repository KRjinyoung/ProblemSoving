#include <stdio.h>

struct NODE
{
    int key;
    struct NODE *next;
};

int main()
{
    struct NODE node[4];
    struct NODE *ptr, *prv_ptr, *nx_ptr;
    int delkey = 250;

    node[3].key = delkey;
    node[3].next = NULL;

    node[0].key = 100;
    node[0].next = &node[1];
    node[1].key = 250;
    node[1].next = &node[2];
    node[2].key = 467;
    node[2].next = NULL;

    ptr = &node[0];

    while (ptr)
    {
        if (ptr->key == delkey)
        {
            prv_ptr->next = ptr->next;
            ptr->next = NULL;
            break;
        }
    }

    ptr = &node[0];
    while (ptr)
    {
        printf("%d -> ", ptr->key);
        ptr = ptr->next;
    }
    printf("NULL\n");

    return 0;
}
