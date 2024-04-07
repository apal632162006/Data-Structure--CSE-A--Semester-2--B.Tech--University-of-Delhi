#include <stdio.h>
#include <stdlib.h>

// Node structure for a single element in the list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// List structure to hold the head of the list
typedef struct {
    Node* head;
    int size;
} List;

// Function to initialize a new list
List* createList() {
    List* newList = (List*)malloc(sizeof(List));
    if (newList == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newList->head = NULL;
    newList->size = 0;
    return newList;
}

// Function to add an element to the end of the list
void append(List* list, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Node* temp = list->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    list->size++;
}

// Function to print the elements of the list
void printList(List* list) {
    Node* temp = list->head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to delete the list and free memory
void destroyList(List* list) {
    Node* current = list->head;
    Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    free(list);
}

int main() {
    List* myList = createList();

    // Adding elements to the list
    append(myList, 10);
    append(myList, 20);
    append(myList, 30);
    append(myList, 40);

    // Printing the elements of the list
    printf("List elements: ");
    printList(myList);

    // Freeing memory allocated for the list
    destroyList(myList);

    return 0;
}