#include <iostream>
using namespace std;

int binary_search(int arr[], int size, int target) {
    int start = 0, end = size - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2; 
        // Hum (start+end)/2 bhi kar saktay thay lekin agar start or end ki value INT_MAX hui to overflow ho jayega is lie ye formula lagaya hai ye bhi same hi formula hai lekin optimized

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

int main() {
    int arr[] = {4, 15, 17, 23, 32, 47, 52, 80};
    int target = 52;
    int size = 8;

    int idx = binary_search(arr, size, target);

    if (idx != -1) {
        cout << "Element found at index : " << idx;
    } else {
        cout << "Element not found!";
    }

    return 0;
}
