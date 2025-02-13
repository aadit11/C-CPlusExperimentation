#include <iostream>
using namespace std;

float vol(float s1)
{
	float v = s1*s1*s1;
	return v;
	
}

int main()
{
	float s;
	cout<<"Enter the side";
	cin>>s;
	
	cout<<vol(s);
	
	return 0;
}
