#include <iostream>
#include <string>

using namespace std;
class pet
{
public:
	virtual void petSound() = 0;
};
class dog : public pet
{
public:
	void petSound()
	{
		cout << "bhow bhow" << endl;
	}
	dog()
	{
		cout << "Dog class created!!" << endl;
	}
};
class cat : public pet
{
public:
	void petSound()
	{
		cout << "Meow Meow" << endl;
	}
	cat()
	{
		cout << "Cat class created!!" << endl;
	}
};
class petFactory
{
public:
	pet * getPet(string sound)
	{
		pet * newPet = NULL;
		if (sound == "bhow")
			newPet = new dog();
		else if(sound == "meow")
			newPet = new cat();
		return newPet;
	}
};

int main() {
	petFactory * dog = new petFactory();
	string sound;
	cout << "Enter the pet sound to create its object " << endl << "1. bhow" << endl << "2. meow" << endl;
	cin >> sound;
	pet * animal = dog->getPet(sound);
	animal->petSound();
	return 0;
}
