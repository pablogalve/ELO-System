#include "users.h"


int main() {
	ELOManager* elo = new ELOManager();
	string myName;	

	cout << "This is my ELO system :)" << endl;
	cout << "What is your name?";
	cin >> myName;

	//Add users
	elo->addNewUser(myName, 0);
	elo->addNewUser("User1", 2724);
	elo->addNewUser("User2", 30);
	elo->addNewUser("User3", 5);
	elo->addNewUser("User4", 2);
	elo->addNewUser("User5", 547);

	cout << "-- Users --" << endl;
	elo->printUsers();
	cout << "-- Sorting users by ELO... " << endl;
	elo->quickSort(elo->getFirstUser(), 0, elo->getArraySize());
	//elo->orderList();
	elo->printUsers();
	
	
	return 0;
}
