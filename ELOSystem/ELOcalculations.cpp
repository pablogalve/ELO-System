#include "users.h"

void ELOManager::calculateELO(user* myself, float result) {
	float changeELO;
	float adjust;
	changeELO = (result - getProbWin(myself->ELO, myself->next->ELO)) * myself->next->ELO * K;
	
	//Change ELO balances to make sure that there are not negative ELOs and to create inflation on users with low ELO
	if (result == 1) {
		if (myself->ELO < 100) //Bonus to help users grow from low ELOs 
			changeELO *= 1.5; //50% bonus
		else if (myself->ELO < 200)
			changeELO *= 1.2; //20% bonus

		myself->ELO += changeELO;
	}
	else { 
		adjust = changeELO + myself->ELO;
		if (adjust < 0) //Players can't have negative ELO
			myself->ELO = 0;
		if (adjust <= 100)
			changeELO += 20; //Bonus to avoid users approach a very low level


	}
}
void ELOManager::calculateScore() {
	//This must be changed at a later stage
	float avg; // average ELO of other users
	float probWin;

	for (user* index = first; index->next != nullptr; index = index->next) {
		avg = getAvgUp(index);
		probWin = getProbWin(index->ELO, index->next->ELO);
	
		index->score = index->ELO/3 + static_cast <float> (rand()) / (static_cast <float> (200 / probWin));
		//index->score = index->ELO+7;

		//avg = getAvgDown(index);
		//probWin = getProbWin(index->ELO, avg) * 100;
		//index->score -= index->ELO + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / probWin));
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
