#include <iostream>
using namespace std;

void insertFunction(int arr[], int size, int element, int index){

	for(int i = size;i > index ; i--){
		arr[i] = arr[i-1];
	}
	
	arr[index] = element;


}

void printArray(int arr[], int newSize){
	cout << "[";
	for(int i = 0 ; i < newSize ; i++){
		if(i < newSize-1)
			cout << arr[i] << " , ";
		else
			cout << arr[i] << "";
	}
	cout << "]";
}

int main(){

	cout << "Enter the size of Array : ";
	int size;
	cin >> size;

	int newSize = size + 1;

	int arr[newSize];

	cout << "\n---- Enter the elements of Array ----\n";
	for (int i = 0; i < size; i++) {
		cout << "\nEnter element " << i + 1 << " : ";
		cin >> arr[i];
	}

	int element, index;
	cout << "\nEnter the element to insert : ";
	cin >> element;
	cout << "\nEnter the index at which to insert the element : ";
	cin >> index;

	insertFunction(arr, size, element, index);
	
	printArray(arr,newSize);
	
	

	return 0;
}