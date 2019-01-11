/* Name: Anthony Cathers
 * Core Concept: use and create a Linked List in a C program.
 * Date Created: 11/20/2018
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct node {
    int checkNumber;
    char date[9], to[41], description[81]; //arrays one size larger to account for terminating char
    double amount;
    struct node *next;

} node;

//function prototypes
void clearInputBuffer();
void printNode(node *node);
int getUserChoice();
void deleteNode(node **, int);
void add(node **, node *);
void printAllNodes(node *);
void displayMenu();
node *searchToDelete(node *, node **, int);
node *search(node *, int);
void printNode(node *);
node *createCheck();


int main() {

    bool continueFlag = true;
    node *head = NULL;

    while (continueFlag) {
        displayMenu();

        switch (getUserChoice()) {
            case 1: {
                add(&head, createCheck());
                break;
            }
            case 2: {
                printf("\nEnter a value to delete: ");
                int value;
                scanf("%d", &value);
                deleteNode(&head, value);
                break;
            }
            case 3: {
                printf("\nEnter a value to search for: ");
                int value;
                scanf("%d", &value);
                printNode(search(head, value));
                break;
            }
            case 4: {
                printAllNodes(head);
                break;
            }
            case 5: {
                continueFlag = false;
                break;
            }
            default: {
                printf("Invalid selection, try again\n");
            }
        }
    }

    return 0;

}

node *createCheck() {
    node *checkNode = (node *) malloc(sizeof(node));

    if (checkNode == NULL) {
        printf("Error creating a new node.\n");
        exit(0);
    }

    printf("Enter a cheque number: ");
    scanf("%3d", &checkNode->checkNumber);
    clearInputBuffer();

    printf("Enter date (ddmmyyyy): ");
    scanf("%8s", checkNode->date);
    clearInputBuffer();

    printf("Enter recipient: ");
    scanf("%40s", checkNode->to);
    clearInputBuffer();

    do {
        printf("Enter amount: ");
        scanf("%lf", &checkNode->amount);
        clearInputBuffer();

    } while (checkNode->amount < 0);

    printf("Enter cheque description: ");
    scanf("%80s", checkNode->description);
    clearInputBuffer();

    checkNode->next = NULL;

    return checkNode;
}

void add(node **head, node *node) {

    if (*head == NULL) {
        *head = malloc(sizeof(node));
        *head = node;
        node->next = NULL;

    } else {
        struct node *currentNode = *head;
        while (currentNode->next != NULL) {
            currentNode = currentNode->next;
        }
        currentNode->next = node;
    }

}

void printAllNodes(node *head) {
    node *currentNode = head;

    while (NULL != currentNode) {
        printNode(currentNode);
        currentNode = currentNode->next;

        printf("press any key to continue");
        getchar();
    }
}

void displayMenu() {
    printf("\n1. Add Check\n");
    printf("2. Delete Check\n");
    printf("3. View Single Check\n");
    printf("4. View Checkbook\n");
    printf("5. Exit\n");
}

void clearInputBuffer() {
    while ((getchar()) != '\n');
}

int getUserChoice() {
    int choice;

    printf("Enter your choice: ");
    scanf("%d", &choice);
    clearInputBuffer();

    return choice;
}

node *search(node *head, int checkNumber) {
    node *current = head;  // set current to head

    while (current != NULL) { //loop while current != NULL (end of list)
        if (current->checkNumber == checkNumber) {
            return current;
        }
        current = current->next;
    }
    return current;

}

node *searchToDelete(node *head, node **previous, int checkNumber) {
    node *current = head;  // set current to head

    while (current != NULL) { //loop while current != NULL (end of list)
        if (current->checkNumber == checkNumber) {
            return current;
        }
        *previous = current;
        current = current->next;
    }
    return current;
}

void deleteNode(node **head, int checkNumber) {
    node *headNode = *head;

    node *previousNode = NULL;
    node *del = NULL;
    del = searchToDelete(headNode, &previousNode, checkNumber);

    if (del == NULL) { // case where not found
        printf("\nNot found, can't delete\n");
        return;
    }

    if (previousNode == NULL && del->checkNumber == checkNumber) { // case head is the node to be deleted
        *head = del->next;   // Changed head
        free(del);               // free old head
        return;
    }

    if (del->next == NULL && del->checkNumber == checkNumber) { // case tail is the node to be deleted
        previousNode->next = NULL; //unlink
        free(del);
        return;
    }

    previousNode->next = del->next; //delete case where has before and after node

    free(del);  // Free memory
}

void printNode(node *node) {

    if (node != NULL) {
        printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("Cheque Number: %i\n", node->checkNumber);
        printf("Date: %s\n", node->date);
        printf("To: %s\n", node->to);
        printf("Amount: $%.2f\n", node->amount);
        printf("Description: %s\n", node->description);
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    }
}

