#ifndef _ELOMANAGER_H
#define _ELOMANAGER_H
#include <iostream>
using namespace std;
#include <string>

#define K 5; //constant number used to calculate ELO variations

struct user {
	string username;
	float ELO;
	float score;
	user* next;
	user* previous;
};
class ELOManager {
private:
	user* first;
	user* last;
public:
	ELOManager(); //Constructor
	~ELOManager(); //Destructor
	void calculateELO();
	float getAvgUp(); //Get average ELO of all the users above you
	float getAvgDown(); //Get average ELO of all the users below you
	float getProbWinUp(); //Get your probabilities of beating users above you
	float getProbWinDown(); //Get your probabilities of beating users below you
	void addNewUser(string name); //Add a new user with an ELO of 0
	void calculateScore(); //Calculate the resulting score of a game/day 
};

#endif // !_ELOMANAGER_H