#include <iostream>
#include <vector>   // Required for using vector
using namespace std;

int main() {

    // --- 1. Declaration and Initialization ---
    vector<int> v1;                   // Empty vector
    vector<int> v2(5);                // Vector of size 5 with default values (0)
    vector<int> v3(5, 10);            // Vector of size 5, all elements = 10
    vector<int> v4 = {1, 2, 3, 4, 5}; // Initialization using list

    cout << "Initial vector v4: ";
    for (int i = 0; i < v4.size(); i++) cout << v4[i] << " ";
    cout << "\n\n";

    // --- 2. Adding Elements ---
    v4.push_back(6);    // Add element at end
    v4.push_back(7);
    cout << "After push_back(6), push_back(7): ";
    for (int i = 0; i < v4.size(); i++) cout << v4[i] << " ";
    cout << "\n\n";

    // --- 3. Removing Elements ---
    v4.pop_back();       // Removes last element
    cout << "After pop_back(): ";
    for (int i = 0; i < v4.size(); i++) cout << v4[i] << " ";
    cout << "\n\n";

    // --- 4. Accessing Elements ---
    cout << "v4[0] = " << v4[0] << "\n";        // Access using index
    cout << "v4.at(2) = " << v4.at(2) << "\n";  // Access using at() (checks bounds)
    cout << "Front element = " << v4.front() << "\n";
    cout << "Back element = " << v4.back() << "\n\n";

    // --- 5. Inserting Elements ---
    v4.insert(v4.begin(), 0);       // Insert at beginning
    v4.insert(v4.begin() + 3, 99);  // Insert at 4th position (index 3)
    cout << "After insertions: ";
    for (int i = 0; i < v4.size(); i++) cout << v4[i] << " ";
    cout << "\n\n";

    // --- 6. Erasing Elements ---
    v4.erase(v4.begin() + 3);       // Erase element at index 3
    v4.erase(v4.begin());           // Erase first element
    cout << "After erasing some elements: ";
    for (int i = 0; i < v4.size(); i++) cout << v4[i] << " ";
    cout << "\n\n";

    // --- 7. Checking Size and Capacity ---
    cout << "Size = " << v4.size() << "\n";
    cout << "Capacity = " << v4.capacity() << "\n";
    cout << "Max Size = " << v4.max_size() << "\n\n";

    // --- 8. Resizing Vector ---
    v4.resize(10, -1); // Resize to 10 elements, new ones = -1
    cout << "After resize(10, -1): ";
    for (int i = 0; i < v4.size(); i++) cout << v4[i] << " ";
    cout << "\n\n";

    // --- 9. Clear all elements ---
    v4.clear();
    cout << "After clear(), size = " << v4.size() << "\n";
    cout << "Is empty? " << (v4.empty() ? "Yes" : "No") << "\n\n";

    // --- 10. Swapping Vectors ---
    vector<int> a = {1, 2, 3};
    vector<int> b = {10, 20, 30};
    cout << "Before swap:\n";
    cout << "a: "; for (int i = 0; i < a.size(); i++) cout << a[i] << " "; cout << "\n";
    cout << "b: "; for (int i = 0; i < b.size(); i++) cout << b[i] << " "; cout << "\n";

    a.swap(b);

    cout << "\nAfter swap:\n";
    cout << "a: "; for (int i = 0; i < a.size(); i++) cout << a[i] << " "; cout << "\n";
    cout << "b: "; for (int i = 0; i < b.size(); i++) cout << b[i] << " "; cout << "\n\n";

    // --- 11. Copying and Assigning ---
    vector<int> c = a;    // Copy constructor
    vector<int> d;
    d.assign(a.begin(), a.end()); // Assign using iterators

    cout << "Copied vector c: ";
    for (int i = 0; i < c.size(); i++) cout << c[i] << " ";
    cout << "\n";

    cout << "Assigned vector d: ";
    for (int i = 0; i < d.size(); i++) cout << d[i] << " ";
    cout << "\n\n";

    // --- 12. Iterators ---
    cout << "Iterating using iterator: ";
    vector<int>::iterator it;
    for (it = a.begin(); it != a.end(); it++) {
        cout << *it << " ";
    }
    cout << "\n\n";

    // --- 13. Reverse Iterators ---
    cout << "Reverse iteration: ";
    vector<int>::reverse_iterator rit;
    for (rit = a.rbegin(); rit != a.rend(); rit++) {
        cout << *rit << " ";
    }
    cout << "\n\n";

    return 0;
}
