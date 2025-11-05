#include <iostream>
using namespace std;

class BinaryTree {
private:
    int* arr;
    int SIZE;

public:
    BinaryTree(int size) {
        SIZE = size;
        arr = new int[SIZE + 1];
        for (int i = 0; i <= SIZE; i++)
            arr[i] = -1;
    }

    void insertRoot(int value) {
        arr[1] = value;
        cout << value << " inserted as ROOT\n";
    }

    void insert(int value, int parent, char place) {
        int pos;
        if (place == 'L' || place == 'l')
            pos = parent * 2;
        else
            pos = parent * 2 + 1;

        if (pos > SIZE) {
            cout << "Overflow! Cannot insert.\n";
            return;
        }

        if (arr[parent] == -1) {
            cout << "Parent not found, cannot insert.\n";
            return;
        }

        arr[pos] = value;
        cout << value << " inserted at index " << pos << "\n";
    }

    void insertLeft(int value, int parent) {
        int pos = parent * 2;

        if (pos > SIZE) {
            cout << "Overflow! Cannot insert LEFT.\n";
            return;
        }

        if (arr[parent] == -1) {
            cout << "Parent not found, cannot insert LEFT.\n";
            return;
        }

        arr[pos] = value;
        cout << value << " inserted LEFT of parent index " << parent << "\n";
    }

    void insertRight(int value, int parent) {
        int pos = parent * 2 + 1;

        if (pos > SIZE) {
            cout << "Overflow! Cannot insert RIGHT.\n";
            return;
        }

        if (arr[parent] == -1) {
            cout << "Parent not found, cannot insert RIGHT.\n";
            return;
        }

        arr[pos] = value;
        cout << value << " inserted RIGHT of parent index " << parent << "\n";
    }

    void insertFunc(int value, int parent, char place) {
        if (place == 'L' || place == 'l')
            insertLeft(value, parent);
        else if (place == 'R' || place == 'r')
            insertRight(value, parent);
        else
            cout << "Invalid place! Use L or R.\n";
    }

    int search(int value) {
        for (int i = 1; i <= SIZE; i++) {
            if (arr[i] == value)
                return i;
        }
        return -1;
    }

    int getParent(int value) {
        if (arr[1] == value) {
            cout << value << " is ROOT, it has no parent.\n";
            return -1;
        }

        for (int i = 2; i <= SIZE; i++) {
            if (arr[i] == value) {
                cout << "Parent of " << value << " is " << arr[i / 2] << endl;
                return arr[i / 2];
            }
        }

        cout << "Value not found in tree.\n";
        return -1;
    }

    int getLeftChild(int value) {
        int index = search(value);
        if (index == -1) {
            cout << "Value not found in tree.\n";
            return -1;
        }

        int leftIndex = index * 2;
        if (leftIndex > SIZE || arr[leftIndex] == -1) {
            cout << "Left child of " << value << " doesn't exist.\n";
            return -1;
        }

        cout << "Left child of " << value << " is " << arr[leftIndex] << endl;
        return arr[leftIndex];
    }

    int getRightChild(int value) {
        int index = search(value);
        if (index == -1) {
            cout << "Value not found in tree.\n";
            return -1;
        }

        int rightIndex = index * 2 + 1;
        if (rightIndex > SIZE || arr[rightIndex] == -1) {
            cout << "Right child of " << value << " doesn't exist.\n";
            return -1;
        }

        cout << "Right child of " << value << " is " << arr[rightIndex] << endl;
        return arr[rightIndex];
    }

    void printTree() {
        for (int i = 1; i <= SIZE; i++)
            cout << i << ":" << arr[i] << "  ";
        cout << "\n";
    }
};

int main() {
    BinaryTree bt(50);

    bt.insertRoot(10);

    bt.insertFunc(20, 1, 'L');
    bt.insertFunc(30, 1, 'R');
    bt.insertFunc(40, 2, 'L');

    bt.printTree();

    bt.getParent(40);
    bt.getLeftChild(10);
    bt.getRightChild(10);

    return 0;
}
