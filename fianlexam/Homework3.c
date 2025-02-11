#include <stdio.h>
#include <stdlib.h>

struct NODE
{
    int key;
    struct NODE *next;
} node[7];

int InsertKey(struct NODE *head, int value, struct NODE **new_head);

void ScanList(struct NODE *head);

int main()
{
    struct NODE *head = &node[0];
    struct NODE *new_head = NULL;

    node[0].key = 100;
    node[1].key = 250;
    node[2].key = 467;
    node[0].next = &node[1];
    node[1].next = &node[2];
    node[2].next = NULL;

    InsertKey(head, 250, &new_head);
    InsertKey(head, 300, &new_head);
    InsertKey(head, 50, &new_head);
    InsertKey(head, 500, &new_head);

    if (new_head != NULL)
    {
        head = new_head;
    }

    ScanList(head);
    return 0;
}

int InsertKey(struct NODE *head, int value, struct NODE **new_head)
{
    struct NODE *p = head->next, *prev = head;
    struct NODE *new_node;

    if (head->key > value)
    {
        new_node = (struct NODE *)malloc(sizeof(struct NODE));
        new_node->key = value;
        new_node->next = head;
        *new_head = new_node;
        printf("%d was successfully inserted.\n", value);
        return 0;
    }

    while (p)
    {
        if (p->key == value)
        {
            printf("%d already exists.\n", value);
            return -1;
        }
        else if (p->key > value)
            break;
        prev = p;
        p = p->next;
    }

    new_node = (struct NODE *)malloc(sizeof(struct NODE));
    new_node->key = value;
    new_node->next = p;
    prev->next = new_node;
    printf("%d was successfully inserted.\n", value);
    return 0;
}

void ScanList(struct NODE *head)
{
    struct NODE *traverse = head;
    while (traverse)
    {
        printf("%d", traverse->key);
        if (traverse->next != NULL)
        {
            printf(" -> ");
        }
        traverse = traverse->next;
    }
    printf("\n");
}
