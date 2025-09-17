#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        next = nullptr;
    }
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = rear = nullptr;
    }

    void Enqueue(int val) {
        Node* n = new Node(val);

        if (isEmpty()) {
            front = rear = n;
            return;
        }

        rear->next = n;
        rear = n;
    }

    void Dequeue() {
        if (isEmpty()) {
            cout << "\nQueue is empty\n";
            return;
        }
        
        if(front->next == nullptr){
        	delete front;
        	front =rear = nullptr;
        	return;
		}

        Node* temp = front;
        front = front->next;
        delete temp;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void print() {
        if (isEmpty()) {
            cout << "\nQueue is empty\n";
            return;
        }

        Node* current = front;
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "nullptr\n\n";
    }

    int Front() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return front->data;
    }

    int Rear() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return rear->data;
    }
};

int main() {
    Queue q;
    for (int i = 1; i <= 5; i++) q.Enqueue(i);

    q.print();

    q.Dequeue();
    q.print();

    q.Dequeue();
    q.print();

    for (int i = 6; i <= 10; i++) q.Enqueue(i);

    q.print();

    cout << "Front: " << q.Front() << endl;
    cout << "Rear: " << q.Rear() << endl;

    return 0;
}
