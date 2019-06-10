#include "users.h"

void ELOManager::calculateELO(user* myself, float theirELO, float result) {
	float changeELO;
	float adjust;
	bool change;
	if (theirELO == 0) //To avoid not updating ELO
		theirELO = 1;
	changeELO = (result - getProbWin(myself->ELO, theirELO)) * K;
	
	//Change ELO balances to make sure that there are not negative ELOs and to create inflation on users with low ELO
	if (result == 1) {
		change = true;
	}
	else { 
		change = true;
		adjust = changeELO + myself->ELO;
		if (adjust < 0) { //Players can't have negative ELO
			myself->ELO = 0;
			change = false;
		}
	}
	if(change)
		myself->ELO += changeELO;
}
void ELOManager::calculateScore() {
	//This must be changed at a later stage
	float avg; // average ELO of other users
	float probWinUp;
	float probWinDown=0;
	user* index = first;
	
	while (index != nullptr) {
		avg = getAvgUp(index);
		//Probabilities of beating the user before you
		if(index->next!=nullptr)
			probWinUp = getProbWin(index->ELO, index->next->ELO);
		
		//Probabilities of beating the user after you
		/*if(index->previous !=nullptr) {
			probWinDown=getProbWin(index->ELO, index->previous->ELO);
		}*/

		index->score = index->ELO / 3 + static_cast <float> (rand()) / (static_cast <float> (200 / (probWinUp+probWinDown)));
		//index->score = index->ELO+7;

		//avg = getAvgDown(index);
		//probWin = getProbWin(index->ELO, avg) * 100;
		//index->score -= index->ELO + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / probWin));

		//Finish loop
		index = index->next;
	}
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
		return ELOsum / i;
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
		return ELOsum / i;
	}
}
float ELOManager::getProbWin(float myELO, float theirELO) {
	return (1 / (1 + pow(10, (theirELO - myELO) / 400)));
}
