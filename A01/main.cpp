#include <iostream>
#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>
#include "queue.h"
using namespace std;

void wrapper()
{
	//queue of ints and testing GetSize
	cout << "int queue and GetSize tests" << endl;
	queue<int> intQueue;
	intQueue.Push(5);
	intQueue.Push(1);
	intQueue.Push(7);
	intQueue.Push(9);
	intQueue.Push(3);
	intQueue.Print();
	cout << "Size: " << intQueue.GetSize() << endl << endl;

	intQueue.Pop();
	intQueue.Pop();
	intQueue.Print();
	cout << "Size: " << intQueue.GetSize() << endl << endl;

	//queue of chars and testing IsEmpty
	cout << "char queue and isEmpty tests" << endl;
	queue<char> charQueue;

	cout << "isEmpty: " << charQueue.IsEmpty() << endl;
	charQueue.Push('C');
	charQueue.Push('A');
	charQueue.Push('D');
	charQueue.Push('B');
	charQueue.Push('E');
	charQueue.Print();
	cout << "isEmpty: " << charQueue.IsEmpty() << endl << endl;;

	charQueue.Pop();
	charQueue.Pop();
	charQueue.Print();

	//queue of floats
	cout << "float queue" << endl;
	queue<float> floatQueue;
	floatQueue.Push(5.5f);
	floatQueue.Push(1.1f);
	floatQueue.Push(7.7f);
	floatQueue.Push(9.9f);
	floatQueue.Push(3.3f);
	floatQueue.Print();

	floatQueue.Pop();
	floatQueue.Pop();
	floatQueue.Print();

	//testing copy constructor and copy assignment operator
	cout << "Testing Copy Constructor and Assignment Operator" << endl;
	queue<int> intQueue2(intQueue);
	intQueue2.Print();

	intQueue2.Pop();
	intQueue2.Pop();
	intQueue2.Print();

	intQueue2 = intQueue;
	intQueue2.Print();
}

int main()
{
	wrapper();
	_CrtDumpMemoryLeaks();
}