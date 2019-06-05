#ifndef _USERS_H
#define _USERS_H
#include <iostream>
#include <string>
#include <list>
using namespace std;

#define K 5; //constant number used to calculate ELO variations

struct user {
public:
	string username;
	float ELO = NULL; //Score of the user
	float score = NULL; //Result of the game
	float exp = NULL; //Level of mastery. 1 victory = +3. 1 draw = 2. 1 loss = +1
	user* next = nullptr;
	user* previous = nullptr;
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
	void calculateScore(); //Calculate the resulting score of a game/day 

	//Normal functions
	void addNewUser(string name, float ELO); //Add a new user with an ELO of 0	
	void printUsers();

	//Ordering users by ELO
	int getArraySize(); //Returns the number of users
	void quickSort(); //Order users based on their ELO
	void _quickSortRecursive(user* low, user* high);
	user* partition(user* low, user* high);
	void swap(user* name, user* second); //change the position of two users
	user* getFirstUser(); //Returns the first user
	void bubblesort();
	int areTheyNeighbours(user* A, user* B);
	
};

#endif // !_USERS_H
