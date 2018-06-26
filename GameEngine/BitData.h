#pragma once

class BitData
{
private:
	unsigned int m_data;

public:
	BitData();

	void Reset();
	void Set(int location, bool flag);
	bool Get(int location);
};