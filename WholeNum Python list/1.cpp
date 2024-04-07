#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class PythonList {
private:
    vector<int> data;

public:
    void append(int x) {
        data.push_back(x);
    }

    void extend(vector<int>& iterable) {
        data.insert(data.end(), iterable.begin(), iterable.end());
    }

    void insert(int i, int x) {
        if (i >= 0 && i <= data.size()) {
            data.insert(data.begin() + i, x);
        } else {
            cout << "Index out of range" << endl;
        }
    }

    void remove(int x) {
        auto it = find(data.begin(), data.end(), x);
        if (it != data.end()) {
            data.erase(it);
        } else {
            cout << "Element not found" << endl;
        }
    }

    int pop(int i = -1) {
        if (data.empty()) {
            cout << "List is empty" << endl;
            return -1; // Returning a sentinel value
        }

        if (i == -1) {
            i = data.size() - 1;
        }

        if (i >= 0 && i < data.size()) {
            int val = data[i];
            data.erase(data.begin() + i);
            return val;
        } else {
            cout << "Index out of range" << endl;
            return -1; // Returning a sentinel value
        }
    }

    void clear() {
        data.clear();
    }

    int index(int x, int start = 0, int end = -1) {
        if (end == -1) {
            end = data.size();
        }

        for (int i = start; i < end; ++i) {
            if (data[i] == x) {
                return i;
            }
        }
        return -1; // If element not found
    }

    int count(int x) {
        return count_if(data.begin(), data.end(), [x](int num) { return num == x; });
    }

    void sort(bool reverse = false) {
        if (!reverse) {
            std::sort(data.begin(), data.end());
        } else {
            std::sort(data.begin(), data.end(), greater<int>());
        }
    }

    void reverse() {
        std::reverse(data.begin(), data.end());
    }

    PythonList copy() {
        PythonList copiedList;
        copiedList.data = data;
        return copiedList;
    }

    void display() {
        for (int num : data) {
            cout << num << " ";
        }
        cout << endl;
    }
};

int main() {
    PythonList myList;
    myList.append(1);
    myList.append(2);
    myList.append(3);
    myList.display(); // Output: 1 2 3

    vector<int> extension = {4, 5};
    myList.extend(extension);
    myList.display(); // Output: 1 2 3 4 5

    myList.insert(2, 6);
    myList.display(); // Output: 1 2 6 3 4 5

    myList.remove(3);
    myList.display(); // Output: 1 2 6 4 5

    myList.pop();
    myList.display(); // Output: 1 2 6 4

    myList.clear();
    myList.display(); // Output:

    return 0;
}
