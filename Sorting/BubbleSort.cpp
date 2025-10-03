#include <iostream>
#include <algorithm> 
using namespace std;

void bubbleSort(int arr[], int L, int U) {
    for(int i = U - 1; i >= L; i--) {
        for(int j = L; j <= i; j++) {
            if(arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]); 
            }
        }
    }
}

int main() {
    int arr[5] = {12, 21, 6, 8, 5};
    int L = 0;
    int U = 4; 

    bubbleSort(arr, L, U);

    cout << "Sorted array: ";
    for(int i = L; i <= U; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
