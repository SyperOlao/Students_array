#pragma once
#include "Menu.h"
#include "InfoAboutUniversity.h"
#include "List.h"

class ConsoleInterface
{
private:
	static void showTextMenu();
	static int enterIndex();
public:
	static void showMenu(List &list);
};

