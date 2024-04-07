#include <stdio.h>
#include <stdlib.h>

// Node structure to represent non-zero elements
struct Node {
    int row;
    int col;
    int value;
    struct Node* next;
};

// Sparse Matrix structure
struct SparseMatrix {
    int rows;
    int cols;
    struct Node** data;
};

// Function to create a new node
struct Node* createNode(int row, int col, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->row = row;
    newNode->col = col;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Function to create a new sparse matrix
struct SparseMatrix* createSparseMatrix(int rows, int cols) {
    struct SparseMatrix* matrix = (struct SparseMatrix*)malloc(sizeof(struct SparseMatrix));
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->data = (struct Node**)malloc(rows * sizeof(struct Node*));
    for (int i = 0; i < rows; i++)
        matrix->data[i] = NULL;
    return matrix;
}

// Function to insert a value into the sparse matrix
void insert(struct SparseMatrix* matrix, int row, int col, int value) {
    if (row >= matrix->rows || col >= matrix->cols) {
        printf("Invalid row or column index.\n");
        return;
    }
    struct Node* newNode = createNode(row, col, value);
    if (matrix->data[row] == NULL || matrix->data[row]->col > col) {
        newNode->next = matrix->data[row];
        matrix->data[row] = newNode;
    } else {
        struct Node* current = matrix->data[row];
        while (current->next != NULL && current->next->col < col)
            current = current->next;
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Function to display the sparse matrix
void display(struct SparseMatrix* matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        struct Node* current = matrix->data[i];
        for (int j = 0; j < matrix->cols; j++) {
            if (current != NULL && current->col == j) {
                printf("%d ", current->value);
                current = current->next;
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

// Main function for testing
int main() {
    struct SparseMatrix* matrix = createSparseMatrix(4, 5);
    insert(matrix, 0, 1, 10);
    insert(matrix, 0, 3, 20);
    insert(matrix, 1, 2, 30);
    insert(matrix, 2, 3, 40);
    insert(matrix, 3, 4, 50);
    display(matrix);

    return 0;
}