#include <iostream>
#include <vector>

using namespace std;

class SparseMatrix {
private:
    vector<vector<int>> data; // Stores non-zero elements
    int rows;
    int cols;

public:
    SparseMatrix(int numRows, int numCols) : rows(numRows), cols(numCols) {
        // Initialize the sparse matrix with zeros
        for (int i = 0; i < rows; ++i) {
            vector<int> row(numCols, 0);
            data.push_back(row);
        }
    }

    // Set value at specified position
    void setValue(int row, int col, int value) {
        if (row >= 0 && row < rows && col >= 0 && col < cols) {
            data[row][col] = value;
        } else {
            cout << "Invalid position" << endl;
        }
    }

    // Get value at specified position
    int getValue(int row, int col) const {
        if (row >= 0 && row < rows && col >= 0 && col < cols) {
            return data[row][col];
        } else {
            cout << "Invalid position" << endl;
            return -1; // Return some error value
        }
    }

    // Display the sparse matrix
    void display() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    SparseMatrix sparseMatrix(5, 5);
    
    sparseMatrix.setValue(0, 0, 1);
    sparseMatrix.setValue(1, 1, 2);
    sparseMatrix.setValue(2, 2, 3);
    sparseMatrix.setValue(3, 3, 4);
    sparseMatrix.setValue(4, 4, 5);

    sparseMatrix.display();

    return 0;
}