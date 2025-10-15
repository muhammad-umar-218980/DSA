#include <iostream>
#include <string>
using namespace std;

/*
    ------------------------------------------------------------
                     BINARY TREE (Array Implementation)
    ------------------------------------------------------------

    Static implementation of a Binary Tree using a normal array.

    Relationships between indices:
        LeftChild(k)  = 2 * k
        RightChild(k) = 2 * k + 1
        Parent(k)     = floor(k / 2)

    - Indexing starts from 1 (Root is at index 1)
    - "null" (represented by "-") indicates absence of a node.
*/

int main() {

    string tree[] = { "-", "A", "B", "C", "D", "E", "F", "G", "-", "H", "-", "-", "I" };

    int n = sizeof(tree) / sizeof(tree[0]) - 1; // I have used n = size-1 because I will not be using index 0 for the tree if you want to start from 0 you can

    cout << "Binary Tree (Array Representation):\n";
    for (int i = 1; i <= n; i++) {

        if (tree[i] == "-") {
            continue;
        }

        cout << "Node " << tree[i] << ":\n";

        int left = 2 * i;
        int right = 2 * i + 1;

        if (left <= n and tree[left] != "-") {
            cout << "\tLeft Child = " << tree[left] << "\n";
        } else {
            cout << "\tLeft Child = None\n";
        }

        if (right <= n and tree[right] != "-") {
            cout << "\tRight Child = " << tree[right];
        } else {
            cout << "\tRight Child = None";
        }

        if ((left > n or tree[left] == "-") and (right > n or tree[right] == "-")) {
            cout << "\n\t(Leaf Node)";
        }

        cout << endl;
    }

    return 0;
}
