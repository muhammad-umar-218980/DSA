#include <iostream>
#include <vector>
using namespace std;


void merge(int* arr , int start , int mid , int end){
	int i = start , j = mid+1;
	vector<int> temp;
	
	while(i<=mid && j<=end){
		if(arr[i]<arr[j]) temp.push_back(arr[i++]);
		else temp.push_back(arr[j++]);
	}
	
	while(i<=mid) temp.push_back(arr[i++]);
	
	while(j<=end) temp.push_back(arr[j++]);
	
	for(int idx = 0 ; idx < temp.size() ;idx++) arr[start+idx] = temp[idx];
}

void mergeSort(int* arr, int start , int end){
	if(start>=end) return;
	
	int mid = start + (end-start)/2;
	
	mergeSort(arr,start,mid);
	mergeSort(arr,mid+1,end);
	merge(arr,start,mid,end);
}

int main(){
	int arr[] = {9,8,7,6,5,4,3,2,1};
	int size = sizeof(arr)/sizeof(arr[0]);
	
	int start = 0 , end = size-1;
	mergeSort(arr,start,end);
	
	for(int i = 0 ; i < size ;i++) cout << arr[i] << " ";
	return 0;
}