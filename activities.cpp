#include "activities.h"
using namespace std;

//Molina Nhoung CS162
//Program 4
//The purpose of this program is to keep track of activities entered by the user
//the user will have the option to display all the activities they entered
//and to display activities that match the level of difficulty
//each activity entered will have the name, location, level of difficulty
//equipment recommendations, and how much the activity would cost.

//Activity constructor
activity::activity()
{
	name = NULL;
	location[0] = '\0';
	level = 0;
	recommend[0] = '\0';
	cost = 0;
}

//Deallocate the dynamic memory with destructor
activity::~activity()
{
	if (name != NULL)
		delete [] name;
	name = NULL;
}

//Read in the name, locatiom, difficulty level, recommended items, and cost of activity
void activity::read()
{
	char temp[NAME];
	cout << "\nEnter the activity name: ";
	cin.get(temp, NAME, '\n');
	cin.ignore(100, '\n');

	name = new char [strlen(temp) + 1];
	strcpy(name, temp);

	cout << "\nEnter the activity location: ";
	cin.get(location, LOCATION, '\n');
	cin.ignore(100, '\n');

	cout << "\nEnter the level of difficulty (1 (easy) - 10 (extreme)): ";
	cin >> level;
	cin.ignore(100, '\n');

	cout << "\nEnter the equipment you recommend to bring: ";
	cin.get(recommend, RECOMMEND, '\n');
	cin.ignore(100, '\n');

	cout << "\nEnter the cost of the activity (e.g. $25.99): ";
	cin >> cost;
	cin.ignore(100, '\n');
}

//Display the activity
void activity::display()
{
	if (name == NULL)
		return;

	cout << "Name: " << name
		<< "\nLocation: " << location
		<< "\nLevel of Difficulty: " << level
		<< "\nRecommendation(s): " << recommend
		<< "\nCost of the activity: " << cost << endl;
}

