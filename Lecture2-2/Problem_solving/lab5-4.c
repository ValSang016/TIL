#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct for each node
struct Node {
    char key[100];
    struct Node* next;
};

int main() {
    // Define an array of 5 structs
    struct Node nodes[5];

    // Store strings as keys in each node
    strcpy(nodes[0].key, "Node 1");
    strcpy(nodes[1].key, "Node 2");
    strcpy(nodes[2].key, "Node 3");
    strcpy(nodes[3].key, "Node 4");
    strcpy(nodes[4].key, "Node 5");

    // Link the nodes together
    for (int i = 0; i < 4; i++) {
        nodes[i].next = &nodes[i + 1];
    }
    
  	nodes[4].next = NULL;

  	// Print the linked list
  	struct Node* current = &nodes[0];
  	while (current != NULL) {
      	// printf("Key: %s\n", current->key);
        puts(current -> key);
      	current = current->next;
  	}

  	return 0;
}
