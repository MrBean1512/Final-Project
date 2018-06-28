#ifndef CABIN_H_
#define CABIN_H_
#include "Camper.h"
#include <string>
#include <vector>
using namespace std;

class Cabin
{
private:
	char gender;
	vector<Camper> campers;

public:
	Cabin(char);
	char getGender();	//necessary so that guys and girls do not end up bunking together
	vector<Camper> getCampers();

	int getSize();
	void setGender(char);
	void addCamper(Camper);
};
#endif