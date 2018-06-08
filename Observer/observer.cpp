#include<iostream>
#include <string>
#include <list>
using namespace std;

class Observer
{
public:
	 virtual void update(int runs, int wickets,float overs);
};
class subject
{
public:
	 void RegisterObserver(Observer o) ;
	 void unregisterObserver(Observer o);
     void notifyObservers() ;
};


class AverageScoreDisplay :public Observer
{
private:
	float runRate;
    int predictedScore;
 
public:
	void update(int runs, int wickets,float overs)
    {
        runRate =(float)runs/overs;
        predictedScore = (int)(runRate * 50);
        display();
    }
 
    void display()
    {
       cout<< "Average Score Display: "<<endl<<"Run Rate: "<<endl<<runRate<<endl<<"PredictedScore: "<<predictedScore<<endl;
    }
};

 
class CurrentScoreDisplay :public Observer
{
private:
	int runs, wickets;
    float overs;
 
public:
	void update(int runs, int wickets,float overs)
    {
        runs = runs;
        wickets = wickets;
        overs = overs;
        display();
    }
 
    void display()
    {
        cout<<"Current Score Display:"<<endl<< "Runs: "<< runs<<endl<< "Wickets: "<< wickets <<endl<< "Overs: " << overs<<endl;
    }
};

class CricketData : public subject
{
    int runs;
    int wickets;
    float overs;
    list<Observer> observerList;
 
public:
	CricketData() {
       // observerList = new list<Observer>();
    }
 

    void registerObserver(Observer o) {
        observerList.push_back(o);
    }
 
    
    void unregisterObserver(Observer o) {
      //  observerList.remove(o);
    }
 
    
    void notifyObservers()
    {
        for (std::list<Observer>::iterator it = observerList.begin();  it!=observerList.end(); ++it)
        {
			Observer oo = *it;
            oo.update(runs,wickets,overs);
        }
    }
	
	void dataChanged()
    {
        //get latest data
        runs = getLatestRuns();
        wickets = getLatestWickets();
        overs = getLatestOvers();
 
        notifyObservers();
    }
    // get latest runs from stadium
private:
	int getLatestRuns()
    {
        // return 90 for simplicity
        return 90;
    }
 
    // get latest wickets from stadium
    int getLatestWickets()
    {
        // return 2 for simplicity
        return 2;
    }
 
    // get latest overs from stadium
    float getLatestOvers()
    {
        // return 90 for simplicity
        return (float)10.2;
    }
 
    // This method is used update displays
    // when data changes
};


int main()
{
     CricketData cricketData;
	 AverageScoreDisplay averageScoreDisplay;
     CurrentScoreDisplay currentScoreDisplay;
 
        cricketData.registerObserver(averageScoreDisplay);
       cricketData.registerObserver(currentScoreDisplay);
 
        // in real app you would have some logic to
        // call this function when data changes
        cricketData.dataChanged();
 
        //remove an observer
      //  cricketData.unregisterObserver(averageScoreDisplay);
 
        // now only currentScoreDisplay gets the
        // notification
       // cricketData.dataChanged();
	return 0;
}
 
