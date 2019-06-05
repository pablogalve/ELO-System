#include "users.h"

ELOManager::ELOManager() {
	this->first = nullptr;
	this->last = nullptr;

}

ELOManager::~ELOManager() {
	delete first;
	delete last;
	cout << "List Deleted";
}

void ELOManager::addNewUser(string name, float ELO) {
	user* newUser = new user();
	user* index;

	if (first == nullptr) {
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
			last = newUser;
		}
	}
}

int ELOManager::getArraySize() {
	user* index;
	int i = 0;

	if (first == nullptr) {
		return 0;
	}
	else {
		for (index = first; index->next != nullptr; index = index->next) {
			i++;
		}
		return i + 1;
	}
}
user* ELOManager::getFirstUser() {
	return first;
}

void ELOManager::printUsers() {
	user* index = new user();
	int i = 1;

	if (first == nullptr) {
		cout << "List is empty" << endl;
	}
	else {
		for (index = first; index != nullptr; index = index->next) {
			cout << i << "-- Name:[" << index->username << "] ";
			cout << "ELO:[" << index->ELO << "] ";
			cout << "Score:[" << index->score << "] ";
			cout << "ProbWin:[" << getProbWin(index->ELO,getAvgUp(index)) << "] ";
			cout << endl;
			i++;
		}
		cout << endl;
	}
}

