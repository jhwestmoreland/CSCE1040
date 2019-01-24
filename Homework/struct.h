/*
        Jared Westmoreland

        Computer Science II     1040    Section 002
        Computer Science Lab    1040    Section 302

        Decription-     Allows you to store student names, course names,
        grades, the average grades, and is able to display them
*/
#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <string.h>
using namespace std;

//Struct for my each of my files
struct courses{
        string course;                  //stores course id
        string coursename;              //stores course name
        string department;              //stores course department
        int grade[20];                  //stores grade
        int number;                     //stores random number
        float average;                  //averages grade
        string major;                   //stores major
        string student;                 //stores student name
};

