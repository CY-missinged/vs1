// encoding=GBK
// 题目：电话号码簿管理系统
// 基本要求：设计一个电话号码簿管理系统，实现的功能如下：
// （1）增加电话号码；
// （2）删除电话号码；
// （3）显示电话号码信息；
#include <direct.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <cstdio>
using namespace std;

#define MAX 1000

// 管理员
class Manager
{
public:
    Manager() : m_people_total(0)
    {
        memset(password, 0, 20 * sizeof(password[0]));
        memset(m_people_a, 0, (MAX + 1) * sizeof(m_people_a[0]));
        memset(m_people_p, 0, (MAX + 1) * sizeof(m_people_p[0]));
    }
    void read_file();                                        // 读取信息--管理员密码，用户信息
    void updata_file();                                      // 更新信息--管理员密码，用户信息
    int Get_total() { return m_people_total; }               // 获取注册用户数量
    char *Get_account(const int i) { return m_people_a[i]; } // 获取用户账号
    void new_people();                                       // 注册用户账号
    void see_account();                                      // 查看用户账号
    void change_password();                                  // 修改管理员密码
    void change_password_people();                           // 修改用户密码
    void change_password_all();                              // 重置所有用户密码
    int logon();                                             // 登录管理员系统
    int logon(char num1[], char num2[]);                     // 登录用户系统(比对账号与密码)
    //
    void change_account_people(const int i, const char num[20]) { strncpy(m_people_a[i], num, 20); }  // 修改指定用户账号
    void change_password_people(const int i, const char num[20]) { strncpy(m_people_p[i], num, 20); } // 修改指定用户密码
private:
    int m_people_total;                                                  // 用户注册数
    char password[20], m_people_a[MAX + 1][20], m_people_p[MAX + 1][20]; // 管理员密码，用户账号，用户密码
};

// 电话信息
struct Data_people
{
    int sex, age;
    char name[20], num[30], address[30];
};

// 用户
class People : public Manager
{
public:
    People() : Data_total(0)
    {
        memset(account, 0, 20 * sizeof(account[0]));
        memset(data, 0, (MAX + 1) * sizeof(data[0]));
    }
    int logon(Manager *manager);                   // 用户登录
    char *Get_account() { return account; }        // 获取用户账号
    char *Get_password() { return password; }      // 获取用户密码
    int Get_total() { return Data_total; }         // 获取用户电话数量
    void zengjia(const int i);                     // 增加电话号码
    void xianshi();                                // 显示电话号码信息
    void xianshi(const int i);                     // 显示某个电话号码信息
    void shanchu();                                // 删除电话号码
    void chazhao();                                // 查找
    void qingkong();                               // 清空电话簿信息
    void updata_file();                                 // 更新电话簿信息
    int change_account_password(Manager *manager); // 修改账号密码
    void file_cout();                              // 导出信息
    void file_cin();                               // 文件导入电话号码信息

private:
    char account[20], password[20]; // 用户账号,密码
    Data_people data[MAX + 1];      // 电话信息
    int Data_total;                 // 用户电话数量
};

void showmenu_people();        // 用户菜单
void showmenu_zhu();           // 主菜单
void showmenu_manager();       // 管理员菜单
void showmenu_people_choose(); // 选择登录方式

