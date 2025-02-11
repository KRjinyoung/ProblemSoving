#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000
#define MAX_WORD_LENGTH 100

// 문자열 길이를 구하는 함수
int stringLength(const char* str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

// 두 문자열이 같은지 비교하는 함수
int stringsEqual(const char* str1, const char* str2, int length) {
    for (int i = 0; i < length; i++) {
        if (str1[i] != str2[i]) {
            return 0; // 서로 다름
        }
    }
    return 1; // 서로 같음
}

// 특정 단어가 문장에 등장하는 횟수를 세는 함수
int countOccurrences(const char* sentence, const char* word) {
    int count = 0;
    int wordLength = stringLength(word);
    int sentenceLength = stringLength(sentence);

    for (int i = 0; i <= sentenceLength - wordLength; i++) {
        // 단어가 문장에 포함되는지 확인
        if (stringsEqual(&sentence[i], word, wordLength)) {
            // 단어가 전체 단어인지 확인
            if ((i == 0 || sentence[i - 1] == ' ') &&
                (i + wordLength == sentenceLength || sentence[i + wordLength] == ' ')) {
                count++;
            }
        }
    }
    return count;
}

// 특정 단어가 문장에 등장하는 횟수를 세는 함수 (부분 문자열 포함)
int countPartialOccurrences(const char* sentence, const char* word) {
    int count = 0;
    int wordLength = stringLength(word);
    int sentenceLength = stringLength(sentence);

    for (int i = 0; i <= sentenceLength - wordLength; i++) {
        // 단어가 문장에 포함되는지 확인
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

    //printf("문장을 입력하세요: ");
    //fgets(sentence, sizeof(sentence), stdin);

    //// 개행 문자 제거
    //sentence[stringLength(sentence) - 1] = '\0';

    //printf("검색할 단어를 입력하세요: ");
    //fgets(word, sizeof(word), stdin);

    //// 개행 문자 제거
    //word[stringLength(word) - 1] = '\0';

    const char sentence[MAX_LENGTH] = "이것은 예제 문장입니다. 예제 문장 안에는 예제라는 단어가 여러 번 포함되어 있습니다. 예제.";
    const char word[MAX_WORD_LENGTH] = "예제";

    int occurrences = countOccurrences(sentence, word);
    printf("단어 '%s'의 등장 횟수: %d\n", word, occurrences);

    int partialOccurrences = countPartialOccurrences(sentence, word);
    printf("단어 '%s'의 등장 횟수(부분 문자열 포함): %d\n", word, partialOccurrences);

    return 0;
}