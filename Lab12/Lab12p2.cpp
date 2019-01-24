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
	public:
	Employee(char n[20])
	{
		strcpy(name, n);
	}
	char *getName()
	{
		return name;
	}
	//virtual function
	void show_info()
	{
		cout<<"Employee "<<name<<endl;
	}
};
class Worker
{
        private:
	char name[20];
        public:
        Worker(char n[20])
        {
               strcpy(name, n);
        }
        char *getName()
        {
                return name;
        }
        //virtual function
        void show_info()
        {
                cout<<"Worker "<<name<<endl;
        }
};
class Technician
{
        private:
	char name[20];
        public:
        Technician(char n[20])
        {
                strcpy(name, n);
        }
        char *getName()
        {
                return name;
        }
        //virtual function
        void show_info()
        {
                cout<<"Technician "<<name<<endl;
        }
};
class Officer
{
        private:
	char name[20];
        public:
        Officer(char n[20])
        {
                strcpy(name, n);
        }
        char *getName()
        {
                return name;
        }
        //virtual function
        void show_info()
        {
                cout<<"Officer "<<name<<endl;
        }
};
class Manager
{
        private:
        char name[20];
        public:
        Manager (char n[20])
        {
                strcpy(name, n);
        }
        char *getName()
        {
                return name;
        }
        //virtual function
        void show_info()
        {
                cout<<"Manager "<<name<<endl;
        }
};
int main()
{
	char r[20]= "Rafa";
	char m[20]= "Mario";
	char a[20]= "Anton";
	char l[20]= "Luis";
	char p[20]= "Pablo";

	Employee Rafa(r);
	Manager Mario(m);
	Worker Anton (a);
	Officer Luis (l);
	Technician Pablo (p);

	//The type of object pointed by a pointer to the base class
	//determines the function that is being called

	Employee *pe;
	Manager *pm;
	Worker *pw;
	Officer *po;
	Technician *pt;

	pe = &Rafa;
	pe->show_info();
	pm = &Mario;
	pm->show_info();
	pw = &Anton;
        pw->show_info();
	po = &Luis;
        po->show_info();
	pt = &Pablo;
	pt->show_info();
	cout<<"Ya he terminado"<<endl;
}
