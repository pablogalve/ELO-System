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
		cout << "Quicksort" << endl;
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

	cout << "Partition user: [" << name->username << "]" << endl;

	float pivot = last->ELO;
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++) 
	{
		if (index->ELO <= last->ELO)
		{
			i++;
			if (aux->next != nullptr)
				aux = aux->next;
			
			swap(aux, index);
		}
		if(index->next != nullptr)
			index = index->next;
	}
	if (aux->next != nullptr) {
		swap(aux->next, index);
	}
	else {
		cout << "Aux is nullptr" << endl;
	}
			
	return(i + 1);
}
void ELOManager::swap(user* A, user* B) {
	user* tmp = new user();
	user* swapperVector[4];

	cout << "swap1[" << A->username << "]" << endl;
	cout << "swap2[" << B->username << "]" << endl;

	swapperVector[0] = A->previous;
	swapperVector[1] = B->previous;
	swapperVector[2] = A->next;
	swapperVector[3] = B->next;

	if (areTheyNeighbours(A, B)) {
		A->previous = swapperVector[2];
		B->previous = swapperVector[0];
		A->next = swapperVector[3];
		B->next = swapperVector[1];
	}
	else {
		A->previous = swapperVector[1];
		B->previous = swapperVector[0];
		A->next = swapperVector[3];
		B->next = swapperVector[2];
	}

	/*aux = name;
	aux->username = name->username;
	aux->score = name->score;
	aux->ELO = name->ELO;
	aux->previous = name->previous;
	aux->next = name->next;
		
	name = second;
	name->username = second->username;
	name->score = second->score;
	name->ELO = second->ELO;
	name->previous = second->previous;
	name->next = second->next;

	second = aux;
	second->username = aux->username;
	second->score = aux->score;
	second->ELO = aux->ELO;
	second->previous = aux->previous;
	second->next = aux->next;*/
	cout << endl << "Print list after swap" << endl;
	printUsers();
}
int ELOManager::areTheyNeighbours(user* A, user* B) {
	return(A->next == B && B->previous == A) || (A->previous == B && B->next == A);//return 1 if true or 0 if false
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
		return i+1;
	}	
}
user* ELOManager::getFirstUser() {
	return first;
}

void ELOManager::printUsers() {
	user* index = new user();
	int i = 1;

	for (index = first; index != nullptr; index = index->next) {
		cout << i << "Name:[" << index->username << "] ";
		cout << "ELO:[" << index->ELO << "] ";
		//cout << "Score:[" << index->score << "] ";
		cout << endl;
		i++;
	}	
	cout << endl;
}

void ELOManager::orderList() {
	user* index;
	user* aux;
	aux = first;
	index = first;

	for (index = first; index->next != nullptr; index = index->next) {
		if (index < index->next) {
			swap(index, index->next);	

			/*aux = index;

	//second node changed
	index->next->previous = index->previous;
	index->next->next = index;

	//first node changed
	index->next = index->next->next;
	index->previous = index->next;

	//previous node changed
	index->previous->next = index->next;

	//last node changed
	index->next->next->previous = index;*/
		}
	}
}