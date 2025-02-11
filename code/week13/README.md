linked list를 c언어로 직접 구현

- singly linked list (단방향 링크드리스트) 
- doubly linked list (양방향 링크드리스트) *다루지않음


singly linked list
나랑 연결된 데이터가 어디에 있는지 

struct NODE{
    int key;
    struct NODE *next;
}node;


static memory와 dynamic memory
