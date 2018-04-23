#include<iostream>
using namespace std;

class primary_key
{
	static primary_key *instance;
	primary_key()
	{
		cout << "Private Constructor called " <<endl;
	}
public:
	static primary_key *createKey()
	{
		if (instance == NULL)
		{
			instance = new primary_key();
		}
		return instance;
	}
};
primary_key *primary_key::instance = NULL;

int main()
{
	primary_key *book1 = primary_key::createKey();
	return 0;
}