int main()
{
    Manager user_manager;
    int ch_zhu, ch_people, ch_manager;
    int i;
    user_manager.read_file();
    showmenu_zhu(); // 主菜单
    cin >> ch_zhu;
    while (1)
    {
        switch (ch_zhu)
        {
        case 1: // 登录管理员系统
        {
            if (user_manager.logon())
                break;
            system("pause");
            system("cls");
            showmenu_manager();
            cin >> ch_manager;
            while (1)
            {
                switch (ch_manager)
                {
                case 1: // 显示系统信息
                    cout << "当前用户注册数：" << user_manager.Get_total() << endl;
                    break;
                case 2: // 删除指定用户
                    cout << "删除指定用户";
                    break;
                case 3: //  删除所有用户
                    break;
                case 4: //  修改管理员系统密码
                    break;
                case 0: // 退出管理员系统
                    cout << "已退出管理员系统。" << endl;
                    break;
                default:
                    cout << "输入错误！请重新输入:" << endl;
                    break;
                }
                if (ch_manager == 0)
                    break;
                system("pause");
                system("cls");
                showmenu_manager();
                cin >> ch_manager;
            }
            break;
        }
        case 2: // 登录用户账号
        {
            People user_people;
            int choose, flag = 0, flag_ch_people = 1;
            system("pause");
            system("cls");
            showmenu_people_choose();
            cin >> choose;
            while (choose != 0)
            {
                switch (choose)
                {
                case 1: // 登录
                    flag = user_people.logon(&user_manager);
                    break;
                case 2: // 注册
                    user_manager.new_people();
                    break;
                default:
                    cout << "输入错误，请重新输入！" << endl;
                    break;
                }
                if (flag == 1)
                    break;
                system("pause");
                system("cls");
                showmenu_people_choose();
                cin >> choose;
            }
            if (choose == 0)
                break;
            system("pause");
            system("cls");
            showmenu_people();
            cin >> ch_people;
            while (1)
            {
                switch (ch_people)
                {
                case 1: // 增加电话号码信息
                    user_people.zengjia(user_people.Get_total() + 1);
                    break;
                case 2: // 删除电话号码信息
                    user_people.shanchu();
                    break;
                case 3: // 显示电话号码信息
                    user_people.xianshi();
                    break;
                case 4: // 查找电话号码信息
                    user_people.chazhao();
                    break;
                case 5: // 清空电话号码信息
                    user_people.qingkong();
                    break;
                case 6: // 修改账号密码
                    flag_ch_people = user_people.change_account_password(&user_manager);
                    break;
                case 7: // 导出电话号码簿信息
                    user_people.file_cout();
                case 8: // 文件导入电话号码簿信息
                    user_people.file_cin();
                    user_manager.updata_file();
                    break;
                case 0:
                    cout << "请确定退出当前账号：" << endl;
                    cout << "";
                    cout << "已退出当前账号！" << endl;
                    break;
                default:
                    cout << "输入错误！请重新输入:" << endl;
                    break;
                }
                if (ch_people == 0 || flag_ch_people == 0)
                {
                    break;
                }
                system("pause");
                system("cls");
                showmenu_people();
                cin >> ch_people;
            }
            break;
        }
        case 0:
            cout << "谢谢使用，再见！" << endl;
            break;
        default:
            cout << "输入错误，请重新输入！" << endl;
            break;
        }
        if (ch_zhu == 0)
        {
            break;
        }
        system("pause");
        system("cls");
        showmenu_zhu();
        cin >> ch_zhu;
    }
    return 0;
}

// 主菜单
void showmenu_zhu()
{
    cout << "**********************************************" << endl;
    cout << "************  电话号码簿管理系统      ********" << endl;
    cout << "************        ————主菜单        ********" << endl;
    cout << "**********************************************" << endl;
    cout << "************   1.管理员模式系统       ********" << endl;
    cout << "************   2.登录电话号码簿系统   ********" << endl;
    cout << "************   0.退出系统             ********" << endl;
    cout << "**********************************************" << endl;
    cout << "请输入你的选择：（0-2）" << endl;
}

// 管理员菜单
void showmenu_manager()
{
    cout << "**********************************************" << endl;
    cout << "************  电话号码簿管理系统      ********" << endl;
    cout << "************        ————管理员权限    ********" << endl;
    cout << "**********************************************" << endl;
    cout << "************   1.显示用户注册数量     ********" << endl;
    cout << "************   2.删除指定用户         ********" << endl;
    cout << "************   3.删除所有用户         ********" << endl;
    cout << "************   4.修改管理员系统密码   ********" << endl;
    cout << "************   0.退出管理员系统       ********" << endl;
    cout << "**********************************************" << endl;
    cout << "请输入你的选择：（0-4）" << endl;
}

// 用户菜单
void showmenu_people()
{
    cout << "***************************************************" << endl;
    cout << "************  电话号码簿管理系统           ********" << endl;
    cout << "************        ————用户权限           ********" << endl;
    cout << "***************************************************" << endl;
    cout << "************   1.增加电话号码信息          ********" << endl;
    cout << "************   2.删除电话号码信息          ********" << endl;
    cout << "************   3.显示电话号码信息          ********" << endl;
    cout << "************   4.查找电话号码信息          ********" << endl;
    cout << "************   5.清空电话号码信息          ********" << endl;
    cout << "************   6.修改账号密码              ********" << endl;
    cout << "************   7.保存电话号码簿信息        ********" << endl;
    cout << "************   8.从文件导入电话号码簿信息  ********" << endl;
    cout << "************   0.退出当前账号              ********" << endl;
    cout << "***************************************************" << endl;
    cout << "请输入你的选择：（0-6）" << endl;
}

