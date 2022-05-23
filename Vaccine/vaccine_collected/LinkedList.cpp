#include "LinkedList.h"
#include <assert.h>
template <class T>
Node<T>::Node() {
	next = 0;
	value = 0;
}
template <class T>
Node<T>::Node(T val) {
	next = 0;
	value = val;
}

template<class T>
LinkedList<T>::LinkedList()
{
	count = 0;
	head = tail = 0;
}

template<class T>
int LinkedList<T>::Length()
{
	return count;
}

template<class T>
void LinkedList<T>::InsertAt(int pos, T val)
{
	assert(pos >= 0 && pos < count);
	Node<T>* newNode = new Node<T>(val);
	Node<T>* temp = head;
	if (pos == 0) {
		newNode->next = head;
		head = newNode;
	}
	else
	{
		for (int i = 0; i < pos - 1; i++) {
			temp = temp->next;
		}
		newNode->next = temp->next;
		temp->next = newNode;
	}
	count++;
}

template<class T>
void LinkedList<T>::DeleteAt(int pos)
{
	assert(pos >= 0 && pos < count);
	Node<T>* temp = head;
	if (pos == 0)
	{
		head = head->next;
		delete temp;
	}
	else
	{
		for (int i = 0; i < pos - 1; i++)
			temp = temp->next;
		Node<T>* del = temp->next;
		temp->next = del->next;
		delete del;
		if (pos == count - 1)
			tail = temp;
	}
	count--;
}

template<class T>
void LinkedList<T>::Append(T val)
{
	Node<T>* temp = new Node<T>(val);
	if (count == 0) {
		tail = head = temp;
	}
	else {
		tail->next = temp;
		tail = temp;
	}
	count++;
}

template<class T>
T LinkedList<T>::At(int pos)
{
	assert(pos >= 0 && pos < count);
	Node<T>* temp = head;
	for (int i = 0; i < pos; i++) {
		temp = temp->next;
	}

	return temp->value;
}