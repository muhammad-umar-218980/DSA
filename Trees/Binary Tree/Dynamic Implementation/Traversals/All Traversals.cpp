#include <iostream>
using namespace std;

/*
	Name : Muhammad Umar
	Class : CSIT Section A Batch 24
	Roll no. : CT - 24028
*/

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

		Node* findNode(Node* root, char key) {
			if (root == nullptr) return nullptr;
			if (root->data == key) return root;
			Node* leftSearch = findNode(root->left, key);
			if (leftSearch != nullptr) return leftSearch;
			return findNode(root->right, key);
		}

		void deleteNode(Node* root, char key) {
			if (root == nullptr) {
				cout << "Tree is empty!" << endl;
				return;
			}

			Node* deletedNode = findNode(root, key);
			if (deletedNode == nullptr) {
				cout << "Node not found!" << endl;
				return;
			}

			// Case 1: Only one node (root only)
			if (deletedNode->left == nullptr && deletedNode->right == nullptr && deletedNode->parent == nullptr) {
				delete deletedNode;
				this->root = nullptr;
				cout << "Tree is now empty!" << endl;
				return;
			}

			// Case 2: Leaf node
			else if (deletedNode->left == nullptr && deletedNode->right == nullptr) {
				if (deletedNode->parent->left == deletedNode) {
					deletedNode->parent->left = nullptr;
				} else {
					deletedNode->parent->right = nullptr;
				}
				delete deletedNode;
				cout << key << " deleted (leaf node)" << endl;
				return;
			}

			// Case 3: One child
			else if ((deletedNode->left != nullptr && deletedNode->right == nullptr) || (deletedNode->left == nullptr && deletedNode->right != nullptr)) {
				Node* child;
				if (deletedNode->left != nullptr) child = deletedNode->left;
				else child = deletedNode->right;

				if (deletedNode->parent != nullptr) {
					if (deletedNode->parent->left == deletedNode) {
						deletedNode->parent->left = child;
					} else {
						deletedNode->parent->right = child;
					}
					child->parent = deletedNode->parent;
				} 
				else {
					this->root = child;
					child->parent = nullptr;
				}

				delete deletedNode;
				cout << key << " deleted (one child)" << endl;
				return;
			}

			// Case 4: Two children
			else if (deletedNode->left != nullptr && deletedNode->right != nullptr) {
				Node* leftChild = deletedNode->left;
				Node* rightChild = deletedNode->right;

				if (deletedNode->parent != nullptr) {
					if (deletedNode->parent->left == deletedNode) {
						deletedNode->parent->left = leftChild;
					} else {
						deletedNode->parent->right = leftChild;
					}
					leftChild->parent = deletedNode->parent;
				} 
				else {
					this->root = leftChild;
					leftChild->parent = nullptr;
				}

				Node* temp = leftChild;
				while (temp->right != nullptr) {
					temp = temp->right;
				}

				temp->right = rightChild;
				rightChild->parent = temp;

				delete deletedNode;
				cout << key << " deleted (two children)" << endl;
				return;
			}
		}

		void preOrder(Node* root) {
			if (root == nullptr) return;
			cout << root->data << " ";
			preOrder(root->left);
			preOrder(root->right);
		}

		void inOrder(Node* root) {
			if (root == nullptr) return;
			inOrder(root->left);
			cout << root->data << " ";
			inOrder(root->right);
		}

		void postOrder(Node* root) {
			if (root == nullptr) return;
			postOrder(root->left);
			postOrder(root->right);
			cout << root->data << " ";
		}
};

int main() {
	BinaryTree bt('A');
	bt.insertNode('B', bt.root, 'L');
	bt.insertNode('C', bt.root, 'R');
	bt.insertNode('D', bt.root->left, 'L');
	bt.insertNode('E', bt.root->left, 'R');

	cout << "\n\nBefore deletion:\n";
	cout << "Preorder: "; bt.preOrder(bt.root);
	cout << "\nInorder: "; bt.inOrder(bt.root);
	cout << "\nPostorder: "; bt.postOrder(bt.root);
	cout << "\n\n";

	bt.deleteNode(bt.root, 'E'); // leaf node
	bt.deleteNode(bt.root, 'B'); // one child
	bt.deleteNode(bt.root, 'A'); // two children

	cout << "\nAfter deletion:\n";
	cout << "Preorder: "; bt.preOrder(bt.root);
	cout << "\nInorder: "; bt.inOrder(bt.root);
	cout << "\nPostorder: "; bt.postOrder(bt.root);
	cout << "\n\n";

	return 0;
}
