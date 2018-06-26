#include <iostream>
#include <conio.h>
#include "BitData.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define TOTAL_BITS sizeof(int) * 8

using namespace std;

enum KEYSTATE
{
	KEYSTATE_INVALID = 0,
	KEYSTATE_UP,
	KEYSTATE_DOWN,
	KEYSTATE_SPACE,
	KEYSTATE_ENTER,
	KEYSTATE_0,
	KEYSTATE_1,
};

KEYSTATE DetectKey()
{
	char c = _getch();

	if (c == (char)0 || c == (char)224) // if the first value is special key
	{
		switch ((int)_getch())
		{
		case KEY_UP:
			// code for arrow up
			return KEYSTATE_UP;
			break;
		case KEY_DOWN:
			// code for arrow down
			return KEYSTATE_DOWN;
			break;
		}
	}
	else if (c == ' ')
	{
		return KEYSTATE_SPACE;
	}
	else if (c == '\r')
	{
		return KEYSTATE_ENTER;
	}
	else if (c == '0')
	{
		return KEYSTATE_0;
	}
	else if (c == '1')
	{
		return KEYSTATE_1;
	}

	return KEYSTATE_INVALID;
}

void ListContent(BitData data, int curPos)
{
	cout << endl;

	cout << "    Bit Data" << endl;

	cout << endl;

	cout << "     ";
	for (int i = 0; i < 6; i++)
		cout << (char)177;
	cout << endl;

	for (int i = 0; i < TOTAL_BITS; i++)
	{
		cout << "     ";
		for (int j = 0; j < 2; j++)
			cout << (data.Get(i) ? (char)178 : (char)176);

		cout << (i < 10 ? "0" : "") << i;

		for (int j = 0; j < 2; j++)
			cout << (data.Get(i) ? (char)178 : (char)176);

		if (i == curPos)
			cout << " " << (char)254;

		cout << endl;
	}

	cout << "     ";
	for (int i = 0; i < 6; i++)
		cout << (char)177;
	cout << endl;

	cout << endl;
}

int main(void)
{
	BitData bitData;
	int curPos = 0;

	while (true)
	{
		system("CLS");
		ListContent(bitData, curPos);

		switch (DetectKey())
		{
			case KEYSTATE_UP:
				curPos--;
				if (curPos < 0)
					curPos = 0;
				break;
			case KEYSTATE_DOWN:
				curPos++;
				if (curPos >= TOTAL_BITS)
					curPos = TOTAL_BITS - 1;
				break;
			case KEYSTATE_SPACE:
				bitData.Set(curPos, !bitData.Get(curPos));
				break;
			case KEYSTATE_0:
				bitData.Set(curPos, false);
				break;
			case KEYSTATE_1:
				bitData.Set(curPos, true);
				break;
			case KEYSTATE_ENTER:
				bitData.Reset();
				break;
		}
	}

	return 0;
}