// 活期储蓄账目管理系统
/*基本功能要求：
（1）向某账户存款；
（2）从某账户取款；
（3）查询某账户余额；
*/

// #include<<stdio.h>>
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
#define M 1000
// 本系统默认最大上限为1000

int i, j;
static int total = 5; // 静态全局变量：用来存放总的用户数量
char admin[20] = "admin";
char cmd[20] = "cmd";

class accout
{
public:
	accout()
	{
		strcpy(card, "000");
		strcpy(name, "000");
		strcpy(cardno, "000");
	}
	char card[20];
	char name[20];
	char cardno[20];
	float money;
	friend ostream &operator<<(ostream &out, accout &x);
	// friend istream& operator>>(ostream& in,accout& x);
};
ostream &operator<<(ostream &out, accout &x)
{
	out << x.card << " " << x.name << " " << x.cardno << " " << x.money << " " << endl;
	return out;
}

/*
istream& operator>>(ostream& in,accout& x){

}
*/

void Myfileopen(accout user[])
{ // 包含读
	ifstream in("information.txt");
	if (!in)
	{
		cout << "打开文件失败！\n";
	}
	else
	{ // 打开成功
		for (i = 0; i < total; i++)
		{
			in >> user[i].card >> user[i].name >> user[i].cardno >> user[i].money;
		}
	}
	in.close();
}

void Myfilewrite(accout user[])
{
	ofstream out("information.txt");
	if (!out)
	{
		cout << "打开文件失败！\n";
	}
	else
	{
		for (i = 0; i < total; i++)
		{
			out << user[i].card << " " << user[i].name << " " << user[i].cardno << " " << user[i].money << endl;
		}
	}
	out.close();
}

/*
struct information{
	char card[20];
	char name[20];
	char cardno[20];
	float money;
};
information I[M];
*/

void Show(accout user[])
{
	cout << "卡号  姓名  密码  金额" << endl;
	// cout<<"total="<<total<<endl;
	for (j = 0; j < total; j++)
	{
		// cout<<"<"<<j<<"> ";
		cout << user[j]; // 重载输出
	}
}

void Inaccout(accout user[])
{
	char str1[20], str2[20]; // 用户输入的卡号与密码
	int flag = 0;			 // 判断是否找到匹配账户
	float inmoney = 0;
	cout << "*------------存款-------------*" << endl;
	cout << "请输入您的卡号:";
	cin >> str1;
	cout << "请输入您的密码:";
	cin >> str2;
	// cout<<"str1="<<str1<<" str2="<<str2<<endl;
	for (i = 0; i < total; i++)
	{
		if (strcmp(user[i].card, str1) == 0 && strcmp(user[i].cardno, str2) == 0)
		{
			flag++;
			cout << "密码正确！" << endl;
			cout << "请输入存款金额：";
			cin >> inmoney;
			user[i].money = user[i].money + inmoney;
			cout << "存款成功！" << endl;
			cout << "您的账户余额为：";
			cout << user[i].money << endl;
			// Myfilewrite(user);
		}
	}
	if (flag == 0)
	{
		cout << "密码或卡号输入有误！" << endl;
	}
}

void Outaccout(accout user[])
{
	char str1[20], str2[20]; // 用户输入的卡号与密码
	int flag = 0;			 // 判断是否找到匹配账户
	float outmoney = 0;
	cout << "*------------取款-------------*" << endl;
	cout << "请输入您的卡号:";
	cin >> str1;
	cout << "请输入您的密码:";
	cin >> str2;
	// cout<<"str1="<<str1<<" str2="<<str2<<endl;
	for (i = 0; i < total; i++)
	{
		if (strcmp(user[i].card, str1) == 0 && strcmp(user[i].cardno, str2) == 0)
		{
			flag++;
			cout << "密码正确！" << endl;
			cout << "请输入取款金额：";
			cin >> outmoney;
			user[i].money = user[i].money - outmoney;
			cout << "取款成功！" << endl;
			cout << "您的账户余额为：";
			cout << user[i].money << endl;
			// Myfilewrite(user);
		}
	}
	if (flag == 0)
	{
		cout << "密码或卡号输入有误！" << endl;
	}
}

