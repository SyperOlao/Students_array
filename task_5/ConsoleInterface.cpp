#include "ConsoleInterface.h"
#include <iostream>

void ConsoleInterface::showTextMenu()
{
    cout << "Choose: \n 1. Show info\n 2. Show all information\n 3. Show info about person\n"
        << " 4. Add person\n 5. Delete persion\n 6. Change perion \n 7. Exit\n";
}

int ConsoleInterface::enterIndex()
{
    std::cout << "Enter index\n";
    int index;
    std::cin >> index;
    return index;
}

void ConsoleInterface::showMenu(Menu &menu, InfoAboutUniversity*& university, int &amount)
{
    while (true) {
        showTextMenu();
        int user;
        cin >> user;
        system("cls");
        switch (user)
        {
        case 1:
            menu.showInfo(university, amount);
            break;
        case 2:
            menu.showAllInformation(university, amount);
            break;
        case 3:
            menu.showInfoAboutPerson(university[enterIndex()]);
            break;
        case 4:
            menu.addPerson(university, amount, enterIndex());
            break;
        case 5:
            menu.deletePersion(university, amount, enterIndex());
            break;
        case 6:
            menu.changePersion(university, amount, enterIndex());
            break;
        default:
            return;
        }
        
    }
}
