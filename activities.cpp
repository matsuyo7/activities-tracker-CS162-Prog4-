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
	location = nullptr;
	level = 0;
	recommend = nullptr;
	cost = 0;
}

//Deallocate the dynamic memory with destructor
activity::~activity()
{
	if (name != nullptr)
		delete [] name;
	name = nullptr;
	if (location != nullptr)
		delete [] location;
	location = nullptr;
	level = 0;
	if (recommend != nullptr)
		delete [] recommend;
	recommend = nullptr;
	cost = 0;
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

	char temp1[LOCATION];
	cout << "\nEnter the activity location: ";
	cin.get(temp1, LOCATION, '\n');
	cin.ignore(100, '\n');

	location = new char [strlen(temp1) + 1];
	strcpy(location, temp1);

	do
	{
		cout << "\nEnter the level of difficulty (1 (easy) - 10 (extreme)): ";
		cin >> level;
		cin.ignore(100, '\n');

		if (level < 1 || level > 10)
			cout << "Difficulty out of range, try again" << endl;
	} while (level < 1 || level > 10);
	
	char temp2[RECOMMEND];
	cout << "\nEnter the equipment you recommend to bring: ";
	cin.get(temp2, RECOMMEND, '\n');
	cin.ignore(100, '\n');

	recommend = new char [strlen(temp2) + 1];
	strcpy(recommend, temp2);

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


//Get levels into another array
bool activity::get_level(int match)
{
	if (match == level)
		return true;
	return false;
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

	if (num_of_activities == array_size)
		cout << "\nActivity list is full" << endl;

}

//Display all activities
void fun_activities::display_all()
{
	int count {0};
	for (int i {0}; i < num_of_activities; ++i)
	{
		array[i].display();
		++count;
	}

	if (count == 0)
		cout << "\nNothing to display" << endl;
}

//Display all level of difficulty matches
void fun_activities::display_match()
{
	int match {0};
	int count {0};
	cout << "\nWhat level of difficulty are you looking for? (1-10): ";
	cin >> match;
	cin.ignore(100, '\n');
	
	for (int i {0}; i < num_of_activities; ++i)
	{
		if (array[i].get_level(match))
		{
			array[i].display();
			++count;
		}
	}

	if (count == 0)
		cout << "\nNo matches found" << endl;
}

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
