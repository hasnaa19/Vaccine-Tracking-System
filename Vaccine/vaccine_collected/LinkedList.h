#pragma once
template <class T>
class Node {
public:
	T value;
	Node<T>* next;

	Node();
	Node(T);
};
template <class T>
class LinkedList
{
public:
	int count;
	Node<T>* head;
	Node<T>* tail;

	LinkedList();
	int Length();
	void InsertAt(int, T);
	void DeleteAt(int);
	void Append(T);

	T At(int);
};

