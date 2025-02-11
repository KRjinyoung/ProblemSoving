#include <stdio.h>
#include <stdlib.h>

struct NODE
{
    int key;
    struct NODE *next;
};

int InsertKey(struct NODE *head, int value);
void printList(struct NODE *p);
int DeleteKey(struct NODE *head, int value);

int main()
{
    // head 노드를 동적으로 할당
    struct NODE *head = (struct NODE *)malloc(sizeof(struct NODE));
    if (head == NULL)
    {
        printf("메모리 할당 실패\n");
        return -1;
    }

    head->key = 100;
    head->next = NULL;

    // 새로운 값 삽입
    InsertKey(head, 250);
    InsertKey(head, 300);
    InsertKey(head, 50);
    InsertKey(head, 500);

    // 리스트 출력
    printList(head);

    // 동적으로 할당된 메모리 해제
    struct NODE *p = head;
    while (p != NULL)
    {
        struct NODE *temp = p;
        p = p->next;
        free(temp);
    }

    return 0;
}

// 키를 링크드 리스트에 정렬된 순서로 삽입
int InsertKey(struct NODE *head, int value)
{
    struct NODE *p = head->next;
    struct NODE *prev = head;

    // 첫 번째 값보다 작은 값이 들어오면 그 앞에 삽입
    if (value < head->key)
    {
        struct NODE *new_node = (struct NODE *)malloc(sizeof(struct NODE));
        if (new_node == NULL)
        {
            return -1; // 메모리 할당 실패
        }
        new_node->key = value;
        new_node->next = p;
        head->next = new_node;
        return 0;
    }

    // 리스트를 순차적으로 돌며 올바른 위치를 찾음
    while (p)
    {
        if (value == p->key)
        {
            return -1; // 중복된 값이 있으면 삽입하지 않음
        }
        if (p->key > value)
            break; // 적절한 위치를 찾았을 때 삽입
        prev = p;
        p = p->next;
    }

    // 새로운 노드 삽입
    struct NODE *new_node = (struct NODE *)malloc(sizeof(struct NODE));
    if (new_node == NULL)
    {
        return -1; // 메모리 할당 실패
    }
    new_node->key = value;
    new_node->next = p;
    prev->next = new_node;
    return 0;
}

int DeleteKey(struct NODE *head, int value)
{
    struct NODE *p = head->next;
    struct NODE *prev = head;
    while (p)
    {
        if (p->key == value)
        {
            break;
        }
        prev = p;
        p = p->next;
    }

    if (p)
    {
        prev->next = p->next;
        free(p);
    }
}

// 리스트 출력
void printList(struct NODE *p)
{
    while (p)
    {
        printf("%d -> ", p->key);
        p = p->next;
    }
    printf("NULL\n");
}