// 选择登录方式
void showmenu_people_choose()
{
    cout << "**********************************************" << endl;
    cout << "************  电话号码簿管理系统      ********" << endl;
    cout << "************        ————用户登录选择  ********" << endl;
    cout << "************   1.登录账号             ********" << endl;
    cout << "************   2.注册账号             ********" << endl;
    cout << "************   0.返回上一层           ********" << endl;
    cout << "**********************************************" << endl;
    cout << "请输入你的选择：（0-3）" << endl;
}

// 读取信息--管理员密码，用户信息
void Manager::read_file()
{
    int num1, i;
    char num2[20], people_a[20], people_p[20];
    ifstream out("Manager.txt"); // 读取管理员密码及用户账号密码数量
    if (out)
    {
        out >> m_people_total;
        out >> num2;
        strncpy(password, num2, 20);
        for (i = 1; i <= m_people_total; i++)
        {
            out >> people_a;
            strncpy(m_people_a[i], people_a, 20);
            out >> people_p;
            strncpy(m_people_p[i], people_p, 20);
        }
        out.close();
    }
    else
    {
        cout << "资源文件位置错误！" << endl;
        cout << "资源文件位置错误！" << endl;
        cout << "资源文件位置错误！" << endl;
        cout << endl;
    }
}

// 更新信息--管理员
void Manager::updata_file()
{
    int i;
    ofstream out_people("Manager.txt", ios::trunc);
    if (out_people)
    {
        out_people << m_people_total << " " << password << endl;
        for (i = 1; i <= m_people_total; i++)
        {
            out_people << m_people_a[i] << " " << m_people_p[i] << endl;
        }
    }
}

// 登录管理员系统
int Manager::logon()
{
    char user_password[20];
    cout << "请输入密码:";
    cin >> user_password;
    if (strncmp(user_password, password, 20) == 0)
    {
        cout << "已成功登录管理员系统" << endl;
        return 0;
    }
    else
    {
        cout << "密码错误" << endl;
        return 1;
    }
}

// 登录用户账号——登录管理员系统重载
int Manager::logon(char *num1, char *num2)
{
    int i;
    for (i = 1; i <= m_people_total; i++)
    {
        if ((strncmp(num1, m_people_a[i], 20) == 0) && (strncmp(num2, m_people_p[i], 20) == 0))
            return 1;
    }
    return 0;
}

// 登录用户账号
int People::logon(Manager *manager)
{
    int i;
    char user_account[20], user_password[20], file_name[25];
    cout << "请输入账号:";
    cin >> user_account;
    cout << "请输入密码:";
    cin >> user_password;
    if (manager->logon(user_account, user_password) == 1)
    {
        cout << "账号" << user_account << "已登录" << endl;
        strncpy(file_name, strcat(user_account, ".txt"), 23);
        fstream out_people(file_name);
        if (out_people)
        {
            out_people >> account >> password >> Data_total;
            for (i = 1; i <= Data_total; i++)
            {
                out_people >> data[i].name >> data[i].sex >> data[i].age;
                out_people >> data[i].num >> data[i].address;
            }
            cout << "资源文件已读取。" << endl;
            out_people.close();
        }
        else
        {
            fstream out_people(file_name, ios::in | ios::out | ios::trunc);
            out_people.close();
            cout << "读取资源文件错误，已创建新的资源文件！" << endl;
        }
        return 1;
    }
    else
    {
        cout << "账号或密码错误！" << endl;
        return 0;
    }
}

// 注册用户账号
void Manager::new_people()
{
    int i = 0, j = 5;
    char account_logon[20], password_logon[20], password2_logon[20];
    while (i <= m_people_total)
    {
        cout << "请输入账号：" << endl;
        cin >> account_logon;
        for (i = 1; i <= m_people_total; i++)
        {
            if (strncmp(account_logon, m_people_a[i], 20) == 0)
            {
                cout << "账号已存在！请重新输入。" << endl;
                break;
            }
        }
    }
    while (j--)
    {
        cout << "请输入密码：" << endl;
        cin >> password_logon;
        cout << "请再次确认密码" << endl;
        cin >> password2_logon;
        if (strncmp(password_logon, password2_logon, 20) == 0)
        {
            cout << "账号注册成功！（返回上一层）" << endl;
            m_people_total++;
            strncpy(m_people_a[m_people_total], account_logon, 20);
            strncpy(m_people_p[m_people_total], password_logon, 20);
            ofstream out_manager("Manager.txt", ios::trunc);
            if (out_manager)
            {
                out_manager << m_people_total << " " << password << endl;
                for (int k = 1; k <= m_people_total; k++)
                    out_manager << m_people_a[k] << " " << m_people_p[k] << endl;
            }
            out_manager.close();
            return;
        }
        else
        {
            cout << "两次密码不相同！(剩余" << j << "次机会）" << endl;
        }
    }
}

