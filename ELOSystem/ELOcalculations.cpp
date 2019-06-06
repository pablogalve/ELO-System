#include "users.h"

void ELOManager::calculateELO(user* myself, float result) {
	myself->ELO += (result - getProbWin(myself->ELO, myself->next->ELO)) * myself->next->ELO * K;
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