#include <iostream>
using namespace std;

#define N 100

//Global variables
int order = 0;
int n;
int x[N];
bool a[N], b[2*N-1], c[2*N-1];
bool *d = &c[N-1];

//Introduce the problem and input initial parameters
void Initial()
{
	cout<<"#########################################################\n";
	cout<<"##       This is the Queens arrangement program!       ##\n";
	cout<<"#########################################################\n\n";
	cout<<"Problem: put n Queens into the chess board n x n while they do not contact with each other\n";
	cout<<"Input n:"; cin>>n;
	for (int i = 0; i <= n-1; i++)
		a[i] = true;
	for (int i = 0; i<= 2*n-2; i++)
		b[i] = true;
	for (int i = 1-n; i<= n-1; i++)
		d[i] = true;
}

//Report the solution
void Result()
{
	order ++;
	cout << order << ".  ";
	for (int i = 0; i<= n-2 ; i++)
		cout<<x[i]<<", ";
	cout<< x[n-1]<<".\n";
}

//Test for the arrangement of a Queen into line i
void Test(int i)
{
	for (int j = 0; j <= n-1; j++)
		if (a[j] && b[i+j] && d[i-j]) //check that there are no Queens arranged before contacting
		{
			x[i] = j+1 ; //accept the new Queens in i column
			a[j] = false; b[i+j] = false; d[i-j] = false;
			if (i == n-1)
				Result();
			else
				Test(i+1);
			a[j] = true; b[i+j] = true; d[i-j] = true; //return the true value for the next solutions
		}
}

//Main program
void main()
{
	Initial();
	Test(0);
	system("pause");
}


