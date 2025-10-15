#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter total number of nodes (including empty positions): ";
    cin >> n;

    vector<string> tree(n + 1);

    cout << "Enter value for Root (index 1): ";
    cin >> tree[1];
    
    cout << "Enter the corresponding values for the tree nodes (enter -1 if no child)\n\n";

    for (int i = 1; i <= n / 2; i++) {
        if (tree[i] == "-1") continue;

        int leftIndex = 2 * i;
        int rightIndex = 2 * i + 1;

        if (leftIndex <= n) {
            cout << "Enter Left Child of Node " << tree[i] << " : ";
            cin >> tree[leftIndex];
        }

        if (rightIndex <= n) {
            cout << "Enter Right Child of Node " << tree[i] << " : ";
            cin >> tree[rightIndex];
        }
    }

    cout << "\nBinary Tree (Array Representation):\n";
    for (int i = 1; i <= n; i++) {
        if (tree[i] == "-1") continue;

        cout << "Node " << tree[i] << ":\n";

        int left = 2 * i;
        int right = 2 * i + 1;

        if (left <= n and tree[left] != "-1") {
            cout << "\tLeft Child = " << tree[left] << "\n";
        } else {
            cout << "\tLeft Child = None\n";
        }

        if (right <= n and tree[right] != "-1") {
            cout << "\tRight Child = " << tree[right];
        } else {
            cout << "\tRight Child = None";
        }

        if ((left > n or tree[left] == "-1") and (right > n or tree[right] == "-1")) {
            cout << "\n\t(Leaf Node)";
        }

        cout << endl;
    }

    return 0;
}
