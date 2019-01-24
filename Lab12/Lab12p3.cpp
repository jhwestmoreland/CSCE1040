/*
	Jared Westmoreland
	4/21/16
*/
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

class Employee
{
	private:
	char name[20];
	long salary;
	char *degree;
	char *position;
	char *getName()
        {
                return name;
        }
        long *GetSalary()
        {
                return salary;
        }

	public:
	char Manager(char name, long salary, char *degree, char *postion)
	{
		getname();
		GetSalary();
	}
	char Officer(char name, long salary, char *postion)
        {
		getname();
                GetSalary();
        }
	char Technician(char name, long salary, char *postion)
        {
		getname();
                GetSalary();
        }
	//virtual function
	void show_info()
	{
		cout<<"Employee "<<endl;
	}
};


int main()
{
	int i;
	#define NUM_EMPLOYEES 6;
	Employee* EmployeeList[NUM_EMPLOYEES];

	EmployeeList[0]= new Manager("Carla Garcia", 35000, "Economist");
	EmployeeList[1]= new Manager("Juan Perez", 38000, "Engineer");
	EmployeeList[2]= new Officer ("Pedro Egia", 18000, "Officer 1");
	EmployeeList[3]= new Officer ("Luisa Penia", 15000, "Officer 2";
	EmployeeList[4]= new Technician("Javier Ramos", 19500, "Welder");
	EmployeeList[5]= new Technician("Amaia Bilbao", 12000, "Electrican");

	Employee Manager(EmployeeList[0]);
	Employee Manager(EmployeeList[1]);
	Employee Officer(EmployeeList[2]);
	Employee Officer(EmployeeList[3]);
	Employee Technician(EmployeeList[4]);
	Employee Technician(EmployeeList[5])

	//The type of object pointed by a pointer to the base class
	//determines the function that is being called

	for(i = 0; i < NUM_EMPLOYEES ; i++)
	{
		EmployeeList[i]->show_info();
	}
	cout<<"Ya he terminado"<<endl;
}
