#include <iostream>
using namespace std;

int sum(int n){
	if(n==1) return 1;
	
	return n+sum(n-1);
}


int main(){
	
	int n;
	cout << "Enter the nth number to find sum up to : ";
	cin >> n;
	
	cout << "\n\n" << "Sum of numbers from 1 - " << n << " is : " << sum(n);
	return 0;
}