#include "users.h"

ELOManager::ELOManager() {
	first = nullptr;
	last = nullptr;
}
/*
ELOManager::~ELOManager() {

}
void ELOManager::calculateELO() {

}
void ELOManager::calculateScore() {

}
float ELOManager::getAvgUp() {

}
float ELOManager::getAvgDown() {

}
float ELOManager::getProbWinUp() {

}
float ELOManager::getProbWinDown() {

}
*/
void ELOManager::addNewUser(string name, float ELO) {
	user* newUser = new user();
	user* index;

	if (first == nullptr) {
		cout << "5";
		first = newUser; //To assign the memory created to first user
		first->username = name;
		first->ELO = ELO;
		first->next = nullptr;
		first->previous = nullptr;
		last = first;
	}
	else {
		for (index = first; index->next != nullptr; index = index->next);
		if (newUser != nullptr) {
			index->next = newUser; //To assign the memory created to first user
			newUser->username = name;
			newUser->ELO = ELO;
			newUser->score = 0;
			newUser->next = nullptr;
			newUser->previous = index;
			last->next = newUser;			
			cout << "New user added: " << newUser->username << endl;
		}
	}
	delete newUser; //Freeing memory to avoid memory leaks
}

void ELOManager::printUsers() {
	user* index = new user();

	cout << "first: [" << first->username << "]";

	for (index = first; index != nullptr; index = index->next) {
		cout << "Name:[" << index->username << "] ";
		cout << "ELO:[" << index->ELO << "] ";
		cout << "Score:[" << index->score << "] ";
		cout << endl;
	}	
	cout << endl;
}
