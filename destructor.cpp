#include <iostream>
using namespace std;

class helloworld
{
	public:
		
		helloworld()
		{
			cout<<"helloworld \n";
			
		}
		
		~helloworld()
		{
			cout<<"destructor!!";
		}
};


int main()
{
	helloworld obj;
	
	return 0;
}
