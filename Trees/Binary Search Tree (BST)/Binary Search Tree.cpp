#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

class BST {
public:
    Node* root = nullptr;

    BST(int* arr, int n) {
        root = buildFromArray(arr, n);
    }

    Node* insert(Node* root, int value) {
        if (root == nullptr) {
            return new Node(value);
        }
        if (value < root->data) {
            root->left = insert(root->left, value);
        } else if (value > root->data) {
            root->right = insert(root->right, value);
        }
        return root;
    }

    Node* buildFromArray(int* arr, int n) {
        for (int i = 0; i < n; i++) {
            root = insert(root, arr[i]);
        }
        return root;
    }

    void inorder(Node* root) {
        if (root == nullptr) return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
};

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int* arr = new int[size];
    cout << "Enter " << size << " elements \n\n";
    for (int i = 0; i < size; i++) {
    	cout << "\nEnter element " << i+1 << " : ";
        cin >> arr[i];
    }

    BST tree(arr, size);
    
    Node* root = tree.root;

    cout << "Inorder Traversal of BST: ";
    tree.inorder(root);
    cout << endl;

    delete[] arr;

    return 0;
}
