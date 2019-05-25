#include "users.h"


int main() {
	ELOManager* elo = new ELOManager();
	string myName;

	cout << "This is my ELO system :)" << endl;
	cout << "What is your name?";
	cin >> myName;

	//Add users
	elo->addNewUser(myName, 0);
	elo->addNewUser("Jose", 2724);
	elo->addNewUser("Alberto", 30);
	elo->addNewUser("Maria", 5);
	elo->addNewUser("Luis", 2);
	elo->addNewUser("User", 547);

	cout << "-- Users --" << endl;
	elo->printUsers();
	cout << "-- Sorting users by ELO... " << endl;
	
	elo->printUsers();



	

	return 0;
}
