#pragma once


class HouseBuilder
{
public:
	virtual void buildBasement() =0;

	virtual void buildStructure() = 0;

	virtual void bulidRoof() =0;

	virtual void buildInterior() =0;

	virtual House *getHouse() =0;
};
