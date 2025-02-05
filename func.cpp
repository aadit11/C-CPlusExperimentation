#include<iostream>
using namespace std;

class fruit
{
	public:
		
	 int qty;  // data member of class fruit
	 string name;  // data member of class fruit
	 
	 
};    // class seds here


int main()
{
	fruit f1;  // f1 is the object of class fruit
	f1.qty = 2;
	f1.name = "Mango";
	cout<<"qty = "<<f1.qty;
	cout<<"Name of fruit = "<<f1.name;
	
	return 0;
	
}
