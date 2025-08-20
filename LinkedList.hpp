#pragma once
#include <vector>

struct Node
{
	int m_data;
	Node* m_next = nullptr;
	Node* m_prev = nullptr;

	Node() :m_data(0) {}
	Node(int value) :m_data(value) {}
	Node(int value, Node* prev) :m_data(value), m_prev(prev) {}
	Node(int value, Node* next, Node* prev) :m_data(value), m_next(next), m_prev(prev) {}
};

class LinkedList
{
public:
	LinkedList()
	{
		m_size = 0;
		m_head = nullptr;
	}

	~LinkedList()
	{
		clear();
	}

	int size() const;
	bool isEmpty() const;
	void insertFirst(int value);
	void insertLast(int value);
	void insertAt(int index, int value);
	void removeFirst();
	void removeLast();
	void removeAt(int index);
	void removeValue(int value);
	int indexOf(int value) const;
	bool contains(int value) const;
	int getFirst() const;
	int getLast() const;
	int getAt(int index) const;
	std::vector<int> findAllOccurrences(int value) const;
	void swap(int value1, int value2);
	void reverse();
	void sort();
	std::vector<int> toArray() const;
	void clear();
	void print() const;
	void printReverse() const;

private:
	int m_size;
	Node* m_head;

	void insertBefore(Node* before, Node* newNode);
	void removeNode(Node* node);
};
