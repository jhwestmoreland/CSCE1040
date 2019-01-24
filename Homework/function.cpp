/*
	Jared Westmoreland

	Computer Science II	1040	Section 002
	Computer Science Lab	1040	Section 302

	Decription-	Allows you to store student names, course names,
	grades, the average grades, and is able to display them
*/
#include "header.h"

void course(courses prog)
{
	//Adds new course
	if (prog.number == 1)
	{
		string filler;

	        ifstream fun;
	        fun.open("Students2.pdf");	//opens Students2.pdf (read)

	        ifstream check;
	        check.open("Courses.pdf");	//opens Courses.pdf (read)

	        ofstream homework;
	        homework.open ("Courses.pdf", ios::app); //Courses.pdf (write to end)

		cout<<"ENTER COURSE ID> ";	//Asks for Coures ID
                cin >> prog.course;		//Stores Course ID

		string line;
		while(prog.course != line)	//loop until input != anything
		{
			check >> line;

			if(prog.course == line)//if course already exists
			{
				cout<<"***ERROR*** "<<prog.course<<" is already added.\n";
				break;
			}
			//if course does not exist
			else if(prog.course !=line && check.eof())
			{
				ifstream three;	//allow to read user input
                                three.open(prog.course.c_str());

				ofstream tree; //allow to write
				tree.open(prog.course.c_str());

				tree<<"\n";	//establishes file

                	        three.close();	//closes ofstream and ifstream
				tree.close();

				cout<<"ENTER COURSE NAME> ";//gets course name
        	                getline(cin, filler);	//I have to use a filler cuz it fails to store
	                        getline(cin, prog.coursename); //actual store line

                        	cout<<"ENTER DEPARTMENT NAME> ";//get department
                	        getline(cin, prog.department);//gets input

				//puts info in file
				homework<<prog.course<<"\t\t"<<prog.coursename<<"\t\t\t"<<prog.department<<"\n";
	                        //couts user input as success prompt
				cout<<prog.course<<" has been added\n";
			 	break;
			}
		}
		fun.close();	//closes the 3 files above
		check.close();
		homework.close();
	}

	//Displays Courses to user
	else if (prog.number == 5)
	{
		ifstream check;	//read Courses.pdf
		check.open("Courses.pdf");

		cout<<"COURSES\n";	//makes it cool
		cout<<"-------\n";

		string line;
		while(!check.eof())	//loops till end of file
		{
			getline(check, line);	//get each line
			cout<<line<<"\n";	//outputs each line
		}
		check.close();		//closes file
	}

	//Add student to course
	else if (prog.number == 3)
	{
		cout<<"ENTER STUDENT NAME> ";	//gets name
		cin >>prog.student;		//stores name

		cout<<"ENTER COURSE ID> ";	//get ID
		cin >>prog.course;		//stores ID

	        ifstream check;			//opens Students.pdf (read)
                check.open("Students.pdf");

                ofstream homework;		//(write to end)
                homework.open ("Students.pdf", ios::app);

		ifstream fun;			//opens Students2.pdf (read)
                fun.open ("Students2.pdf");

                ofstream hate;			//(write to end)
                hate.open("Students2.pdf", ios::app);

		string line;

		ifstream three;			//opens user input course file
                three.open(prog.course.c_str());

		if(!three.is_open())	//if user input fails
                {
	                cout<<"***ERROR*** :"<<prog.course<<" IS INVALID\n\n";
                }

		else if (three.is_open())//if user input successed
                {
			ofstream tree;		//write to end of file
                	tree.open(prog.course.c_str(), ios::app);

			string extra;
			string Id;
			string lane;

			while(prog.student != lane)	//checks if student exists
			{
				check >> Id>> lane>>extra;//lane should match up with user input Student

				if(prog.student == lane)//if so
				{
					string blessed;
					while(prog.student != blessed)//checks if student exists already
					{
						three >> blessed;//blessed will equal user input Student
						if(prog.student == blessed)//if so
						{
							cout<<"***ERROR*** :"<<prog.student<<" already enrolled in "<<prog.course<<"\n\n";
                                                        break;
						}
						else if (prog.student != blessed && three.eof())//if not
						{
							cout<<"Added to "<<prog.course<<" -- "<<prog.student<<"\n\n";	//couts everything
                                                        tree<<Id<<"\t"<<prog.student<<"\n";
                                                        break;
						}
					}
					tree.close();//closes user input file
					break;
				}
				else if (prog.student != line && check.eof())//if not user input student has not been added
				{
					cout<<"***ERROR :*** "<<prog.student<<" IS NOT ENROLLED\n\n";
					break;
				}
			}
		}
		check.close();		//closes 5 files above
		homework.close();
		fun.close();
		hate.close();
		three.close();
	}

	//Adds grades
	if(prog.number == 4)
	{
		cout<<"ENTER COURSE ID> ";	//gets course
		cin >>prog.course;

		cout<<"ENTER STUDENT NAME> ";	//gets name
		cin >>prog.student;

		cout<<"\n<ENTER -1 WHEN COMPLETED>\n";	//Allows user to know how to exit program

		ifstream three;		//open user input file
                three.open(prog.course.c_str());

                if(!three.is_open()) //if fails to open
                {
                        cout<<"***ERROR*** :"<<prog.course<<" IS INVALID\n\n";
                }

                else if (three.is_open()) //if successful
                {
			ofstream tree;		//open it and write to end
                        tree.open(prog.course.c_str(), ios::app);

			ifstream student;	//allow to read input student
        	        student.open(prog.student.c_str());

			if(!student.is_open())//if user input file does not exist
                	{
                	        cout<<"***ERROR*** :"<<prog.student<<" IS ENROLLED\n\n";
                	}

	                else if (student.is_open())//if user input file does
        	        {
				ofstream right;		//open it up to write in
	                        right.open(prog.student.c_str(), ios::app);	//writes to the end

				string first;
				string second;

				while(prog.student != first)	//checks if student exists
				{
					three>>first>>second;	//first word in file will equal user input student
					int j;
					if(prog.student == second)	//if does
					{
						while(true)//make a endless loop
						{
							j++;
							cout<<"ENTER GRADE> ";	//get grade
							cin>>prog.grade[j];	//stores grade in array
							if(prog.grade[j] != -1)	//if user input grade does not equal
							{
								right<<"\n"<<prog.grade[j]; //store value
							}
							else if(prog.grade[j] == -1)
							{
								break;
							}
						}
						j = 0;
						cout<<"ADDED GRADES: "<<prog.student<<" "<<prog.course<<" ";//cout user inputs
						while(true)
						{
							j++;
							if(prog.grade[j] != -1)
							{
								cout<<prog.grade[j]<<" ";
							}
							else
							{break;}
						}
						cout<<"\n\n";
						break;
					}

					else if(prog.student != second && three.eof())//if does not
					{
						cout<<"***ERROR***: "<<prog.student<<" IS NOT ENROLLED\n\n";
						break;
					}

			}
			//Closes files
			tree.close();
			three.close();
			right.close();
			student.close();

	}
	}}
	else if (prog.number == 9)	//if number == 9
	{
		cout<<"ENTER FILENAME> ";	//gets user input
		cin >>prog.course;		//stores users input

		ifstream buddy;			//open file to read
		buddy.open(prog.course.c_str());
		if(!buddy.is_open())	//if file opening fails
		{
			cout<<"***ERROR***: File does not exist: "<<prog.course<<"\n\n";
		}
		else	//if it opens without fail
		{
			cout<<"\nData successfully initialized from: "<<prog.course<<"\n";

			string line;
			while(!buddy.eof())//loop each line
			{
				getline(buddy, line);//get each line
				cout<<line<<"\n";//output each line
			}
			cout<<"Input file closed: "<<prog.course<<"\n\n";
		}
		buddy.close();//closes file
	}
}

