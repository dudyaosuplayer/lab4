#pragma once

#include <iostream>
#include <windows.h>

using namespace std;

struct Node {
	int data;
	Node* Next;
	Node* Prev;
};

class DList {
private:
	Node* Head;
	Node* Tail;
	int count;
public:
	DList() : Head(NULL), Tail(NULL), count(0){}
	DList(const DList& copy_list) {
		Head = Tail = NULL;
		count = 0;
		Node* temp = copy_list.Head;
		while (temp != 0){
			PushBack(temp->data);
			temp = temp->Next;
		}
	}

	void PushBack(int param_data) {
		Node* temp = new Node;
		temp->Next = NULL;
		temp->data = param_data;
		temp->Prev = Tail;

		if (Tail != 0)
			Tail->Next = temp;

		if (count == 0)
			Head = Tail = temp;
		else
			Tail = temp;

		count++;
	}
	void PushFront(int param_data) {
		Node* temp = new Node;
		temp->Prev = NULL;
		temp->data = param_data;
		temp->Next = Head;

		if (Head != 0)
			Head->Prev = temp;

		if (count == 0)
			Head = Tail = temp;
		else
			Head = temp;

		count++;
	}

	int PopBack() {
		return Tail->data;
	}
	int PopFront() {
		return Head->data;
	}

	void Clear() {
		while (count != 0) {
			Node* temp = new Node;
			temp = Head->Next;
			Head->data = NULL;
			Head = temp;
			temp = NULL;
			delete temp;
			count--;
		}
		return;
	}

	void Print() {
		if (count != 0) {
			Node* temp = Head;
			cout << "[";
			while (temp->Next != 0) {
				cout << temp->data << ", ";
				temp = temp->Next;
			}
			cout << temp->data << "]\n";
			return;
		} else {
			cout << "List is empty!" << "\n";
		}
		return;
	}

	bool isEmpty() {
		if (count == 0)
			return true;
		return false;
	}

	~DList(){
		while (count != 0) {
			Node* temp = new Node;
			temp = Head->Next;
			Head->data = NULL;
			Head = temp;
			temp = NULL;
			delete temp;
			count--;
		}
	}
};