/* Name: Anthony Cathers
 * Core Concept: use and create a BST in a C program.
 * Date Created: 11/21/2018
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Node {
    int value;
    struct Node *left;
    struct Node *right;
} Node;


//function prototypes
Node *createNode(int);

void displayMenu();

void addNode(Node **, int);

bool searchTree(Node *, int);

void printPreorder(Node *);

int main() {

    int choice;
    Node *root = NULL; //create pointer for root node

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int value;
                printf("\nEnter a number to add: ");
                scanf("%d", &value);
                addNode(&root, value);
                break;
            }
            case 2: {
                printf("\nTree: ");
                printPreorder(root);
                printf("\n");
                break;
            }

            case 3: {
                int value;
                printf("\nEnter a integer to search for: ");
                scanf("%d", &value);
                printf(searchTree(root, value) ? "\nfound\n" : "\nNot found\n");
                break;
            }

            default: {
                printf("\nInvalid selection, try again\n");
            }

        }

    } while (choice != 4);

    return 0;
}

void displayMenu() {
    printf("\n1. Add integer to tree");
    printf("\n2. Print tree(pre-order)");
    printf("\n3. Search tree");
    printf("\n4. Exit");
    printf("\nSelection: ");

}

Node *createNode(int value) {
    Node *newNode = (Node *) malloc(sizeof(Node)); //allocate memory for node

    if (newNode == NULL) {
        printf("Error creating a new node.");
        exit(0);
    }

    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

void addNode(Node **root, int value) {

    if (*root == NULL) {  //if root is null, create root
        *root = createNode(value);
        return;
    }

    Node **currentNode = root; //assign the root node to currentNode using pointer to pointer
    while (*currentNode != NULL) {
        if (value > (*currentNode)->value) {  //if it's greater than the value, go right
            currentNode = &(*currentNode)->right; //set current node to memory address of dereferenced pointers right value
        } else {                                     //go left
            currentNode = &(*currentNode)->left; //set current node to memory address of dereferenced pointers left value
        }
    }
    *currentNode = createNode(value);  // create node in correct position
}

bool searchTree(Node *node, int value) {

    if (node == NULL) { // empty tree or end of tree
        return false;
    }

    if (node->value == value) { // if found return true;
        return true;
    }

    if (value <
        node->value) { // only search the part of the tree needed (previously had it where no return encountered.)
        return searchTree(node->left, value); //traverse left
    } else {
        return searchTree(node->right, value); //traverse right
    }


}

void printPreorder(Node *node) {
    if (node == NULL) {  //return if null
        return;
    }
    printf("%d ", node->value); //print root node
    printPreorder(node->left); //traverse left side
    printPreorder(node->right); //traverse right side
}