#pragma once

class CivilEngineer
{

private:
	HouseBuilder *m_houseBuilder;

public:
	CivilEngineer(HouseBuilder *houseBuilder)
	{
		m_houseBuilder = houseBuilder;
	}

	House *getHouse()
	{
		return m_houseBuilder->getHouse();
	}

	void constructHouse()
	{
		m_houseBuilder->buildBasement();
		m_houseBuilder->buildStructure();
		m_houseBuilder->bulidRoof();
		m_houseBuilder->buildInterior();
	}
};
