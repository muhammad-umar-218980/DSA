#include <iostream>
using namespace std;

class Node {
	public:
		int data;
		Node* next;
		Node* prev;

		Node(int data) {
			this->data = data;
			next = prev = nullptr;
		}
};

class DoublyList {
	private:
		Node* head;
		Node* tail;

	public:
		DoublyList() {
			head = tail = nullptr;
		}

		void push_front(int val) {
			Node* n = new Node(val);

			if(isEmpty()) {
				head = tail = n;
				this->print();
				return;
			}

			n->next = head;
			head->prev = n;
			head = n;

			this->print();
		}

		void push_back(int val) {
			Node* n = new Node(val);

			if(isEmpty()) {
				head = tail = n;
				this->print();
				return;
			}

			n->prev = tail;
			tail->next = n;
			tail = n ;
			this->print();
		}

		void pop_front() {
			if(isEmpty()) {
				cout << "\nList is empty\n";
				return;
			}

			if(head->next == nullptr) {
				delete head;
				head = tail = nullptr;
				this->print();
				return;
			}
			Node* temp = head;
			head = head->next;
			head->prev = nullptr;
			temp->next = nullptr;
			delete temp;

			this->print();
		}

		void pop_back() {
			if(isEmpty()) {
				cout << "\nList is empty\n";
				return;
			}

			if(tail->prev == nullptr) {
				delete tail;
				head = tail = nullptr;
				this->print();
				return;
			}
			Node* temp = tail;
			tail = tail->prev;
			tail->next = nullptr;
			temp->prev = nullptr;
			delete temp;

			this->print();
		}

		void insert(int pos, int val) {

			if(pos <= 0) {
				cout << "Invalid position\n";
				return;
			}

			if(pos == 1) {
				push_front(val);
				return;
			}

			Node* current = head;
			int idx = 1;

			while(current != nullptr && idx <pos-1) {
				current = current->next;
				idx++;
			}

			if(current == nullptr) {
				cout << "Position out of range\n";
				return;
			}


			if(current == tail) {
				push_back(val);
				return;
			}


			Node* newNode = new Node(val);

			newNode->next = (*current).next;
			current->next->prev = newNode;
			current->next = newNode;
			newNode->prev = current;

			this->print();
		}

		void deleteByPosition(int pos) {

			if (isEmpty()) {
				cout << "List is empty\n";
				return;
			}
			if(pos<=0) {
				cout << "Invalid Position";
				return ;
			}

			if(pos == 1) {
				this->pop_front();
				return;
			}

			Node* current = head;
			int idx = 1;

			while(current != nullptr && idx<pos-1) {
				current = current->next;
				idx++;
			}

			if (current == nullptr || current->next == nullptr) {
				cout << "Position out of range\n";
				return;
			}

			Node* deletedNode = current->next;

			if (deletedNode == tail) {
				this->pop_back();  
				return;
			}

			current->next = deletedNode->next;
			deletedNode->next->prev = current;
			
			deletedNode->next = nullptr;
			deletedNode->prev = nullptr;
			delete deletedNode;

			this->print();
		}

		void print() {
			Node* temp = head;
			while(temp != nullptr) {
				cout << temp->data << " <-> ";
				temp = temp->next;
			}

			this->isEmpty() ? cout << "List is empty \n" : cout << "nullptr\n\n";
//		if(isEmpty()){
//			cout << "List is empty \n";
//		}else{
//			cout << "nullptr";
//		}

		}

		bool isEmpty() {
			return head == nullptr;
		}
};

int main() {

	DoublyList dll;

//	dll.push_front(3);
//	dll.push_front(2);
//	dll.push_front(1);
//
//	dll.push_back(4);
//	dll.push_back(5);
//
//	dll.pop_front();
//	dll.pop_front();
//
//	dll.pop_back();
//	dll.pop_back();

	for(int i= 0 ; i < 6 ; i++) {
		if(i == 3) continue;

		dll.push_back(i+1);
	}

	dll.insert(4,4);
	dll.insert(1,100);

	dll.deleteByPosition(6);

	return 0;
}