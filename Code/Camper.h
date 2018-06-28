#ifndef CAMPER_H_
#define CAMPER_H_
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

class Camper
{
private:
	string name;
	int grade, interests, team, cabin;	//interests are to ensure that one team does not recieve all of the sporty/outgoing children
	char gender;

public:
	Camper();
	Camper(string, int, char, int);	//only these variables are called because teams and cabins are generated when option 2 is selected

	string getName();
	int getGrade(), getCabin(), getTeam(), getInterests();
	char getGender();

	void setName(string);
	void setGrade(int);
	void setGender(char);
	void setInterests(int);
	void setTeam(int);
	void setCabin(int);

	bool operator<(Camper& c) { return (grade < c.getGrade()); }	//now that I'm looking back at this, I don't
	bool operator>(Camper& c) { return (grade > c.getGrade()); }	//think I ever used it but it might be nifty
};
#endif