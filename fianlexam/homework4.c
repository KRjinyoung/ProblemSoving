#include <stdio.h>
#include <stdlib.h>

struct NUM
{
    int key;
    struct NUM *next;
};

int InsertKey(struct NUM *head, int value);
void ScanList(struct NUM *head);

int main()
{
    int nums[10] = {17, 39, 11, 9, 42, 12, 15, 8, 13, 41};

    struct NUM *head = (struct NUM *)malloc(sizeof(struct NUM));
    head->next = NULL;

    for (int i = 0; i < 10; i++)
    {
        InsertKey(head, nums[i]);
    }

    ScanList(head);

    return 0;
}

int InsertKey(struct NUM *head, int value)
{
    struct NUM *p = head->next, *prev = head;
    struct NUM *new_node;

    while (p)
    {
        if (p->key == value)
        {
            printf("%d already exists.\n", value);
            return -1;
        }
        else if (p->key > value)
        {
            break;
        }
        prev = p;
        p = p->next;
    }

    new_node = (struct NUM *)malloc(sizeof(struct NUM));
    new_node->key = value;
    prev->next = new_node;
    new_node->next = p;

    return 0;
}

void ScanList(struct NUM *head)
{
    struct NUM *traverse = head->next;
    while (traverse)
    {
        printf("%d", traverse->key);
        if (traverse->next != NULL)
        {
            printf(" -> ");
        }
        traverse = traverse->next;
    }
}
