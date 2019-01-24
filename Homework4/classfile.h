/*
	Jared Westmoreland
	4/3/16
	My struct and my class
*/
#include "beginning.h"
using namespace std;

struct node	//makes node
{
        char character;	//allows character in node
	node *next;	//repeats
	node *before;
};

class Homework3{
        public:		//Public rather than private

        char character;	//character number
        string name;	//string name
        char find;	//character target

        void addFirstElement(node *&head, node *&last, char character);	//adds if node doesn't exist
        void add(node *&head, node *&last, char character);		//adds user input
        void search(node *head, char find);				//searchs for target, user input
        void remove(node *&head, node *&last, char character);		//removes
	void left(node *&head, node *&last);				//shifts the list left
        void right(node *&head, node *&last);				//shifts the list right
	void print(node *current);					//prints all nodes
        void commands();						//displays all commands
        bool Empty(node *head);						//checks node if empty
};

