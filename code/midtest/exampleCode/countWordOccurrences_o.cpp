#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000
#define MAX_WORD_LENGTH 100

int countOccurrences(const char* sentence, const char* word) {
    int count = 0;
    const char* temp = sentence;
    int wordLength = strlen(word);

    while ((temp = strstr(temp, word)) != NULL) {
        // Check if the found word is a whole word
        if ((temp == sentence || *(temp - 1) == ' ') &&
            (*(temp + wordLength) == ' ' || *(temp + wordLength) == '\0')) {
            count++;
        }
        temp += wordLength; // Move past the found word
    }
    return count;
}

int main() {
    char sentence[MAX_LENGTH];
    char word[MAX_WORD_LENGTH];

    printf("������ �Է��ϼ���: ");
    fgets(sentence, sizeof(sentence), stdin);

    // Remove the newline character if present
    sentence[strcspn(sentence, "\n")] = 0;

    printf("�˻��� �ܾ �Է��ϼ���: ");
    fgets(word, sizeof(word), stdin);

    // Remove the newline character if present
    word[strcspn(word, "\n")] = 0;

    int occurrences = countOccurrences(sentence, word);
    printf("�ܾ� '%s'�� ���� Ƚ��: %d\n", word, occurrences);

    return 0;
}