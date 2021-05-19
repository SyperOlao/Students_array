#pragma once
#include "Menu.h"
#include "InfoAboutUniversity.h"


class ConsoleInterface
{
private:
	static void showTextMenu();
	static int enterIndex();
public:
	static void showMenu(Menu &menu, InfoAboutUniversity*& university, int &amount);
};

