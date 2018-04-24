#include <iostream>
#include<string>
using namespace std;
#include "prototype.h"

class SampleA_Prototype : public Prototype
{
public:
	SampleA_Prototype(int number)
	{
		type = "Sample A";
		value = number;
	}

	Prototype* clone()
	{
		return new SampleA_Prototype(*this);
	}
};

class SampleB_Prototype : public Prototype
{
public:
	SampleB_Prototype(int number)
	{
		type = "Sample B";
		value = number;
	}

	Prototype* clone()
	{
		return new SampleB_Prototype(*this);
	}
};

/* Factory that manages prorotype instances and produces their clones. */
class ObjectFactory
{
	static Prototype* SampleA_value1;
	static Prototype* SampleA_value2;
	static Prototype* SampleB_value1;
	static Prototype* SampleB_value2;

public:
	static void  initialize()
	{
		SampleA_value1 = new SampleA_Prototype(1);
		SampleA_value2 = new SampleA_Prototype(2);
		SampleB_value1 = new SampleB_Prototype(1);
		SampleB_value2 = new SampleB_Prototype(2);
	}

	static Prototype* getSampleA_value1()
	{
		return SampleA_value1->clone();
	}

	static Prototype* getSampleA_value2()
	{
		return SampleA_value2->clone();
	}

	static Prototype* getSampleB_value1()
	{
		return SampleB_value1->clone();
	}

	static Prototype* getSampleB_value2()
	{
		return SampleB_value2->clone();
	}
};

Prototype* ObjectFactory::SampleA_value1 = 0;
Prototype* ObjectFactory::SampleA_value2 = 0;
Prototype* ObjectFactory::SampleB_value1 = 0;
Prototype* ObjectFactory::SampleB_value2 = 0;

int main()
{
	ObjectFactory::initialize();
	Prototype* object;

	/* All the object were created by cloning the prototypes. */
	object = ObjectFactory::getSampleA_value1();
	std::cout << object->getType() << ": " << object->getValue() << std::endl;

	object = ObjectFactory::getSampleA_value2();
	std::cout << object->getType() << ": " << object->getValue() << std::endl;

	object = ObjectFactory::getSampleB_value1();
	std::cout << object->getType() << ": " << object->getValue() << std::endl;

	object = ObjectFactory::getSampleB_value2();
	std::cout << object->getType() << ": " << object->getValue() << std::endl;


	return 0;
}
