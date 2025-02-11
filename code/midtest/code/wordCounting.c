#include <stdio.h>

return count;
}

int main()
{
    char sentence[1000];
    fgets(sentence, sizeof(sentence), stdin);
    printf("%d", word_count(sentence));
}