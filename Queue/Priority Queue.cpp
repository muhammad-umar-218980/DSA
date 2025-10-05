#include <iostream>
#include <algorithm>
using namespace std;

class PriorityQueue {
    int arr[100][2]; // arr[i][0] = value, arr[i][1] = priority
    int size;
    int capacity;

public:
    PriorityQueue(int cap) {
        capacity = cap;
        size = 0;
    }

	// I have added this bubble sort algorithm so that in queue elements are always in sorted order 
    void bubbleSort(int L, int U) {
        for (int i = U - 1; i >= L; i--) {
            for (int j = L; j <= i; j++) {
                if (arr[j][1] < arr[j + 1][1]) { // descending priority
                    swap(arr[j][0], arr[j + 1][0]);
                    swap(arr[j][1], arr[j + 1][1]);
                }
            }
        }
    }

    void insert(int value, int priority) {
        if (size == capacity) {
            cout << "Queue is full!\n";
            return;
        }

        arr[size][0] = value;
        arr[size][1] = priority;
        size++;

        bubbleSort(0, size - 1);
    }

    void remove() {
        if (size == 0) {
            cout << "Queue is empty!\n";
            return;
        }

        cout << "Removed element: " << arr[0][0]
             << " (Priority: " << arr[0][1] << ")\n";

        for (int i = 0; i < size - 1; i++) {
            arr[i][0] = arr[i + 1][0];
            arr[i][1] = arr[i + 1][1];
        }
        size--;
    }

    void display() {
        if (size == 0) {
            cout << "Queue is empty!\n";
            return;
        }

        cout << "Value\tPriority\n";
        for (int i = 0; i < size; i++) {
            cout << arr[i][0] << "\t" << arr[i][1] << "\n";
        }
    }
};

int main() {
    int cap;
    cout << "Enter capacity of the priority queue: ";
    cin >> cap;

    PriorityQueue pq(cap);
    int value, priority, choice;

    while (true) {
        cout << "\n1. Insert\n2. Remove\n3. Display\n4. Exit\nEnter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value: ";
            cin >> value;
            cout << "Enter priority: ";
            cin >> priority;
            pq.insert(value, priority);
        }
        else if (choice == 2) {
            pq.remove();
        }
        else if (choice == 3) {
            pq.display();
        }
        else if (choice == 4) {
            break;
        }
        else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}
