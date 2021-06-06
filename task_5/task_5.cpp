#include <iostream>
#include <string>
#include "InfoAboutUniversity.h"
#include "Menu.h"
#include "ConsoleInterface.h"
using namespace std; 


int main()
{
    
    int amount = 4;
    List university;
    Menu::readFromFile(university, amount, "stud.txt");
    ConsoleInterface::showMenu(university);
}

