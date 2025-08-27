#include <iostream>
#include <string>
using namespace std;

template <typename T>
int linear_search(T arr[], int size, T target) {
	for (int i = 0; i < size; i++) {
		if (arr[i] == target) {
			return i;
		}
	}
	return -1;
}

template <typename T>
void run_search(int size) {
	T arr[size];

	cout << "\n---- Enter the elements of Array ----\n";
	for (int i = 0; i < size; i++) {
		cout << "Enter element " << i + 1 << " : ";
		cin >> arr[i];
	}

	T target;
	cout << "\nEnter the element to search in the Array : ";
	cin >> target;

	int index = linear_search(arr, size, target);

	if (index != -1) {
		cout << "\n"
			 << target << " is found at index " << index << endl;
	} else {
		cout << "\n"
			 << target << " is not found in the array." << endl;
	}
}

int main() {
	int size;
	cout << "Enter the size of Array : ";
	cin >> size;

	cout << "\nChoose data type of array:\n";
	cout << "1. int\n";
	cout << "2. float\n";
	cout << "3. double\n";
	cout << "4. char\n";
	cout << "5. string\n";

	int choice;
	cin >> choice;

	switch (choice) {
	case 1:
		run_search<int>(size);
		break;
	case 2:
		run_search<float>(size);
		break;
	case 3:
		run_search<double>(size);
		break;
	case 4:
		run_search<char>(size);
		break;
	case 5:
		run_search<string>(size);
		break;
	default:
		cout << "Invalid choice!" << endl;
	}

	return 0;
}
