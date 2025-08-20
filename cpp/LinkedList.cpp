#include "LinkedList.hpp"
#include <iostream>

// TODO: make this list doubly and add object type support
// TODO: modify index out of bound error to tell index and size of list
// TODO: use for loop instead of while

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
	// FIX: use remove node directly instead of remove last
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

// FIX: better return value for this function as -1 is not expressive enough
int LinkedList::getFirst() const
{
	if (isEmpty())
	{
		return -1;
	}
	return m_head->m_data;
}

int LinkedList::getLast() const
{
	return getAt(m_size - 1);
}

// FIX: better return value for this function as -1 is not expressive enough
int LinkedList::getAt(int index) const
{
	if (isEmpty())
	{
		return -1;
	}

	if (index<0 || index > m_size)
	{
		throw std::out_of_range("Index below 0 or more than size of list are not Allowed");
	}

	Node* current = m_head;
	for (int i = 0; i < index; i++)
	{
		current = current->m_next;
	}
	return current->m_data;
}

std::vector<int> LinkedList::findAllOccurrences(int value) const
{
	if (isEmpty())
	{
		return std::vector<int>(0);
	}

	std::vector<int> indexes(0);
	Node* current = m_head;
	for (int i = 0; i < m_size; i++)
	{
		if (current->m_data == value)
		{
			indexes.push_back(i);
		}
	}

	return indexes;
}

void LinkedList::swap(int value1, int value2)
{
	if (isEmpty())
	{
		return;
	}

	int index1 = indexOf(value1);
	int index2 = indexOf(value2);

	if (index1 == -1 || index2 == -1)
	{
		return;
	}

	Node* current = m_head;
	int smallIndex = 0, bigIndex = 0;

	if (value1 >= value2)
	{
		smallIndex = value2;
		bigIndex = value1;
	}
	else
	{
		smallIndex = value1;
		bigIndex = value2;
	}

	Node* swap = new Node();
	for (int i = 0; i <= bigIndex; i++)
	{
		if (i == smallIndex)
		{
			swap = current;
		}
		current = current->m_next;
	}

	int tempData = current->m_data;
	current->m_data = swap->m_data;
	swap->m_data = tempData;
}

void LinkedList::reverse()
{
	// TODO: Implement this function
}

void LinkedList::sort()
{
	// TODO: Implement this function
}

std::vector<int> LinkedList::toArray() const
{
	if (isEmpty())
	{
		std::vector<int>();
	}

	std::vector<int> result;
	result.reserve(m_size);

	Node* current = m_head;
	for (int i = 0; i < m_size; i++)
	{
		result.emplace_back(current->m_data);
		current = current->m_next;
	}

	return result;
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

void LinkedList::printReverse() const
{
	// TODO: Implement this function
}
