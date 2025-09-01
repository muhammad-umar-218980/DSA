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

int main(){
	Node* newNode = new Node(5);
	cout << "\nnewNode->data = " << newNode->data ;
	cout << "\nnewNode->next = " << newNode->next;
	return 0;
}