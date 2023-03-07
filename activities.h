//Molina Nhoung CS162
//Program 4
//The purpose of this program is to keep track of activities entered by the user
//the user will have the option to display all the activities they entered
//and to display activities that match the level of difficulty
//each activity entered will have the name, location, level of difficulty
//equipment recommendations, and how much the activity would cost.

#include <iostream>
#include <cctype>
#include <cstring>

//Constants
const int NAME {31};
const int LOCATION {51};
const int RECOMMEND {101};
const int ACTIVITIES {10};

//Classes
class activity
{
	public:
		activity();		//constructor
		~activity();		//destructor
		void read();		//read in activity
		void display();		//display the activity
	private:
		char * name;
		char location[LOCATION];
		int level;
		char recommend[RECOMMEND];
		float cost;
};

class fun_activities
{
	public:
		fun_activities(); 		//constructor
		~fun_activities();		//destructor
		void read_activities(); //read in  activities
		void display_all(); 	//display all activities
		void display_match(); 	//display all difficulty matches
	private:
		activity * array;
		int array_size;
		int num_of_activities;
};

//Prototypes
void welcome();
int menu();
void exit();
