#include <stdio.h>
#include <stdlib.h>

// Define the structure for the list
typedef struct {
    int *items;
    int capacity;
    int size;
} List;

// Function to initialize a new list
List* list_init(int capacity) {
    List* list = (List*)malloc(sizeof(List));
    list->items = (int*)malloc(capacity * sizeof(int));
    list->capacity = capacity;
    list->size = 0;
    return list;
}

// Function to append an item to the list
void list_append(List* list, int x) {
    if (list->size >= list->capacity) {
        // If the list is full, double its capacity
        list->capacity *= 2;
        list->items = (int*)realloc(list->items, list->capacity * sizeof(int));
    }
    list->items[list->size++] = x;
}

// Function to extend the list with items from an iterable
void list_extend(List* list, int* iterable, int iterable_size) {
    for (int i = 0; i < iterable_size; i++) {
        list_append(list, iterable[i]);
    }
}

// Function to insert an item at a specific index
void list_insert(List* list, int index, int x) {
    if (index < 0 || index > list->size) {
        printf("Index out of bounds\n");
        return;
    }
    if (list->size >= list->capacity) {
        // If the list is full, double its capacity
        list->capacity *= 2;
        list->items = (int*)realloc(list->items, list->capacity * sizeof(int));
    }
    for (int i = list->size; i > index; i--) {
        list->items[i] = list->items[i - 1];
    }
    list->items[index] = x;
    list->size++;
}

// Function to remove the first occurrence of an item from the list
void list_remove(List* list, int x) {
    int found = 0;
    for (int i = 0; i < list->size; i++) {
        if (list->items[i] == x) {
            found = 1;
            for (int j = i; j < list->size - 1; j++) {
                list->items[j] = list->items[j + 1];
            }
            list->size--;
            break;
        }
    }
    if (!found) {
        printf("Item not found\n");
    }
}

// Function to remove and return the item at the given index
int list_pop(List* list, int index) {
    if (index < 0 || index >= list->size) {
        printf("Index out of bounds\n");
        return -1; // Return a default value indicating failure
    }
    int popped = list->items[index];
    for (int i = index; i < list->size - 1; i++) {
        list->items[i] = list->items[i + 1];
    }
    list->size--;
    return popped;
}

// Function to clear all items from the list
void list_clear(List* list) {
    list->size = 0;
}

// Function to find the index of the first occurrence of an item
int list_index(List* list, int x) {
    for (int i = 0; i < list->size; i++) {
        if (list->items[i] == x) {
            return i;
        }
    }
    return -1; // Return -1 if item not found
}

// Function to count the occurrences of an item in the list
int list_count(List* list, int x) {
    int count = 0;
    for (int i = 0; i < list->size; i++) {
        if (list->items[i] == x) {
            count++;
        }
    }
    return count;
}

// Function to sort the list
void list_sort(List* list) {
    // Implementation of sorting algorithm (e.g., bubble sort, quicksort, etc.)
    // Not implemented in this example
    printf("Sorting not implemented\n");
}

// Function to reverse the list
void list_reverse(List* list) {
    int temp;
    for (int i = 0; i < list->size / 2; i++) {
        temp = list->items[i];
        list->items[i] = list->items[list->size - i - 1];
        list->items[list->size - i - 1] = temp;
    }
}

// Function to create a shallow copy of the list
List* list_copy(List* list) {
    List* copy = list_init(list->capacity);
    for (int i = 0; i < list->size; i++) {
        list_append(copy, list->items[i]);
    }
    return copy;
}

// Function to print the list
void list_print(List* list) {
    printf("[");
    for (int i = 0; i < list->size; i++) {
        printf("%d", list->items[i]);
        if (i < list->size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

// Function to free memory used by the list
void list_destroy(List* list) {
    free(list->items);
    free(list);
}

int main() {
    // Example usage
    List* mylist = list_init(5);
    
    list_append(mylist, 10);
    list_append(mylist, 20);
    list_append(mylist, 30);
    list_print(mylist);
    
    list_insert(mylist, 1, 15);
    list_print(mylist);
    
    list_remove(mylist, 20);
    list_print(mylist);
    
    int popped = list_pop(mylist, 2);
    printf("Popped: %d\n", popped);
    list_print(mylist);
    
    list_clear(mylist);
    list_print(mylist);
    
    list_destroy(mylist);
    
    return 0;
}