// 增加电话号码信息
void People::zengjia(const int i)
{
    if (Data_total >= MAX)
    {
        cout << "电话簿已满！" << endl;
        return;
    }
    cout << "请输入姓名：" << endl;
    cin >> data[i].name;
    cout << "请输入性别：" << endl;
    cout << "1--男" << endl;
    cout << "2--女" << endl;
    cin >> data[i].sex;
    cout << "请输入年龄：" << endl;
    cin >> data[i].age;
    cout << "请输入电话号码：" << endl;
    cin >> data[i].num;
    cout << "请输入住址：" << endl;
    cin >> data[i].address;
    Data_total++;
    this->updata_file();
    cout << "保存成功！" << endl;
}

// 删除电话号码信息
void People::shanchu()
{
    if (Data_total == 0)
    {
        cout << "电话簿为空！" << endl;
        return;
    }
    int i, flag;
    char num_delete[30];
    cout << "请输入需要删除的电话号码：" << endl;
    cin >> num_delete;
    for (i = 1; i <= Data_total; i++)
    {
        if (strncmp(num_delete, data[i].num, 20) == 0)
        {
            cout << "确定删除电话号码————";
            cout << data[i].num << "？" << endl;
            cout << "请确定：" << endl;
            cout << "1--删除" << endl;
            cout << "2--取消删除" << endl;
            cin >> flag;
            if (flag == 1)
            {
                for (i++; i <= Data_total; i++)
                {
                    data[i - 1] = data[i];
                }
                Data_total--;
                cout << "已成功删除!" << endl;
                this->updata_file();
                return;
            }
            else
            {
                cout << "已取消删除" << endl;
                return;
            }
        }
    }
    cout << "未查询到需要删除的电话，请重新确认！" << endl;
}

// 查找电话号码信息
void People::chazhao()
{
    if (Data_total == 0)
    {
        cout << "电话簿为空！" << endl;
        return;
    }
    int i, flag, judge, sex_age_find;
    char num_name_find[30];
    judge = 0;
    cout << "请选择需要查找的信息：" << endl;
    cout << "1.电话号码" << endl;
    cout << "2.姓名" << endl;
    cout << "3.性别" << endl;
    cout << "4.年龄" << endl;
    cin >> flag;
    switch (flag)
    {
    case 1:
        cout << "请输入需要查找的电话号码：" << endl;
        cin >> num_name_find;
        for (i = 1; i <= Data_total; i++)
        {
            if (strncmp(num_name_find, data[i].num, 20) == 0)
            {
                cout << "查找成功！信息如下：" << endl;
                judge = 1;
                cout << "姓名\t  性别\t年龄\t电话\t\t住址" << endl;
                this->xianshi(i);
            }
        }
        break;
    case 2:
        cout << "请输入需要查找的姓名：" << endl;
        cin >> num_name_find;
        for (i = 1; i <= Data_total; i++)
        {
            if (strncmp(num_name_find, data[i].name, 30) == 0)
            {
                cout << "查找成功！信息如下：" << endl;
                judge = 1;
                cout << "姓名\t  性别\t年龄\t电话\t\t住址" << endl;
                this->xianshi(i);
            }
        }
        break;
    case 3:
        cout << "请输入需要查找的性别：" << endl;
        cout << "1--男" << endl;
        cout << "2--女" << endl;
        cin >> sex_age_find;
        for (i = 1; i <= Data_total; i++)
        {
            if (sex_age_find == data[i].sex)
            {
                judge++;
                if (judge == 1)
                {
                    cout << "查找成功！信息如下：" << endl;
                    cout << "姓名\t  性别\t年龄\t电话\t\t住址" << endl;
                }
                this->xianshi(i);
            }
        }
        break;
    case 4:
        cout << "请输入需要查找的年龄：" << endl;
        cin >> sex_age_find;
        for (i = 1; i <= Data_total; i++)
        {
            if (sex_age_find == data[i].age)
            {
                judge++;
                if (judge == 1)
                {
                    cout << "查找成功！信息如下：" << endl;
                    cout << "姓名\t  性别\t年龄\t电话\t\t住址" << endl;
                }
                this->xianshi(i);
            }
        }
        break;
    default:
        cout << "输入错误！" << endl;
        break;
    }
    if (judge == 0 && (flag == 1 || flag == 2 || flag == 3 || flag == 4))
        cout << "未查找到该信息！" << endl;
}

