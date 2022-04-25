#pragma once
#include <string>

class Iweapon
{
public:
	virtual std::string GetDescription() = 0;
	virtual std::string GetStats() = 0;
};

