#include <iostream>
#include <algorithm> 
using namespace std;

void insertionSort(int* arr,int L ,int U){
	if(L>=U) return;
	
	int val = arr[L+1] , j;
		for(j = L; j >= 0 ; j--){
			if(arr[j] < val) break;
			
			arr[j+1]= arr[j];
		}
		arr[j+1] = val;
		
	insertionSort(arr,L+1,U);
}

int main() {
    int arr[5] = {12, 21, 6, 8, 5};
    int L = 0;
    int U = 4; 

    insertionSort(arr, L, U);

    cout << "Sorted array: ";
    for(int i = L; i <= U; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
