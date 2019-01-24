/*
	Jared Westmoreland
	Displays menu and processes userinput
	4/13/16
*/

#include "classfile.h"
using namespace std;

int main(void)
{
	Homework3 jo;

	node *head = NULL;		//makes pointer head null
	node *last = NULL;		//makes pointer tail null

	cout<<"\n\n+---------MENU----------+\n"	//menu
               << "|>ADD                   |\n"
               << "|>SEARCH                |\n"
               << "|>REMOVE                |\n"
               << "|>PRINT                 |\n"
               << "|>COMMANDS              |\n"
               << "|>EXIT                  |\n"
	        <<"+-----------------------+\n\n";

	while(jo.name != "exit")//loop until exit
	{
		cout<< "cmd> ";	//asks userinput
		cin >>jo.name;	//store userinput
		for(int i = 0; i< jo.name.length(); ++i)//makes userinput lowercase
		{
			jo.name[i] = tolower(jo.name[i]);
		}
		if(jo.name == "add")//if add
		{
			cin >>jo.character;//store character
			jo.add(head, last, jo.character);//goes to function add
			cout<<"\n";
		}
		else if(jo.name == "search")//if search
		{
			cin >>jo.find;//store character
			jo.search(head, jo.find);//goes to function search
			cout<<"\n";
		}
		else if(jo.name == "remove")//if remove
		{
			cin >>jo.character;//store character
			jo.remove(head, last, jo.character);//goes to function remove
			cout<<"\n";
		}
		else if(jo.name == "print")//if print
		{
			jo.print(head);//goes to function print
			cout<<"\n";
		}
		else if(jo.name == "commands")//if commands
		{
			jo.commands();//goes to commands
			cout<<"\n";
		}
		else if(jo.name == "exit")//if exit
		{
			cout<<"GOODBYE!\n\n";
			break;//breaks while
		}
		else
		{
			string worthless;
			getline(cin, worthless);// just stores any thing after the first name
			cout<<"Error! "<<jo.name<<" cannot be read\n\n";
		}
	}
	return 0;
}
