#include <iostream>
using namespace std;

int fib(int n){
	if(n==0||n==1) return n;
	
	return fib(n-1)+fib(n-2);
}

int sumFib(int n) {
    if (n == 0) return 0;
    return fib(n) + sumFib(n - 1);
}

int main() {
    int n;
    cout << "Enter the nth number to find sum of fibonacci numbers up to :  ";
    cin >> n;

    cout << "\nSum of Fibonacci numbers from 0 to " << n << " is: " << sumFib(n) << endl;
    return 0;
}
