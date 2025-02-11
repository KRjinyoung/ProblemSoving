#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define size 100

int stack[size];
int top = -1;

bool isFull();
bool isEmpty();
void push(int item);
int pop();

int main()
{

    push(3);
    push(5);
    push(1);
    pop();

    for (int i = 0; i < top + 1; i++)
    {
        printf("%d", stack[i]);
    }
}

bool isFull()
{
    int stacksize = top + 1;
    if (stacksize == size)
        return true;
    else
        return false;
}

bool isEmpty()
{
    int stacksize = top + 1;
    if (stacksize == 0)
        return true;
    else
        return false;
}

void push(int item)
{
    if (isFull())
    {
        printf("OVERFLOW_ERROR");
        return;
    }
    else
    {
        top++;
        stack[top] = item;
    }
}

int pop()
{
    if (isEmpty())
    {
        printf("UNDERFLOW_ERROR");
        return -1;
    }
    else
        top--;
}
