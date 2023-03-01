#include "Queue.h"
#include <iostream>
using namespace std;

template <typename T>
Queue<T> :: Queue()
{
	 rear =0 ;
	 front =0;
	capacity=0;
	 noe=0;
	T* data = nullptr;
}

template <typename T>
Queue<T> ::Queue(const Queue <T>& rhs)
{
	rear = rhs.rear;
	front = rhs.front;
	noe = rhs.noe;
	capacity = rhs.capacity;
	for (int i = 0; i < noe; i++)
	{
		data[i] = rhs.data[i];
	}

}

template <typename T>
Queue<T>&  Queue<T> :: operator = (const Queue<T>& rhs)
{
	rear = rhs.rear;
	front = rhs.front;
	noe = rhs.noe;
	capacity = rhs.capacity;
	for (int i = 0; i < noe; i++)
	{
		data[i] = rhs.data[i];
	}
}

template < typename T>
Queue<T> ::~Queue()
{
	/*if (data != nullptr)
	{
		delete[] data;
		data = nullptr;
		rear = 0;
		front = 0;
		capacity = 0;
		noe = 0;
	}*/
}

template < typename T>
void Queue<T> :: enQueue(T val)
{
	if (isFull())
	{
		reSize(capacity == 0 ? 1 : capacity * 2);
	}
	data[rear] = val;
	rear++;
	noe++;
}


template < typename T>
T Queue<T> ::deQueue()
{
	if (isEmpty()) exit(0);
	noe--;
	T val = data[front];
	front++;
	if (rear > 0 && (capacity / 4) == rear) reSize(capacity / 2);
	return val;
}


template < typename T>
T Queue<T> :: getElementsAtFront() const
{
	if (!isEmpty())
	{
		return data[front];
	}
}

template < typename T>
void Queue<T> ::change(T val)
{
	data[front] = val;
}


template < typename T>
bool Queue<T> ::isFull() const
{
	if (noe == capacity)return true;
	return  false;
}

template < typename T>
bool Queue<T> ::isEmpty() const
{
	if (noe == 0)return true;
	return  false;
}

template < typename T>
int Queue<T> ::getCapacity() const
{
	return capacity;
}

template < typename T>
int Queue<T> ::getNumberOfElements() const
{
	return noe;
}

/*
int main()
{

	Queue<int> s;
	for (int i = 0; i < 12; i++)
	{
		s.enQueue(i);
	}
	cout << " **** " << endl;
	for ( int i =0 ; i < 5 ; i++)
	{
		cout << s.deQueue() << endl;;
	}
	//cout << " printing again ";
	//for (int i = 1; i < 10; i++)
	//{
	//	s.enQueue(i*10);
	//}
	//while (!s.isEmpty())
	//{
	//	cout << s.deQueue() << endl;;
	//}
}
*/