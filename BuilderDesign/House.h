#pragma once

class House : public HousePlan
{
private:
	string m_basement;
	string m_structure;
	string m_roof;
	string m_interior;
public:
	void setBasement(string basement)
	{
		m_basement = basement;
	}

	void setStructure(string structure)
	{
		m_structure = structure;
	}

	void setRoof(string roof)
	{
		m_roof = roof;
	}

	void setInterior(string interior)
	{
		m_interior = interior;
	}
};

