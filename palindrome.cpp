#include<iostream>
#include<string.h>
using namespace std;
//class palindrome
class palindrome
{
        public:
                void pal(int n);
                void pal(char c[]);
};
//function palindrome
void palindrome :: pal(int n)
{
        int n1,sum,a;
        n1=n;
        sum=0;
        //do while loop
        do
        {
                sum=sum*10;
                a=n%10;
                sum=sum+a;
                n=n/10;
        }while(n>0);
        if(sum==n1)
                cout<<"\n it is Palindrome";
        else
                cout<<"\n it is not a palindrome";

}
//function palindrome
void palindrome :: pal(char c[])
{
        	int length, flag = 0;
			length = strlen(c);
	
			for(int i=0; i < length; i++){
			if (c[i] != c[length - i - 1]){
			flag = 1;
			break;
			}
		}
	        //if else statement
			if (flag){
				cout << "string is not a palindrome";
		
		}
			else{
	
				cout << "String is a palindrome";
		}
}
//int main
int main()
{
        char c[50];
        int k,r;
        char v;
        palindrome p;
        do
        {
                cout<<"########### Palindrome Checker #############"<<endl;
                cout<<"1) Interger"<<endl;
                cout<<"2) Character"<<endl;
                cout<<"\nEnter the choice: ";
                cin>>r;
                switch(r)
                {       //case1
                        case 1:
                                cout<<"Enter the number: ";
                                cin>>k;
                                p.pal(k);
                                break;
                        //case2
                        case 2:
                                cout<<"\nEnter the string to be checked: ";
                                cin>>c;
                                p.pal(c);
                                break;
                }
                cout<<"\ndo you want to continue? (y/n): ";
                cin>>v;
        }while(v == 'y');
        return 0;
}
