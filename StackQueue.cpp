// StackQueues.cpp : Defines the exported functions for the DLL application.
//

#include "StackQueue.h"

ArrayBasedStack::ArrayBasedStack(void)
{
	currentIndex = -1;
}

ArrayBasedStack::~ArrayBasedStack(void)
{
	//Generic Deconstructor
}

bool ArrayBasedStack::isEmpty() const
{
	if (currentIndex == -1)
	{
		return true;
	}

	return false;
}

bool ArrayBasedStack::push(const int & val)
{
	bool success = false;

	if (currentIndex < 9)
	{
		stackData[currentIndex + 1] = val;
		currentIndex++;
		success = true;
	}

	return success;
}

bool ArrayBasedStack::pop()
{
	if (this->isEmpty())
	{
		return false;
	}

	stackData[currentIndex] = 0;
	currentIndex--;

	return true;
}

std::string ArrayBasedStack::toString() const 
{
	if (this->isEmpty())
	{
		return "";
	}	

	std::string result = "";
	for (int i = 0; i < currentIndex + 1; i++)
	{
		result += std::to_string(stackData[i]) + " ";
	}

	return result;
}

int ArrayBasedStack::peek() const
{
	if (this->isEmpty())
	{
		throw "ADT is emtpy";
	}
	else
	{
		return stackData[currentIndex];
	}
}

ArrayBasedQueue::~ArrayBasedQueue(void)
{
	//Generic Deconstructor
}

ArrayBasedQueue::ArrayBasedQueue(void)
{
	startIndex = 0;
	endIndex = -1;
	queueSize = 0;
}

bool ArrayBasedQueue::isEmpty() const
{
	if (queueSize == 0)
	{
		return true;
	}

	return false;
}

bool ArrayBasedQueue::enQueue(const std::string &val)
{
	// If there is no room in  the Queue, fail enQueue
	if (endIndex >= 100)
	{
		return false;
	}

	queueData[endIndex + 1] = val;
	endIndex++;
	queueSize++;

	return true;
}

bool ArrayBasedQueue::deQueue()
{
	// If the stack is empty, fail the deQueue
	if(this->isEmpty())
	{
		return false;
	}

	queueData[startIndex] = "";
	startIndex++;
	queueSize--;

	return true;
}

std::string ArrayBasedQueue::toString() const
{
	if (this->isEmpty())
	{
		return "";
	}	

	std::string result = "";
	for (int i = startIndex; i < endIndex + 1; i++)
	{
		result += queueData[i]+ " ";
	}

	return result;
}

std::string ArrayBasedQueue::peek() const
{
	if (this->isEmpty())
	{
		throw "ADT is emtpy";
	}
	else
	{
		return queueData[startIndex];
	}
}
