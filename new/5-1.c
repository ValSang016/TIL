#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 33
#define MAX_KEY_SIZE 20

// Structure to hold a key-value pair
typedef struct {
    char key[MAX_KEY_SIZE];
    int value;
} KeyValuePair;

// Structure to represent a node in the overflow list
typedef struct OverflowNode {
    KeyValuePair data;
    struct OverflowNode* next;
} OverflowNode;

// Structure to represent a hash table bucket
typedef struct {
    KeyValuePair data;
    OverflowNode* overflow;
} Bucket;

// Hash function
int hash(const char* key) {
    int sum = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        sum += key[i];
    }
    return sum % TABLE_SIZE;
}

// Function to insert a key-value pair into the hash table
void insert(Bucket* table, const char* key, int value) {
    int index = hash(key);
    Bucket* bucket = &table[index];

    if (strcmp(bucket->data.key, "") == 0) {
        strcpy(bucket->data.key, key);
        bucket->data.value = value;
    } else {
        OverflowNode* newNode = (OverflowNode*)malloc(sizeof(OverflowNode));
        strcpy(newNode->data.key, key);
        newNode->data.value = value;
        newNode->next = bucket->overflow;
        bucket->overflow = newNode;
    }
}

// Function to search for a key in the hash table
int search(Bucket* table, const char* key) {
    int index = hash(key);
    Bucket* bucket = &table[index];

    if (strcmp(bucket->data.key, key) == 0) {
        return bucket->data.value;
    } else {
        OverflowNode* current = bucket->overflow;
        while (current != NULL) {
            if (strcmp(current->data.key, key) == 0) {
                return current->data.value;
            }
            current = current->next;
        }
    }

    return -1; // Key not found
}

// Function to delete a key from the hash table
void delete(Bucket* table, const char* key) {
    int index = hash(key);
    Bucket* bucket = &table[index];

    if (strcmp(bucket->data.key, key) == 0) {
        strcpy(bucket->data.key, "");
        bucket->data.value = 0;
    } else {
        OverflowNode* current = bucket->overflow;
        OverflowNode* prev = NULL;

        while (current != NULL) {
            if (strcmp(current->data.key, key) == 0) {
                if (prev == NULL) {
                    bucket->overflow = current->next;
                } else {
                    prev->next = current->next;
                }
                free(current);
                return;
            }
            prev = current;
            current = current->next;
        }
    }
}

// Function to print the contents of the hash table
void printTable(Bucket* table) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Bucket %d: ", i);
        if (strcmp(table[i].data.key, "") == 0) {
            printf("NULL\n");
        } else {
            printf("(%s, %d) ", table[i].data.key, table[i].data.value);

            OverflowNode* current = table[i].overflow;
            while (current != NULL) {
                printf("-> (%s, %d) ", current->data.key, current->data.value);
                current = current->next;
            }

            printf("\n");
        }
    }
}

int main() {
    // Create the hash table
    Bucket table[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++) {
        strcpy(table[i].data.key, "");
        table[i].data.value = 0;
        table[i].overflow = NULL;
    }

    // Read keys from the keyinput.txt file and insert them into the hash table
    FILE* file = fopen("keyinput.txt", "r");
    if (file == NULL) {
        printf("Failed to open keyinput.txt file.\n");
        return 1;
    }

    char key[MAX_KEY_SIZE];
    int value;
    while (fscanf(file, "%s %d", key, &value) != EOF) {
        insert(table, key, value);
    }
    fclose(file);

    // Print the initial contents of the hash table
    printf("Initial hash table:\n");
    printTable(table);
    printf("\n");

    // Search for specific keys
    printf("Search Results:\n");
    printf("Blue: %s\n", search(table, "Blue") != -1 ? "found" : "not found");
    printf("Black: %s\n", search(table, "Black") != -1 ? "found" : "not found");
    printf("Purple: %s\n", search(table, "Purple") != -1 ? "found" : "not found");
    printf("\n");

    // Delete specific keys
    printf("Delete Results:\n");
    delete(table, "Purple");
    delete(table, "Blue");
    delete(table, "Green");
    printf("Purple: %s\n", search(table, "Purple") != -1 ? "not deleted" : "deleted");
    printf("Blue: %s\n", search(table, "Blue") != -1 ? "not deleted" : "deleted");
    printf("Green: %s\n", search(table, "Green") != -1 ? "not deleted" : "deleted");
    printf("\n");

    // Insert new keys
    printf("Insert Results:\n");
    insert(table, "Green", 123);
    insert(table, "White", 456);
    insert(table, "Golden", 789);
    insert(table, "nedloG", 321);
    printf("Green: %s\n", search(table, "Green") != -1 ? "already exists" : "inserted");
    printf("White: %s\n", search(table, "White") != -1 ? "already exists" : "inserted");
    printf("Golden: %s\n", search(table, "Golden") != -1 ? "already exists" : "inserted");
    printf("nedloG: %s\n", search(table, "nedloG") != -1 ? "already exists" : "inserted");
    printf("\n");

    // Search for keys again
    printf("Search Results:\n");
    printf("Blue: %s\n", search(table, "Blue") != -1 ? "found" : "not found");
    printf("nedloG: %s\n", search(table, "nedloG") != -1 ? "found" : "not found");
    printf("Yellow: %s\n", search(table, "Yellow") != -1 ? "found" : "not found");
    printf("Green: %s\n", search(table, "Green") != -1 ? "found" : "not found");
    printf("\n");

    // Print the final contents of the hash table
    printf("Final hash table:\n");
    printTable(table);

    return 0;
}
