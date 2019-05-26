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
*/
void ELOManager::quickSort(user* name, int low, int high){
	if(low<high)
	{
		cout << "aqui" << endl;
		int pi = partition(name, low, high);
		
		quickSort(name, low, pi - 1);
		quickSort(name, pi + 1, high);
	}
}
int ELOManager::partition(user* name, int low, int high) {
	user* index;
	user* aux;

	index = first;
	aux = first;

	cout << "user: [" << name->username << "]" << endl;

	float pivot = last->ELO;
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++) 
	{
		if (index->ELO <= last->ELO)
		{
			i++;
			if (aux->next != nullptr) 
			{
				aux = aux->next;
			}
			swap(aux, index);
		}
		index = index->next;
	}	
	swap(aux->next, index);
		
	return(i + 1);
}
void ELOManager::swap(user* name, user* second) {
	user* aux = new user();

	//aux = name;
	//aux->username = name->username;
	//aux->score = name->score;
	//->ELO = name->ELO;
	aux->previous = name->previous;
	aux->next = name->next;
		
	//name = second;
	//name->username = second->username;
	//name->score = second->score;
	//name->ELO = second->ELO;
	name->previous = second->previous;
	name->next = second->next;

	//second = aux;
	//second->username = aux->username;
	//second->score = aux->score;
	//second->ELO = aux->ELO;
	second->previous = aux->previous;
	second->next = aux->next;
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
	
	for (index = first; index->next != nullptr; index = index->next) {
		i++;
	}
	return i;
	
}
user* ELOManager::getFirstUser() {
	return first;
}

void ELOManager::printUsers() {
	user* index = new user();

	for (index = first; index != nullptr; index = index->next) {
		cout << "Name:[" << index->username << "] ";
		cout << "ELO:[" << index->ELO << "] ";
		//cout << "Score:[" << index->score << "] ";
		cout << endl;
	}	
	cout << endl;
}
