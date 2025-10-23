#pragma once
#include <string>

/*Raw-pointer based; info in Node will be STRINGS (convenient)*/
struct Node
{
	std::string info{};
	Node* pNext{}; //pointer to (address of) next node in list 

	Node() = default;
	Node(const std::string& info, Node* pNext);

};

class SinglyLinkedList
{
	Node* pHead{};
	Node* pTail{};

public:
	SinglyLinkedList() = delete;
	SinglyLinkedList(const std::string& valueInitiallyInHead);

	/*@brief O(1) complexity! To be used for queue's "enqueue" implementation (queues insert at rear (back))*/
	void pushBack(const std::string& newEndValue);
	/*@brief O(1) complexity. To be used for queue's "dequeue" (FIFO -> (front in line is first out)*/
	void popFront();

	/*@brief Returns, but does not remove, the person at the front of the list*/
	std::string peekFront();
};


