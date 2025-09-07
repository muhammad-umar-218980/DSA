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

class List {
	private:
		Node* head;
		Node* tail;

	public:
		List() {
			head = tail = nullptr;
		}

		void push_front(int val) {
			Node* n = new Node(val);

			if (head == nullptr) {
				head = tail = n;
				return;
			}

			n->next = head;
			head = n;
			
			this->print();
		}

		void push_back(int val) {
			Node* n = new Node(val);

			if (head == nullptr) {
				head = tail = n;
				return;
			}

			tail->next = n;
			tail = n;
			this->print();
		}

		void pop_front() {
			if (head == nullptr) {
				cout << "\n The list is empty \n";
				return;
			}

			Node* current = head;
			head = head->next;
			current->next = nullptr;
			delete current;
			this->print();
		}

		void pop_back() {
			if (head == nullptr) {
				cout << "\n The list is empty \n";
				return;
			}

			if (head->next == nullptr) {
				delete head;
				head = tail = nullptr;
				return;
			}

			Node* current = head;
			while (current->next != tail) {
				current = current->next;
			}

			current->next = nullptr;
			delete tail;
			tail = current;
			this->print();
		}

		void insert(int pos, int val) {
			if(pos <= 0) {
				cout << "Invalid position";
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

			n->next = current->next;
			current->next = n;
			this->print();
		}

		void deleteByPosition(int pos) {
			Node* current = head;
			int idx = 1;

			while(current != nullptr && idx < pos-1) {
				current = current->next;
				idx++;
			}

			Node* deletedNode = current->next;
			current->next = deletedNode->next;
			deletedNode->next = nullptr;
			delete deletedNode;
			this->print();
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
			this->print();
		}



		bool isEmpty() {
			if (head == nullptr) {
				return true;
			}
			return false;
		}

		void print() {
			Node* current = head;
			while (current != nullptr) {
				cout << current->data << " -> ";
				current = current->next;
			}
			if(this->isEmpty()) {
				cout << "\nList is empty\n";
			} else {
				cout << " nullptr \n\n";
			}
		}
};

int main() {
	List ll;
//    for (int i = 5; i > 0; i--) {
//        ll.push_front(i);
//    }
//
//    ll.print();
//
//    for (int i = 6; i <= 10; i++) ll.push_back(i);
//
//    ll.print();
//
//    ll.pop_front();
//    ll.print();
//
//    ll.pop_back();
//    ll.print();


	for(int i = 1 ; i <= 5 ; i++) {
		if(i == 3) {
			continue;
		}

		ll.push_back(i);
	}

	ll.insert(3,3);

	ll.insert(2,87);
	ll.insert(4,464);

	ll.deleteByPosition(2);
	
	ll.deleteByValue(464);
	return 0;
}
