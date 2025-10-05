#include <iostream>
using namespace std;

int fib(int n){
	if(n==0||n==1) return n;
	
	return fib(n-1)+fib(n-2);
}

int main(){
	
	int n;
	cout << "Enter the nth number to find fibonacci of : ";
	cin >> n;
	
	cout << "\n\n" << n<<"th Fiboncacci number is : " << fib(n);
	return 0;
}