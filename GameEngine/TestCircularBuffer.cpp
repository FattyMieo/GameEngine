#include <iostream>
#include <conio.h>
#include "CircularBuffer.h"

using namespace std;

int main(void)
{
	CircularBuffer cb;

	while (true)
	{
		char input;

		system("CLS");
		for (int i = 0; i < cb.GetSize(); i++)
		{
			cout << cb.GetValue(i) << " ";
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
		else
		{
			cb.Push(input);
		}
	}

	system("PAUSE");
	return 0;
}