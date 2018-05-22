#include "CircularBuffer.h"

inline int ToNext(int num, int add)
{
	return (num + add) % BUFFER_SIZE;
}

inline int ToPrev(int num, int minus)
{
	return (num - minus) + (num < minus ? BUFFER_SIZE : 0);
}

int CircularBuffer::GetSize()
{
	return size;
}

char CircularBuffer::GetValue(int index)
{
	int realIndex = (back + index) % BUFFER_SIZE;

	return array[realIndex];
}

char CircularBuffer::GetFront()
{
	return array[front];
}

char CircularBuffer::GetBack()
{
	return array[back];
}

void CircularBuffer::Push(char value)
{
	array[front] = value;
	front = (front + 1) % BUFFER_SIZE;
	++size;

	//Check if Overflow happens
	int overflow = size - BUFFER_SIZE;

	if (overflow > 0) 
	{
		//std::cout << "Buffer overflow!" << std::endl;
		size -= overflow;
		back = (back + overflow) % BUFFER_SIZE;
	}
}

char CircularBuffer::PopFront()
{
	if(size <= 0)
	{
		//std::cout << "Buffer empty, nothing to pop!" << std::endl;
		return NULL;
	}

	char ret = GetFront();

	front = (front - 1) + (front < 1 ? BUFFER_SIZE : 0);
	--size;
	return ret;
}

char CircularBuffer::PopBack()
{
	if (size <= 0)
	{
		//std::cout << "Buffer empty, nothing to pop!" << std::endl;
		return NULL;
	}

	char ret = GetBack();

	back = (back + 1) % BUFFER_SIZE;
	--size;
	return ret;
}

CircularBuffer::CircularBuffer()
{
	back = 0;
	front = 0;
	size = 0;
}