void student(courses prog)
{	int i = -1;
	string id;
	//Stores Student
	if (prog.number == 2)
        {
        	ofstream homework;	//write to end file student
        	homework.open ("Students.pdf", ios::app);

		ifstream check;		//read
                check.open("Students.pdf");

		ofstream hate;		//write to end file student2
		hate.open("Students2.pdf", ios::app);

		ifstream fun;		//read
                fun.open ("Students2.pdf");

		string p;

		while(true)//endless loop
                {
			getline(check, p);	//checks how many lines
			++i;			//keeps how many loop/lines
			if(check.eof())		//when at end of file break
			{break;}
		}
		if(i >= 0 || i < 10 )		//if loop is 0<=i<10
	        {
			id = "ID00";		//store string
                }
            	else if(i >= 10 || i<100)	//if loop is 10 <= i <100
               	{
               	 	id = "ID0";		//store string
                }
                else if	(i >=100)		//if loop is i>=100
                {
                	id = "ID";		//store string
              	}

                cout<<"ENTER STUDENT NAME> ";	//enter name
                cin >> prog.student;

		ifstream student;
		student.open(prog.student.c_str());	//open name

		ofstream right;				//writes to name
		right.open(prog.student.c_str(), ios::app);
		right<<"\n";		//establishes file name

		student.close();		//closes files
		right.close();

		string hello;
		string why;
                string line;
		while(prog.student != line)	//checks for student input file is already enrolled
		{
			fun>>line;	//line should equal student input

                        if(prog.student == line)	//if does
                        {
				cout<<"***ERROR*** "<<prog.student<<" IS ALREADY ENROLLED\n\n";
                        	break;
                        }

                        else if(prog.student != line && fun.eof())//if not
                      	{
		                cout<<"ENTER MAJOR> ";//Input
				getline(prog.major, cin);

				hate<<prog.student<<endl;//put student in Student2 so it will be easier to access later
				homework<<id<<i<<"\t\t"<<prog.student<<"\t\t"<<prog.major<<"\n";//puts it in Student2
				cout<<"Added:\t"<<prog.student<<"\t"<<id<<i<<"\n\n";//couts the info

    				break;
                        }
		}
	//closes file
	fun.close();
        hate.close();
        check.close();
        homework.close();
	}

	//Display Students to user
        else if (prog.number == 6)
        {
                ifstream check;	//oens student
                check.open("Students.pdf");

		if(!check.is_open())//if fail
                {
                        cout<<"***ERROR*** :"<<prog.course<<" IS INVALID\n\n";
                }
		else if(check.is_open())//if success
                {
			string line;
                	while(!check.eof())//loop till it reach the bottom of the file
                	{
                	        getline(check, line);//get each line
                       		cout<<line<<"\n";//couts each line
                	}
		}
		check.close();//closes
        }

	//lists all students in selected course
	else if(prog.number == 7)
	{
		cout<<"ENTER COURSE ID> ";//asks for course
		cin >>prog.course;

		ifstream three;//trys to read input course
		three.open(prog.course.c_str());

		if(!three.is_open())//checks if able to open
		{
			//if no
			cout<<"***ERROR*** :"<<prog.course<<" IS INVALID\n\n";
		}
		else if(three.is_open())//if yes
		{
			string line;
			while(!three.eof())	//loops till it hits the bottom
			{
				getline(three, line); //gets each line
				cout<<line<<"\n";	//couts each line
			}
		}
		three.close();	//close
	}

	//average of student grade
	else if(prog.number == 8)
	{
		int numbers = 0;
                int i = 0;
		double sum = 0;
		cout<<"ENTER COURSE ID> "; //get course ID
		cin >>prog.course;
		cout<<"ENTER STUDENT ID> ";//gets student ID
		cin >>prog.student;

		ifstream three;		//opens course file
                three.open(prog.course.c_str());

		string Id;
		string line;
		while(Id != prog.student)//if it exists
		{
			three>>Id>>line;//looking for ID and Name
			if(Id == prog.student)//if Student ID equals ID
			{
				ifstream stud;	//open line file
				stud.open(line.c_str());
				if(!stud.is_open())//if line file fails
                		{
                        		cout<<"***ERROR*** :"<<prog.student<<" IS NOT ENROLLED\n\n";
					break;
               			}
                		else if (stud.is_open())//if successeds
				{
					cout<<"Average: ";
					string End;
					while(true)//endless loop
        				{
        					stud >> numbers;      //checks how many lines
        				        sum += numbers;
						cout<<numbers<<" ";
						++i;                    //keeps how many loop/lines
				                if(stud.eof())         //when at end of file break
				                {break;}
					}
					prog.average= (sum / i);
					cout<<": "<<prog.average;
				}
				cout<<"\n\n";
				break;
			}
			else if(Id != prog.student)	//if fails to find
			{
				cout<<"ERROR UNABLE TO FIND "<<prog.course<<"\n\n";
				break;
			}

		}
	}
	else if (prog.number == 10)	//if number == 10
        {
                cout<<"ENTER FILENAME> ";
                cin >>prog.course;	//saves file name

                ofstream buddy;		//open file to write
                buddy.open(prog.course.c_str(), ios::app);//puts all input at the end without replacing
                if(!buddy.is_open())	//if failed
                {
              		buddy<<"\n";	//makes unknown file
			cout<<prog.course<<" has been created";
		}
                else
                {
			string line;
                        cout<<"\nOuput file opened: "<<prog.course<<"\n";
                        cout<<"Proceed to write to the file: "<<prog.course<<"\n";
			getline(cin, line);	//getline was acting funny
			getline(cin, line);	//gets spaces and any number or character
			buddy<<line;		//stores in file specified by user
                        cout<<"\nOnput file closed: "<<prog.course<<"\n\n";
                }
                buddy.close();	//closes file
        }
}



