#include <stdio.h>
int main()
{
    int a;
    scanf("%d", &a);
    int mask = 0x1;

    int arr[16];
    for (int i = 0; i < 16; i++)
    {
        arr[i] = a & mask;
        a = a >> 1;
    }
    for (int i = 16; i >= 0; i--)
    {
        printf("%d", arr[i]);
    }

    printf("\n\n");
    scanf("%d", &a);
    int mask = 0xF;

    int arr[16];
    for (int i = 0; i < 16; i++)
    {
        arr[i] = a & mask;
        a = a >> 4;
    }
    for (int i = 16; i >= 0; i--)
    {
        printf("%d", arr[i]);
    }
}

/* 정수 2진수 변환

    예를들어 a = 가 5라면 5는 0000....0101

    마스크를 0x1로 만들어

        a를 shift 하셈
            마지막에 반대로 뒤집어야함

    16진수는 0xF를 만들어서 4씩 shift하셈
        반대로 뒤집어야함 */