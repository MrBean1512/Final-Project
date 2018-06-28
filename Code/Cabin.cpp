#include "Cabin.h"
#include "Camper.h"


Cabin::Cabin(char gender)
{
	(*this).gender = gender;
}

char Cabin::getGender()
{
	return gender;
}

vector<Camper> Cabin::getCampers()
{
	return campers;
}

int Cabin::getSize()
{
	return campers.size();
}

void Cabin::setGender(char)
{
	(*this).gender = gender;
}

void Cabin::addCamper(Camper camper)
{
	campers.push_back(camper);
}