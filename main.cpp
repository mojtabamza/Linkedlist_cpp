#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node() : data(0), next(NULL) {}
	Node(int val) : data(val), next(NULL) {}
};

class Linkedlist {
public:
	Node* head;
	Linkedlist() { head = NULL; }
	void push(int);
	void print(void);
	void deleteNode(int);
	void pop(void);
	int  back(void);
	//static int list_len(void);
};

void Linkedlist::push(int data) {
	Node* new_node = new Node(data);
	if (head == NULL) {
		head = new_node;
		//this->print();
		return;
	}
	Node* temp = head;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = new_node;
	//this->print();
}
void Linkedlist::print(void) {
	Node* temp = head;
	while (temp != NULL) {
		cout << temp->data << " -> ";
		temp = temp->next;
	}
	cout << endl;
}
void Linkedlist::deleteNode(int node) {
	if (node == 0) {
		if (head == NULL) {
			cout << "ERR! Empty List" << endl;
			return;
		}
		Node* temp = head;
		head = head->next;
		delete temp;
		return;
	}
	Node* temp = head;
	int listlen = 0;
	while (temp != NULL) {
		listlen++;
		temp = temp->next;
	}
	cout << "listlen : " << listlen << endl;
	if (node > listlen) {
		cout << "OUT OF RANGE REQUEST";
		return;
	}
	temp = head;
	for (int i = 0; i < node - 1; i++) {
		temp = temp->next;
	}
	Node* temp1 = temp->next;
	temp->next = temp->next->next;
	delete temp1;



}
int  Linkedlist::back(void) {
	Node* temp = head;
	if (temp == NULL) {
		cout << "ERR! Empty List" << endl;
		return -1;
	}
	while (temp->next != NULL) {
		temp = temp->next;
	}
	return temp->data;
}
void Linkedlist::pop(void) {
	Node* temp = head;
	if (head == NULL) {
		cout << "ERR! Empty List" << endl;
		return;
	}
	while (temp->next != NULL) {
		temp = temp->next;
	}
	delete temp;
}	

int main(void) {
	cout << "hello ll" << endl;
	Linkedlist myll;
	myll.push(0);
	myll.push(1);
	myll.push(2);
	myll.push(3);
	myll.push(4);
	myll.push(5);
	myll.print();
	myll.deleteNode(3);
	myll.print();
	myll.deleteNode(0);
	myll.print();
	cout << "back : " << myll.back() << endl;
	myll.pop();
	//myll.pop();
	myll.print();
	myll.pop();
	myll.print();
	return  0;

}