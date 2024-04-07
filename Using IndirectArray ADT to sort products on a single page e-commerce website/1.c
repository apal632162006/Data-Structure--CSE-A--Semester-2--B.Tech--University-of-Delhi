#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Product ADT
typedef struct {
    char category[50];
    char name[50];
    char seller[50];
    double price;
    int rating;
} Product;

// IndirectArray ADT
typedef struct {
    int* indices;
    int size;
} IndirectArray;

// Function prototypes
IndirectArray createIndirectArray(int size);
void sortProductsByCategory(IndirectArray indices, Product products[], int size);
void sortProductsByName(IndirectArray indices, Product products[], int size);
void sortProductsBySeller(IndirectArray indices, Product products[], int size);
void sortProductsByPrice(IndirectArray indices, Product products[], int size);
void sortProductsByRating(IndirectArray indices, Product products[], int size);
Product getProductAtIndex(int index, IndirectArray indices, Product products[], int size);

int main() {
    // Sample product data
    Product products[5] = {
        {"Electronics", "Laptop", "ABC Electronics", 1200.0, 4},
        {"Clothing", "T-Shirt", "XYZ Fashion", 25.0, 5},
        {"Electronics", "Smartphone", "PQR Tech", 800.0, 4},
        {"Books", "Python Programming", "Tech Books", 40.0, 4},
        {"Home & Kitchen", "Coffee Maker", "Home Essentials", 50.0, 3}
    };

    // Initialize IndirectArray
    IndirectArray indices = createIndirectArray(5);

    // Sort products by category
    sortProductsByCategory(indices, products, 5);

    // Retrieve and print sorted products
    printf("Sorted products by category:\n");
    for (int i = 0; i < 5; i++) {
        Product sortedProduct = getProductAtIndex(i, indices, products, 5);
        printf("%s, %s, %s, %.2f, %d\n", sortedProduct.category, sortedProduct.name, sortedProduct.seller, sortedProduct.price, sortedProduct.rating);
    }

    // Free memory
    free(indices.indices);

    return 0;
}

IndirectArray createIndirectArray(int size) {
    IndirectArray array;
    array.indices = (int*)malloc(size * sizeof(int));
    array.size = size;
    return array;
}

void sortProductsByCategory(IndirectArray indices, Product products[], int size) {
    // Implement sorting by category
    // For demonstration, let's assume a simple bubble sort
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (strcmp(products[indices.indices[j]].category, products[indices.indices[j + 1]].category) > 0) {
                // Swap indices
                int temp = indices.indices[j];
                indices.indices[j] = indices.indices[j + 1];
                indices.indices[j + 1] = temp;
            }
        }
    }
}

Product getProductAtIndex(int index, IndirectArray indices, Product products[], int size) {
    return products[indices.indices[index]];
}