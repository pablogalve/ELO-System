#ifndef _ELOMANAGER_H
#define _ELOMANAGER_H
#include <iostream>
using namespace std;
#include <string>

#define K 5; //constant number used to calculate ELO variations

struct users {
	string username;
	float ELO;
	float score;
};
class ELOManager {
private:
	
public:
	ELOManager(); //Constructor
	~ELOManager(); //Destructor
	void calculateELO();
	float getAvgUp(); //Get average ELO of all the users above you
	float getAvgDown(); //Get average ELO of all the users below you
	float getProbWinUp(); //Get your probabilities of beating users above you
	float getProbWinDown(); //Get your probabilities of beating users below you
	void 
};

#endif // !_ELOMANAGER_H