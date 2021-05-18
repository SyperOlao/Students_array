#pragma once
#include <string>

struct InfoAboutUniversity
{
public: 
	int choise;
	std::string name;
	InfoAboutUniversity(){
		choise = 0;
		name = " ";

	}

	union{
		struct
		{
			int experience;
			int salary;

		} Teacher;
		struct {
			bool hasSalary;
			int group;
			int course;
			int id;
		}Student;

	};
	int size = 0;
	~InfoAboutUniversity(){}
};

