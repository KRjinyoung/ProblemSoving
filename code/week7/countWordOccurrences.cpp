#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000
#define MAX_WORD_LENGTH 100

// ���ڿ� ���̸� ���ϴ� �Լ�
int stringLength(const char* str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

// �� ���ڿ��� ������ ���ϴ� �Լ�
int stringsEqual(const char* str1, const char* str2, int length) {
    for (int i = 0; i < length; i++) {
        if (str1[i] != str2[i]) {
            return 0; // ���� �ٸ�
        }
    }
    return 1; // ���� ����
}

// Ư�� �ܾ ���忡 �����ϴ� Ƚ���� ���� �Լ�
int countOccurrences(const char* sentence, const char* word) {
    int count = 0;
    int wordLength = stringLength(word);
    int sentenceLength = stringLength(sentence);

    for (int i = 0; i <= sentenceLength - wordLength; i++) {
        // �ܾ ���忡 ���ԵǴ��� Ȯ��
        if (stringsEqual(&sentence[i], word, wordLength)) {
            // �ܾ ��ü �ܾ����� Ȯ��
            if ((i == 0 || sentence[i - 1] == ' ') &&
                (i + wordLength == sentenceLength || sentence[i + wordLength] == ' ')) {
                count++;
            }
        }
    }
    return count;
}

// Ư�� �ܾ ���忡 �����ϴ� Ƚ���� ���� �Լ� (�κ� ���ڿ� ����)
int countPartialOccurrences(const char* sentence, const char* word) {
    int count = 0;
    int wordLength = stringLength(word);
    int sentenceLength = stringLength(sentence);

    for (int i = 0; i <= sentenceLength - wordLength; i++) {
        // �ܾ ���忡 ���ԵǴ��� Ȯ��
        int found = 1;
        for (int j = 0; j < wordLength; j++) {
            if (sentence[i + j] != word[j]) {
                found = 0;
                break;
            }
        }
        if (found) {
            count++;
        }
    }
    return count;
}

int main() {
    //char sentence[MAX_LENGTH];
    //char word[MAX_WORD_LENGTH];

    //printf("������ �Է��ϼ���: ");
    //fgets(sentence, sizeof(sentence), stdin);

    //// ���� ���� ����
    //sentence[stringLength(sentence) - 1] = '\0';

    //printf("�˻��� �ܾ �Է��ϼ���: ");
    //fgets(word, sizeof(word), stdin);

    //// ���� ���� ����
    //word[stringLength(word) - 1] = '\0';

    const char sentence[MAX_LENGTH] = "�̰��� ���� �����Դϴ�. ���� ���� �ȿ��� ������� �ܾ ���� �� ���ԵǾ� �ֽ��ϴ�. ����.";
    const char word[MAX_WORD_LENGTH] = "����";

    int occurrences = countOccurrences(sentence, word);
    printf("�ܾ� '%s'�� ���� Ƚ��: %d\n", word, occurrences);

    int partialOccurrences = countPartialOccurrences(sentence, word);
    printf("�ܾ� '%s'�� ���� Ƚ��(�κ� ���ڿ� ����): %d\n", word, partialOccurrences);

    return 0;
}