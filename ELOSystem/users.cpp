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
float ELOManager::getAvgUp(user* myself) {
	float ELOsum = 0, i = 0;

	if (first == myself)
		return NULL;
	else {
		for (user* index = first; index->next != myself; index = index->next) {
			ELOsum += index->ELO;
			i++;
		}
		return ELOsum / i;;
	}
}
float ELOManager::getAvgDown(user* myself) {
	float ELOsum = 0, i = 0;

	if (last == myself)
		return NULL;
	else {
		for (user* index = last; index->previous != myself; index = index->previous) {
			ELOsum += index->ELO;
			i++;
		}
		return ELOsum / i;;
	}
}
float ELOManager::getProbWin(float myELO, float theirELO) {
	return (1 / (1 + pow(10, (theirELO - myELO) / 400)));
}

void ELOManager::_quickSortRecursive(user* low, user* high) {
	//user* aux = high;
	if (high != nullptr && low != high && low != high->next) {
		user* p = partition(low, high);
		cout << "HIGH1: " << high->username << endl;
		_quickSortRecursive(low, p->previous);
		cout << "Now, quicksort right part **************************************************" << endl;
		cout << "LOW: " << p->next->username << endl;
		cout << "HIGH2: " << high->username << endl;
		_quickSortRecursive(p->next, high);
	}
}
void ELOManager::quickSort() {
	_quickSortRecursive(first, last);
}
user* ELOManager::partition(user* low, user* high) {
	user* pivot = high;
	int index = -1, JJ = 0;
	user* i = low->previous;
	user* auxI = high;
	user* auxJ = high;
	bool breakLoop = false; //Break left partition and start on the right part

	cout << "Pivot Previous: " << pivot->ELO << "/////////////////////////////////" << endl;
	for (user* j = low; j != high && j != nullptr; j = j->next) {
		if (j->ELO <= pivot->ELO) {
			cout << endl << j->ELO << " <= pivot-> ELO --> TRUE" << endl;
			cout << "i++ and swap(i,j)" << endl;
			cout << "j: " << JJ << endl;
			cout << "index before: " << index << endl;
			cout << "j: " << j->username << endl;
			if (i != nullptr)
				cout << "index before: " << i->username << endl;
			i = (i == NULL) ? low : i->next;
			index++;
			cout << "index after: " << index << endl;
			cout << "index after: " << i->username << endl;

			swap(i, j);


			int k = 0;
			for (user* indexI = first; indexI->next != nullptr; indexI = indexI->next) {

				if (k == index) {
					i = indexI;
				}
				k++;
			}

			k = 0;
			for (user* indexJ = first; indexJ->next != nullptr; indexJ = indexJ->next) {

				if (k == index) {
					i = indexJ;
				}
				k++;
			}
		//	cout << "index after swap: " << i->username << endl;
		//	cout << "j after swap: " << j->username << endl;
			breakLoop = true;
		}
		else {
		//	cout << "j->ELO <= pivot-> ELO --> FALSE" << endl;
		//	cout << "j: " << JJ << endl;
		//	cout << "index: " << index << endl;
		}
		JJ++;
	}
	i = (i == NULL) ? low : i->next;
	if (i->next != nullptr) {
		swap(i->next, pivot);
		int k = 0;
		for (user* indexI = first; indexI->next != nullptr; indexI = indexI->next) {

			if (k == index) {
				i = indexI;
			}
			k++;
		}
	//	cout << "partition returns i: " << i->next->ELO << endl;
	//	cout << endl << "Loop finished -----------------------" << endl;
		printUsers();
		return i->next;

	}
	else {
	//	cout << "We return low " << endl;
		return low;
	}
}

void ELOManager::swap(user* A, user* B) {
	user* tmp = new user();
	user* swapperVector[6];

	//cout << endl << "swap1[" << A->username << "]" << endl;
	//cout << "swap2[" << B->username << "]" << endl;

	if (A == B) {
		//cout << "Same Users: Continue" << endl;
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
			if (A->next != nullptr)
				A->next->previous = A;
		}
		else if (A == first) {

			//A->previous->next = B;
			A->next->previous = B;
			B->previous->next = A;
			//B->next->previous = swapperVector[2];


			A->previous = B;
			B->previous = swapperVector[0];
			A->next = swapperVector[3];
			B->next = A;
			if (A->next != nullptr)
				A->next->previous = A;

			first = B;
		}

		//cout << endl << "Option 1" << endl;
	}
	else {
		A->previous = swapperVector[1];
		B->previous = swapperVector[0];
		A->next = swapperVector[3];
		B->next = swapperVector[2];

		if (A->previous != nullptr)
			A->previous->next = A;
		if (A->next != nullptr)
			A->next->previous = A;
		if (B->previous != nullptr)
			B->previous->next = B;
		if (B->next != nullptr)
			B->next->previous = B;
		//cout << endl << "Option 2" << endl;
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


	//cout << "Print list after swap" << endl << "-----" << endl;
	//printUsers();
}
int ELOManager::areTheyNeighbours(user* A, user* B) {
	if ((A->next == B && B->previous == A) || (A->previous == B && B->next == A)) {
		//cout << endl << "We are neighbours ++++++" << endl;
		return 1;
	}
	else {
		//cout << endl << "No neighbours ------" << endl;
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
			//cout << "Score:[" << index->score << "] ";
			cout << endl;
			i++;
		}
		cout << endl;
	}
}

void ELOManager::bubblesort() {
	
	bool swapLocal;
	cout << "Please be patient. It may take a couple of seconds..." << endl;
	do {
		swapLocal = false;
		for (user* index = first; index->next != nullptr; index = index->next) {
			if (index->ELO < index->next->ELO) {
				swap(index, index->next);
				swapLocal = true;
				if(index->previous!=nullptr)
					index = index->previous;
			}
		}
	} while (swapLocal);
}