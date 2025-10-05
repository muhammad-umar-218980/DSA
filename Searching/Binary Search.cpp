#include <iostream>
#include <algorithm>
using namespace std;

int binarySearch(int arr[], int L, int U, int KEY) {
    int start = L , end = U;
    while(start <= end){
    	int mid = start + (end-start)/2;
    	if(arr[mid] == KEY) return mid;
    	
    	if(arr[mid] < KEY) start = mid+1;
    	else end = mid-1;
	}
    return -1; 
}

int main() {
    int arr[] = {5, 9, 3, 7, 2, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    sort(arr,arr+n);
    cout << "Sorted Array : ";
    for(int i = 0 ; i < n ;i++) cout << arr[i] << " ";
    cout <<"\n\n";
    
    int KEY;
    cout << "Enter key to search: ";
    cin >> KEY;

    int L = 0;           
    int U = n - 1;       

    int result = binarySearch(arr, L, U, KEY);

    (result != -1) ? cout << "Key found at index " << result << endl : cout << "Key not found" << endl;

    return 0;
}
