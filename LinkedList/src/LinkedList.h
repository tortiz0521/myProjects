#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <vector>
#include <string>
#include <iostream>
#include "leaker.h"
using namespace std;

template <typename T>
class LinkedList
{
public:
	struct Node
	{
		T data;
		Node* next = nullptr;
		Node* prev = nullptr;
	};
	//Behaviors
	void PrintForward() const;
	void PrintReverse() const;
	void PrintForwardRecursive(const Node* node) const;
	void PrintReverseRecursive(const Node* node) const;

	//Accessors
	unsigned int NodeCount() const;
	void FindAll(vector<Node*>& outData, const T& value) const;
	const Node* Find(const T& data) const;
	Node* Find(const T& data);
	const Node* GetNode(unsigned int index) const;
	Node* GetNode(unsigned int index);
	Node* Head();
	const Node* Head() const;
	Node* Tail();
	const Node* Tail() const;

	//Insertion
	void AddHead(const T& data);
	void AddTail(const T& data);
	void AddNodesHead(const T* data, unsigned int count);
	void AddNodesTail(const T* data, unsigned int count);
	void InsertAfter(Node* node, const T& data);
	void InsertBefore(Node* node, const T& data);
	void InsertAt(const T& data, unsigned int index);

	//Removal
	bool RemoveHead();
	bool RemoveTail();
	unsigned int Remove(const T& data);
	bool RemoveAt(unsigned int index);
	void Clear();

	//Operators
	const T& operator[](unsigned int index) const;
	T& operator[](unsigned int index);
	bool operator==(const LinkedList<T>& rhs);
	LinkedList<T>& operator=(const LinkedList<T>& rhs);

	//Construction/Destruction
	LinkedList();
	LinkedList(const LinkedList<T>& list);
	~LinkedList();


private:
	Node* head = nullptr;
	Node* tail = nullptr;
	unsigned int numNodes;
};

template <typename T>
LinkedList<T>::LinkedList()
{
	numNodes = 0;
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& list)
{
	//Clear();
	Node* curr = list.head;

	while (curr) {
		this->AddTail(curr->data);
		curr = curr->next;
	}

	//numNodes = list.numNodes;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
	Clear();
}

//Behaviors
template <typename T>
void LinkedList<T>::PrintForward() const
{
	Node* current = head;

	while (current != nullptr) {
		cout << current->data << endl;
		current = current->next;
	}
}

template <typename T>
void LinkedList<T>::PrintReverse() const
{
	Node* current = tail;

	while (current != nullptr) {
		cout << current->data << endl;
		current = current->prev;
	}
}

template <typename T>
void LinkedList<T>::PrintForwardRecursive(const Node* node) const
{ //Give this a look later, not entirely sure how do this recursively.
	Node* temp;

	if (node->next == nullptr) {
		cout << node->data << endl;
	}
	else {
		cout << node->data << endl;
		temp = node->next;
		PrintForwardRecursive(temp);
	}
}

template <typename T>
void LinkedList<T>::PrintReverseRecursive(const Node* node) const
{ //Give this a look later, not entirely sure how do this recursively.
	Node* temp;

	if (node->prev == nullptr) {
		cout << node->data << endl;
	}
	else {
		cout << node->data << endl;
		temp = node->prev;
		PrintReverseRecursive(temp);
	}
}

template <typename T>
unsigned int LinkedList<T>::NodeCount() const
{
	unsigned int count;
	count = this->numNodes;
	return count;
}

template <typename T>
void LinkedList<T>::FindAll(vector<Node*>& outData, const T& value) const
{
	Node* current = head;

	while (current != nullptr) {
		if (current->data == value) {
			outData.push_back(current);
		}

		current = current->next;
	}
}

template <typename T>
const typename LinkedList<T>::Node* LinkedList<T>::Find(const T& data) const
{
	Node* current = head;
	Node* found = nullptr;

	while (current != nullptr) {
		if (current->data == data) {
			found = current;
			break;
		}

		current = current->next;
	}

	return found;
}

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::Find(const T& data)
{
	Node* current = head;
	Node* found = nullptr;

	while (current != nullptr) {
		if (current->data == data) {
			found = current;
			break;
		}

		current = current->next;
	}

	return found;
}

