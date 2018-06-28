#include "Cabin.h"
#include "Camper.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

void registerCamper();//////////////////////gathers info from user about the camper being registered

string enterName();
int enterGrade();
char enterGender();
int enterInterests();

void generateRoster(vector<Camper>&);//////////////////////generates teams and cabins and then displays them

void generateTeams(vector<Camper>&, int&);	//teams are balanced based on camper age and interest
void generateCabins(vector<Camper>&, int&);	//cabins are generated so that there are only up to 10 students per cabin

int main()
{
	vector<Camper> camperList;
	ifstream input("roster.txt");
	if (!input) {
		cout << "No campers have been registered or the associated 'roster.txt' file does not exist. Creating new list." << endl;
		input.open("roster.txt");
		registerCamper();
	}
	else
		input.close();
	int choice;
	int i;
	while (i = 1) {
		cout << "Would you like to: \n(1) Register a new camper?\n(2) Generate a final roster (based on current registrants)?\n(3) Or exit the program?" << endl;
		cin >> choice;
		if (choice == 1)
			registerCamper();
		if (choice == 2) {
			generateRoster(camperList);
		}
		if (choice == 3)
			return 0;
		else
			cout << "Invalid choice. Retry." << endl;
	}
}

//////////////////////////////The following functions are used for registering new campers

void registerCamper()
{
	string tempName = enterName();
	int tempGrade = enterGrade();
	char tempGender = enterGender();
	int tempInterest = enterInterests();
	Camper tempCamper(tempName, tempGrade, tempGender, tempInterest);
	ofstream camperFile;
	camperFile.open("roster.txt", ios::app);
	camperFile.write((char*)&tempCamper, sizeof(tempCamper));
	camperFile.close();
}

string enterName()
{
	string name;
	cout << "Enter the name of your camper: ";
	cin >> name;
	return name;
}

int enterGrade()
{
	int grade = 0;
	int i = 0;
	while (i == 0) {
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Enter the grade of your camper: ";
		cin >> grade;
		if (grade < 5 || grade > 8)
			cout << "That is not a valid grade. Only 5th - 8th graders may attend Camp Whitworth" << endl;
		else
			i++;
	}
	return grade;
}

char enterGender()
{
	char gender = 'N';
	int i = 0;
	while (i == 0) {
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Enter the gender of your camper (M or F): ";
		cin >> gender;
		if (gender == 'M' || gender == 'F')
			i++;
		else
			cout << "That is not valid gender." << endl;
	}
	return gender;
}

int enterInterests()
{
	int interests = 0;
	int i = 0;
	while (i == 0) {
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Choose the interest which best describes your camper: "<<endl;
		cout << "(1) My camper enjoys videogames" << endl;
		cout << "(2) My camper enjoys sports" << endl;
		cout << "(3) My camper enjoys nature" << endl;
		cout << "(4) My camper enjoys art" << endl;
		cout << "(5) My camper enjoys socializing" << endl;
		cin >> interests;
		if (interests < 1 || interests > 5)
			cout << "That is not a valid interest. Retry." << endl;
		else
			i++;
	}
	return interests;
}

////////////////////The following fuctions are for generating teams, cabins, and a final roster for actual usage
void generateRoster(vector<Camper>& camperList)
{
	ifstream fileCampers;
	fileCampers.open("Roster.txt", ios::in);
	Camper obj;
	
	int count = 0;
	while (!fileCampers.eof()) {
		fileCampers.read((char*)&obj, sizeof(obj));
		if (fileCampers.fail()) break;
		camperList.push_back(obj);
		count++;
		//fileCampers.read((char*)&obj, sizeof(obj));
		cout << obj.getName();
	}
	fileCampers.close();
	int size = camperList.size();
	generateTeams(camperList, size);
	generateCabins(camperList, size);
	for (int i = 0; i < count; i++)
		cout <<"Name: " << camperList[i].getName() << "\t Grade: " << camperList[i].getGrade()
		<< "\t Cabin: " << camperList[i].getCabin() << "\t Team: " << camperList[i].getTeam() << endl;
	cout << "Camp List Generated" << endl;
}	//bracket produces errors even though it is correct

void generateTeams(vector<Camper>& camperList, int& size)
{
	int count = 0;
	for (int i = 5; i <= 8; i++) {
		for (int j = 1; j <= 5; j++) {
			for (int k = 0; k < size; k++) {
				if ((camperList[k].getGrade() == i) && (camperList[k].getInterests() == j)) {
					count++;
					camperList[k].setTeam(count%6);
				}
			}
		}
	}
}

void generateCabins(vector<Camper>& camperList, int& size)
{
	int count = 1;
	int cabin = 1;
	for (int i = 0; i < size; i++) {
		if (camperList[i].getGender() == 'M') {
			if (count >= 10) {
				count = 1;
				cabin++;
			}
			camperList[i].setCabin(cabin);
			count++;
		}
	}
	cabin = 13;		//I start at 13 here because the main campgrounds are split into a boys' side
	count = 1;		//and a girls' side with about 24 cabins total
	for (int i = 0; i < size; i++) {
		if (camperList[i].getGender() == 'F') {		//I could have made gender based on a numerical system so that I could avoid copying an pasting this
			if (count == 10) {						//but I would have needed to translate from char to int and viseversa elsewhere meaning this was the simplest option
				count = 1;
				cabin++;
			}
			camperList[i].setCabin(cabin);
			count++;
		}
	}
}