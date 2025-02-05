#include<iostream>
using namespace std;
class multi
{
	private:
	float a , b;
	public:
	friend float product(float x , float y);
		
};

float product(float x , float y)
{
	multi obj;
	obj.a= x;
	obj.b= y;
	return(obj.a * obj.b);
	
}

int main()
{
	float a,b;
	cout<<"Enter two numbers";
	cin>>a>>b;
	cout<<"Product is "<<product(a,b);
	return 0;
}
