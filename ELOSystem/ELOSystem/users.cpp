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

void ELOManager::calculateELO() {
	
}
void ELOManager::calculateScore() {

}
float ELOManager::getAvgUp() {
	return 0;
}
float ELOManager::getAvgDown() {
	return 0;
}
float ELOManager::getProbWinUp() {
	return 0;
}
float ELOManager::getProbWinDown() {
	return 0;
}

void ELOManager::_quickSortRecursive(user* low, user* high) {
	if (high != nullptr && low != high && low != nullptr) {
		user* p = partition(low, high);
		_quickSortRecursive(low, p->previous);
		_quickSortRecursive(p->next, high);
	}
}
void ELOManager::quickSort(){
	_quickSortRecursive(first, last);
}
user* ELOManager::partition(user* low, user* high) {
	user* pivot = high;
	int index =-1, JJ = 0;
	user* i = low->previous;
	user* auxI = high;
	user* auxJ = high;

	cout << "Pivot Previous: " << pivot->ELO << "/////////////////////////////////" << endl;
	for (user* j = low; j != high && j!=nullptr; j = j->next) {
		if (j->ELO <= pivot->ELO){
			cout << endl << j->ELO <<" <= pivot-> ELO --> TRUE" << endl;
			cout << "i++ and swap(i,j)" << endl;
			cout << "j: " << JJ << endl;
			cout << "index before: " << index << endl;
			i = (i == NULL) ? low : i->next;
			index++;
			cout << "index after: " << index << endl;
			auxI = i->previous;
			auxJ = j;
			swap(i, j);
			//i = auxI;
			//j = auxJ;
		}
		else {
			cout << "j->ELO <= pivot-> ELO --> FALSE" << endl;
			cout << "j: " << JJ << endl;
			cout << "index: " << index << endl;
		}
	}
	//i = (i == NULL) ? low : i->next;
	cout << "We swap pivot and i->next: " << pivot->username << "  " << i->next->username << endl;
	swap(i->next, pivot);
	cout << endl << "Loop finished -----------------------" << endl;
	//printUsers();
	return i;
}
void ELOManager::test() {
	//swap(first->next, first->next->next);
	//swap(first->next, first->next->next->next->next);
	swap(first->next->next, first->next->next->next);
	swap(first->next, first->next->next);
	swap(first->next->next, first->next->next->next);
	swap(first->next, first->next->next);
}
void ELOManager::swap(user* A, user* B) {
	user* tmp = new user();
	user* swapperVector[6];

	cout << endl << "swap1[" << A->username << "]" << endl;
	cout << "swap2[" << B->username << "]" << endl;

	if (A == B) {
		cout << "Same Users: Continue" << endl;
		return;
	}
	
	if (B->next == A) {
		tmp = A;
		A = B;
		B = tmp;
		return;
	}

	swapperVector[0] = A->previous;
	swapperVector[1] = B->previous;
	swapperVector[2] = A->next;
	swapperVector[3] = B->next;	
	swapperVector[4] = first->next;	
	swapperVector[5] = last->previous;	
	
	if (areTheyNeighbours(A, B)) {
		if (A != first)
		{
			A->previous->next = B;
			A->next->previous = B;
			B->previous->next = A;
			//B->next->previous = swapperVector[2];


			A->previous = B;
			B->previous = swapperVector[0];
			A->next = swapperVector[3];
			B->next = A;
			A->next->previous = A;
		}
			
		cout << endl << "Option 1" << endl;
	}
	else {
		A->previous = swapperVector[1];
		B->previous = swapperVector[0];
		A->next = swapperVector[3];
		B->next = swapperVector[2];

		A->previous->next = B;
		A->next->previous = B;
		B->previous->next = A;
		B->next->previous = A;
		cout << endl << "Option 2" << endl;
	}

	
	/*
	if (A->previous != nullptr)
		A->previous->next = A;
	if (A->next != nullptr)
		A->next->previous = A;

	if (B->previous != nullptr)
		B->previous->next = B;
	if (B->next != nullptr)
		B->next->previous = B;
	*/	
	

	cout <<"Print list after swap" << endl << "-----" << endl;
	printUsers();
}
int ELOManager::areTheyNeighbours(user* A, user* B) {
	if ((A->next == B && B->previous == A) || (A->previous == B && B->next == A)) {
		cout << endl << "We are neighbours ++++++" << endl;
		return 1;
	}
	else {
		cout << endl << "No neighbours ------" << endl;
		return 0;
	}
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
		cout << i << "-- Name:[" << index->username << "] ";
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