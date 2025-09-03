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
	
	void print(){
		Node* temp = head;
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
	ll.push_back(67);
	ll.print();
	return 0;
}