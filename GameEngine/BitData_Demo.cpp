#include <iostream>
#include "BitData.h"

using namespace std;

void ListContent(BitData data)
{
	for (int i = 0; i < sizeof(int) * 8; i++)
	{
		cout << i << ". ";
		if (data.Get(i))
		{
			cout << "TRUE" << endl;
		}
		else
		{
			cout << "FALSE" << endl;
		}
	}
}

int main(void)
{
	BitData bitData;

	bitData.Set(0, true);
	bitData.Set(4, true);
	bitData.Set(7, true);
	bitData.Set(8, true);

	ListContent(bitData);

	system("PAUSE");
	system("CLS");

	bitData.Set(0, false);
	bitData.Set(2, true);
	bitData.Set(4, false);
	bitData.Set(11, true);

	ListContent(bitData);

	system("PAUSE");
	system("CLS");

	bitData.Set(0, true);
	bitData.Set(1, false);
	bitData.Set(2, true);
	bitData.Set(3, true);
	bitData.Set(3, false);

	ListContent(bitData);

	system("PAUSE");

	return 0;
}