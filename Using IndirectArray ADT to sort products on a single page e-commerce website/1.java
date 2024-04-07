import java.util.Arrays;

// Product class
class Product {
    String category;
    String name;
    String seller;
    double price;
    int rating;

    public Product(String category, String name, String seller, double price, int rating) {
        this.category = category;
        this.name = name;
        this.seller = seller;
        this.price = price;
        this.rating = rating;
    }
}

// IndirectArray class
class IndirectArray {
    int[] indices;

    public IndirectArray(int size) {
        this.indices = new int[size];
        for (int i = 0; i < size; i++) {
            this.indices[i] = i;
        }
    }
}

public class Main {
    public static void main(String[] args) {
        // Sample product data
        Product[] products = {
            new Product("Electronics", "Laptop", "ABC Electronics", 1200.0,