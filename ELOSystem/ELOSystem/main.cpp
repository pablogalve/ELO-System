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
	elo->addNewUser("User4", 100);
	elo->addNewUser("User5", 85);
	elo->addNewUser("User6", 40);
	elo->addNewUser("User7", 50);
	elo->addNewUser("User8", 70);
	
	//elo->addNewUser("first", 1);
	//for (int i = 0; i < 10; i++) {
		//elo->addNewUser("user", i);
	//}


	cout << "-- Users --" << endl;
	elo->printUsers();
	cout << "-- Sorting users by ELO... " << endl;
	elo->quickSort();
	//elo->orderList();
	//elo->test();
	elo->printUsers();
	cout << "Done! " << endl;
	
	return 0;
}
