/*\
	Jared Westmoreland
	2/4/2016
	Input file and states the name and the exam grades, then adds the grades up and divides by 3; giving
	the average.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

//Gives the format
struct student
{
	char  name[20];
        char  last[20];
        int   exam1;
        int   exam2;
        int   exam3;
        float mean;
};

int main()
{
	float plus=0;
	//says what the course is
	char courseID[9];
	//states the file
	FILE *fp;
	//Struct
	student currentStudent;

	//opens the file
	fp = fopen("student_data.txt", "r");
	//scans the courseID then saves it as courseID
	fscanf(fp, "%s", courseID);
	//Prints the courseID
	printf("%s\n", courseID);

	//If the file fails then it fails it
	if(fp == NULL)
	{
		printf("Error: File failed to open");
		return(1);
	}
	//If it finds the file opens then it allows it to run
	else
	{
		for(int i=0; i<20; i++)
		{
			//scans the file completely and saves it as the name last grades
			fscanf(fp, "%s %s %d %d %d", currentStudent.name, currentStudent.last, &currentStudent.exam1, &currentStudent.exam2, &currentStudent.exam3);
			plus = currentStudent.exam1 + currentStudent.exam2 + currentStudent.exam3;

			//Adds the grades together and gets the mean
			currentStudent.mean = plus/3;

			//prints the name last grade and mean
			printf("%s %s %d %d %d %.2lf\n", currentStudent.name, currentStudent.last, currentStudent.exam1, currentStudent.exam2, currentStudent.exam3, currentStudent.mean);
		}
	}

	//closes the file
	fclose(fp);
	return 0;
}
