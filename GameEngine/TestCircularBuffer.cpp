#include <iostream>
#include "CircularBuffer.h"

using namespace std;

int main(void)
{
	CircularBuffer cb;

	while (true)
	{
		char input;
		cin >> input;
		cb.Push(input);

		for (int i = 0; i < cb.GetSize(); i++)
		{
			cout << cb.GetValue(i) << " ";
		}
		cout << endl;
	}

	system("PAUSE");
	return 0;
}