#include <iostream>
using namespace std;

int linearSearch(int arr[], int L, int U, int KEY) {
    if(L > U) return -1;

    cout << "Checking index " << L << " (value = " << arr[L] << ")\n";

    if(arr[L] == KEY) return L;

    return linearSearch(arr, L + 1, U, KEY);
}

int main() {
    int arr[] = {5, 9, 3, 7, 2, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Array: ";
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n\n";

    int KEY;
    cout << "Enter key to search: ";
    cin >> KEY;

    int L = 0;
    int U = n - 1;

    cout << "\n--- Recursive Trace ---\n";
    int result = linearSearch(arr, L, U, KEY);
    cout << "-----------------------\n\n";

    (result != -1) ? cout << "Key found at index " << result << endl : cout << "Key not found" << endl;

    return 0;
}
