#include "users.h"

int main() {
	ELOManager* elo = new ELOManager();

	cout << "1";

	elo->addNewUser("Jose", 5);
	elo->addNewUser("Alberto", 30);
	cout << "2";
	elo->printUsers();

	cout << "3";
	

	return 0;
}
