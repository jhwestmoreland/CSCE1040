/*
	Jared Westmoreland

	Computer Science II	1040	Section 002
	Computer Science Lab	1040	Section 302

	Decription-	Allows you to store student names, course names,
	grades, the average grades, and is able to display them
*/
#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include "header.h"
using namespace std;

int main()
{
	ifstream jared;
	jared.open("Students.pdf");

		if(!jared.is_open())
		{
			ofstream k;
	        	k.open ("Students.pdf", ios::app);      //opens Students.pdf file
	        	k<<"\n";                                //establishes the file open
	        	k.close();                              //close the file

	        	ofstream hate;
        		hate.open("Students2.pdf", ios::app);   //opens Students2.pdf file
        		k<<"\n";                                //establishes the file open
        		hate.close();                           //closes the file

        		ofstream homework;
         		homework.open ("Courses.pdf", ios::app);//opens Courses.pdf file
         		homework<<"\n";                         //establishes the file open
         		homework.close();                       //closes the file
		}


	struct courses prog;			//class on struct

	//Menu
	cout<<"\n";
	cout<<" 1. Add new course\n";
	cout<<" 2. Add a new student\n";
	cout<<" 3. Add a student to a course\n";
	cout<<" 4. Add grades for a student in a course\n";
	cout<<" 5. Print a list of all courses\n";
	cout<<" 6. Print a list of all students\n";
	cout<<" 7. Print a list of all students in a course\n";
	cout<<" 8. Compute the average for a student in a course\n";
	cout<<" 9. Load Grade Book (from a user-specified file)\n";
	cout<<"10. Store Grade Book (to a user-specified file)\n";
	cout<<"11. Exit\n";

	//A loop which will only break if user picks 9
	while(true)
	{
		cout<< "\ncmd> ";	//asks user input
		cin>> prog.number;	//stores user input

		cout<<"\n";

		if (prog.number == 1 || prog.number == 5 || prog.number == 3 || prog.number == 4 || prog.number == 9)
		{
			course(prog);//goes to function course
		}

		else if (prog.number == 2 || prog.number == 6 || prog.number == 7 || prog.number == 8 || prog.number == 10)
		{
			student(prog);//goes to function student
		}

		else if (prog.number == 11)//kills the  program
		{
			cout<<"Good-bye -- Thank you for flying with CSCE1040 \n\n";
			break;
		}

		else//if input 1-9 wasn't valid
		{
			cout<<"Error: Number not found\n\n";
		}
	}

	return 0;
}
