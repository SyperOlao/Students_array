#pragma once
#include <string>

struct InfoAboutUniversity
{
public: 
	int choise;
	std::string name;
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
	InfoAboutUniversity() {
		choise = 0;
		name = " ";
	}
	~InfoAboutUniversity(){}
};

