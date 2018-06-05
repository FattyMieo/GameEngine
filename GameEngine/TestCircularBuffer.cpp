/*
#include <iostream>
#include <conio.h>
#include "CircularBuffer.h"

using namespace std;

int main(void)
{
	CircularBuffer cb;
	bool reverse = false;

	while (true)
	{
		char input;

		system("CLS");
		if (reverse)
		{
			cout << "  ";
		}
		for (int i = 0; i < cb.GetSize(); i++)
		{
			cout << cb.GetValue(i) << " ";
		}
		if (reverse)
		{
			cout << "\r";
		}

		//cin >> input;
		
		input = _getch();
		if (input == '\b')
		{
			cb.PopFront();
		}
		else if (input == '\r')
		{
			cb.PopBack();
		}
		else if (input == '\t')
		{
			reverse = !reverse;
		}
		else
		{
			if (!reverse)
			{
				cb.PushFront(input);
			}
			else
			{
				cb.PushBack(input);
			}
		}
	}

	system("PAUSE");
	return 0;
}
*/