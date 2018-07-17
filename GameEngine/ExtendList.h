#pragma once

#include <list>

namespace ExtendList
{
	template<class T>
	T Get(std::list<T> mList, std::size_t index)
	{
		std::list<T>::iterator it = mList.begin();
		std::size_t count = 0;

		while (it != mList.end())
		{
			if (count == index)
				return *it;

			it++;
			count++;
		}

		return NULL;
	}
}
