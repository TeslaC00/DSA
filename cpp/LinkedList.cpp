#include "LinkedList.hpp"
#include <iostream>

int LinkedList::size() const
{
	return m_size;
}

inline bool LinkedList::isEmpty() const
{
	return m_head == nullptr;
}

void LinkedList::insertFirst(int value)
{
	insertLast(value);
	m_head = m_head->m_prev;
}

void LinkedList::insertLast(int value)
{
	Node* newNode = new Node(value);

	if (isEmpty())
	{
		m_head = newNode;
		m_head->m_next = m_head;
		m_head->m_prev = m_head;
		m_size++;
		return;
	}

	insertBefore(m_head, newNode);
}

void LinkedList::insertAt(int index, int value)
{
	if (index == 0)
	{
		insertFirst(value);
		return;
	}

	if (index == m_size)
	{
		insertLast(value);
		return;
	}

	if (index<0 || index > m_size)
	{
		throw std::out_of_range("Index below 0 or more than size of list are not Allowed");
	}

	Node* newNode = new Node(value);
	Node* currentNode = m_head->m_next;

	for (int i = 1; i < index; i++)
	{
		currentNode = currentNode->m_next;
	}

	insertBefore(currentNode, newNode);
}

void LinkedList::insertBefore(Node* before, Node* newNode)
{
	if (before == nullptr || newNode == nullptr)
	{
		return;
	}

	newNode->m_next = before;
	newNode->m_prev = before->m_prev;
	before->m_prev->m_next = newNode;
	before->m_prev = newNode;
	m_size++;
}

void LinkedList::removeFirst()
{
	if (isEmpty())
	{
		return;
	}

	if (m_size == 1)
	{
		clear();
		return;
	}

	m_head = m_head->m_next;
	removeLast();
}

void LinkedList::removeLast()
{
	if (isEmpty())
	{
		return;
	}

	if (m_size == 1)
	{
		clear();
		return;
	}

	removeNode(m_head->m_prev);
}

void LinkedList::removeAt(int index)
{
	if (index == 0)
	{
		removeFirst();
		return;
	}

	if (index == m_size)
	{
		removeLast();
		return;
	}

	if (index<0 || index > m_size)
	{
		throw std::out_of_range("Index below 0 or more than size of list are not Allowed");
	}

	Node* currentNode = m_head->m_next;

	for (int i = 1; i < index; i++)
	{
		currentNode = currentNode->m_next;
	}

	removeNode(currentNode);
}

void LinkedList::removeValue(int value)
{
	if (isEmpty())
	{
		return;
	}

	if (m_head->m_data == value)
	{
		removeFirst();
		return;
	}

	Node* currentNode = m_head->m_next;
	while (currentNode != m_head)
	{
		if (currentNode->m_data == value)
		{
			removeNode(currentNode);
			return;
		}
		currentNode = currentNode->m_next;
	}
}

int LinkedList::indexOf(int value) const
{
	if (isEmpty())
	{
		return -1;
	}

	int index = 0;
	Node* currentNode = m_head;
	do
	{
		if (currentNode->m_data == value)
		{
			return index;
		}
		currentNode = currentNode->m_next;
		index++;
	} while (currentNode != m_head);

	return -1;
}

bool LinkedList::contains(int value) const
{
	return indexOf(value) != -1;
}

void LinkedList::removeNode(Node* node)
{
	if (node == nullptr)
	{
		return;
	}

	node->m_prev->m_next = node->m_next;
	node->m_next->m_prev = node->m_prev;
	delete node;
	m_size--;
}

void LinkedList::clear()
{
	if (isEmpty())
	{
		return;
	}

	Node* currentNode = m_head;
	do
	{
		Node* nextNode = currentNode->m_next;
		delete currentNode;
		currentNode = nextNode;
	} while (currentNode != m_head);

	m_head = nullptr;
	m_size = 0;
}

void LinkedList::print() const
{
	if (isEmpty())
	{
		std::cout << "List is Empty \n";
	}

	Node* currentNode = m_head;
	std::cout << currentNode->m_data;
	currentNode = currentNode->m_next;

	while (currentNode != m_head)
	{
		std::cout << " -> " << currentNode->m_data;
		currentNode = currentNode->m_next;
	}
	std::cout << " END! \n";
}
