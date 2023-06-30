#include<iostream>
#include"employee.h"
using namespace std;


Employee::Employee(string n, string a)
	{
		name = n;
		address = a;
	}

void Employee::print()
	{
	cout << "Name : " << name << endl;
	cout << "Address : " << address << endl;
	}

ProfessionalEmployee::ProfessionalEmployee(string n, string a, double m) : Employee(n, a)
	{
		monthlySalary = m;
	}

double ProfessionalEmployee::weeklySalary()
	{
		return monthlySalary / 4;
	}

int ProfessionalEmployee::vacations()
	{
		return 23;
	}

double ProfessionalEmployee:: insurance()
	{
		return (2.0 * monthlySalary) / 3.0;
	}


NonProfessionalEmployee::NonProfessionalEmployee(string n, string a, double w, double h) : Employee(n, a)
	{
		timeWork = w;
		hourRate = h;
	}

	//overriding the virtual methods of parent class
double NonProfessionalEmployee :: weeklySalary()
	{
		return timeWork * hourRate;
	}

int NonProfessionalEmployee:: vacations()
	{
	return 12;
	}

double NonProfessionalEmployee :: insurance()
	{
		return weeklySalary() / 2.0;
	}