#include<iostream>
#include<string>
using namespace std;


int main()
{
	std::string s;
	std::cout<<"Enter the first line :";
	std::getline(std::cin , s);
	std::cout<<std::endl<<s<<std::endl;
	
	
	char book[100];
	std::cout<<"Enter your book";
	std::cin.get(book, 100);
	std::cout<<book;
	
	return 0;
	
}
