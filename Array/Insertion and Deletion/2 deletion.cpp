#include <iostream>
#include <algorithm>
using namespace std;

int binary_search(int arr[], int size, int target);
void deleteFunction(int arr[], int &size, int element) {
    int index = binary_search(arr, size, element);
    if (index == -1) {
        cout << "Element not found!\n";
        return;
    }
    for (int i = index; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int size;
    cout << "Enter the size of the Array : ";
    cin >> size;

    int arr[size];
    cout << "\n---- Enter the elements of Array ----\n";
    for (int i = 0; i < size; i++) {
        cout << "Enter element " << i + 1 << " : ";
        cin >> arr[i];
    }

    sort(arr, arr + size);

    cout << "\nArray after sorting: ";
    printArray(arr, size);

    int element;
    cout << "\nEnter the element to delete : ";
    cin >> element;

    deleteFunction(arr, size, element);

    cout << "\nArray after deletion: ";
    printArray(arr, size);

    return 0;
}

int binary_search(int arr[], int size, int target) {
    int start = 0, end = size - 1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] < target) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return -1;
}
