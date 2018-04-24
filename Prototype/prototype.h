#pragma once

class Prototype
{
protected:

	string type;
	int value;

public:
	virtual Prototype* clone() = 0;

	std::string getType()
	{
		return type;
	}

	int getValue()
	{
		return value;
	}
};
