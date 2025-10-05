#include <iostream>
#include <algorithm> 
using namespace std;

void bubbleSort(int arr[], int L, int U) {
	if(L>=U) return;
	
	for(int i = U-1 ; i >=L ;i--){
		if (arr[i]>arr[i+1]) swap(arr[i],arr[i+1]);
	}
	
	bubbleSort(arr,L+1,U);
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
