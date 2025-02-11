// fgets로 입력받고 마지막 개행문자까지 포함되기때문에 개행문자를 제거해줘야함
#include <stdio.h>
#define MAX_LENTH 1000
#define MAX_WORD_LENTH 100

int stringLength(const char *str);

int main()
{
    char sentence[MAX_LENTH];
    char word[MAX_WORD_LENTH];

    printf("enter your sentence : ");
    fgets(sentence, sizeof(sentence), stdin);
    sentence[stringLength(sentence) - 1] = '\0';

    printf("enter your word : ");
    fgets(word, sizeof(word), stdin);
    word[stringLength(word) - 1] = '\0';
}

int stringLength(const char *str)
{
    int count = 0;
    while (str[count] != '\0')
}