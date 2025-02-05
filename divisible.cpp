#include <iostream>
using namespace std;

int main()
{
	
	int n;
	cout<<"Enter your number";
	cin>>n;
	
	if(n%5 == 0 && n%8 == 0)
	{
		cout<<"Number is divisible by both 5 and 8";
	}
	else if(n%5 != 0 && n%8 != 0)
	{
		cout<<"Number is not  divisible by both 5 and 8";
	}
	else if(n%5 == 0 && n%8 != 0)
	{
		cout<<"Number is only divisible by 5 ";
	}
	else if(n%5 != 0 && n%8 == 0)
	{
		cout<<"Number is only divisible by 8 ";
	}
	
	return 0;
}
