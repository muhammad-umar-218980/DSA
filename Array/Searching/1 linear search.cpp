#include <iostream>
using namespace std;

int linear_search(int arr[], int size, int target){
	
	for (int i = 0; i < size; i++){
		if (arr[i] == target){
			return i;
		}
	}
	return -1;
}

int main(){
	
	int size;
	
	cout << "Enter the size of Array : ";
	cin >> size;
	
	int arr[size];
	
	cout << "\n---- Enter the elements of Array  ----\n";
	for(int i = 0 ; i < size ; i++){
		cout << "\nEnter element " << i+1 << " : ";
		cin >> arr[i];
	}
	
	int target ;
	cout << "\nEnter the element to search in the Array : ";
	cin >> target;
	
	int index = linear_search(arr,size,target);
	cout << "\n" << target << " is found at index " << index; 
}