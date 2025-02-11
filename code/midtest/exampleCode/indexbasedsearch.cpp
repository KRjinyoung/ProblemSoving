#include <stdio.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LENGTH 50
#define MAX_HOBBY_LENGTH 100

// Define a struct to hold the dataset
typedef struct
{
    char name[MAX_NAME_LENGTH];
    int age;
    char hobby[MAX_HOBBY_LENGTH];
} Person;

// Define a struct for the index
typedef struct
{
    char name[MAX_NAME_LENGTH];
    int index; // Index of the person in the dataset
} NameIndex;

// Function to search for a person by name in the index
void searchByIndex(NameIndex index[], Person people[], int count, const char *name)
{
    for (int i = 0; i < count; i++)
    {
        if (strcmp(index[i].name, name) == 0)
        {
            int personIndex = index[i].index;
            printf("Name: %s, Age: %d, Hobby: %s\n", people[personIndex].name, people[personIndex].age, people[personIndex].hobby);
            return;
        }
    }
    printf("Person with name '%s' not found.\n", name);
}

int main()
{
    // Sample dataset
    Person people[MAX_ENTRIES] = {
        {"Alice", 30, "Painting"},
        {"Bob", 25, "Cycling"},
        {"Charlie", 28, "Reading"},
        {"Diana", 22, "Dancing"},
        {"Eve", 35, "Hiking"}};

    int count = 5; // Number of entries in the dataset

    // Create an index for the names
    NameIndex index[MAX_ENTRIES];
    for (int i = 0; i < count; i++)
    {
        strcpy(index[i].name, people[i].name);
        index[i].index = i; // Store the index of the person in the dataset
    }

    // Example search
    char nameToSearch[MAX_NAME_LENGTH];
    printf("Enter a name to search: ");
    fgets(nameToSearch, sizeof(nameToSearch), stdin);
    nameToSearch[strcspn(nameToSearch, "\n")] = '\0'; // Remove the newline character

    searchByIndex(index, people, count, nameToSearch);

    return 0;
}
