#include <stdio.h>

struct NODE
{
    int key;
    struct NODE *next;
};

int main()
{
    struct NODE node[4]; // 0부터 3까지 사용할 배열, 4개의 노드
    struct NODE *ptr, *old_ptr = NULL;
    int newkey = 300;

    // node[3]에 새로운 값 삽입
    node[3].key = newkey;
    node[3].next = NULL;

    // 초기값 설정 (node[0], node[1], node[2]에 임의의 값)
    node[0].key = 100;
    node[0].next = &node[1];
    node[1].key = 250;
    node[1].next = &node[2];
    node[2].key = 467;
    node[2].next = NULL;

    // 삽입할 값을 찾기 위한 포인터 설정
    ptr = &node[0];

    // 링크드 리스트를 검색하며 새로운 값을 삽입할 위치를 찾음
    while (ptr)
    {
        if (ptr->key == newkey)
        {
            // 새로운 값이 이미 존재하는 경우
            printf("key already exists\n");
            break;
        }
        if (ptr->key < newkey)
        {
            // 삽입할 위치를 찾지 못했으면 old_ptr 갱신
            old_ptr = ptr;
            ptr = ptr->next;
        }
        else
        {
            // 삽입 위치 찾음
            old_ptr->next = &node[3]; // old_ptr의 next를 새로운 노드로 설정
            node[3].next = ptr;       // 새로운 노드의 next는 기존의 ptr로 설정
            printf("key inserted\n");
            break;
        }
    }

    // 결과 출력
    ptr = &node[0];
    while (ptr)
    {
        printf("%d -> ", ptr->key);
        ptr = ptr->next;
    }
    printf("NULL\n");

    return 0;
}
