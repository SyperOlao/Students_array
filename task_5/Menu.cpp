#include "Menu.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void Menu::showInfo(InfoAboutUniversity arr[], int amount)
{
	for (int i = 0; i < amount; i++)
	{
		cout << "Name: " << arr[i].name << std::endl;
		if (arr[i].choise == 1) {
			cout <<"Lesson: " << arr[i].Teacher.experience<< std::endl;
		}
		if (arr[i].choise == 2) {
			cout <<"Course: " <<arr[i].Student.course << std::endl;
			cout <<"Group: " <<arr[i].Student.group << std::endl;
		}
		cout << std::endl;
	}
}

void Menu::showAllInformation(InfoAboutUniversity arr[], int amount)
{
	for (int i = 0; i < amount; i++)
	{
		showInfoAboutPerson(arr[i]);
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

void Menu::addPerson(InfoAboutUniversity*& arr, int &amount, int index)
{	
	if (index < 0 && index > amount)
		return;
	amount++;

	InfoAboutUniversity person = readPersionFromKeyBoard();
	InfoAboutUniversity* temp = new InfoAboutUniversity[amount];
	for (int i = 0, k = 0; i < amount; i++)
	{
		if (i != index) {
			temp[i] = arr[k];
			k++;
		}
		else {
			temp[i] = person;	
		}
	}	
	arr = temp;
}

void Menu::deletePersion(InfoAboutUniversity* &arr, int &amount, int index)
{
	if (index < 0 && index > amount)
		return;
	amount--;
	InfoAboutUniversity* temp = new InfoAboutUniversity[amount];
	for (int i = 0, k = 0; i < amount+1; i++)
	{
		if (i != index) {
			temp[k] = arr[i];
			k++;
		}
	}
	arr = temp;
}

void Menu::changePersion(InfoAboutUniversity*& arr, int amount, int index)
{
	if (index < 0 && index > amount)
		return;
	arr[index] = readPersionFromKeyBoard();
}

void Menu::readFromFile(InfoAboutUniversity arr[], int &amount, string file)
{
	std::ifstream reading(file);
	if (reading) {
		for (int i = 0; i < amount; i++) {
			reading >> arr[i].choise;
			reading.ignore();
			getline(reading, arr[i].name);
			if (arr[i].choise == 1) {
				reading >> arr[i].Teacher.salary;
				reading >> arr[i].Teacher.experience;
			}
			if (arr[i].choise == 2) {
				reading >> arr[i].Student.id;
				reading >> arr[i].Student.hasSalary;
				reading >> arr[i].Student.course;
				reading >> arr[i].Student.group;
			}
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
		cin >> person.Student.hasSalary;

	default:
		cout << "You enter a wrong number!!!\n";
		break;
	}
	return person;
}