// 显示电话号码信息
void People::xianshi()
{
    int i;
    if (Data_total == 0)
    {
        cout << "电话簿为空！" << endl;
        return;
    }
    cout << "账号" << account << "的电话簿信息如下：" << endl;
    cout << "姓名\t  性别\t年龄\t电话\t\t住址" << endl;
    for (i = 1; i <= Data_total; i++)
    {
        cout << data[i].name << "\t  ";
        if (data[i].sex == 1)
            cout << "男";
        else if (data[i].sex == 2)
            cout << "女";
        else
            cout << "未知";
        cout << "\t" << data[i].age << "\t" << data[i].num;
        cout << "\t" << data[i].address << endl;
    }
}

// 显示某个电话号码信息
void People::xianshi(const int i)
{
    cout << data[i].name << "\t  ";
    if (data[i].sex == 1)
        cout << "男";
    else if (data[i].sex == 2)
        cout << "女";
    else
        cout << "未知";
    cout << "\t" << data[i].age << "\t" << data[i].num;
    cout << "\t" << data[i].address << endl;
}

// 清空电话号码信息
void People::qingkong()
{
    if (Data_total == 0)
    {
        cout << "电话簿为空！" << endl;
        return;
    }
    int choose;
    cout << "确定清空电话簿信息？" << endl;
    cout << "1--是" << endl;
    cout << "2--否" << endl;
    cin >> choose;
    switch (choose)
    {
    case 1:
        Data_total = 0;
        cout << "电话簿已清空！" << endl;
        this->updata_file();
        break;
    case 2:
        cout << "已取消清空操作。" << endl;
        break;
    default:
        cout << "输入错误！" << endl;
    }
}

// 更新电话簿信息
void People::updata_file()
{
    int i;
    char account_updata[20];
    strncpy(account_updata, account, 20);
    ofstream out_people(strcat(account_updata, ".txt"), ios::trunc);
    if (out_people)
    {
        out_people << account << " " << password << " " << Data_total << endl;
        for (i = 1; i <= Data_total; i++)
        {
            out_people << data[i].name << " " << data[i].sex << " " << data[i].age;
            out_people << " " << data[i].num << " " << data[i].address << endl;
        }
    }
}

