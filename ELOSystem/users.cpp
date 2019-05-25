#include "users.h"

ELOManager::ELOManager() {
	first = nullptr;
	last = nullptr;
}
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
void ELOManager::addNewUser(string name, float ELO) {
	
	user* newUser = new user();
	user* index;

	if (first == nullptr) {
		first = newUser; //To assign the memory created to first user
		first->username = name;
		first->ELO = ELO;
	}
	else {
		for (index = first; index->next != nullptr; index = index->next);
		if (newUser != nullptr) {
			
			index->next->username = name;
			index->next->ELO = ELO;
			index->next->score = 0;
			index->next->next = nullptr;
			index->next->previous = index;
			
		}				
	}
}
void ELOManager::printUsers() {

}