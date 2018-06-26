#include "BitData.h""

BitData::BitData()
{
	Reset();
}

void BitData::Reset()
{
	m_data = 0;
}

void BitData::Set(int location, bool flag) //Location starts at 0
{
	if (flag == Get(location)) return;

	m_data += (1 << location) * (flag ? 1 : -1);
}

bool BitData::Get(int location)
{
	return (m_data >> location) & 1;
}