#include <iostream>
using namespace std;
class demoDC 
{ 
   private:
   int num1, num2 ;
   public:
   	
   demoDC()
    {
      num1 = 10;
      num2 = 20;
    }
   
    void display()
    {
      cout<<"num1 = "<< num1 <<endl;
      cout<<"num2 = "<< num2 <<endl;
    }
};
int main()
 {
   demoDC obj;
   obj.display();
    obj.display();
     obj.display();
   return 0;
 }   
