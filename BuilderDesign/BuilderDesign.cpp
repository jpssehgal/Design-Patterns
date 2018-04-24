#include<iostream>
#include<string>
using namespace std;
#include "HousePlan.h"
#include "House.h"
#include "HouseBuilder.h"
#include "Engineer.h"


class IglooHouseBuilder : public HouseBuilder
{
private:
	House *m_house;
public:
	IglooHouseBuilder()
	{
		cout << "New Igloo House" << endl;
		m_house = new House();
	}

	void buildBasement()
	{
		cout << "setBasement - Ice Bars" << endl;
		m_house->setBasement("Ice Bars");
	}

	void buildStructure()
	{
		cout << "buildStructure - Ice Blocks" << endl;
		m_house->setStructure("Ice Blocks");
	}

	void buildInterior()
	{
		cout << "buildInterior - Ice Carvings" << endl;
		m_house->setInterior("Ice Carvings");
	}

	void bulidRoof()
	{
		cout << "buildRoof - Ice Dome" << endl;
		m_house->setRoof("Ice Dome");
	}

	House *getHouse()
	{
		return m_house;
	}
};


class TipiHouseBuilder: public HouseBuilder
{
private:
	House *m_house;

public:
	TipiHouseBuilder()
	{
		cout << "TipiHouseBuilder" << endl;
		m_house = new House();
	}

	void buildBasement()
	{
		cout << "buildBasement - Wooden Poles" << endl;
		m_house->setBasement("Wooden Poles");
	}

	void buildStructure()
	{
		cout << "buildStructure - Wood and Ice" << endl;
		m_house->setStructure("Wood and Ice");
	}

	 void buildInterior()
	{
		cout << "buildInterior - Fire Wood" << endl;
		m_house->setInterior("Fire Wood");
	}

	 void bulidRoof()
	{
		 cout << "bulidRoof - Wood, caribou and seal skins" << endl;
		m_house->setRoof("Wood, caribou and seal skins");
	}

	 House *getHouse()
	{
		return m_house;
	}

};

int main()
{
	HouseBuilder *iglooBuilder = new IglooHouseBuilder();
	CivilEngineer *engineer = new CivilEngineer(iglooBuilder);

	engineer->constructHouse();

	House *house = engineer->getHouse();

	cout<<"Builder constructed: " << house <<endl;
	return 0;
}





