#include<iostream>
#include <string>
using namespace std;
class Pizza
{
public:
	string description;
	virtual string getDesc() 
	{
		return description;
	}
	virtual int getCost() = 0;
};


class PeppyPaneer : public Pizza
{
public:
	PeppyPaneer() { description = "PeppyPaneer"; }
    int getCost() {  return 100; }
};
class FarmHouse : public Pizza
{
public:
	FarmHouse() {  description = "FarmHouse"; }
    int getCost() { return 200; }
};
class Margherita : public Pizza
{
public:
	Margherita()  { description = "Margherita"; }
    int getCost() { return 100;  }
};
class ChickenFiesta : public Pizza
{
public:
	ChickenFiesta() { description = "ChickenFiesta";}
    int getCost() { return 200; }
};
class SimplePizza : public Pizza
{
public:
	SimplePizza() { description = "SimplePizza"; }
	int getCost() {  return 50;  }
};

class FreshTomato : public Pizza
{
    // we need a reference to obj we are decorating
    Pizza *pizza;
 
public:
	FreshTomato(Pizza *pizza) { this->pizza = pizza; }
    string getDesc() {
		return (pizza->getDesc() + ", Fresh Tomato ");
    }
    int getCost() { return 40 + pizza->getCost(); }
};
class Barbeque : public Pizza
{
    Pizza *pizza;
public:
	Barbeque(Pizza* pizza) {  this->pizza = pizza;  }
    string getDesc() {
        return pizza->getDesc() + ", Barbeque ";
    }
    int getCost() { return 90 + pizza->getCost(); }
};
class Paneer : public Pizza
{
    Pizza *pizza;
public:
	Paneer(Pizza* pizza)  {  this->pizza = pizza; }
    string getDesc() {
        return pizza->getDesc() +  ", Paneer ";
    }
    int getCost()  {  return 70 + pizza->getCost(); }
};

int main()
{
		Pizza *pizza = new Margherita();
        cout<< pizza->getDesc() <<  " Cost :" << pizza->getCost()<<endl;
 
        // create new FarmHouse pizza
        Pizza *pizza2 = new FarmHouse();
		cout<< pizza2->getDesc() <<  " Cost :" << pizza2->getCost()<<endl;
        // decorate it with freshtomato topping
        pizza2 = new FreshTomato(pizza2);
 
        //decorate it with paneer topping
        pizza2 = new Paneer(pizza2);
 
       cout<< pizza2->getDesc() << " Cost :" << pizza2->getCost();
       // Pizza *pizza3 = new Barbeque(NULL);    //no specific pizza
       // cout<< pizza3->getDesc() << "  Cost :" << pizza3->getCost();
	return 0;
}
