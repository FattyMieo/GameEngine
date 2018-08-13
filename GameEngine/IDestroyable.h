#pragma once

class IDestroyable
{
public:
	virtual bool DestroyNow() = 0;
};