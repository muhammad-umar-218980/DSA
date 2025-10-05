#include <iostream>
using namespace std;

int linearSearch(int arr[], int L, int U, int KEY) {
    for(int i = L; i <= U; i++) {
        if(arr[i] == KEY) {
            return i; 
        }
    }
    return -1; 
}

int main() {
    int arr[] = {5, 9, 3, 7, 2, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int KEY;

    cout << "Enter key to search: ";
    cin >> KEY;

    int L = 0;           
    int U = n - 1;       

    int result = linearSearch(arr, L, U, KEY);

    (result != -1) ? cout << "Key found at index " << result << endl : cout << "Key not found" << endl;

    return 0;
}