// 修改账号密码
int People::change_account_password(Manager *manager)
{
    char password_old[20], password_change[20], account_change[20], account_old[20];
    int choose_change, i = 0, flag = 0;
    strncpy(account_old, account, 20);
    cout << "请输入密码进行身份确定：" << endl;
    cin >> password_old;
    if (strncmp(password_old, password, 20) == 0)
    {
        cout << "密码正确！" << endl;
        cout << "请输入需要修改的信息：" << endl;
        cout << "1--账号" << endl;
        cout << "2--密码" << endl;
        cout << "3--账号与密码" << endl;
        cin >> choose_change;
        switch (choose_change)
        {
        case 1: // 修改账号
        {
            while (i <= manager->Get_total())
            {
                cout << "请输入修改后账号:" << endl;
                cin >> account_change;
                for (i = 1; i <= manager->Get_total(); i++)
                {
                    if (strncmp(account_change, manager->Get_account(i), 20) == 0)
                    {
                        cout << "该账号已存在！请重新输入。" << endl;
                        break;
                    }
                }
            }
            for (i = 1; i <= manager->Get_total(); i++)
            {
                if (strncmp(account, manager->Get_account(i), 20) == 0)
                {
                    manager->change_account_people(i, account_change);
                    break;
                }
            }
            strncpy(account, account_change, 20);
            this->updata_file();
            remove(strcat(account_old, ".txt"));
            manager->updata_file();
            cout << "登录失效，请重新登录！" << endl;
            return 1;
        }
        case 2: // 修改密码
        {
            while (1)
            {
                cout << "请输入修改后密码:" << endl;
                cin >> password_change;
                if (strncmp(password_change, password, 20) == 0)
                {
                    cout << "新密码与旧密码相同！请重新输入。" << endl;
                }
                else
                {
                    cout << "密码修改成功！" << endl;
                    cout << "登录失效，请重新登录！" << endl;
                    break;
                }
            }
            for (i = 1; i <= manager->Get_total(); i++)
            {
                if (strncmp(account, manager->Get_account(i), 20) == 0)
                {
                    manager->change_password_people(i, password_change);
                    break;
                }
            }
            strncpy(password, password_change, 20);
            this->updata_file();
            manager->updata_file();
            return 0;
        }
        case 3: // 修改账号与密码
        {
            while (i <= manager->Get_total())
            {
                cout << "请输入修改后账号:" << endl;
                cin >> account_change;
                for (i = 1; i <= manager->Get_total(); i++)
                {
                    if (strncmp(account_change, manager->Get_account(i), 20) == 0)
                    {
                        cout << "该账号已存在！请重新输入。" << endl;
                        break;
                    }
                }
            }
            for (i = 1; i <= manager->Get_total(); i++)
            {
                if (strncmp(account, manager->Get_account(i), 20) == 0)
                {
                    manager->change_account_people(i, account_change);
                    break;
                }
            }
            strncpy(account, account_change, 20);
            remove(strcat(account_old, ".txt"));
            while (1)
            {
                cout << "请输入修改后密码:" << endl;
                cin >> password_change;
                if (strncmp(password_change, password, 20) == 0)
                {
                    cout << "新密码与旧密码相同！请重新输入。" << endl;
                }
                else
                {
                    cout << "密码修改成功！" << endl;
                    cout << "登录失效，请重新登录！" << endl;
                    break;
                }
            }
            for (i = 1; i <= manager->Get_total(); i++)
            {
                if (strncmp(account, manager->Get_account(i), 20) == 0)
                {
                    manager->change_password_people(i, password_change);
                    break;
                }
            }
            strncpy(password, password_change, 20);
            this->updata_file();
            manager->updata_file();

            return 0;
        }
        default:
        {
            cout << "输入错误！" << endl;
            return 1;
        }
        }
    }
    else
        cout << "密码错误！" << endl;
}

// 导出电话号码簿信息
void People::file_cout()
{
    int i;
    char *path;
    path = _getcwd(NULL, 0);
    cout << "文件已保存至" << path << endl;
    char account_updata[20];
    strncpy(account_updata, account, 20);
    ofstream out_people(strcat(account_updata, "_电话簿.txt"), ios::trunc);
    if (out_people)
    {
        out_people << "账号" << account << "的电话簿信息如下：" << endl;
        out_people << "电话总数： " << Data_total << endl;
        out_people << "姓名\t性别\t年龄\t电话\t\t\t住址" << endl;
        for (i = 1; i <= Data_total; i++)
        {
            out_people << data[i].name << "\t";
            if (data[i].sex == 1)
                out_people << "男";
            else
                out_people << "女";
            out_people << "\t\t" << data[i].age;
            out_people << "\t\t" << data[i].num << "\t\t" << data[i].address << endl;
        }
        out_people.close();
    }
}

// 文件导入电话号码信息
void People::file_cin()
{
    char path[100], total_cin[10][20], somethings[10][20], sex_cin[5];
    int i = 3, j, Data_total_cin;
    cout << "请输入需要导入文件的绝对路径：" << endl;
    cin >> path;
    fstream out_people(path);
    if (out_people)
    {
        for (i = 1; i <= 3; i++)
        {
            if (i == 3)
                out_people >> Data_total_cin;
            else
                out_people >> total_cin[i];
        }
        for (i = 1; i <= 5; i++)
        {
            out_people >> somethings[i];
        }
        for (j = Data_total + 1; j <= Data_total + Data_total_cin; j++)
        {
            out_people >> data[j].name;
            out_people >> sex_cin;
            if (strcmp(sex_cin, "男") == 0)
                data[j].sex = 1;
            else
            {
                if (strcmp(sex_cin, "女") == 0)
                    data[j].sex = 2;
                else
                    data[j].sex = 3;
            }
            out_people >> data[j].age >> data[j].num >> data[j].address;
        }
        Data_total = Data_total + Data_total_cin;
        cout << "导入成功！" << endl;
        out_people.close();
    }
    else
    {
        cout << "文件打开失败！" << endl;
    }
    this->updata_file();
}
