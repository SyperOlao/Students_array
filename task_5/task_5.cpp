#include <iostream>
#include <string>
#include "InfoAboutUniversity.h"
#include "Menu.h"

using namespace std; 
void showTextMenu();
int enterIndex();
void showMenu(Menu menu, InfoAboutUniversity*& arr, int amount);

int main()
{
    Menu menu;
    int amount = 2;
    InfoAboutUniversity* university = new InfoAboutUniversity[amount];
    menu.readFromFile(university, amount, "stud.txt");
    cout << "Students: \n";
    showMenu(menu, university, amount);
  
}
int enterIndex() {
    cout << "Enter index\n";
    int index;
    cin >> index;
    return index;
}
void showMenu(Menu menu, InfoAboutUniversity*& university, int amount)
{
    while (true) {
        showTextMenu();
        int user;
        cin >> user;
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
void showTextMenu() {
    cout << "Choose: \n 1. Show info\n 2. Show all information\n 3. Show info about person\n"
        <<" 4. Add person\n 5. Delete persion\n 6. Change perion \n 7. Exit\n";
}

