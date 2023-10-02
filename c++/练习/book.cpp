#include<iostream>
#include"book.h"

using namespace std;

void book::book_input()
{
    cout<<"请输入书名、作者、出版社和价格"<<endl;
    cin>>title>>author>>publish>>price;
}

void book::book_print()
{
    cout<<title<<" "<<author<<" "<<publish<<" "<<price<<endl;
}

int main()
{
    book b1;
    b1.book_input();
    b1.book_print();
    return 0;
}