//Accessors
template <typename T>
const typename LinkedList<T>::Node*::LinkedList<T>::GetNode(unsigned int index) const
{
	Node* current = head;
	Node* found = nullptr;
	unsigned int count = 0;

	if (numNodes <= index || index < 0) {
		throw out_of_range("Index is out of range");
	}

	while (count <= index) {
		if (count == index) {
			found = current;
			return found;
		}
		current = current->next;
		count++;
	}

	return found;
}

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::GetNode(unsigned int index)
{
	Node* current = head;
	Node* found = nullptr;
	unsigned int count = 0;

	if (numNodes <= index || index < 0) {
		throw out_of_range("Index is out of range");
	}

	while (count <= index) {
		if (count == index) {
			found = current;
			return found;
		}
		current = current->next;
		count++;
	}

	return found;
}

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::Head()
{
	return head;
}

template <typename T>
const typename LinkedList<T>::Node* LinkedList<T>::Head() const
{
	return head;
}

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::Tail()
{
	return tail;
}

template <typename T>
const typename LinkedList<T>::Node* LinkedList<T>::Tail() const
{
	return tail;
}

//Insertions
template <typename T>
void LinkedList<T>::AddHead(const T& data)
{
	Node* newHead = new Node;
	newHead->data = data;

	if (numNodes == 0) { //We can say if(numNodes == 0)
		head = tail = newHead;
		tail->next = nullptr;
		head->prev = nullptr;
	}
	else {
		newHead->next = head;
		head->prev = newHead;

		head = newHead;
		head->prev = nullptr;
	}

	numNodes++;
}

template <typename T>
void LinkedList<T>::AddTail(const T& data)
{
	Node* newTail = new Node;
	newTail->data = data;

	if (numNodes == 0) { //We can say if(numNodes == 0)
		tail = head = newTail;
		head->prev = nullptr;
		tail->next = nullptr;
	}
	else {
		newTail->prev = tail;
		tail->next = newTail;

		tail = newTail;
		tail->next = nullptr;
	}

	numNodes++;
}

template <typename T>
void LinkedList<T>::AddNodesHead(const T* data, unsigned int count)
{
	for (int i = count - 1; i >= 0; i--) {
		Node* newHead = new Node;
		newHead->data = *(data + i);

		newHead->next = head;
		head->prev = newHead;
		head = newHead;
		head->prev = nullptr;
	}
}

template <typename T>
void LinkedList<T>::AddNodesTail(const T* data, unsigned int count)
{
	for (unsigned int i = 0; i < count; i++) {
		Node* newTail = new Node;
		newTail->data = *(data + i);

		newTail->prev = tail;
		tail->next = newTail;

		tail = newTail;
		tail->next = nullptr;
	}
}

template <typename T>
void LinkedList<T>::InsertAfter(Node* node, const T& data)
{
	Node* temp = new Node;
	Node* newNext = node->next;
	temp->data = data;

	if (newNext == nullptr) {
		temp->next = newNext;
		node->next = temp;
		temp->prev = node;
		tail = temp;
	}
	else {
		temp->next = newNext;
		node->next = temp;
		temp->prev = node;
		newNext->prev = temp;
	}

	//delete temp;
	numNodes++;
}

template <typename T>
void LinkedList<T>::InsertBefore(Node* node, const T& data)
{
	Node* temp = new Node;
	Node* newPrev = node->prev;
	temp->data = data;

	if (newPrev == nullptr) {
		temp->prev = newPrev;
		node->prev = temp;
		temp->next = node;
		head = temp;
	}
	else {
		temp->prev = newPrev;
		node->prev = temp;
		temp->next = node;
		newPrev->next = temp;
	}

	//delete temp;
	numNodes++;
}

template <typename T>
void LinkedList<T>::InsertAt(const T& data, unsigned int index)
{
	Node* temp = new Node;
	temp->data = data;
	Node* current = head;

	unsigned int i = 0;

	if (index > numNodes) {
		throw out_of_range("Index is out of range!");
	}

	while (current) {
		if (i == index) {
			InsertBefore(current, temp->data);
			break;
		}
		if (i == (numNodes - 1)) {
			InsertAfter(current, temp->data);
			break;
		}

		current = current->next;
		i++;
	}

	delete temp;                                                                                                 
}

