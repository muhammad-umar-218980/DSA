#include <iostream>
using namespace std;

int binary_search(int arr[], int size, int target) {
    int start = 0, end = size - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2; 
        // Hum mid = (start+end)/2 bhi kar saktay thay lekin agar start or end ki value INT_MAX hui to overflow ho jayega is lie ye formula lagaya hai ye bhi same hi formula hai lekin optimized

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
    
    int size;
    cout << "Enter the size of the Array : ";
    cin >> size;
    
    int arr[size];

    cout << "\n---- Enter the elements of Array (in ascending order)----\n";
    for (int i = 0; i < size; i++) {
        cout << "\nEnter element " << i + 1 << " : ";
        cin >> arr[i];

        while (i > 0 && arr[i-1] > arr[i]) {   
            cout << "\n" << arr[i-1] << " is greater than " << arr[i] << " please enter any other number greater than " << arr[i - 1] << " : ";
            cin >> arr[i];
        }
    }
	
    int target;
    cout << "\nEnter the targeted element : ";
    cin >> target;

    int idx = binary_search(arr, size, target);

    if (idx != -1) {
        cout << "\nElement found at index : " << idx;
    } else {
        cout << "\nElement not found!";
    }

    return 0;
}
