#include <stdio.h>

#define MAX_LENGTH 1000
#define MAX_WORD_LENGTH 100

int stringLength(const char *str)
{
    int length = 0;
    while (str[length] != '\0')
    {
        length++;
    }
    return length;
}

// Ư�� ���ڿ��� �����ϰ� ������ ��� ���ڿ��� ã�� �Լ�
int countWildcardOccurrences(const char *sentence, const char *prefix, const char *suffix)
{
    int count = 0;
    int sentenceLength = stringLength(sentence);
    int prefixLength = stringLength(prefix);
    int suffixLength = stringLength(suffix);

    //
    for (int i = 0; i <= sentenceLength - prefixLength; i++)
    {
        // ���λ� üũ
        int matchPrefix = 1;
        for (int j = 0; j < prefixLength; j++)
        {
            if (sentence[i + j] != prefix[j])
            {
                matchPrefix = 0;
                break;
            }
        }

        // ���λ簡 ��ġ�ϸ� ���̻� üũ
        if (matchPrefix)
        {
            for (int k = i + prefixLength; k <= sentenceLength - suffixLength; k++)
            {
                // ���̻� üũ
                int matchSuffix = 1;
                for (int l = 0; l < suffixLength; l++)
                {
                    if (sentence[k + l] != suffix[l])
                    {
                        matchSuffix = 0;
                        break;
                    }
                }
                if (matchSuffix)
                {
                    count++;
                }
            }
        }
    }
    return count;
}

int main()
{
    // ���� ���� ����� �˻��� ���ڿ�
    const char sentence[MAX_LENGTH] = "This is a sample sentence. The sample begins with sample text and ends with a sample.";
    const char input[MAX_WORD_LENGTH] = "sample*text"; // prefix�� suffix�� ������ �Է� ����

    // '*'�� �������� ������
    char prefix[MAX_WORD_LENGTH];
    char suffix[MAX_WORD_LENGTH];
    int i = 0, j = 0;

    // prefix �κ� ����
    while (input[i] != '*' && input[i] != '\0')
    {
        prefix[i] = input[i];
        i++;
    }
    prefix[i] = '\0'; // Null terminator

    // '*'�� �Ѿ �� suffix �κ� ����
    if (input[i] == '*')
    {
        i++; // Skip the '*'
    }

    while (input[i] != '\0')
    {
        suffix[j] = input[i];
        i++;
        j++;
    }
    suffix[j] = '\0'; // Null terminator

    // ���ϵ�ī��� ��ġ�ϴ� �κ� ���ڿ��� ������ ����
    int occurrences = countWildcardOccurrences(sentence, prefix, suffix);
    printf("Occurrences of '%s*%s': %d\n", prefix, suffix, occurrences);

    return 0;
}