#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

float calc(int n1)
{
	int i = 0;
	int sum = 0;
	for(i = 1;i<=n1;i++)
	{
	    sum = sum + i;	
	}
	
	return sum;
	
}

int main()
{
	
	int n;
	cout<<"Enter your number";
	cin>>n;
	
	cout<<calc(n);
	
	return 0;
}
	
	
