#pragma once


class HousePlan
{
public:
	virtual void setBasement(string basement) = 0;

	virtual void setStructure(string structure) = 0;

	virtual void setRoof(string roof) = 0;

	virtual void setInterior(string interior) = 0;
};
