#include <stdio.h>

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

// 특정 문자열로 시작하고 끝나는 모든 문자열을 찾는 함수
int countWildcardOccurrences(const char* sentence, const char* prefix, const char* suffix) {
    int count = 0;
    int sentenceLength = stringLength(sentence);
    int prefixLength = stringLength(prefix);
    int suffixLength = stringLength(suffix);

    for (int i = 0; i <= sentenceLength - prefixLength; i++) {
        // 접두사 체크
        int matchPrefix = 1;
        for (int j = 0; j < prefixLength; j++) {
            if (sentence[i + j] != prefix[j]) {
                matchPrefix = 0;
                break;
            }
        }

        // 접두사가 일치하면 접미사 체크
        if (matchPrefix) {
            for (int k = i + prefixLength; k <= sentenceLength - suffixLength; k++) {
                // 접미사 체크
                int matchSuffix = 1;
                for (int l = 0; l < suffixLength; l++) {
                    if (sentence[k + l] != suffix[l]) {
                        matchSuffix = 0;
                        break;
                    }
                }
                if (matchSuffix) {
                    count++;
                }
            }
        }
    }
    return count;
}

int main() {
    // 샘플 예제 문장과 검색할 문자열
    const char sentence[MAX_LENGTH] = "This is a sample sentence. The sample begins with sample text and ends with a sample.";
    const char input[MAX_WORD_LENGTH] = "sample*text"; // prefix와 suffix를 포함한 입력 형식

    // '*'를 기준으로 나누기
    char prefix[MAX_WORD_LENGTH];
    char suffix[MAX_WORD_LENGTH];
    int i = 0, j = 0;

    // prefix 부분 추출
    while (input[i] != '*' && input[i] != '\0') {
        prefix[i] = input[i];
        i++;
    }
    prefix[i] = '\0'; // Null terminator

    // '*'를 넘어간 후 suffix 부분 추출
    if (input[i] == '*') {
        i++; // Skip the '*'
    }

    while (input[i] != '\0') {
        suffix[j] = input[i];
        i++;
        j++;
    }
    suffix[j] = '\0'; // Null terminator

    // 와일드카드로 일치하는 부분 문자열의 개수를 세기
    int occurrences = countWildcardOccurrences(sentence, prefix, suffix);
    printf("Occurrences of '%s*%s': %d\n", prefix, suffix, occurrences);

    return 0;
}