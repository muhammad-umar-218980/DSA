#include <iostream>
#include <queue>
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

    Node* search(Node* root, int key) {
        if (root == nullptr || root->data == key) {
            return root;
        }
        if (key < root->data) {
            return search(root->left, key);
        } else {
            return search(root->right, key);
        }
    }

    Node* findMin(Node* root) {
        if (root == nullptr) return nullptr;
        while (root->left != nullptr) {
            root = root->left;
        }
        return root;
    }

    Node* findMax(Node* root) {
        if (root == nullptr) return nullptr;
        while (root->right != nullptr) {
            root = root->right;
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

    void inorder(Node* root) {
        if (root == nullptr) return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    void preorder(Node* root) {
        if (root == nullptr) return;
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }

    void postorder(Node* root) {
        if (root == nullptr) return;
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }

    void levelOrder(Node* root) {
        if (root == nullptr) return;

        queue<Node*> q;
        q.push(root);
        q.push(nullptr);

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();

            if (curr == nullptr) {
                if (!q.empty()) {
                    cout << endl;
                    q.push(nullptr);
                    continue;
                } else {
                    break;
                }
            }

            cout << curr->data << " ";

            if (curr->left != nullptr) {
                q.push(curr->left);
            }
            if (curr->right != nullptr) {
                q.push(curr->right);
            }
        }
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

    cout << "\nInorder Traversal of BST: ";
    tree.inorder(tree.root);
    cout << endl;

    char choice;
    while (true) {
        cout << "\nDo you want to insert another element? (y/n): ";
        cin >> choice;

        if (choice == 'y' || choice == 'Y') {
            int val;
            cout << "Enter value to insert: ";
            cin >> val;
            tree.root = tree.insert(tree.root, val);
            cout << "Updated Inorder Traversal: ";
            tree.inorder(tree.root);
            cout << endl;
        } else if (choice == 'n' || choice == 'N') {
            break;
        } else {
            cout << "Invalid choice! Please enter y or n.\n";
        }
    }

    int key;
    cout << "\nEnter a value to search: ";
    cin >> key;
    Node* result = tree.search(tree.root, key);
    if (result != nullptr) {
        cout << key << " found in BST.\n";
    } else {
        cout << key << " not found in BST.\n";
    }

    cout << "\nEnter a value to delete: ";
    cin >> key;
    tree.root = tree.deleteNode(tree.root, key);
    cout << "Inorder after deletion: ";
    tree.inorder(tree.root);
    cout << endl;

    Node* minNode = tree.findMin(tree.root);
    Node* maxNode = tree.findMax(tree.root);
    if (minNode != nullptr) {
        cout << "\nMinimum value in BST: " << minNode->data << endl;
    }
    if (maxNode != nullptr) {
        cout << "Maximum value in BST: " << maxNode->data << endl;
    }

    cout << "\nPreorder: ";
    tree.preorder(tree.root);
    cout << "\nInorder: ";
    tree.inorder(tree.root);
    cout << "\nPostorder: ";
    tree.postorder(tree.root);
    cout << "\nLevel Order:\n";
    tree.levelOrder(tree.root);
    cout << endl;

    delete[] arr;
    return 0;
}
