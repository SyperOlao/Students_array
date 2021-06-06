#include "Menu.h"
#include <iostream>
#include <fstream>
#include <string>
#include "List.h"

using namespace std;

void Menu::showInfo(List list)
{
	for (int i = 0; i < list.size; i++)
	{
		cout << "Name: " << list.get(i).name << std::endl;
		if (list.get(i).choise == 1) {
			cout <<"Lesson: " << list.get(i).Teacher.experience<< std::endl;
		}
		if (list.get(i).choise == 2) {
			cout <<"Course: " << list.get(i).Student.course << std::endl;
			cout <<"Group: " << list.get(i).Student.group << std::endl;
		}
		cout << std::endl;
	}
}

void Menu::showAllInformation(List list)
{
	for (int i = 0; i < list.size; i++)
	{
		showInfoAboutPerson(list.get(i));
	}
}

void Menu::showInfoAboutPerson(InfoAboutUniversity persion)
{
	cout << "Name: " << persion.name << std::endl;
	if (persion.choise == 1) {
		cout << "Experience: " << persion.Teacher.experience << std::endl;
		cout << "Salary: " << persion.Teacher.salary << std::endl;
	}
	if (persion.choise == 2) {
		cout << "Id: " << persion.Student.id << std::endl;
		cout << "Course: " << persion.Student.course << std::endl;
		cout << "Group: " << persion.Student.group << std::endl;
		cout << "Has Salary: ";
		(persion.Student.hasSalary) ? std::cout << "yes\n" : std::cout << "no\n";
		
	}
	cout << std::endl;
}


void Menu::readFromFile(List &list, int &amount, string file)
{
	std::ifstream reading(file);
	InfoAboutUniversity temp;
	if (reading) {
		for (int i = 0; i < amount; i++) {
			reading >> temp.choise;
			reading.ignore();
			getline(reading, temp.name);
			if (temp.choise == 1) {
				reading >> temp.Teacher.salary;
				reading >> temp.Teacher.experience;
			}
			if (temp.choise == 2) {
				reading >> temp.Student.id;
				reading >> temp.Student.hasSalary;
				reading >> temp.Student.course;
				reading >> temp.Student.group;
			}
			list.add(temp);
		}
	}
	else {
		cout << "File is underfined" << endl;
	}
	reading.close();
}

InfoAboutUniversity Menu::readPersionFromKeyBoard()
{
	InfoAboutUniversity person;
	cout << "Enter name: " << std::endl;
	cin >> person.name;
	cout << "Choose teacher(1) or student (2)" << std::endl;
	int choise = 0;
	std::cin >> choise;
	person.choise = choise;
	switch (choise)
	{
	case 1:
		cout << "Enter an experience: " << std::endl;
		cin >> person.Teacher.experience;
		cout << "Enter a salary: " << std::endl;
		cin >> person.Teacher.salary;
		break;
	case 2:
		cout << "Enter an id: " << std::endl;
		cin >> person.Student.id;
		cout << "Enter a course: " << std::endl;
		cin >> person.Student.course;
		cout << "Enter a group: " << std::endl;
		cin >> person.Student.group;
		cout << "Has Salary: has(1) no(0)\n";
		bool b; 
		cin >> b;
		person.Student.hasSalary = b; 
		break;
	default:
		//cout << "You enter a wrong number!!!\n";
		break;
	}
	return person;
}

