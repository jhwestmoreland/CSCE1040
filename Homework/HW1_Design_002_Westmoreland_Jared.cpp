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
using namespace std;

struct courses{
	string course;
	string coursename;
	string department;
        int grade;
        int number;
        float average;
	string major;
	string student;
};

void course(courses);
void student(courses);

int main()
{
	ofstream homework;
        homework.open ("Courses.pdf", ios::app);
	homework<<" ";
	homework.close();

	ofstream k;
        k.open ("Students.pdf", ios::app);
	k<<" ";
	k.close();

	ofstream hate;
        hate.open("Students2.pdf", ios::app);
	k<<" ";
	hate.close();

	struct courses prog;
	cout<<"\n";
	cout<<"1. Add new course\n";
	cout<<"2. Add a new student\n";
	cout<<"3. Add a student to a course\n";
	cout<<"4. Add grades for a student in a course\n";
	cout<<"5. Print a list of all courses\n";
	cout<<"6. Print a list of all students\n";
	cout<<"7. Print a list of all students in a course\n";
	cout<<"8. Compute the average for a student in a course\n";
	cout<<"9. Exit\n";

	while(true)
	{
		cout<< "\ncmd> ";
		cin>> prog.number;

		cout<<"\n";

		if (prog.number == 1 || prog.number == 5 || prog.number == 3 || prog.number == 4)
		{
			course(prog);
		}

		else if (prog.number == 2 || prog.number == 6 || prog.number == 7 || prog.number == 8)
		{
			student(prog);
		}

		else if (prog.number == 9)
		{
			cout<<"Good-bye -- Thank you for flying with CSCE1040 \n\n";
		}

		else
		{
			cout<<"Error: Number not found\n\n";
			return 1;
		}
	}

	return 0;
}

void course(courses prog)
{
	if (prog.number == 1)
	{
		string filler;

	        ifstream fun;
	        fun.open("Students2.pdf");

	        ifstream check;
	        check.open("Courses.pdf");

	        ofstream homework;
	        homework.open ("Courses.pdf", ios::app);

		cout<<"ENTER COURSE ID> ";
                cin >> prog.course;

		string line;
		while(prog.course != line)
		{
			check >> line;

			if(prog.course == line)
			{
				cout<<"***ERROR*** "<<prog.course<<" is already added.\n";
				break;
			}
			else if(prog.course !=line && check.eof())
			{
				ifstream three;
                                three.open(prog.course.c_str());

				ofstream tree;
				tree.open(prog.course.c_str());

				tree<<"\n";

                	        three.close();
				tree.close();

				cout<<"ENTER COURSE NAME> ";
        	                getline(cin, filler);
	                        getline(cin, prog.coursename);

                        	cout<<"ENTER DEPARTMENT NAME> ";
                	        getline(cin, prog.department);

				homework<<prog.course<<"\t\t"<<prog.coursename<<"\t\t\t"<<prog.department<<"\n";
	                        cout<<prog.course<<" has been added\n";
			 	break;
			}
		}
	}

	else if (prog.number == 5)
	{
		ifstream check;
		check.open("Courses.pdf");

		cout<<"COURSES\n";
		cout<<"-------\n";

		string line;
		while(!check.eof())
		{
			getline(check, line);
			cout<<line<<"\n";
		}
		check.close();
	}

	else if (prog.number == 3)
	{
		cout<<"ENTER STUDENT NAME> ";
		cin >>prog.student;

		cout<<"ENTER COURSE ID> ";
		cin >>prog.course;

	        ifstream check;
                check.open("Students.pdf");

                ofstream homework;
                homework.open ("Students.pdf", ios::app);

		ifstream fun;
                fun.open ("Students2.pdf");

                ofstream hate;
                hate.open("Students2.pdf", ios::app);

		string line;

		ifstream three;
                three.open(prog.course.c_str());

		if(!three.is_open())
                {
	                cout<<"***ERROR*** :"<<prog.course<<" IS INVALID\n\n";
                }

		else if (three.is_open())
                {
			ofstream tree;
                	tree.open(prog.course.c_str(), ios::app);

			string extra;
			string Id;
			string lane;

			while(prog.student != lane)
			{
				check >> Id>> lane>>extra;

				if(prog.student == lane)
				{
					string blessed;
					while(prog.student != blessed)
					{
						three >> blessed;
						if(prog.student == blessed)
						{
							cout<<"***ERROR*** :"<<prog.student<<" already enrolled in "<<prog.course<<"\n\n";
                                                        break;
						}
						else if (prog.student != blessed && three.eof())
						{
							cout<<"Added to "<<prog.course<<" -- "<<prog.student<<"\n\n";
                                                        tree<<Id<<"\t"<<prog.student<<"\n";
                                                        break;
						}
					}
					tree.close();
					break;
				}
				else if (prog.student != line && check.eof())
				{
					cout<<"***ERROR :*** "<<prog.student<<" IS NOT ENROLLED\n\n";
					break;
				}
			}
		}
		fun.close();
		hate.close();
		three.close();
	}

	if(prog.number == 4)
	{
		cout<<"ENTER COURSE ID> ";
		cin >>prog.course;

		cout<<"ENTER STUDENT NAME> ";
		cin >>prog.student;

		cout<<"\n<ENTER -1 WHEN COMPLETED>\n";

		ifstream three;
                three.open(prog.course.c_str(), ios::in);

                if(!three.is_open())
                {
                        cout<<"***ERROR*** :"<<prog.course<<" IS INVALID\n\n";
                }

                else if (three.is_open())
                {
			ofstream tree;
                        tree.open(prog.course.c_str(), ios::app);

			ifstream student;
        	        student.open(prog.student.c_str());

			if(!student.is_open())
                	{
                	        cout<<"***ERROR*** :"<<prog.student<<" IS ENROLLED\n\n";
                	}

	                else if (student.is_open())
        	        {
				ofstream right;
	                        right.open(prog.student.c_str(), ios::app);

				string first;
				string second;

				while(prog.student != first)
				{
					three>>first>>second;
					int j =0;
					int grade[6];
					int sum =0;
					if(prog.student == second)
					{
						while(true)
						{
							j++;
							cout<<"ENTER GRADE> ";
							cin>>grade[j];
							if(grade[j] != -1)
							{
								right<<" "<<grade[j];
							}
							sum += grade[j];
							if(grade[j] == -1)
							{
								prog.average = (sum+1)/(j-1);
								right<<" = "<<prog.average;
								break;
							}
						}

						cout<<"ADDED GRADES: "<<prog.student<<" "<<prog.course;
						for(int i = 0; i < j; i++)
						{
							cout<<grade[i]<<" ";
						}
						break;
					}

					else if(prog.student != second && three.eof())
					{
						cout<<"***ERROR***: "<<prog.student<<" IS NOT ENROLLED\n\n";
						break;
					}

			}

			}

		}
}}

