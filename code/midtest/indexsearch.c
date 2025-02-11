#include <stdio.h>
#include <string.h>

typedef struct
{
    char name[20];
    int age;
    char hobby[20];
} Person;

typedef struct
{
    char name[20];
    int index;
} NameIndex;

//   serachByIndex(indexarr, people, count, nameToSearch);
void searchByIndex(NameIndex index[], Person people[], int count, const char *name)
{
    for (int i = 0; i < count; i++)
    {
        if (strcmp(index[i].name, name) == 0)
        {
            int hisIndex = index[i].index;
            // 출력하기
            return;
        }
    }
    printf("찾을 수 없음");
}

int main()
{
    NameIndex indexarr[100];

    Person people[100] = {
        {"Alice", 30, "Painting"},
        {"Bob", 25, "Cycling"},
        {"Charlie", 28, "Reading"},
        {"Diana", 22, "Dancing"},
        {"Eve", 35, "Hiking"}};

    int count = 5;

    for (int i = 0; i < count; i++)
    {
        strcpy(indexarr[i].name, people[i].name);
        indexarr[i].index = i;
    }
    char nameToSearch[20];
    printf("enter your name : ");
    fgets(nameToSearch, sizeof(nameToSearch), stdin);
    nameToSearch[strlen(nameToSearch) - 1] = '\0';

    searchByIndex(indexarr, people, count, nameToSearch);
}