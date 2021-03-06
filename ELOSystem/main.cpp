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
	int rounds;
	int users;

	cout << "This is my ELO system :)" << endl;
	cout << "What is your name?";
	cin >> myName;
	cout << "What is your ELO?";
	cin >> myELO;
	cout << "Total users:";
	cin >> users;
	cout << "How many rounds will it have? ";
	cin >> rounds;
	

	//Add users
	elo->addNewUser(myName, myELO);
	/*elo->addNewUser("User1", 80);
	elo->addNewUser("User2", 30);
	elo->addNewUser("User3", 90);
	elo->addNewUser("User4", 100);
	elo->addNewUser("User5", 85);
	elo->addNewUser("User6", 40);
	elo->addNewUser("User7", 50);
	elo->addNewUser("User8", 70);*/

	
	for (int i = users; i >0; i--) {
		//elo->addNewUser("user", i+rand() %3000);
		elo->addNewUser("user", 1500);
	}
	elo->bubblesort("ELO");
	elo->calculateScore();

	cout << "-- Users --" << endl;
	elo->printUsers();
	//cout << endl << "-- We will start sorting in 3 seconds --" << endl;
	//sleep_until(system_clock::now() + seconds(3));
		
	cout << "Click any button to start the tournament" << endl; 
	system("pause");
	for (int i = 0; i < rounds; i++) {
		//Users competing agains lower users in the ranking
		for (user* index = elo->getFirstUser(); index->next != nullptr; index = index->next) {
			if (index->score > index->next->score)
				elo->calculateELO(index, index->next->ELO, 1.0f);
			else if (index->score < index->next->score)
				elo->calculateELO(index, index->next->ELO, 0.0f);
			else
				elo->calculateELO(index, index->next->ELO, 0.5f);
		}
		//Users competing agains higher users in the ranking
		for (user* index = elo->getLastUser(); index->previous != nullptr; index = index->previous) {
			if (index->score > index->previous->score)
				elo->calculateELO(index, index->previous->ELO, 1.0f);
			else if (index->score < index->previous->score)
				elo->calculateELO(index, index->previous->ELO, 0.0f);
			else
				elo->calculateELO(index, index->previous->ELO, 0.5f);
		}
		elo->bubblesort("ELO");
		elo->calculateScore();		
		elo->printUsers();
	}
	cout << "--ELO Changes completed--" << endl;

	system("pause");
	return 0;
}
