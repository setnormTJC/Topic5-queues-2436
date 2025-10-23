#pragma once
#include <string>
#include <vector>
#include "SinglyLinkedList.h"


namespace MySpace
{
	class QueueADT
	{
	protected:
		/*Enqueue puts a customer (process) in line at the back*/
		virtual void enqueue(const std::string& thingToEnqueue) = 0;
		/*REMOVES the first guy in line*/
		virtual void dequeue() = 0; //this is pronounced Dee-CUE, (not deck) deque (double-ended queue) 
	};

	/*implemented using a C-style array (as opposed to a linked list (node) - based implementation*/
	class NaiveQueue : public QueueADT
	{
	private:
		static const int MAX_QUEUE_CAPACITY = 5; //presumably, our RAM is not INFINITE

		std::string theQueueData[MAX_QUEUE_CAPACITY]; //C-style array ( an example of a software DESIGN choice) 

		//int indexOfFIRSTElement; //... not always 0! -> play around with "circular arrays" (involving the mod operator) if desired 
		int indexOfLastElement = -1; //empty initially, with default constructor

	public:
		/*pushes element in at the end of the queue*/
		void enqueue(const std::string& thingToEnqueue);
		/*Removes element at the front of the queue*/
		virtual void dequeue();

		NaiveQueue();

	};

	/*Uses a "circular" array - which requires additional SPACE complexity but has better TIME complexity for dequeuing
* Note the tradeoff between time and space
*/
	class CircularStaticQueue : public QueueADT
	{
	private:
		static const int MAX_QUEUE_CAPACITY = 5;

		std::string theQueueData[MAX_QUEUE_CAPACITY];

		/*the index of the first element (AKA: "customer to be serviced") in the queue*/
		int first = -1; // initialize to -1 because default constructor will make empty strings in `theQueueData` array 
		int last = -1;

	public:
		void enqueue(const std::string& thingToEnqueue) override;

		/*N.B. "chaining" example: queueName.enqueue("Thing 1).enqueue("Thing 2")
		Just a "convenience" method */
		CircularStaticQueue& enqueueWithChaining(const std::string& thingToEnqueue);

		/*Aiming at average time complexity O(1) here...*/
		void dequeue() override;

		bool isEmpty() const;
		bool isFull();

		std::string front() const;

		CircularStaticQueue();

		void print();

		/*******************"Extra" methods****************/


		CircularStaticQueue& inPlaceMerge(CircularStaticQueue& other);

		/*NOTE: this method will EMPTY "this" queue and "other" queue
		* ALSO note: this method relies on `enqueue`'s safety check for a full queue
		*/
		CircularStaticQueue outOfPlaceMerge(CircularStaticQueue& other);
	};

	class QueueFromLinkedList : public QueueADT
	{
		SinglyLinkedList theQueueData; //NOTE: above we used a C-style array here

	public: 
		QueueFromLinkedList(const std::string& valueInitiallyAtFrontOfQueue); 
		void enqueue(const std::string& thingToEnqueue) override;
		void dequeue() override; 
	};

	/*SHOULD a queue's max capacity be able to grow and shrink?
	* Suppose your queue was previously serviced by a slow processor (cashier) - and now a faster one is used?
	* Or the amount of available memory (RAM) on your machine increases
	*/
	class ResizeableQueue : public QueueADT
	{
	private:
		std::vector<std::string> theQueueData;
		int capacity = 5; //non-const!
	public:
		ResizeableQueue();

		void enqueue(const std::string& thingToEnqueue);
		/*Aiming at average time complexity O(1) here...*/
		void dequeue();

		bool isEmpty() const;

		/******************************************OPTIONAL member functions*******************/
		/*a resizeable queue might be a "natural" candidate for an inplace merge*/
		void inPlaceMerge(const ResizeableQueue& otherQueue);

		/*return by reference?*/
		ResizeableQueue outOfPlaceMerge(const ResizeableQueue& otherQueue);

		void appendOtherQueue(const ResizeableQueue& otherQueue);
	};
}