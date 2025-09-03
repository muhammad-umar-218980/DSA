#include <iostream>
using namespace std;

class Node{
public:
	int data;
	Node* next;
	
	Node(int val){
		data = val;
		next = nullptr;
	}

};

class List{
	Node* head;
	
public:
	List(){
		head = nullptr;
	}

	
	void push_front(int val){
		Node* newNode = new Node(val);
		   if(head == nullptr){
			   head = newNode;
			   return;
		   }
		   newNode->next = head;
		   head = newNode;
	}
	
	void push_back(int val){
		Node* newNode = new Node(val);
		if(head == nullptr){
			head = newNode;
		}else{
			Node* temp = head;
			
			while(temp->next != nullptr){
				temp = temp->next;
			}
			
			temp->next = newNode;
		}
	}
	
	void pop_front(){
		Node* temp = head;
		head = head->next;
		temp->next = nullptr;
		delete temp;
	}
	
	void print(){
		Node* temp = head;
		while(temp != nullptr){
			cout << temp->data << " -> " ;
			temp = temp->next;
		}
		cout << "nullptr\n\n";
	}
};

int main(){
	
	List ll;
	ll.push_front(3);
	ll.push_front(2);
	ll.push_front(1);
	ll.push_back(4);
	ll.push_back(5);
	ll.print();
	
	ll.push_front(100);
	ll.push_front(101);
	ll.print();
	
	ll.pop_front();
	ll.print();
	
	ll.pop_front();
	ll.print();
	
	return 0;
}