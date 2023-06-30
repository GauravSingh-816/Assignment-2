#include<iostream>
using namespace std;

//Class employee
class Employee {
	//private data members
private:
	string name;
	string address;
public:
	//constructor
	Employee(string n, string a);
	//A print method to output class data
	void print();

	//Virtual functions
	virtual double weeklySalary() = 0;
	virtual int vacations() = 0;
	virtual double insurance() = 0;
};
class ProfessionalEmployee : public Employee
{
private:
	double monthlySalary;
public:
	//Constructor
	ProfessionalEmployee(string n, string a, double m);
	double weeklySalary();
	int vacations();
	double insurance();
};
class NonProfessionalEmployee : public Employee
{
private:
	double timeWork, hourRate;

public:
	//constructor
	NonProfessionalEmployee(string n, string add, double w, double h);
	double weeklySalary();
	int vacations();
	double insurance();
};