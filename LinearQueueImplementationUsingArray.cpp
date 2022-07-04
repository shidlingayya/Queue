#include <iostream>
#include <forward_list>

class Queue
{
public:
	Queue(int size);
	void Enqueue(int data);
	int Dequeue();
	int Peek();
	void Display();
	~Queue();
private:
	int* arr;
	int count;
	int front; //Pointer to front
	int rear;
	int capacity;
	bool IsEmpty();
	bool IsFull();
};

//Initial Values
Queue::Queue(int size)
{
	capacity = size;
	arr = new int[size];
	front = 0;
	rear = -1;
	count = 0;
}

Queue::~Queue()
{
	if (arr)
	{
		delete[]arr;
		arr = nullptr;
	}
}

bool Queue::IsEmpty()
{
	if (count == 0)
	{
		return true;
	}
	return false;
}

bool Queue::IsFull()
{
	if (count == capacity)
	{
		return true;
	}
	return false;
}

//Function to delete front element
int Queue::Dequeue()
{
	if (IsEmpty())
	{
		std::cout << "Queue empty" << std::endl;
		exit(EXIT_FAILURE);
	}
	int elem_deleted = arr[front];
	front = (front + 1) % capacity;	
	count--;
	return elem_deleted;
}

void Queue::Enqueue(int data)
{
	if (IsFull())
	{
		std::cout << "Queue alrady full" << std::endl;
		exit(EXIT_FAILURE);
	}
	rear = (rear + 1) % capacity;
	arr[rear] = data;
	count++;
}

void Queue::Display()
{
	if (IsEmpty())
	{
		std::cout << "Queue is empty" << std::endl;
		exit(EXIT_FAILURE);
 	}
	for (auto i = front; i <= rear; i++)
	{
		std::cout << arr[i] << "->";
	}
	std::cout << std::endl;
}

int Queue::Peek()
{
	if (IsEmpty())
	{
		std::cout << "Queue is empty" << std::endl;
		exit(EXIT_FAILURE);
	}
	return(arr[front]);
}

int main()
{ 
	Queue queue(5);
	queue.Enqueue(10);
	queue.Enqueue(20);
	queue.Enqueue(30);
	queue.Enqueue(40);
	queue.Display();

	std::cout << "Delete top element: " << queue.Dequeue() << std::endl;
	queue.Display();
	std::cout << "Peek element in queue: " << queue.Peek() << std::endl;
	return 0;
}