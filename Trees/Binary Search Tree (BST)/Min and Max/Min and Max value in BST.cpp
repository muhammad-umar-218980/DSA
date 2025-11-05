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

	cout << "Inorder Traversal of BST: ";
	tree.inorder(tree.root);
	cout << endl;

	Node* minNode = tree.findMin(tree.root);
	Node* maxNode = tree.findMax(tree.root);

	if (minNode != nullptr) {
		cout << "\nMinimum value in BST: " << minNode->data;
	} else {
		cout << "\nBST is empty. No minimum value.";
	}

	if (maxNode != nullptr) {
		cout << "\nMaximum value in BST: " << maxNode->data << endl;
	} else {
		cout << "\nBST is empty. No maximum value.";
	}


	delete[] arr;

	return 0;
}
