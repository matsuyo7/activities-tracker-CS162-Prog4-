#include "activities.h"

int main()
{
	//Variables
	fun_activities multiple;
	int option {0};	

	welcome();
	do
	{
		option = menu();
		if (option == 1)
		{
			multiple.read_activities();
		}
		if (option == 2)
		{
			multiple.display_all();
		}
		if (option == 3)
		{
			multiple.display_match();
		}

	} while (option != 4);
	exit();

	return 0;
}

