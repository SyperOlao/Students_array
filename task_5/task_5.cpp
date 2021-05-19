#include <iostream>
#include <string>
#include "InfoAboutUniversity.h"
#include "Menu.h"
#include "ConsoleInterface.h"
using namespace std; 


int main()
{
    Menu menu;
    int amount = 2;
    InfoAboutUniversity* university = new InfoAboutUniversity[amount];
    menu.readFromFile(university, amount, "stud.txt");
    cout << "Students: \n";
    ConsoleInterface::showMenu(menu, university, amount);
  
}

