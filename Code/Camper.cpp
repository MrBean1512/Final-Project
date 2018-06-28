#include "Camper.h"

Camper::Camper()
{
	name = "placeholder";
	grade = 0;
	gender = 'N';
	interests = 0;
	cabin = 0;
	team = 0;
}

Camper::Camper(string name, int grade, char gender, int interests)
{
	(*this).name = name;
	(*this).grade = grade;
	(*this).gender = gender;
	(*this).interests = interests;
	cabin = 0;
	team = 0;
}

string Camper::getName()
{
	return name;
}

int Camper::getGrade()
{
	return grade;
}

char Camper::getGender()
{
	return gender;
}

int Camper::getInterests()
{
	return interests;
}

int Camper::getTeam()
{
	return team;
}

int Camper::getCabin()
{
	return cabin;
}

void Camper::setName(string name)
{
	(*this).name = name;
}

void Camper::setGrade(int grade)
{
	(*this).grade = grade;
}

void Camper::setGender(char gender)
{
	(*this).gender = gender;
}

void Camper::setInterests(int interests)
{
	(*this).interests = interests;
}

void Camper::setTeam(int team)
{
	(*this).team = team;
}

void Camper::setCabin(int cabin)
{
	(*this).cabin = cabin;
}