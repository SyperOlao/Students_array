#pragma once
#include "InfoAboutUniversity.h"
#include <string>

using namespace std;

class Menu
{
public:
	void showInfo(InfoAboutUniversity arr[], int amount);
	void showAllInformation(InfoAboutUniversity arr[], int amount);
	void showInfoAboutPerson(InfoAboutUniversity persion);
	void addPerson(InfoAboutUniversity*& arr, int &amount, int index);
	void deletePersion(InfoAboutUniversity* &arr, int &amount, int index);
	void changePersion(InfoAboutUniversity* &arr, int amountOfInformation, int index);
	void readFromFile(InfoAboutUniversity arr[], int &amount, string file);
	InfoAboutUniversity readPersionFromKeyBoard();
};

