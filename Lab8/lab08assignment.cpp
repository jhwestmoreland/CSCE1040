/*
	Jared Westmoreland
	3/24/16
*/
#include <iostream>
#include <stdlib.h>
using namespace std;

int main(int argc, char* argv[])
{
	int k= 3;
	int row;
	int column;
	int counter;
	int j= 0;
	int input;
	row = atoi(argv[1]);
	column = atoi(argv[2]);

	cout<<"1. Print the matrix\n"
	    <<"2. Sum all of the element\n"
	    <<"3. Show the upper half\n"
	    <<"4. Show middle row\n"
	    <<"5. Show middle column\n\n"
	    << "cmd>";
	cin >>input;

	int table[100][100];
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < column; j++)
		{
			table[i][j] = atoi(argv[k]);
			k++;
		}
	}

	if(input == 1)
	{
		for(int i = 0; i < row; i++)
        	{
        	        for(int j = 0; j < column; j++)
        	        {
				cout<<table[i][j]<<"\t";
			}
			cout<<"\n";
        	}
	}

	else if(input == 2)
	{
		int sum = 0;
		for(int i = 3; i < argc; i++)
		{
			sum += atoi(argv[i]);
		}
		cout<<sum<<"\n\n";
	}

	else if (input == 3)
	{}

	else if (input == 4)
	{
		int m = row /2;
		if(row % 2 == 0)
                {
                        cout<<"Sorry the matrix is a square so there is not a defined middle\n\n";
                }
		else
                {
                        for(int i= 0; i < column; i++)
                        {
                                cout<<table[m][i]<<"\t";
                                cout<<" ";
                        }
                }
		cout<<"\n";
	}

	else if (input == 5)
	{
		int m = column /2;
		if(row % 2 == 0)
                {
                        cout<<"Sorry the matrix is a square so there is not a defined middle\n\n";
                }
		else
		{
			for(int i= 0; i < row; i++)
			{
				cout<<table[i][m]<<"\t";
				cout<<" ";
			}
		}
		cout<<"\n";
	}

/*	else if(input == 3)
	{
		int j = -1;
		for(int i = 3; i < argc; i++)
                {
                        j++;
                        if(j != column)
                        {
                                cout<<argv[i]<<"\t";
                        }
			else
			{
				cout<<"\n\n";
				return 0;
			}
		}
	}
	else if(input == 4)
	{
		if(row % 2 == 0)
		{
			cout<<"Sorry the matrix is a square so there is not a defined middle\n\n";
		}
		else
		{
			int j = 0;
			for(int i = column * 2; i < argc; i++)
                	{
	       			j++;
               			if(j != column)
               			{
                	     		cout<<argv[i-1]<<"\t";
				}
                	       	else
                	       	{
                	       	        cout<<argv[i-1]<<"\n\n";
                	       	        return 0;
                	       	}
                	}
		}
	}
	else if(input == 5)
        {
		int guess = column / 2;
		cout<<guess<<"\n\n";
                if(column % 2 == 0)
                {
                        cout<<"Sorry the matrix is a square so there is not a defined middle\n\n";
                }
                else
                {
                        int j = 0;
                        int i = column-(guess*2);
			while(i < argc)
			{
				i++;
				i += guess * 2;
                                j++;
                                if(j != row)
                                {
                                        cout<<argv[i]<<"\t";
                                }
                                else
                                {
                                        cout<<argv[i]<<"\n\n";
                                        return 0;
                              	}
                        }
                }
        }
*/
}
