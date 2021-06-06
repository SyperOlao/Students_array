#pragma once
#include "InfoAboutUniversity.h"
#include <string>
#include "List.h"

using namespace std;

class Menu
{
public:
	static void showInfo(List list);
	static void showAllInformation(List list);
	static void showInfoAboutPerson(InfoAboutUniversity persion);
	static void readFromFile(List &list, int &amount, string file);
	static InfoAboutUniversity readPersionFromKeyBoard();
};

