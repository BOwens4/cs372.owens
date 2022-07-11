// Braden Owens
// 6/27/2022
// Midterm Data Structures
#include <iostream>
using namespace std;

// Problem 1: Fueler Problem for calculating 
class Fueler
{
private: //vars for fuel consumed/ dist traveled
	int milestraveled; 
	double gallonsused;
public:
	Fueler() //constructor to set variables to zero
	{
		milestraveled = 0;
		gallonsused = 0;
	}
	void resetfuelanddist() // function to later reset these variables
	{
		milestraveled = 0;
		gallonsused = 0;
	}
	void addmiles(double miles) // function to update miles
	{
		milestraveled += miles;
	}
	void addfuel(double gallons) // function to update fuel
	{
		gallonsused += gallons;
	}
	const double gettotaldist() // returns total miles
	{
		return milestraveled;
	}
	const double getfuelconsumed() //returns fuel used
	{
		return gallonsused;
	}
	const double getmpg() // returns mpg
	{
		return milestraveled/gallonsused;
	}


};

int main()
{
	cout << "This main function will test our Fuel Class." << endl;
	Fueler Fuel;
	Fuel.addmiles(20);
	Fuel.addmiles(40);
	Fuel.addmiles(60);
	Fuel.addmiles(80);
	Fuel.addmiles(100);

	Fuel.addfuel(20);
	Fuel.addfuel(20);
	Fuel.addfuel(10);
	Fuel.addfuel(10);
	cout << "The car traveled " << Fuel.gettotaldist() <<" miles!"<<endl;
	cout << "The car used " << Fuel.getfuelconsumed() << " gallons of gas!" << endl;
	cout << "The cars mpg is " << Fuel.getmpg() <<" miles per gallon! "<<endl;

}