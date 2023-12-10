#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PEOPLE 100
#define MAX_NAME_LEN 50
#define MAX_HOBBY_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    int age;
    char hobby[MAX_HOBBY_LEN];
} Person;

void readData(char* filename, Person people[], int* count) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        exit(1);
    }

    while (fscanf(file, "%s %d %s", people[*count].name, &people[*count].age, people[*count].hobby) == 3) {
        (*count)++;
    }

    fclose(file);
}

void writeData(char* filename, Person people[], int count) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        perror("Error opening file");
        exit(1);
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%s %d %s\n", people[i].name, people[i].age, people[i].hobby);
    }

    fclose(file);
}

// Function to sort people by age in ascending order
void selectionSortByAge(Person people[], int count) {
    for (int i = 0; i < count - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < count; j++) {
            if (people[j].age < people[min_idx].age) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            Person temp = people[i];
            people[i] = people[min_idx];
            people[min_idx] = temp;
        }
    }
}

// ******
// Function to sort people by hobby in lexicographical order
void selectionSortByHobby(Person people[], int count) {
    for (int i = 0; i < count - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < count; j++) {
            if (strcmp(people[j].hobby, people[min_idx].hobby) < 0) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            Person temp = people[i];
            people[i] = people[min_idx];
            people[min_idx] = temp;
        }
    }
}


int compareByAge(const Person* a, const Person* b) {
    return a->age - b->age;
}

int compareByHobby(const Person* a, const Person* b) {
    return strcmp(a->hobby, b->hobby);
}

int main() {
    Person people[MAX_PEOPLE];
    int count = 0;

    readData("personal.txt", people, &count);

    selectionSortByAge(people, count);
    writeData("age.txt", people, count);

    selectionSortByHobby(people, count);
    writeData("hobby.txt", people, count);

    return 0;
}
