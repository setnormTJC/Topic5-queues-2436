#include "MyQueue.h"
#include <iostream>

void MySpace::NaiveQueue::enqueue(const std::string& thingToEnqueue)
{
	if (indexOfLastElement > MAX_QUEUE_CAPACITY - 1)
	{
		throw std::exception("queue is full - cannot add more");
	}

	indexOfLastElement++;
	theQueueData[indexOfLastElement] = thingToEnqueue;
}

void MySpace::NaiveQueue::dequeue()
{
	if (indexOfLastElement == -1)
	{
		throw std::exception("queue is empty - cannot remove from empty queue");
	}

	std::cout << "Dequeueing " << theQueueData[0] << "\n";

	//O(N) complexity! (bad)
	//move previous second element to the first position, third to second, etc.: 
	for (int i = 1; i <= indexOfLastElement; ++i)
		//+ 1 to overwrite the former last element with empty string (goes out of bounds if queue is FULL!)
	{
		theQueueData[i - 1] = theQueueData[i];
	}

	//set the last element to the empty string: 
	theQueueData[indexOfLastElement] = "";

	indexOfLastElement--;
}

MySpace::NaiveQueue::NaiveQueue()
{
	for (int i = 0; i < MAX_QUEUE_CAPACITY; ++i)
	{
		theQueueData[i] = ""; //EXPLICITLY initializing all queue elements to empty string
	}
}

void MySpace::CircularStaticQueue::enqueue(const std::string& thingToEnqueue)
{
	if (isFull()) throw std::exception("queue is full - cannot add more");

	else if (isEmpty())
	{
		//set both first and last to 0 (the first index in an array)
		first = 0;
		last = 0;
		//(equivalently: first++; last++)
	}

	else
	{
		//last++;  //this is ONE way to do it

		last = (last + 1) % MAX_QUEUE_CAPACITY; //ANOTHER way (getting "circular")
		//ex: if last == -1 (initially empty), this becomes last = (-1 + 1) % 5 = 0
		//and if last == 0 (before calling this function), this becomes (0 + 1) % 5 = 1
		//...
		//and if last == 4, this becomes (4 + 1) % 5 = 0

		//Now this last example MIGHT seem like it overwrites the FIRST value in the queue
		//BUT look into the definition of `isFull` for that:
		//(returns true if (last + 1) % MAX_QUEUE_CAPACITY == first; -> (4 + 1) % 5 = 0 == 0

	}

	//now put the thing in: 
	theQueueData[last] = thingToEnqueue;
}

MySpace::CircularStaticQueue& MySpace::CircularStaticQueue::enqueueWithChaining(const std::string& thingToEnqueue)
{
	if (isFull()) throw std::exception("queue is full - cannot add more");

	else if (isEmpty())
	{
		//set both first and last to 0 (the first index in an array)
		first = 0;
		last = 0;
		//(equivalently: first++; last++)
	}

	else
	{
		last = (last + 1) % MAX_QUEUE_CAPACITY; //ANOTHER way (getting "circular")
	}

	theQueueData[last] = thingToEnqueue;

	return *this;
}

void MySpace::CircularStaticQueue::dequeue()
{
	if (isEmpty()) throw std::exception("Queue is empty");

	//std::cout << "Dequeueing " << theQueueData[first] << "\n";

	if (first == last) //this means queue will be emptied as a result of this dequeue! "Flip reset"
	{
		first = -1;
		last = -1;
	}

	//first++; //not the best approach...
	else
	{
		first = (first + 1) % MAX_QUEUE_CAPACITY; //vetted 
		//last = (last + 1) % MAX_QUEUE_CAPACITY; //DO we need to this? (oh snap!)
	}
}

bool MySpace::CircularStaticQueue::isEmpty() const
{
	if (first == -1)
	{
		return true;
	}

	else
	{
		return false;
	}
}

bool MySpace::CircularStaticQueue::isFull()
{
	//return (last == MAX_QUEUE_CAPACITY - 1); //one, "non-circular" way to do it: 

	int remainder = (last + 1) % MAX_QUEUE_CAPACITY; //making this a variable for ease of viewing in debugger...

	return remainder == first;
}

std::string MySpace::CircularStaticQueue::front() const
{
	return theQueueData[first];
}


MySpace::CircularStaticQueue::CircularStaticQueue()
{
	for (int i = 0; i < MAX_QUEUE_CAPACITY; ++i)
	{
		theQueueData[i] = ""; //again, explicitly initializing to empty strings for "clarity"
	}
}

void MySpace::CircularStaticQueue::print()
{
	while (!this->isEmpty())
	{
		//get front
		//pop
	}

	//the approach above empties the queue!
	//make a copy (or make this a "free function" that takes a queue by value (makes a copy) - not by reference)

	//or, you COULD use the underlying array implementation's subscript operator
	//this somewhat "breaks" the FIFO access, but the client does not get to access these details
}

MySpace::CircularStaticQueue& MySpace::CircularStaticQueue::inPlaceMerge(CircularStaticQueue& other)
{
	while (other.isEmpty() == false)
	{
		if (!this->isEmpty())
		{
			this->enqueue(this->front());
			this->dequeue();
		}

		if (!other.isEmpty())
		{
			this->enqueue(other.front());
			other.dequeue();
		}
	}

	return *this;
}

MySpace::CircularStaticQueue MySpace::CircularStaticQueue::outOfPlaceMerge(CircularStaticQueue& other)
{
	CircularStaticQueue newQueue;

	bool isThisQueueEmpty = this->isEmpty();
	bool isOtherQueueEmpty = other.isEmpty();

	while (isThisQueueEmpty == false || isOtherQueueEmpty == false)
	{
		if (isThisQueueEmpty == false)
		{
			newQueue.enqueue(this->front());
			this->dequeue();
			isThisQueueEmpty = this->isEmpty();
		}

		if (isOtherQueueEmpty == false)
		{
			newQueue.enqueue(other.front());
			other.dequeue();
			isOtherQueueEmpty = other.isEmpty(); //check if other queue becomes empty after dequeueing
		}
	}

	return newQueue;
}


#pragma region QueueFromLinkedList
MySpace::QueueFromLinkedList::QueueFromLinkedList(const std::string& valueInitiallyAtFrontOfQueue)
	:theQueueData(valueInitiallyAtFrontOfQueue) //NOTE: this gives a good example of why this syntax is preferred
{
}

void MySpace::QueueFromLinkedList::enqueue(const std::string& thingToEnqueue)
{
	//just call the underlying container(linked list)'s pushBack method
	theQueueData.pushBack(thingToEnqueue);
}

void MySpace::QueueFromLinkedList::dequeue()
{
	//just called the underlying implementation's popFront method: 
	theQueueData.popFront(); 
}

#pragma endregion