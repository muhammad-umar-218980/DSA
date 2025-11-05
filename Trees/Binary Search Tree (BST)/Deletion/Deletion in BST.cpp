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
        if (value <= root->data) {
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

    Node* findMin(Node* root) {
        while (root != nullptr && root->left != nullptr) {
            root = root->left;
        }
        return root;
    }

    Node* deleteNode(Node* root, int key) {
        if (root == nullptr) {
            return nullptr;
        }

        if (key < root->data) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->data) {
            root->right = deleteNode(root->right, key);
        } else {
            // Case 1: No child
            if (root->left == nullptr && root->right == nullptr) {
                delete root;
                return nullptr;
            }
            // Case 2: One child
            else if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            // Case 3: Two children (replace with inorder successor)
            else {
                Node* successor = findMin(root->right);
                root->data = successor->data;
                root->right = deleteNode(root->right, successor->data);
            }
        }
        return root;
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

    int key;
    cout << "\nEnter a value to delete: ";
    cin >> key;
    root = tree.deleteNode(root, key);

    cout << "Inorder Traversal after deletion: ";
    tree.inorder(root);
    cout << endl;

    delete[] arr;
    return 0;
}
