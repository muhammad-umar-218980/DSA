#include <iostream>
#include <list>     // Header file for list
#include <iterator> // For iterators
#include <algorithm> // For algorithms like find, count
using namespace std;

int main() {

    // ********** 1. DECLARATION **********
    list<int> l1;                  // Empty list of integers
    list<int> l2(5, 10);           // List with 5 elements, each initialized to 10
    list<int> l3 = {1, 2, 3, 4, 5}; // Initializer list

    cout << "List l1 (empty): ";
    for(int x : l1) cout << x << " ";
    cout << "\nList l2 (5 elements of 10): ";
    for(int x : l2) cout << x << " ";
    cout << "\nList l3 (initialized): ";
    for(int x : l3) cout << x << " ";

    cout << "\n\n";

    // ********** 2. INSERTION **********
    l1.push_back(20);    // Add element at the end
    l1.push_front(5);    // Add element at the front
    l1.insert(l1.end(), 15); // Insert element before iterator position (here before end)
    l1.insert(++l1.begin(), 10); // Insert after first position

    cout << "List l1 after insertions: ";
    for(int x : l1) cout << x << " ";

    cout << "\n\n";

    // ********** 3. TRAVERSAL **********
    cout << "Traversal using iterator: ";
    list<int>::iterator it;
    for(it = l1.begin(); it != l1.end(); it++) {
        cout << *it << " ";
    }
    cout << "\nTraversal using reverse_iterator: ";
    for(list<int>::reverse_iterator rit = l1.rbegin(); rit != l1.rend(); rit++) {
        cout << *rit << " ";
    }

    cout << "\n\n";

    // ********** 4. ACCESS FUNCTIONS **********
    cout << "Front element: " << l1.front() << "\n";
    cout << "Back element: " << l1.back() << "\n";

    cout << "\n";

    // ********** 5. DELETION **********
    l1.pop_front();   // Removes first element
    l1.pop_back();    // Removes last element
    it = l1.begin();
    advance(it, 1);   // Move iterator to 2nd element
    l1.erase(it);     // Removes element at iterator

    cout << "List l1 after deletions: ";
    for(int x : l1) cout << x << " ";

    cout << "\n\n";

    // ********** 6. SIZE & EMPTY **********
    cout << "Size of l1: " << l1.size() << "\n";
    cout << "Is l1 empty? " << (l1.empty() ? "Yes" : "No") << "\n\n";

    // ********** 7. CLEAR **********
    list<int> temp = {11, 22, 33};
    cout << "Before clear: ";
    for(int x : temp) cout << x << " ";
    temp.clear();  // Removes all elements
    cout << "\nAfter clear, size = " << temp.size() << "\n\n";

    // ********** 8. SORT **********
    list<int> l4 = {5, 1, 8, 3, 2};
    cout << "Before sorting: ";
    for(int x : l4) cout << x << " ";
    l4.sort();   // Sorts in ascending order
    cout << "\nAfter sorting (asc): ";
    for(int x : l4) cout << x << " ";
    l4.sort(greater<int>());  // Sorts in descending order
    cout << "\nAfter sorting (desc): ";
    for(int x : l4) cout << x << " ";

    cout << "\n\n";

    // ********** 9. REVERSE **********
    l4.reverse();
    cout << "After reverse: ";
    for(int x : l4) cout << x << " ";

    cout << "\n\n";

    // ********** 10. UNIQUE **********
    list<int> l5 = {1, 1, 2, 2, 3, 3, 3, 4};
    cout << "Before unique: ";
    for(int x : l5) cout << x << " ";
    l5.unique(); // Removes consecutive duplicates
    cout << "\nAfter unique: ";
    for(int x : l5) cout << x << " ";

    cout << "\n\n";

    // ********** 11. MERGE **********
    list<int> l6 = {1, 3, 5};
    list<int> l7 = {2, 4, 6};
    l6.merge(l7);  // Merges l7 into l6 (lists must be sorted)
    cout << "Merged list l6: ";
    for(int x : l6) cout << x << " ";
    cout << "\nList l7 after merge (should be empty): " << l7.size();

    cout << "\n\n";

    // ********** 12. SPLICE **********
    list<int> a = {1, 2, 3};
    list<int> b = {10, 20, 30};
    it = a.begin();
    advance(it, 1);
    a.splice(it, b);  // Moves all elements of b into a at position it

    cout << "List a after splice: ";
    for(int x : a) cout << x << " ";
    cout << "\nList b after splice (should be empty): " << b.size();

    cout << "\n\n";

    // ********** 13. REMOVE & REMOVE_IF **********
    list<int> l8 = {1, 2, 3, 4, 5, 6};
    l8.remove(3);  // Removes all 3s
    cout << "After remove(3): ";
    for(int x : l8) cout << x << " ";

    // Remove even numbers using lambda function
    l8.remove_if([](int n){ return n % 2 == 0; });
    cout << "\nAfter remove_if(even): ";
    for(int x : l8) cout << x << " ";

    cout << "\n\n";

    // ********** 14. ASSIGN **********
    list<int> l9;
    l9.assign(4, 7);  // Assign 4 elements with value 7
    cout << "List l9 after assign: ";
    for(int x : l9) cout << x << " ";

    cout << "\n\n";

    // ********** 15. SWAP **********
    list<int> l10 = {1, 2, 3};
    list<int> l11 = {10, 20, 30};
    cout << "Before swap:\n";
    cout << "l10: ";
    for(int x : l10) cout << x << " ";
    cout << "\nl11: ";
    for(int x : l11) cout << x << " ";

    l10.swap(l11);

    cout << "\nAfter swap:\n";
    cout << "l10: ";
    for(int x : l10) cout << x << " ";
    cout << "\nl11: ";
    for(int x : l11) cout << x << " ";

    cout << "\n\n";

    // ********** 16. RESIZE **********
    list<int> l12 = {1, 2, 3};
    l12.resize(5, 100); // Resizes to 5, fills new elements with 100
    cout << "After resize: ";
    for(int x : l12) cout << x << " ";

    cout << "\n\n";

    // ********** 17. USING find() **********
    list<int> l13 = {10, 20, 30, 40};
    it = find(l13.begin(), l13.end(), 30);
    if(it != l13.end()) cout << "Element 30 found!\n";
    else cout << "Element not found!\n";

    cout << "\nProgram Completed Successfully!\n";

    return 0;
}