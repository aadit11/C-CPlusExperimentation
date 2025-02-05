#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    fstream f;
    f.open("myfile.txt",ios::out);
    if(!f)
    {
        cout<<"File is not created"<<endl;
    }
    else
    {
        cout<<"File is successfully created"<<endl;
        f<<"HelloWorld!";
    }
    f.close();
    
    string s;
    f.open("myfile.txt",ios::in);
    if(!f)
    {
        cout<<"File not found"<<endl;
    }
    else
    {
        while(!f.eof())
        {
            f>>s;
        }
        cout<<"Text from the file is : ";
        cout<<s<<endl;
    }
    f.close();
    
    return 0;
}
