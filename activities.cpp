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
	name = nullptr;
	location[0] = '\0';
	level = 0;
	recommend[0] = '\0';
	cost = 0;
}

//Deallocate the dynamic memory with destructor
activity::~activity()
{
	if (name != nullptr)
		delete [] name;
	name = nullptr;
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

	do
	{
		cout << "\nEnter the level of difficulty (1 (easy) - 10 (extreme)): ";
		cin >> level;
		cin.ignore(100, '\n');

		if (level < 1 || level > 10)
			cout << "Difficulty out of range, try again" << endl;
	} while (level < 1 || level > 10);

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
	if (name == nullptr)
		return;

	cout << "\nName: " << name
		<< "\nLocation: " << location
		<< "\nLevel of Difficulty: " << level
		<< "\nRecommendation(s): " << recommend
		<< "\nCost of the activity: " << cost << endl;
}
//Initialize data members
fun_activities::fun_activities()
{
	cout << "\nHow many activities are you keeping track: ";
	cin >> array_size;
	cin.ignore(100, '\n');

	array = new activity[array_size];
	num_of_activities = 0;
}

//Deallocate the dynamic memory
fun_activities::~fun_activities()
{
	if (array != nullptr)
		delete [] array;
	array = 0;
	array_size = 0;
	num_of_activities = 0;
}

//Read in all activities until user wants to stop
void fun_activities::read_activities()
{
	char response {' '};
	do
	{
		array[num_of_activities].read();
		++num_of_activities;
		
		if (num_of_activities < array_size)
		{
			cout << "\nDo you want to add another activity? y/n: ";
			cin >> response;
			cin.ignore(100, '\n');
		}
	} while (num_of_activities < array_size && toupper(response) == 'Y');

}

//Display all activities
void fun_activities::display_all()
{
	for (int i {0}; i < num_of_activities; ++i)
	{
		array[i].display();
	}
}

//Display all level of difficulty matches
void fun_activities::display_match()
{}

//Welome the user and inform them on what the program does
void welcome()
{
	cout << "\n***ACTIVITY TRACKER***"
		<< "\nKeep track of activities that you want to do"
		<< "\nThe program will ask you how many activities you would like to store"
		<< "\nEach activity will ask for: "
		<< "\n\t- Activity Name"
		<< "\n\t- Location"
		<< "\n\t- Level of difficulty"
		<< "\n\t- Recommended items to take"
		<< "\n\t- How much the activity costs to do"
		<< "\nYou will be given options to enter a new activity, display all activities, and display all matches for level of difficulty in the menu below." << endl;
}

//Display a menu of options
int menu()
{
	int option {0};
	do
	{
		cout << "\n***ACTIVITIES MENU***"
			<< "\n1. Enter a new activity"
			<< "\n2. Display all activities"
			<< "\n3. Display all level of difficulty matches"
		       	<< "\n4. Quit"
		       	<< "\n\nPick an option (1-4): ";

		cin >> option;
		cin.ignore(100, '\n');

		if (option < 1 || option > 4)
			cout << "Input out of range, try again" << endl;
	} while (option < 1 || option > 4);
	return option;
}

//Message to exit to program
void exit()
{
	cout << "\n***EXITING PROGRAM***" << endl;
}
