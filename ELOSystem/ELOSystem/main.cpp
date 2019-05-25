#include "users.h"

int main() {
	ELOManager* elo = new ELOManager();

	elo->addNewUser("Jose", 2724);
	elo->addNewUser("Alberto", 30);
	elo->printUsers();

	

	return 0;
}
