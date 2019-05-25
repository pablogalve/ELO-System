#ifndef _USERS_H
#define _USERS_H
#include <iostream>
using namespace std;
#include <string>

class userController {
private:
	string username;
	float ELO;
	float score;
public:
	userController();
	~userController();
	void calculateELO();

};

#endif // !_USERS_H