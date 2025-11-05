#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node* parent;

    Node(int data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
    }
};

class MaxHeap {
public:
    Node* root = nullptr;

    void insert(int value) {
        Node* newNode = new Node(value);

        if (root == nullptr) {
            root = newNode;
            return;
        }

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();

            if (curr->left == nullptr) {
                curr->left = newNode;
                newNode->parent = curr;
                break;
            } else {
                q.push(curr->left);
            }

            if (curr->right == nullptr) {
                curr->right = newNode;
                newNode->parent = curr;
                break;
            } else {
                q.push(curr->right);
            }
        }

        heapifyUp(newNode);
    }

    void heapifyUp(Node* node) {
        while (node->parent != nullptr && node->data > node->parent->data) {
            swap(node->data, node->parent->data);
            node = node->parent;
        }
    }

    Node* getLastNode() {
        if (root == nullptr) return nullptr;

        queue<Node*> q;
        q.push(root);
        Node* curr = nullptr;

        while (!q.empty()) {
            curr = q.front();
            q.pop();

            if (curr->left != nullptr) q.push(curr->left);
            if (curr->right != nullptr) q.push(curr->right);
        }

        return curr;
    }

    void heapifyDown(Node* node) {
        if (node == nullptr) return;

        Node* largest = node;

        if (node->left != nullptr && node->left->data > largest->data) {
            largest = node->left;
        }

        if (node->right != nullptr && node->right->data > largest->data) {
            largest = node->right;
        }

        if (largest != node) {
            swap(node->data, largest->data);
            heapifyDown(largest);
        }
    }

    int extractMax() {
        if (root == nullptr) return -1;

        int maxVal = root->data;
        Node* lastNode = getLastNode();

        if (lastNode == root) {
            delete root;
            root = nullptr;
            return maxVal;
        }

        root->data = lastNode->data;

        if (lastNode->parent->left == lastNode) {
            lastNode->parent->left = nullptr;
        } else {
            lastNode->parent->right = nullptr;
        }

        delete lastNode;
        heapifyDown(root);

        return maxVal;
    }

    void buildFromArray(int arr[], int n) {
        for (int i = 0; i < n; i++) {
            insert(arr[i]);
        }
    }
};


void HeapSort_1(int arr[], int size) {
    MaxHeap h;
    h.buildFromArray(arr, size);
    for (int i = size - 1; i >= 0; i--) {
        arr[i] = h.extractMax();
    }
}

void HeapSort_2(int arr[], int size) {
    MaxHeap h;
    h.buildFromArray(arr, size);
    for (int i = size - 1; i >= 0; i--) {
        arr[i] = h.extractMax();
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int size1, size2;

    cout << "Enter size of first array: ";
    cin >> size1;
    int* arr1 = new int[size1];
    cout << "\n\nEnter elements of first array\n\n";
    for (int i = 0; i < size1; i++) {
        cout << "Element " << i + 1 << " : ";
        cin >> arr1[i];
    }

    cout << "\nEnter size of second array: ";
    cin >> size2;
    int* arr2 = new int[size2];
    cout << "\n\nEnter elements of second array\n\n";
    for (int i = 0; i < size2; i++) {
        cout << "Element " << i + 1 << " : ";
        cin >> arr2[i];
    }

    HeapSort_1(arr1, size1);
    HeapSort_2(arr2, size2);

    cout << "\n\nSorted array using HeapSort_1 (ascending): ";
    printArray(arr1, size1);

    cout << "\n\nSorted array using HeapSort_2 (ascending): ";
    printArray(arr2, size2);

    delete[] arr1;
    delete[] arr2;

    return 0;
}
