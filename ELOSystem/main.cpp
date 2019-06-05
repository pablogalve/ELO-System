#include "users.h"
//Includes to use "waitfor"
#include <chrono>
#include <thread>
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds

int main() {
	ELOManager* elo = new ELOManager();
	string myName;
	float myELO;

	cout << "This is my ELO system :)" << endl;
	cout << "What is your name?";
	cin >> myName;
	cout << "What is your ELO?";
	cin >> myELO;

	//Add users
	elo->addNewUser(myName, myELO);
	elo->addNewUser("User1", 80);
	elo->addNewUser("User2", 30);
	elo->addNewUser("User3", 90);
	elo->addNewUser("User4", 100);
	elo->addNewUser("User5", 85);
	elo->addNewUser("User6", 40);
	elo->addNewUser("User7", 50);
	elo->addNewUser("User8", 70);

	//elo->addNewUser("first", 1);
	for (int i = 40; i >0; i--) {
		elo->addNewUser("user", i+rand() %3000);
	}
	elo->bubblesort("ELO");
	elo->calculateScore();

	cout << "-- Users --" << endl;
	elo->printUsers();
	cout << endl << "-- We will start sorting in 3 seconds --" << endl;
	sleep_until(system_clock::now() + seconds(3));
	cout << "-- Sorting users by ELO... " << endl;
	elo->bubblesort("Score");
	elo->printUsers();
	cout << "Done! " << endl;

	system("pause");
	return 0;
}