void Findaccout(accout user[])
{
	char str1[20], str2[20]; // 用户输入的卡号与密码
	int flag = 0;			 // 判断是否找到匹配账户
	cout << "*----------查询余额-----------*" << endl;
	cout << "请输入您的卡号:";
	cin >> str1;
	cout << "请输入您的密码:";
	cin >> str2;
	// cout<<"str1="<<str1<<" str2="<<str2<<endl;
	for (i = 0; i < total; i++)
	{
		if (strcmp(user[i].card, str1) == 0 && strcmp(user[i].cardno, str2) == 0)
		{
			flag++;
			cout << "密码正确！" << endl;
			cout << "您的账户余额为：";
			cout << user[i].money << endl;
		}
	}
	if (flag == 0)
	{
		cout << "密码或卡号输入有误！" << endl;
	}
}

void Creataccout(accout user[])
{
	int x = total;
	cout << "请输入用户卡号：" << endl;
	cin >> user[x].card;
	cout << "请输入用户姓名：" << endl;
	cin >> user[x].name;
	cout << "请输入用户密码：" << endl;
	cin >> user[x].cardno;
	user[x].money == 0;
	cout << "开户成功！" << endl;
	// Myfilewrite(user);
	total++;
}

void Destroyaccout(accout user[])
{
	int flag = 0, f = 0;
	char str1[20], str2[20];
	cout << "请输入用户卡号：" << endl;
	cin >> str1;
	cout << "请输入用户密码：" << endl;
	cin >> str2;
	for (i = 0; i < total; i++)
	{
		if (strcmp(user[i].card, str1) == 0 && strcmp(user[i].cardno, str2) == 0)
		{
			flag++;
			cout << "确认为卡号为" << user[i].card << "的用户销户请输入1,取消则输入0!" << endl;
			cout << "请输入：";
			cin >> f;
			if (f)
			{
				cout << "销户成功！" << endl;
				// Myfilewrite(user);
				total--;
			}
			else
			{
				cout << "销户操作已取消！" << endl;
			}
		}
	}
	if (flag == 0)
	{
		cout << "未查找到相关账户信息！" << endl;
	}
}

void Adminmenu(accout user[])
{
	char str1[20], str2[20];
	int select;
	cout << "请输入用户名：";
	cin >> str1;
	cout << "请输入密码：";
	cin >> str2;
	if (strcmp(str1, admin) == 0 && strcmp(str2, cmd) == 0)
	{
		cout << "登录成功！" << endl;
		do
		{
			cout << "*******************************" << endl;
			cout << "*       管理员操作菜单        *" << endl;
			cout << "*******************************" << endl;
			cout << "*1-----显示所有账户信息-------*" << endl;
			cout << "*2---------用户开户-----------*" << endl;
			cout << "*3---------用户销户-----------*" << endl;
			cout << "*0-----------退出-------------*" << endl;
			cout << "*******************************" << endl
				 << endl;
			cout << "请输入您的选择:";
			cin >> select;
			switch (select)
			{
			case 1:
				Myfileopen(user);
				Show(user);
				system("pause");
				system("cls");
				break;
			case 2:
				Myfileopen(user);
				Creataccout(user);
				system("pause");
				system("cls");
				break;
			case 3:
				Myfileopen(user);
				Destroyaccout(user);
				system("pause");
				system("cls");
				break;
			}
		} while (select != 0);
	}

	else
	{
		cout << "用户名或密码错误！" << endl;
	}
}

int main()
{
	int select;
	accout user[M];

	do
	{
		system("cls");
		cout << "*******************************" << endl;
		cout << "*    活期储蓄账目管理系统     *" << endl;
		cout << "*******************************" << endl;
		cout << "*1------以管理员身份登入------*" << endl;
		// cout<<"*1------------显示所有账户信息*"<<endl;
		cout << "*2-----------存款-------------*" << endl;
		cout << "*3-----------取款-------------*" << endl;
		cout << "*4---------查询余额-----------*" << endl;
		cout << "*0-----------退出-------------*" << endl;
		cout << "*******************************" << endl
			 << endl;
		cout << "请输入您的选择:";
		cin >> select;
		switch (select)
		{
		case 1:
			Adminmenu(user);
			system("pause");
			system("cls");
			break;
		case 2:
			Myfileopen(user);
			Inaccout(user);
			system("pause");
			system("cls");
			break;
		case 3:
			Myfileopen(user);
			Outaccout(user);
			system("pause");
			system("cls");
			break;
		case 4:
			Myfileopen(user);
			Findaccout(user);
			system("pause");
			system("cls");
			break;
		}
	} while (select != 0);
	system("cls");
	cout << "感谢使用本系统，祝您生活愉快！" << endl;
	return 0;
}
