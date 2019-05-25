#ifndef _USERS_H
#define _USERS_H
#include <iostream>
#include <string>
using namespace std;

#define K 5; //constant number used to calculate ELO variations

struct user {
public:
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
	void addNewUser(string name, float ELO); //Add a new user with an ELO of 0
	void calculateScore(); //Calculate the resulting score of a game/day 
	void printUsers();
	int getArraySize(); //Returns the number of users
	void quickSort(user* first, int low, int high); //Order users based on their ELO
	int partition(user* first, int low, int high);
};

#endif // !_USERS_H
