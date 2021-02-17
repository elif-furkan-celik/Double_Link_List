
/*
 * DoublyIntLinkedList.h
 *
 */

#ifndef DOUBLYINTLINKEDLIST_H_
#define DOUBLYINTLINKEDLIST_H_

#include <iostream>

using namespace std;


class Node {

public:
	int data;
	Node* prev;
	Node* next;

	Node(){
		data = 0;
		prev = nullptr;
		next = nullptr;
	}

	Node(int data_){
		data = data_;
		prev = nullptr;
		next = nullptr;
	}

	Node(int data_, Node* prev_, Node* next_){
		data = data_;
		prev = prev_;
		next = next_;
	}
};


class DoublyIntLinkedList {

public:
	// Constructing the empty list
	DoublyIntLinkedList() {
		front = nullptr;
	}

	// Constructing the list with one element
	DoublyIntLinkedList(int data) {
		front = new Node(data);
	}

	// Adding element at the end of the list
	void add(int data) {
	    Node* current = front;
	    if(current == nullptr){
            Node *tmp = new Node(data);
            current = tmp;
            front = tmp;
	    }else{
            while (current->next != nullptr) {
                current = current->next;  // move to next node
            }
            Node *tmp = new Node(data);
            tmp->prev = current;
            current->next = tmp;
	    }
	}

	// Adding element at the specified index of the list
	void add(int data, int index) {
	    Node* current = front;
		int temp = 0;
        if(index == 0){
            if(front == nullptr){
                Node *tmp = new Node(data);
                front = tmp;
            }else{
                Node *tmp = new Node(data);
                tmp->next = front;
                front->prev = tmp;
                front = tmp;
            }
        }else{
            if(current == nullptr){
                cout << "Out of range!" << endl;
            }else{
                temp++;
                while (current->next != nullptr) {
                    if(temp == index){
                        Node *tmp = new Node(data, current, current->next);
                        current->next = tmp;
                        break;
                    }else{
                        current = current->next;  // move to next node
                        temp++;
                    }
                }
                if(current->next == nullptr){
                    if(temp == index){
                        Node *tmp = new Node(data, current, nullptr);
                        current->next = tmp;
                    }
                }
            }
        }
	}

	// Removing the element at the specified index
	void remove(int index) {
	    Node* current = front;
		int temp = 0;
        if(index == 0){
            if(front == nullptr){
                cout << "Out of range!" << endl;
            }else{
                Node *tmp = current;
                front = current->next;
                delete tmp;
            }
        }else{
            if(current == nullptr){
                cout << "Out of range!" << endl;
            }else{
                while (current != nullptr) {
                    if(temp == index){
                        if(current->next == nullptr){
                            Node* tmp;
                            tmp = current;
                            current->prev->next = nullptr;
                            delete tmp;
                            break;
                        }else{
                            Node* tmp;
                            tmp = current;
                            current->prev->next = current->next;
                            current->next->prev = current->prev;
                            delete tmp;
                            break;
                        }
                    }else{
                        current = current->next;  // move to next node
                        temp++;
                    }
                }
                if(current == nullptr){
                    cout << "Out of range!" << endl;
                }
            }
        }
	}

	// Testing whether the list is empty
	bool empty() {
		return front == nullptr;
	}

	// Returning the number of elements in the list
	int size() {
	    Node* current = front;
		int nNodes = 0;
		while (current != nullptr) {
			current = current->next;  // move to next node
			nNodes++;
		}
		return nNodes;
	}

	// Printing the elements in the list
	void print() {
		Node* current = front;
		cout << "front ->\t";
		while (current != nullptr) {
		    cout << current->data << " ";
		    current = current->next;  // move to next node
		}
		cout << "\n";
	}

	// Deleting the elements in the L�ST
	void clear() {
	    while (front != nullptr) {
			Node* temp = front;  // move to next node
			front = front->next;
			delete temp;
		}
	}

	// Finding the index of an element
	// Returns -1 if the value does not exists in the list
	int indexOf(int n) {
	    Node* current = front;
		int index = 0;
		while (current != nullptr) {
		    if(current->data == n)
		    	return index;
		    else{
		    	current = current->next;  // move to next node
		    	index++;
		    }
		}
		return -1;
	}

private:
	Node* front;
};

#endif /* DOUBLYINTLINKEDLIST_H_ */
