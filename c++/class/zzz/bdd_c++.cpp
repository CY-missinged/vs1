// 题目：电话号码簿管理系统
// 基本要求：设计一个电话号码簿管理系统，实现的功能如下：
// （1）增加电话号码；
// （2）删除电话号码；
// （3）显示电话号码信息；

#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

#define MAX 1000

//
class Data_people
{
public:
    static int total;
    Data_people() : sex(0), age(0)
    {
        memset(name, 0, 20 * sizeof(name[0]));
        memset(num, 0, 30 * sizeof(num[0]));
        memset(address, 0, 30 * sizeof(address[0]));
    }
    char *Get_num() { return num; }
    void zengjia(); // 增加电话号码
    void shanchu(); // 删除电话号码
    void xianshi(); // 显示电话号码信息

private:
    int sex, age;
    char name[20], num[30], address[30];
};

int Data_people::total = 0;

void showmenu1(); // 菜单
int chazhao(Data_people people[]);

Data_people people[MAX];

int main()
{
    int ch = 1;
    showmenu1();
    cin >> ch;
    while (ch != 0)
    {
        switch (ch)
        {
        case 1:
            if (Data_people::total == MAX)
                cout << "电话簿已满！" << endl;
            else
                people[Data_people::total + 1].zengjia();
            break;
        case 2:
            if (Data_people::total == 0)
                cout << "电话簿为空！" << endl;
            else
                people[1].shanchu();
            break;
        case 3:
            if (Data_people::total == 0)
            {
                cout << "电话簿为空！" << endl;
            }
            else
            {
                cout << "姓名\t  性别\t年龄\t电话\t\t住址" << endl;
                for (int i = 1; i <= Data_people::total; i++)
                {
                    people[i].xianshi();
                }
            }
            break;
        case 0:
            cout << "感谢使用，已退出！" << endl;
            break;
        default:
            cout << "输入错误，请重新输入！" << endl;
            break;
        }
        showmenu1();
        cin >> ch;
        system("pause");
        system("cls");
    }
    return 0;
}

// 菜单
void showmenu1()
{
    cout << "**********************************************" << endl;
    cout << "************  电话号码簿管理系统  ************" << endl;
    cout << "**********************************************" << endl;
    cout << "************   1.增加电话号码信息 ************" << endl;
    cout << "************   2.删除电话号码信息 ************" << endl;
    cout << "************   3.显示电话号码信息 ************" << endl;
    // cout << "************   4.?????????   ***************" << endl;
    // cout << "************   5.????????   ***************" << endl;
    // cout << "************   6.????????   ***************" << endl;
    // cout << "************   0.??????   ***************" << endl;
    cout << "*********************************************" << endl;
}

// 增加
void Data_people::zengjia()
{
    cout << "请输入姓名：" << endl;
    cin >> name;
    cout << "请输入性别：" << endl;
    cout << "1--男" << endl;
    cout << "2--女" << endl;
    cin >> sex;
    cout << "请输入年龄：" << endl;
    cin >> age;
    cout << "请输入电话号码：" << endl;
    cin >> num;
    cout << "请输入住址：" << endl;
    cin >> address;
    Data_people::total++;
    cout << "保存成功！" << endl;
}

// 删除电话号码
void Data_people::shanchu()
{
    int i = chazhao(people), flag;
    if (i != 0)
    {
        cout << "确定删除电话号码：" << people[i].Get_num() << endl;
        cout << "请确定：" << endl;
        cout << "1--删除" << endl;
        cout << "1--否" << endl;
        cin >> flag;
        if (flag == 1)
        {
            for (i++; i < Data_people::total; i++)
            {
                people[i - 1] = people[i];
            }
            Data_people::total--;
            cout << "已成功删除!" << endl;
        }
        else
        {
            cout << "已取消删除" << endl;
        }
    }
    else
    {
        cout << "未查询到该电话号码！" << endl;
    }
}

// 查找
int chazhao(Data_people people[])
{
    int i;
    char find_num[30];
    cout << "请输入需要查找的电话号码：";
    cin >> find_num;
    for (i = 1; i <= Data_people::total; i++)
    {
        if (strcmp(find_num, people[i].Get_num()))
            return i;
    }
    if (i != 0)
        return 0;
}

// 显示电话号码信息
void Data_people::xianshi()
{
    cout << name << "\t  ";
    if (sex == 1)
        cout << "男";
    else if (sex == 2)
        cout << "女";
    else
        cout << "未知";
    cout << "\t" << age << "\t" << num << "\t" << address << endl;
}
