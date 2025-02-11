#include<iostream>
using namespace std;

class rectangle
{
	private:
		int l;
		int b;
	
	public:
		rectangle()
		{
			std::cout<<"l:";
			std::cin>>l;
			std::cout<<"b:";
			std::cin>>b;
		}
		
		friend class square;
	
		
};

class square
{
	private:
		int s;
	public:
		square()
		{
			std::cout<<"s:";
			std::cin>>s;
		}
		
	void display(rectangle ob)
	{
		
		std::cout<<ob.l<<ob.b<<""<<s<<std::endl;
    }
		
};

int main()
{
	rectangle ob1;
	square ob2;
	ob2.display(ob1);
	
	return 0;
}

