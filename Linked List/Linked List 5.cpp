#include <iostream>
using namespace std;

class Node {
	public:
		int data;
		Node* next;

		Node(int val) {
			data = val;
			next = nullptr;
		}

};

class List {
		Node* head;

	public:
		List() {
			head = nullptr;
		}


		void push_front(int val) {
			Node* newNode = new Node(val);
			if(head == nullptr) {
				head = newNode;
				return;
			}
			newNode->next = head;
			head = newNode;
		}

		void push_back(int val) {
			Node* newNode = new Node(val);
			if(head == nullptr) {
				head = newNode;
			} else {
				Node* temp = head;

				while(temp->next != nullptr) {
					temp = temp->next;
				}

				temp->next = newNode;
			}
		}

		void pop_front() {
			if(head == nullptr) {
				cout << "List is empty \n";
				return;
			}
			Node* temp = head;
			head = head->next;
			temp->next = nullptr;
			delete temp;
		}

		void pop_back() {
			if(head == nullptr) {
				cout << "List is empty ";
				return;
			}

			if(head->next == nullptr) {
				delete head;
				head = nullptr;
				return;
			}

			Node* temp = head;
			while(temp->next->next != nullptr) {
				temp = temp->next;
			}

			delete temp->next;
			temp->next = nullptr;

		}

		void insert(int pos, int val) {
			if(pos <= 0) {
				cout << "Invalid position\n";
				return;
			}

			if(pos == 1) {
				this->push_front(val);
				return;
			}

			Node* n = new Node(val);
			Node* current = head;
			int idx = 1;

			while(current != nullptr && idx < pos-1) {
				current = current->next;
				idx++;
			}

			if(current == nullptr) {
				cout << "Position out of range\n";
				delete n;
				return;
			}

			n->next = current->next;
			current->next = n;
		}

		void deleteByPosition(int pos) {
			if(pos <= 0) {
				cout << "Invalid Position\n";
				return;
			}

			if(head == nullptr) {
				cout << "List is empty\n";
				return;
			}

			if(pos == 1) {
				pop_front();
				return;
			}

			Node* current = head;
			int idx = 1;
			while(idx < pos-1 && current != nullptr) {
				current = current->next;
				idx++;
			}

			if(current == nullptr || current->next == nullptr) {
				cout << "Position out of range\n";
				return;
			}

			Node* deletedNode = current->next;
			current->next = deletedNode->next;
			delete deletedNode;
		}


		void deleteByValue(int val) {
			if(head == nullptr) {
				cout << "List is empty\n";
				return;
			}

			if(head->data == val) {
				pop_front();
				return;
			}

			Node* current = head;
			while(current->next != nullptr && current->next->data != val) {
				current = current->next;
			}

			if(current->next == nullptr) {
				cout << "Value not found\n";
				return;
			}

			Node* deletedNode = current->next;
			current->next = deletedNode->next;
			delete deletedNode;
		}




		void print() {
			Node* temp = head;
			while(temp != nullptr) {
				cout << temp->data << " -> " ;
				temp = temp->next;
			}
			cout << "nullptr\n\n";
		}
};

int main() {

	List ll;
//	ll.push_front(3);
//	ll.push_front(2);
//	ll.push_front(1);
//	ll.push_back(4);
//	ll.push_back(5);
//	ll.print();
//
//	ll.push_front(100);
//	ll.push_front(101);
//	ll.print();
//
//	ll.pop_front();
//	ll.print();
//
//	ll.pop_front();
//	ll.print();
//
//	ll.pop_back();
//	ll.pop_back();
//	ll.print();
//
//
//	ll.insert(4,100);

//	for(int i = 0 ; i < 5 ; i++) {
//		ll.push_back(i+1);
//	}
//
//	ll.insert(4,65);
//	ll.insert(4,100);
//
//
//	ll.print();
//
//	ll.deleteByValue(100);
//	ll.print();
//
//	ll.deleteByPosition(4);
//	ll.print();


// Case 1: Delete from empty list
ll.deleteByPosition(1);
ll.deleteByValue(10);

// Case 2: Single element list
ll.push_back(5);
ll.deleteByValue(5); // should clear
ll.print();

// Case 3: Insert at start, middle, end
ll.push_back(1);
ll.push_back(2);
ll.push_back(3);
ll.insert(1, 100);   // at head
ll.insert(3, 200);   // in middle
ll.insert(6, 300);   // at end
ll.print();

// Case 4: Delete by value not found
ll.deleteByValue(999);

// Case 5: Delete last element by position
ll.deleteByPosition(6);
ll.print();

}