#include "SinglyLinkedList.h"

SinglyLinkedList::SinglyLinkedList(const std::string& valueInitiallyInHead)
{

}

void SinglyLinkedList::pushBack(const std::string& newEndValue)
{
	Node* pNew = new Node(newEndValue, nullptr);
	//update previous tail node's next pointer to point at this new guy: 
	pTail->pNext = pNew;
	pTail = pNew; //pNew is the tail now
}

void SinglyLinkedList::popFront()
{
	//A PROPER approach should verify the list is not empty (pHead != nullptr) first!

	//briefly: just move pHead forward one step:
	pHead = pHead->pNext;

	/*NOTE that the non-leaky way is: */
	//Node* temp = pHead; 
	//pHead = pHead->pNext; 
	//delete temp; //deallocates the memory occupied by the previous head (which is no longer in the list)
	/*Or just use smart pointers to nodes instead of raw pointers*/
}

std::string SinglyLinkedList::peekFront()
{
	return pHead->info;
}