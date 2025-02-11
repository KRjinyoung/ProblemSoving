#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>

struct Node {
    int key;
    struct Node* next;
};

struct Stack {
    struct Node* top;
};

int is_empty(struct Stack *s) {
    return (s->top == NULL);
}

void push(struct Stack *s, int object) {
    struct Node *tmp = (struct Node*)malloc(sizeof(struct Node));
    tmp->key = object;
    tmp->next = s->top;
    s->top = tmp;
}

int pop(struct Stack *s) {
    if (is_empty(s)) {
        printf("under flow!!!!!!!!");
        return 0;
    }
    else {
        struct Node *tmpNode = s->top;
        int tmp = tmpNode->key;
        s->top = tmpNode->next;
        free(tmpNode);
        return tmp;
    }
}

int main() {
    struct Stack s;
    s.top = NULL;

    push(&s, 3);
    push(&s, 1);
    push(&s, 5);
    push(&s, 7);
  
    int i;
    for (i = 0; i < 5; i++) {
        printf("%d\n", pop(&s));
    }

    return 0;
}
