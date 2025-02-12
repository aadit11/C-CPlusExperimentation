#include <iostream>
using namespace std;

int main()
 {    
    int num1;
    int num2;
    int c;
    int num3;
    
    cout<<"Enter first number";
    cout<<"Enter second number";
    
    cin>>num1;
    cin>>num2;
    
    cout<<"Enter your choice between 1 and 4";
    cin>>c;
    
    switch(c)
    {
    	case 1:
    		num3 = num1 + num2;
    		cout<<num3;
    		break;
    		
    	case 2:
    		num3 = num1 - num2;
    		cout<<num3;
    		break;
			
		case 3:
    		num3 = num1 * num2;
    		cout<<num3;
    		break;
			
		case 4:
    		num3 = num1 / num2;
    		cout<<num3;
    		break;
			
		default:
			cout<<"wrong choice entered";
		}
	}
			

						
    	
	
