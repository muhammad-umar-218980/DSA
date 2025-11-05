#include <iostream>
using namespace std;

class Node {
public:
    char data;
    Node* left;
    Node* right;
    Node* parent;

    Node(char data, Node* parent = nullptr) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
        this->parent = parent;
    }
};

class BinaryTree {
public:
    Node* root = nullptr;

    BinaryTree(char data) {
        root = new Node(data);
        cout << data << " inserted as ROOT" << endl;
    }

    void insertNode(char data, Node* parent, char pos) {
        if (parent == nullptr) {
            cout << "Invalid parent!" << endl;
            return;
        }

        if (pos == 'l' || pos == 'L') {
            if (parent->left != nullptr) {
                cout << "Left child already exists!" << endl;
                return;
            }
            parent->left = new Node(data, parent);
            cout << data << " inserted as LEFT child of " << parent->data << endl;
        } 
        else if (pos == 'r' || pos == 'R') {
            if (parent->right != nullptr) {
                cout << "Right child already exists!" << endl;
                return;
            }
            parent->right = new Node(data, parent);
            cout << data << " inserted as RIGHT child of " << parent->data << endl;
        } 
        else {
            cout << "Invalid position for child element!" << endl;
            return;
        }
    }
};

int main() {
    BinaryTree bt('A');
    bt.insertNode('B', bt.root, 'L');
    bt.insertNode('C', bt.root, 'R');
    bt.insertNode('D', bt.root->left, 'L');
    bt.insertNode('E', bt.root->left, 'R');
    bt.insertNode('X', nullptr, 'L');
    return 0;
}
