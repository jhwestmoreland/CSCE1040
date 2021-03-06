/*
	Jared Westmoreland
	4/3/16
	Processes userinput and displays results
*/
#include "classfile.h"
using namespace std;

bool Homework3::Empty(node *head)	//check if node is empty
{
        if(head == NULL)		//if no node
        {
                return true;
        }
        else				//if yes node
        {
                return false;
        }
}
void Homework3::addFirstElement(node *&head, node *&last, char character)	//if no
{
        node *file = new node;		//makes new struct named file
        file->character = character;	//puts character into struct file
        file->next = NULL;		//makes null
        head = file;			//head = character
	last = file;			//last = character
}

typedef node* NodePtr;

void Homework3::add(node * &head, node * &last, char character)
{
        Homework3 jo;			//class
	NodePtr file;
	file = new node;
	NodePtr file2;
        file2 = new node;


	if(!head)		//goes to empty for true or false
        {
                addFirstElement(head, last, character);		//makes the head if none exists
  		cout<<"ADDED: "<<character<<"\n";
	      	return;
	}
        else if(head->character < character)				//if empty is false
        {
		file->character = character;	//puts character into struct file
          	file->next= NULL;		//makes null
		last->next= file;		//puts character on top
		last = file;
		cout<<"ADDED: "<<character<<"\n";
	}
	else
	{
		if(head->character <= character)		//if character is equal to anything
		{
			cout<<"DUPLICATE: "<<character<<"\n";
			return;
		}
		else						//if less
		{
			file->character = character;		//put it on botttom
			file->next = head;
			head = file;
			cout<<"ADDED: "<<character<<"\n";
			return;
		}
	}
}
void Homework3::search(node *head, char find)
{
        Homework3 jo;
	if(!head)
	{
		cout<<"ERROR: List is empty\n";
		return;
	}

        while(head->character != find && head->next != NULL)//looks at all characters inside each lined list
        {
                head = head-> next;//looks, next
        }
        if(head->character == find)//if finds userinput
        {
                cout<<"TRUE:"<<find<<"\n\n";
		return;
        }
        else//if cannot found
        {
                cout<<"FALSE:"<<find<<"\n\n";
        	return;
	}
}
void Homework3::remove(node *&head, node *&last, char character)
{
        Homework3 jo;

        if(!head)//looks if empty for true or false
        {
                cout<<"ERROR: Not found for Removal: "<<character<<"\n";
		return;
        }
        else//if empty is false
	{
	        node *previous = head;                          //add previous to head
	        node *current = head->next;                     //makes next current

		while(current)					//if there is a next
		{
			if(current->character == character)	//if character equals anything in program
			{
				previous->next = current->next;
				delete current;			//delete it
				cout<<"Removal successful: "<<character<<"\n";
				return;				//return
			}
			previous = current;			//if does if it loop back by shifting look
			current = current->next;
		}
		if(!current)					//if there is not a next
		{
			if(head->character == character)		//inside character = character
			{
				delete head;			//delete character looking for
				node *file = head;		//create opening
				head = head->next;
				return;
			}
			else
			cout<<"ERROR: Not found for Removal: "<<character<<"\n";	//if could not find
		}
	}
}
void Homework3::print(node *head)
{
        Homework3 jo;

        if(!head)//looks at empty if true or false
        {
                cout<<"NO NAMES IN LIST\n";
        	return;
	}
        else//if empty is false
        {
                while(head != NULL)//loops until end of list
                {
                        cout<<"\t"<< head->character <<"\n";//couts character
                        head = head->next;//goes to next list
                }
        }
}
void Homework3::commands() //basically repeats the menu and a command prompt
{
        cout<<"\n\tADD\n"
            << "\tREMOVE\n"
            << "\tPRINT\n"
            << "\tSEARCH\n"
	    << "\tCOMMANDS\n"
            << "\tEXIT\n\n"
	    << "\tcmd>\n";
}