//Removal
template <typename T>
bool LinkedList<T>::RemoveHead()
{ //There are plenty of ways to implement this function.
	bool removed = true;

	if (head == nullptr) {
		return !removed;
	}

	Node* newHead = head->next;
	Node* temp = head;
	vector<Node*> out;
	FindAll(out, temp->data);
	
	if (newHead == nullptr) {
		delete head;
		head = tail = newHead;
	}
	else {
		newHead->prev = nullptr;
		delete head;
		head = newHead;
	}

	numNodes--;

	vector<Node*> newOut;
	FindAll(newOut, temp->data);
	if (out.size() == newOut.size()) {
		removed = false;
		numNodes++;
	}

	return removed;

}

template <typename T>
bool LinkedList<T>::RemoveTail()
{ //There are also plenty of ways to implement this function here.
	bool removed = true;
	if (tail == nullptr) {
		return !removed;
	}

	Node* newTail = tail->prev;
	Node* temp = tail;
	vector<Node*> out;
	FindAll(out, temp->data);

	if (newTail == nullptr) {
		delete tail;
		tail = head = newTail;
	}
	else {
		newTail->next = nullptr;
		delete tail;
		tail = newTail;
	}

	numNodes--;

	vector<Node*> newOut;
	FindAll(newOut, temp->data);
	if (out.size() == newOut.size()) {
		removed = false;
		numNodes++;
	}

	return removed;
}

template <typename T>
unsigned int LinkedList<T>::Remove(const T& data)
{ //Again, a few ways to think about doing this.
	Node* current = head;
	int count = 0;

	while (current != nullptr) {
		if (current->data == data) {
			if (current == tail) {
				current = current->next;
				RemoveTail();
				numNodes--;
			}
			else if (current == head) {
				current = current->next;
				RemoveHead();
				numNodes--;
			}
			else {
				Node* newCurrent, * newPrev;
				newPrev = current->prev;
				newCurrent = current->next;

				newCurrent->prev = newPrev;
				newPrev->next = newCurrent;

				delete current;
				current = newCurrent;
				count++;
				numNodes--;
			}
		}
		else {
			current = current->next;
		}
	}

	return count;
}

template <typename T>
bool LinkedList<T>::RemoveAt(unsigned int index)
{
	vector<Node*> out, newOut;
	Node* current = head, * newPrev, * newNext;
	if (index >= numNodes || index < 0) {
		return false;
	}

	for (unsigned int i = 0; i < numNodes; i++) {
		if (i == index) {
			newNext = current->next;
			newPrev = current->prev;
			FindAll(out, current->data);

			if (newNext == nullptr) {
				newPrev->next = newNext;
				tail = newPrev;
			}
			else if (newPrev == nullptr) {
				newNext->prev = newPrev;
				head = newNext;
			}
			else {
				newPrev->next = newNext;
				newNext->prev = newPrev;
			}

			FindAll(newOut, current->data);
			delete current;
			numNodes--;
			break;
		}

		current = current->next;
	}

	if (out.size() != newOut.size()) {
		return false;
	}

	return true;
}

template <typename T>
void LinkedList<T>::Clear()
{
	Node* current = head;
	head = tail = nullptr;

	while (current) {
		Node* temp = current->next;
		delete current;
		current = temp;
	}

	numNodes = 0;
}

//Operators
template <typename T>
T& LinkedList<T>::operator[](unsigned int  index)
{
		Node* current = head;
	Node* found = nullptr;
	unsigned int count = 0;

	if (numNodes < index) {
		throw out_of_range("Index is out of range");
	}

	while (count != index) {
		current = current->next;
		count++;
	}

	found = current;
	return found->data;
}

template <typename T>
bool LinkedList<T>::operator==(const LinkedList<T>& rhs)
{
	if (numNodes < rhs.numNodes || numNodes > rhs.numNodes) {
		return false;
	}

	Node* current = head, * rhsCurr = rhs.head;

	while (current) {
		if (current->data != rhsCurr->data) {
			return false;
		}
		else {
			current = current->next;
			rhsCurr = rhsCurr->next;
		}
	}

	return true;
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& rhs)
{
	Clear();
	Node* curr = rhs.head;

	while (curr) {
		this->AddTail(curr->data);
		curr = curr->next;
	}

	numNodes = rhs.numNodes;
	return *this;
}
#endif // !LINKEDLISTCLASS_H