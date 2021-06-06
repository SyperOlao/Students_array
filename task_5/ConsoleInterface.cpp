#include "ConsoleInterface.h"
#include <iostream>

void ConsoleInterface::showTextMenu()
{
    cout << "Choose: \n 1. Show info\n 2. Show all information\n 3. Show info about person\n"
        << " 4. Add person\n 5. Delete persion\n 6. Exit\n";
}

int ConsoleInterface::enterIndex()
{
    std::cout << "Enter index\n";
    int index;
    std::cin >> index;
    return index;
}

void ConsoleInterface::showMenu(List &list)
{
    while (true) {
        showTextMenu();
        InfoAboutUniversity a; 
        int user, index;
        cin >> user;
        system("cls");
        switch (user)
        {
        case 1:
            Menu::showInfo(list);
            break;
        case 2:
            Menu::showAllInformation(list);
            break;
        case 3:
            index = enterIndex(); 
            if (index > 0 && index < list.size) {
                Menu::showInfoAboutPerson(list.get(index));
            }
            else
            {
                cout << "You enter a wrong number!!\n";
            }
            break;
        case 4:
            a = Menu::readPersionFromKeyBoard();
            list.add(a);
            break;
        case 5:
            list.delete_elem(enterIndex());
            break;
  
        default:
            return;
        }
        
    }
}
