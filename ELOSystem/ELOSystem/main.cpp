#include "users.h"


int main() {
	ELOManager* elo = new ELOManager();
	string myName;	
	
	cout << "This is my ELO system :)" << endl;
	cout << "What is your name?";
	cin >> myName;

	//Add users
	elo->addNewUser(myName, 10);
	elo->addNewUser("User1", 80);
	elo->addNewUser("User2", 30);
	elo->addNewUser("User3", 90);
	elo->addNewUser("User4", 40);
	elo->addNewUser("User5", 50);
	elo->addNewUser("User6", 70);

	cout << "-- Users --" << endl;
	elo->printUsers();
	cout << "-- Sorting users by ELO... " << endl;
	//elo->quickSort();
	//elo->orderList();
	elo->test();
	elo->printUsers();
	
	
	return 0;
}
