/*
	Author: Jared Westmoreland
	Date:	3/10/2016
	Encrypts words
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	int i = 0;
	ifstream test;
	test.open("sentences.txt");

	if(!test.is_open())
	{
		cout<<"Failure to open file\n\n";
		return 1;
	}

	string line;
	char word[300];
	char letter;
	while(!test.eof())
	{
		test>>line;
		ofstream exam;
		exam.open("exam.txt", ios::app);
		for(int i= 0; i < line.length(); i++)
		{
			exam<<line[i]<<"\n";
		}
	}
			ifstream read;
			read.open("exam.txt");
			while(!read.eof())
			{
				i++;
				read>>letter;
				if(letter == 'a')
				{
					word[i]= 'f';
				}
				else if (letter == 'b')
				{
					word[i]= 'c';

				}
				else if (letter  == 'c')
				{
                      			word[i]= 's';
        		       	}
				else if (letter  == 'd')
                                {
                                        word[i]= 'a';
                                       
                                }
                                else if (letter  == 'e')
                                {
                                        word[i]= 'n';
                                       
                                }
				else if (letter  == 'f')
                                {
                                        word[i]= 'k';
                                       
                                }
                                else if (letter  == 'g')
                                {
                                        word[i]= 'r';
                                       
                                }
				else if (letter  == 'h')
                                {
                                        word[i]= 'p';
                                       
                                }
                                else if (letter  == 'i')
                                {
                                        word[i]= 'o';
                                       
                                }
				else if (letter  == 'j')
                                {
                                        word[i]= 'y';
                                       
                                }
                                else if (letter  == 'k')
                                {
                                        word[i]= 'g';
                                       
                                }
				else if (letter  == 'l')
                                {
                                        word[i]= 'u';
                                       
                                }
                                else if (letter  == 'm')
                                {
                                        word[i]= 'i';
                                       
                                }
				else if (letter  == 'n')
                                {
                                        word[i]= 'm';
                                       
                                }
                                else if (letter  == 'o')
                                {
                                        word[i]= 'q';
                                       
                                }
				else if (letter  == 'p')
                                {
                                        word[i]= 'v';
                                       
                                }
                                else if (letter  == 'q')
                                {
                                        word[i]= 't';
                                       
                                }
				else if (letter  == 'r')
                                {
                                        word[i]= 'w';
                                       
                                }
                                else if (letter  == 's')
                                {
                                        word[i]= 'x';
                                       
                                }
				else if (letter  == 't')
                                {
                                        word[i]= 'j';
                                       
                                }
                                else if (letter  == 'u')
                                {
                                        word[i]= 'l';
                                       
                                }
				else if (letter  == 'v')
                                {
                                        word[i]= 'b';
                                       
                                }
                                else if (letter  == 'w')
                                {
                                        word[i]= 'd';
                                       
                                }
				else if (letter  == 'x')
                                {
                                        word[i]= 'e';
                                       
                                }
                                else if (letter  == 'y')
                                {
                                        word[i]= 'z';
                                       
                                }
				else if (letter  == 'z')
				{
					word[i]= 'h';
				
				}
			cout<<word<<" ";
			}
		read.close();
//		if(exam.eof())
//		{
//			break;
//		}

	//else break;

	return 0;
}
