#include <iostream>
#include <vector>
using namespace std;

void merge(int* arr , int start , int mid , int end){
	int i = start , j = mid+1;
	vector<int> temp;
	
	// The two halfs are sorted in their own halfs , this loop will combine both halfs into temp in a ascending order
	while(i<=mid && j<=end){
		if(arr[i]<arr[j]) temp.push_back(arr[i++]);
		else temp.push_back(arr[j++]);
	}
	
	
	// Below 2 loops are for merging the left or right half elements if any remaining
	while(i<=mid) temp.push_back(arr[i++]);
	
	while(j<=end) temp.push_back(arr[j++]);
	
	
	
	// Ye loop original array mein copy karnay k lie hai kiun k original array ko sort karna tha
	
	for(int idx = 0 ; idx < temp.size() ; idx++) arr[start+idx] = temp[idx];
}

void mergeSort(int* arr, int start , int end){
	if(start>=end) return;
	
	// Mid find karnay ka formula
	int mid = start + (end-start)/2;
	
	// Repeatedly array ko 2 halfs mein divide kareinge
	
	
	// For left half
	mergeSort(arr,start,mid);
	
	// For right half
	mergeSort(arr,mid+1,end);
	
	
	// Merge function for sorting the two halfs in ascending order
	merge(arr,start,mid,end);
}

int main(){
	int size ;
	cout << "\nEnter the size of array : ";
	cin >> size;
	
	int* arr = new int[size];
	
	for(int i = 0 ; i < size ; i++){
		cout << "\nEnter element " << i+1 << " : ";
		cin >> arr[i];
	}
	
	int start = 0 , end = size-1;
	mergeSort(arr,start,end);
	
	cout << "\n\nSorted Array using merge sort : \n";
	for(int i = 0 ; i < size ;i++) cout << arr[i] << " ";
	return 0;
}