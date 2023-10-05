#include <stdio.h>
#include <stdlib.h>


// Node structure
struct Node {
    int key;
    struct Node *left;
    struct Node *right;
};



// function to make a new node and assign an integer value to it
// argument: int data
// return: a pointer to the node
struct Node* newnode(int data)
{
    // dynamic memory allocation and check memory assignment
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    if(node == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    // node initialization
    node->key = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}


// function to traverse inorder
// when visiting a node, print its key
// argument: a pointer to a node
void print_inorder(struct Node *node) {
    if(node){
    print_inorder(node->left);
    printf("%d ", node->key);
    print_inorder(node->right);
    }
}

// function to traverse postorder
// when visiting a node, print its key
// argument: a pointer to a node
void print_postorder(struct Node *node) {
if (node){
    print_postorder(node->left);
    print_postorder(node->right);
    printf("%d ", node->key);
}
}

// function to traverse preorder
// when visiting a node, print its key
// argument: a pointer to a node
void print_preorder(struct Node *node) {
    if(node){
    printf("%d ", node->key);
    print_preorder(node->left);
    print_preorder(node->right);
    }
}

// function to free tree nodes allocated in memory
// using postorder traversal
void free_tree(struct Node *node)
{
    if(node) {
        free_tree(node->left);
        free_tree(node->right);
        printf("freed %d  ", node->key);
        free(node);
    }
}


int main() {

    // build a tree manually
    // the same tree as in p.24 of the lecture slides "1-trees.pdf"

    // level 1: root
    struct Node *root = newnode(100);
    
    // level 2
    root->left = newnode(75);
    root->right = newnode(150);

    // level 3
    root->left->left = newnode(50);
    root->left->right = newnode(90);

    root->right->left = newnode(120);
    root->right->right = newnode(490);

    // level 4
    root->right->right->left = newnode(160);

    // print inorder traversal
    printf("inorder : ");
    print_inorder(root);
    printf("\n");

    // print postorder traversal 
    printf("postorder : ");
    print_postorder(root);
    printf("\n");

    // print preorder traversal 
    printf("preorder : ");
    print_preorder(root);
    printf("\n");

    // free all tree nodes
    free_tree(root);
    printf("\n");

    return 0;
}