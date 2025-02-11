#include <string.h>
#include <stdio.h>

int searchCount(const char *sentence, const char *word);

int main()
{
    char sentence[1000];
    char word[100];

    printf("put your sentence : ");
    fgets(sentence, sizeof(sentence), stdin);

    sentence[strlen(sentence) - 1] = '\0';

    printf("put your word : ");
    fgets(word, sizeof(word), stdin);

    word[strlen(word) - 1] = '\0';

    printf("%d", searchCount(sentence, word));

    return 0;
}

int searchCount(const char *sentence, const char *word)
{
    int count = 0;
    int sentenceLen = strlen(sentence);
    int wordLen = strlen(word);

    for (int i = 0; i <= sentenceLen - wordLen; i++)
    {
        int isFound = 1;
        if (sentence[i] == word[0])
        {
            for (int j = 0; j < wordLen; j++)
            {
                if (sentence[i + j] != word[j])
                {
                    isFound = 0;
                    break;
                }
            }
            if (isFound)
            {
                count++;
            }
        }
    }

    return count;
}
