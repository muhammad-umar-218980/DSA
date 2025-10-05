#include <iostream>
#include <algorithm> 
using namespace std;

void selectionSort(int* arr,int L ,int U){
	if(L>=U) return ;
	
	int min = L;
	
	for(int j = L+1; j <= U ; j++){
		if(arr[j] < arr[min]) min = j;
	}
	
	swap(arr[L],arr[min]);
		
	selectionSort(arr,L+1,U);
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
