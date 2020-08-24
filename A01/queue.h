#pragma once
#include <iostream>
using namespace std;

template <class dataType>
class queue
{
	//Variables
private:
	int queueSize;		//how large array is
	int numberOfItems;	//number of items in array
	dataType* queuePtr;	//pointer to array

public:
	//Constructor
	queue()
	{
		queueSize = 1;
		numberOfItems = 0;
		queuePtr = new dataType[queueSize]();
	};

	//Destructor
	~queue()
	{
		delete[] queuePtr;
		queueSize = 0;
		queuePtr = nullptr;
	};

	//Copy Constructor
	queue(const queue& other)
	{
		queueSize = other.queueSize;
		numberOfItems = other.numberOfItems;
		queuePtr = new dataType[queueSize];

		for (int i = 0; i < queueSize; i++)
		{
			queuePtr[i] = other.queuePtr[i];
		}
	};

	//Copy Assignment Operator
	queue& operator =(const queue& other)
	{
		if (this == &other)
		{
			return *this;
		}

		if (queuePtr != nullptr)
		{
			delete[] queuePtr;
			queuePtr = nullptr;
		}

		queueSize = other.queueSize;
		queuePtr = new dataType[queueSize];

		copy(other.queuePtr, other.queuePtr + other.queueSize, queuePtr);

		return *this;
	};

	//Push Method - Pushes new item to queue and sorts it
	void Push(dataType newItem)
	{
		if (queueSize == numberOfItems)		//transfers data to temp array, makes queue array bigger, puts data back in queue array, deletes temp array
		{
			dataType* tempPtr = new dataType[queueSize]();	//stores values while queue is expanded
			copy(queuePtr, queuePtr + queueSize, tempPtr);
			delete[] queuePtr;
			queueSize *= 2;
			queuePtr = new dataType[queueSize]();
			copy(tempPtr, tempPtr + queueSize / 2, queuePtr);
			delete[] tempPtr;
			tempPtr = nullptr;
		}
		for (int i = 0; i < queueSize; i++)	//adds new item
		{
			if (queuePtr[i] == NULL)
			{
				queuePtr[i] = newItem;
				break;
			}
		}
		numberOfItems++;

		for (int i = numberOfItems - 1; i > 0; i--)		//sorts items by lowest value first
		{
			if (queuePtr[i] < queuePtr[i - 1])
			{
				queuePtr[i] = queuePtr[i - 1];
				queuePtr[i - 1] = newItem;
			}
		}
	};

	//Pop Method - Returns item in front and removes it
	dataType Pop()
	{
		dataType toReturn = 0;
		if (numberOfItems > 0)		//returns NULL if queue is empty
		{
			toReturn = queuePtr[0];		//grabs item at front of queue
			numberOfItems--;
			for (int i = 0; i < numberOfItems; i++)	//shifts all items forward one index to fill gap
			{
				queuePtr[i] = queuePtr[i + 1];
			}
			queuePtr[numberOfItems] = NULL;
		}
		else
		{
			return NULL;
		}
		return toReturn;
	};

	//Print Method - Prints all items on the queue
	void Print()
	{
		for (int i = 0; i < queueSize; i++)
		{
			if (queuePtr[i] != 0)
			{
				cout << i << ": " << queuePtr[i] << endl;
			}
		}
		cout << endl;
	};

	//GetSize Method - Returns number of elements on queue
	int GetSize()
	{
		return numberOfItems;
	};

	//IsEmpty Method - Returns true if there is any data on queue, otherwise false
	bool IsEmpty()
	{
		if (queuePtr[0] == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	};
};