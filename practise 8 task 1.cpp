#include <iostream>
using namespace std;

template<typename T>
class Dequeue 
{
	int rear;
	int front;
	int noe;
	int capacity;
	T* data;
	void reSize(int newsize)
	{
		T* temp = new T[newsize];
		noe = rear;
		for (int i = 0; i < noe; i++)
			temp[i] = data[i];
		this->~Dequeue();
		rear = noe;
		data = temp;
		capacity = newsize;
	}

public:

	void inserTail(T val)
	{
		if (isFull())
		{
			reSize(capacity == 0 ? 1 : capacity * 2);
		}
		data[rear] = val;
		rear++;
		noe++;
	}

	void insertHead(T a)
	{

		if (isFull())
		{
			reSize(capacity == 0 ? 1 : capacity * 2);
		}
		front--;
		data[front] = a;
		noe++;

	}

    T deleteTail()
	{

		if (isEmpty()) exit(0);
		noe--;
		T val = data[rear];
		rear--;
		if (rear > 0 && (capacity / 4) == rear) reSize(capacity / 2);
		return val;

	}
	T deleteHead()
	{
		if (isEmpty()) exit(0);
		noe--;
		T val = data[front];
		front++;
//		if (front < rear && (capacity / 4) == rear) reSize(capacity / 2);
		return val;
	}

	Dequeue();
	Dequeue(const Dequeue <T>& rhs);
//	Dequeue& operator = (const Dequeue<T>& rhs);
	~Dequeue();
	bool isEmpty()const;
	bool isFull()const;
	int getCapacity() const;
	int getNumberOfElements() const;

};


template <typename T>
Dequeue<T> ::Dequeue()
{
	rear = 0;
	front = 0;
	capacity = 0;
	noe = 0;
	T* data = nullptr;
}

template <typename T>
Dequeue<T> ::Dequeue(const Dequeue <T>& rhs)
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
bool Dequeue<T> ::isFull() const
{
	if (noe == capacity)return true;
	return  false;
}

template < typename T>
bool Dequeue<T> ::isEmpty() const
{
	if (noe == 0)return true;
	return  false;
}

template < typename T>
int Dequeue<T> ::getCapacity() const
{
	return capacity;
}

template < typename T>
int Dequeue<T> ::getNumberOfElements() const
{
	return noe;
}


int main()
{
	Dequeue <int> s;
	for (int i = 0; i < 12; i++)
	{
	if ( i<6)	s.inserTail(i);
	else
	{
		s.insertHead(i * 10);
	}
	}
	cout << " **** " << endl;
	for (int i = 0; i < 12; i++)
	{
		cout << s.deleteTail() << endl;;
	}
}