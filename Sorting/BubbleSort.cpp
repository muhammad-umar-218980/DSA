#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    for(int i = n - 1; i > 0; i--) {
        for(int j = 0; j < i; j++) {
            if(arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    int arr[] = {5, 2, 9, 1, 5, 6};
    int n = 6;

    bubbleSort(arr, n);

    cout << "Sorted Array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
