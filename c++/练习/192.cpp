#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    char str[20]="Welcome to C++!";
    int i=1234;
    ofstream out("test.tt");
    if(out)
    {
        out<<str<<i;
        out.close();
    }
    ifstream in("test.tt");
    if(in){
        in>>str;
        in>>i;
        cout<<str<<endl;
        cout<<i<<endl;
        in.close();
    }
    return 0;
}
