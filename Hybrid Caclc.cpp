#include<iostream>
#include<cmath>


using namespace std;
//class Simple calc
class SimpleCalc{
	public:
		float num1,num2;
		float add,sub,div,multi;
		
		void input(){
		//asking the user for input
		cout << "Enter two numbers: ";
		cin >> num1 >> num2;
		}
		//function simplecalc
		void simplecalc(){
			int ch;
			cout << ">>>####### Simple Calculator ########<<<" << endl;
			cout << "1) Addition" << endl;
			cout << "2) Substraction " << endl;
			cout << "3) Division " << endl;
			cout << "4) Multiplication " << endl;
			cout << "Enter your choice: ";
			cin >> ch;
			//switch case
			switch(ch){
				//case1
				case 1:
					add = num1 + num2;
					cout << "The Addition of the numbers are: " << add << endl;
					break;
				//case2	
				case 2:
					sub = num1 - num2;
					cout << "The Substraction of the numbers are: " << sub << endl;
					break;
				//case3	
				case 3:
					div = num1 / num2;
					cout << "The Division of the numbers are: " << div << endl;
					break;
				//case4	
				case 4:
					multi = num1 * num2;
					cout << "The Multiplication of the numbers are: " << multi << endl;
					break;
				//default	
				default:
					cout << "Wrong Choice, Try again!" << endl;
					break;
			}
			
		}
};
//class ScientificCalc
class ScientificCalc{
	public:
		float n;
		
		//function sciCalc
		void sciCalc(){
			int ch1;
			cout << ">>>########### Scientific Calculator #########<<<" << endl;
			cout << "1) Square " << endl;
			cout << "2) Sin" << endl;
			cout << "3) Log" << endl;
			cout << "4) Cos" << endl;
			cout << "Enter your choice: ";
			cin >> ch1;
			switch(ch1){
				//case1
				case 1:
					cout << "Enter the number: ";
					cin >> n;
					cout << "The Square of the number is: " << n * n;
					break;
				//case2	
				case 2:
					cout << "Enter the number: ";
					cin >> n;
					cout << "The Sine of the number is: " << sin(n);
					break;
				//case3	
				case 3:
					cout << "Enter the number: ";
					cin >> n;
					cout << "The Log of the number is: " << log(n);
					break;
				//case4	
				case 4:
					cout << "Enter the number: ";
					cin >> n;
					cout << "The Cosine of the number is: " << cos(n);
					break;
				//default	
				default:
					cout << "Wrong Choice, Try Again!"<<endl;
			}
		}
		
		
};
//class HybridCalc
class HybridCalc : public SimpleCalc, public ScientificCalc{
	public:
		//function display
		void display(){
			int ch2;
			
			cout << "########### Hybrid Calculator ###########" << endl;
			cout << endl;
			cout << "1) Simple Calculator" << endl;
			cout << "2) Scientific Calculator " << endl;
			cout << "3) Exit" << endl;
			cout << "Enter your choice: ";
			cin >> ch2;
			
			switch(ch2){
					//case1
					case 1:
						input();
						simplecalc();
						break;
					//case2	
					case 2:
						sciCalc();
						break;
					//case3	
					case 3:
						exit(0);
					//default	
					default:
						cout << "Wrong Choice, Try Again!" << endl;
						break;
				}
			}
		
		
};
//int main
int main(){
	
	HybridCalc c;
	c.display();
	char a;
	cout << "\nDo you want to continue? (y/n): ";
	cin >> a;
	do{
	
	if (a == 'y'){
		c.display();
		
	}
	else{
		exit(0);
	}
}while(a != 'n');
	return 0;
}
