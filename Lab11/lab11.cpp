/*
	Jared Westmoreland
	4/14/16
	Programming Bank transactions
*/
#include <iostream>
#include <string>
using namespace std;

class bank{


public:
	int info[10];
        string trans;
        int num;
        int value;
        int num1;
        int num2;
        string test;

void deposit(int num, int value, int *info);
void withdraw(int num, int value, int *info);
void balance(int num, int *info);
void transfer(int num1, int num2, int value, int *info);

};


int main()
{
	bank money;
	for (int i= 0; i<10; i++)
	{
		money.info[i]= 0;
	}

	for(int i = 1; i < 10; i++)
	{
		money.info[i];
	}

	while(money.trans != "quit")
	{
		cout<< "\nbank>";
	        cin >>  money.trans;

		if(money.trans == "deposit")
		{
			cin>>  money.num;
			cin>>  money.value;
			money.deposit(money.num, money.value, money.info);
		}
		else if( money.trans == "withdraw")
		{
			cin>>  money.num;
                        cin>>  money.value;
			money.withdraw(money.num, money.value, money.info);
		}
		else if( money.trans == "balance")
		{
			cin>>  money.num;
			money.balance(money.num, money.info);
			if(money.info[money.num]!=0)
			cout<< money.info[money.num]<<"\n";
			else
			cout<<"Error! command not recognized\n";
		}
		else if( money.trans == "transfer")
		{
			cin>> money.num1;
			cin>> money.num2;
			cin>> money.value;
			money.transfer(money.num1, money.num2, money.value, money.info);
		}
		else if( money.trans == "quit")
		{
			cout<<"Thank you, have a nice day\n\n";
			break;
		}
		else
		{
			getline(cin,  money.test);
			cout<<"Error! command not recognized\n";
		}
	}
	return 0;
}

void bank::deposit(int num, int value, int *info)
{
	if(num > 9 || num < 1)
	{
		cout<<"Error! Account number does not exist\n";
	}
	else
	info[num]= info[num] + value;
}

void bank::withdraw(int num, int value, int *info)
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

void bank::balance(int num, int *info)
{
	if(num > 9 || num < 1)
        {
                cout<<"Error! Account number does not exist\n";
        }
        else
        info[num]= info[num];
}

void bank::transfer(int num1, int num2, int value, int *info)
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
