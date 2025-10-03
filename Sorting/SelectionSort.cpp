#include <iostream>
#include <algorithm> 
using namespace std;

void selectionSort(int* arr,int L ,int U){
	for(int i = L ; i <= U-1 ; i++){
		int min = i;
		for(int j = i+1; j <= U ; j++){
			if(arr[j] < arr[min]){
				min = j;
			}
		}
			swap(arr[i],arr[min]);
	}
}

int main() {
    int arr[5] = {12, 21, 6, 8, 5};
    int L = 0;
    int U = 4; 

    selectionSort(arr, L, U);

    cout << "Sorted array: ";
    for(int i = L; i <= U; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
