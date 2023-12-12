#include <iostream>
using namespace std;

void showflags(long f)
{
    long i;
    for (i = 0x8000; i; i = i >> 1)
    {
        if (i & f)
            cout << "1";
        else
            cout << "0";
    }
    cout << endl;
}

int main()
{
    long flag;
    flag = cout.flags();
    showflags(flag);
    // cout.self(ios::dec|ios::boolalpha|ios::skipws);
    return 0;
}
