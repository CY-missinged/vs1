/*
 * @Author: CY-missinged 1809214019@qq.com
 * @Date: 2022-10-12 14:41:35
 * @LastEditors: CY-missinged 1809214019@qq.com
 * @LastEditTime: 2023-11-12 14:14:15
 * @FilePath: \vscode\time\test2.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>

using namespace std;

class A
{
public:
    int a;
    A(){
        a=1;
    }
};

class B{
public:
    A a;
    int b;
    B(){
        a=new A();
        b = 2;
    }
};

int main()
{
    A x;
    cout << x.a;
    return 0;
}