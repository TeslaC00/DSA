#include "LinkedList.hpp"
#include <iostream>
#include "leetcode/q4.cpp"

int main()
{
	return 0;
}

static void linkedListTest() {
	LinkedList list;
	std::cout << "List size when empty " << list.size() << " \n";
	std::cout << "List isEmpty when empty " << list.isEmpty() << " \n";
	list.insertFirst(1);
	list.insertLast(100);
	list.insertAt(1, 10);
	list.insertAt(3, 5);
	list.print();
	list.removeLast();
	list.removeAt(1);
	list.removeFirst();
	std::cout << "List indexOf when element is present " << list.indexOf(100) << " \n";
	list.removeValue(100);
	std::cout << "List contains when element is absent " << std::boolalpha << list.contains(100) << " \n";
	list.print();
}

static void q4() {
	Solution sol;
	double median = sol.findMedianSortedArrays({ 1,2 }, { 3,4 });
	std::cout << median << std::endl;
}