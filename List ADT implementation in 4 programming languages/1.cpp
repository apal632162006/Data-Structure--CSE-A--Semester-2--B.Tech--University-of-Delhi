#include <iostream>
using namespace std;

template <class T>
class List {
private:
    struct Node {
        T data;
        Node* next;
        Node(T val) : data(val), next(nullptr) {}
        ~Node() { delete next; } // Deallocate memory recursively
    };

    Node* head;

public:
    List() : head(nullptr) {}

    ~List() { delete head; } // Destructor to deallocate memory

    void insert(T val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};