#include <iostream>
using namespace std;

class Node{
public:
	int data;
	Node* next;
	
	Node(int val){
		this->data = val;
		this->next = nullptr;
	}
};

class List{
	Node* head;
	
public:
	List(){
		this->head = nullptr;
	}
	
	void push_front(int val){
		Node* newNode = new Node(val);
		if(this->head == nullptr){
			this->head = newNode;
			return;
		}
		newNode->next = this->head;
		this->head = newNode;
	}
	
	void print(){
		Node* temp = this->head;
		while(temp != nullptr){
			cout << temp->data << "->" ;
			temp = temp->next;
		}
		cout << "nullptr";
	}
};

int main(){
	
	List ll;
	ll.push_front(3);
	ll.push_front(2);
	ll.push_front(1);
	ll.print();
	return 0;
}