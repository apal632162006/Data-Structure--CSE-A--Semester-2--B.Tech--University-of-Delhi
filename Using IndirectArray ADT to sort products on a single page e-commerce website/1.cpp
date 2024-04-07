#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// Product ADT
struct Product {
    string category;
    string name;
    string seller;
    double price;
    int rating;
};

// IndirectArray ADT
struct IndirectArray {
    vector<int> indices;
};

// Function prototypes
IndirectArray createIndirectArray(int size);
void sortProductsByCategory(IndirectArray& indices, vector<Product>& products);
void sortProductsByName(IndirectArray& indices, vector<Product>& products);
void sortProductsBySeller(IndirectArray& indices, vector<Product>& products);
void sortProductsByPrice(IndirectArray& indices, vector<Product>& products);
void sortProductsByRating(IndirectArray& indices, vector<Product>& products);
Product getProductAtIndex(int index, IndirectArray& indices, vector<Product>& products);

int main() {
    // Sample product data
    vector<Product> products = {
        {"Electronics", "Laptop", "ABC Electronics", 1200.0, 4},
        {"Clothing", "T-Shirt", "XYZ Fashion", 25.0, 5},
        {"Electronics", "Smartphone", "PQR Tech", 800.0, 4},
        {"Books", "Python Programming", "Tech Books", 40.0, 4},
        {"Home & Kitchen", "Coffee Maker", "Home Essentials", 50.0, 3}
    };

    // Initialize IndirectArray
    IndirectArray indices = createIndirectArray(products.size());

    // Sort products by category
    sortProductsByCategory(indices, products);

    // Retrieve and print sorted products
    cout << "Sorted products by category:" << endl;
    for (int i = 0; i < products.size(); i++) {
        Product sortedProduct = getProductAtIndex(i, indices, products);
        cout << sortedProduct.category << ", " << sortedProduct.name << ", " << sortedProduct.seller << ", " << sortedProduct.price << ", " << sortedProduct.rating << endl;
    }

    return 0;
}

IndirectArray createIndirectArray(int size) {
    IndirectArray array;
    array.indices.resize(size);
    for (int i = 0; i < size; i++) {
        array.indices[i] = i;
    }
    return array;
}

void sortProductsByCategory(IndirectArray& indices, vector<Product>& products) {
    // Implement sorting by category
    // For demonstration, let's use std::sort with a custom comparator
    sort(indices.indices.begin(), indices.indices.end(), [&products](int a, int b) {
        return products[a].category < products[b].category;
    });
}

Product getProductAtIndex(int index, IndirectArray& indices, vector<Product>& products) {
    return products[indices.indices[index]];
}