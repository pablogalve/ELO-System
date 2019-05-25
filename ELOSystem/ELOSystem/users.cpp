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
/*
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

void ELOManager::quickSort(user* first, int low, int high){
		
}
int ELOManager::partition(user* first, int low, int high) {
	
}
*/
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
	
	for (index = first; index->next != nullptr; index = index->next) {
		i++;
	}
	return i;
	
}

void ELOManager::printUsers() {
	user* index = new user();

	for (index = first; index != nullptr; index = index->next) {
		cout << "Name:[" << index->username << "] ";
		cout << "ELO:[" << index->ELO << "] ";
		cout << "Score:[" << index->score << "] ";
		cout << endl;
	}	
	cout << endl;
}