void student(courses prog)
{	int i = 0;
	string id;
	if (prog.number == 2)
        {
        	ofstream homework;
        	homework.open ("Students.pdf", ios::app);

		ifstream check;
                check.open("Students.pdf");

		ofstream hate;
		hate.open("Students2.pdf", ios::app);

		ifstream fun;
                fun.open ("Students2.pdf");

		string p;

		while(true)
                {
			getline(check, p);
			++i;
			if(check.eof())
			{break;}
		}
		if(i >= 0 || i < 10 )
	        {
			id = "ID00";
                }
            	else if(i >= 10 || i<100)
               	{
               	 	id = "ID0";
                }
                else if	(i >=100)
                {
                	id = "ID";
              	}
                cout<<"ENTER STUDENT NAME> ";
                cin >> prog.student;

		ifstream student;
		student.open(prog.student.c_str());

		ofstream right;
		right.open(prog.student.c_str(), ios::app);
		right<<"AVERAGE:";

		student.close();
		right.close();

                string line;
		while(prog.student != line)
		{
			fun >>line;

                        if(prog.student == line)
                        {
				string sting;
				while(prog.student != sting)
				{
					check>>line>>sting;
					cout<<sting<<" "<<line;
					if(prog.student != sting)
					{
                                		cout<<"***ERROR*** "<<prog.student<<" IS ALREADY ENROLLED AS "<<line<<"\n\n";
                                		break;
					}
				}
                        }

                        else if(prog.student != line && fun.eof())
                      	{
		                cout<<"ENTER MAJOR> ";
				cin >>prog.major;

				hate<<prog.student<<endl;
				homework<<id<<i<<"\t\t"<<prog.student<<"\t\t"<<prog.major<<"\n";
				cout<<"Added:\t"<<prog.student<<"\t"<<id<<i<<"\n\n";

    				break;
                        }
		}

	fun.close();
        hate.close();
        check.close();
        homework.close();
	}

        else if (prog.number == 6)
        {
                ifstream check;
                check.open("Students.pdf");

		if(!check.is_open())
                {
                        cout<<"***ERROR*** :"<<prog.course<<" IS INVALID\n\n";
                }
		else if(check.is_open())
                {
			string line;
                	while(!check.eof())
                	{
                	        getline(check, line);
                       		cout<<line<<"\n";
                	}
		}
		check.close();
        }

	else if(prog.number == 7)
	{
		cout<<"ENTER COURSE ID> ";
		cin >>prog.course;

		ifstream three;
		three.open(prog.course.c_str());

		if(!three.is_open())
		{
			cout<<"***ERROR*** :"<<prog.course<<" IS INVALID\n\n";
		}
		else if(three.is_open())
		{
			string line;
			while(!three.eof())
			{
				getline(three, line);
				cout<<line<<"\n";
			}
		}
		three.close();
	}

	else if(prog.number == 8)
	{
		cout<<"ENTER COURSE ID> ";
		cin >>prog.course;
		cout<<"ENTER STUDENT ID> ";
		cin >>prog.student;

		ifstream three;
                three.open(prog.course.c_str());

		string Id;
		string line;
		while(Id != prog.student)
		{
			three>>Id>>line;

			if(Id == prog.student)
			{
				ifstream student;
				student.open(line.c_str());

				if(!student.is_open())
                		{
                        		cout<<"***ERROR*** :"<<prog.student<<" IS NOT ENROLLED\n\n";
               			}
                		else if (student.is_open())
				{
					ifstream right;
                                	right.open(line.c_str());

					string End;
					while(!right.eof())
					{
						getline(right, End);
						cout<<End<<"\n";
					}
				}
			}
			else if(Id != prog.student)
			{
				cout<<"ERROR UNABLE TO FIND "<<prog.course<<"\n\n";
				break;
			}
		}}

	}


