/*
	Jared Westmoreland
	3/31/16
	Programming Bank transactions
*/
#include <iostream>
#include <string>
using namespace std;

void deposit(int num, int value, int *info);
void withdraw(int num, int value, int *info);
void balance(int num, int *info);
void transfer(int num1, int num2, int value, int *info);

int main()
{
	int info[10]= {0,0,0,0,0,0,0,0,0,0};
	string trans;
	int num;
	int value;
	int num1;
	int num2;
	string test;

	for(int i = 1; i < 10; i++)
	{
		info[i];
	}

	while(trans != "quit")
	{
		cout<< "bank>";
	        cin >>trans;

		if(trans == "deposit")
		{
			cin>> num;
			cin>> value;
			deposit(num, value, info);
			cout<<info[num]<<"\n";
		}
		else if(trans == "withdraw")
		{
			cin>> num;
                        cin>> value;
			withdraw(num, value, info);
			cout<<value<<"\n";
		}
		else if(trans == "balance")
		{
			cin>> num;
			balance(num, info);
			cout<<info[num]<<"\n";
		}
		else if(trans == "transfer")
		{
			cin>>num1;
			cin>>num2;
			cin>>value;
			transfer(num1, num2, value, info);
		}
		else if(trans == "quit")
		{
			cout<<"Thank you, have a nice day\n";
			break;
		}
		else
		{
			getline(cin, test);
			cout<<"Error! command not recognized\n";
		}
	}
	return 0;
}

void deposit(int num, int value, int *info)
{
	if(num > 9 || num < 1)
	{
		cout<<"Error! Account number does not exist\n";
	}
	else
	info[num]= info[num] + value;
}

void withdraw(int num, int value, int *info)
{
	if(num > 9 || num < 1)
        {
                cout<<"Error! Account number does not exist\n";
        }
	else if(value > info[num])
        {
		cout<<"Error! Account has insufficient funds\n";
	}
	else
        info[num]= info[num] - value;
}

void balance(int num, int *info)
{
	if(num > 9 || num < 1)
        {
                cout<<"Error! Account number does not exist\n";
        }
        else
        info[num]= info[num];
}

void transfer(int num1, int num2, int value, int *info)
{
	if(num1 > 9 || num1 < 1 || num2 > 9|| num2 < 1)
        {
                cout<<"Error! Account number does not exist\n";
        }
	else if(info[num1] < value)
	{
		cout<<"Error! Account has insufficient funds\n";
	}
	else
	{
		info[num1]= info[num1] - value;
		info[num2]= info[num2] + value;
	}
}
