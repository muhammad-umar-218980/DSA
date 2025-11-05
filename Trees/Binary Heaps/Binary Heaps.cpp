#include <iostream>
using namespace std;

void MaxHeapify(int arr[], int i, int heapSize) {
    int left = 2 * i;
    int right = 2 * i + 1;
    int max = i;

    if (left <= heapSize && arr[left] > arr[max]) {
        max = left;
    }

    if (right <= heapSize && arr[right] > arr[max]) {
        max = right;
    }

    if (max != i) {
        swap(arr[i], arr[max]);
        MaxHeapify(arr, max, heapSize);
    }
}

void BuildMaxHeap(int arr[], int size) {
    for (int i = size / 2; i >= 1; i--) {
        MaxHeapify(arr, i, size);
    }
}

int ExtractMaxFromHeap(int arr[], int& heapSize) {
    int max = arr[1];
    arr[1] = arr[heapSize];
    heapSize = heapSize - 1;
    MaxHeapify(arr, 1, heapSize);
    return max;
}

void HeapSort_1(int arr[], int size) {
    BuildMaxHeap(arr, size);
    int* temp = new int[size + 1];
    int heapSize = size;

    for (int i = size; i >= 1; i--) {
        temp[i] = ExtractMaxFromHeap(arr, heapSize);
    }

    for (int i = 1; i <= size; i++) {
        arr[i] = temp[i];
    }

    delete[] temp;
}

void HeapSort_2(int arr[], int size) {
    BuildMaxHeap(arr, size);
    int heapSize = size;

    for (int i = size; i >= 2; i--) {
        swap(arr[1], arr[i]);
        heapSize = heapSize - 1;
        MaxHeapify(arr, 1, heapSize);
    }
}

void printArray(int arr[], int size) {
    for (int i = 1; i <= size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int size1, size2;

    cout << "Enter size of first array: ";
    cin >> size1;
    
    int* arr1 = new int[size1 + 1];
    
    cout << "\n\nEnter elements of first array \n\n";
    for (int i = 1; i <= size1; i++) {
    	cout << "\nEnter element " << i << " : ";
        cin >> arr1[i];
    }

    cout << "\nEnter size of second array: ";
    cin >> size2;
    
    int* arr2 = new int[size2 + 1];
    
    cout << "\n\nEnter elements of second array \n\n";
    for (int i = 1; i <= size2; i++) {
    	cout << "\nEnter element " << i << " : ";
        cin >> arr2[i];
    }

    HeapSort_1(arr1, size1);
    HeapSort_2(arr2, size2);

    cout << "\n\nSorted array using HeapSort_1: ";
    printArray(arr1, size1);

    cout << "\n\nSorted array using HeapSort_2: ";
    printArray(arr2, size2);

    delete[] arr1;
    delete[] arr2;

    return 0;
}
